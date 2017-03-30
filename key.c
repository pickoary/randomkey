#include<stdio.h>  
#include<String.h>
#include<stdlib.h> 
#include <time.h>
 
//const char lower_chars[] = "abcdefghijklmnopqrstuvwxyz";
//const char upper_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const char number_chars[] = "0123456789"; 
const char lower_chars[] = "abcdefghijkmnpqrstuvwxyz"; // no l or o
const char upper_chars[] = "ABCDEFGHJKLMNPQRSTUVWXYZ"; // no I or O
const char number_chars[] = "23456789"; // no 1 or 0
const char special_chars[] = "!@#$%^&*()-=_+[]{};:'\"<>,.?/";
 
const int _ks_key_len = 20;
 
void mkkey(char key[_ks_key_len+1]){
	int i = 0, j = 0, k = 0,n = 0;
	n = _ks_key_len/4;
	for (; i < n; i++){
		key[i] = lower_chars[rand()%(strlen(lower_chars))];
		key[i+n] = upper_chars[rand()%(strlen(upper_chars))];
		key[i+2*n] = number_chars[rand()%(strlen(number_chars))];
		key[i+3*n] = special_chars[rand()%(strlen(special_chars))];
	}
 
 
	j = _ks_key_len - 4*n;
	for (i = 0; i<j; i++) {
		key[i+4*n] = special_chars[rand()%(strlen(special_chars))];
	}
//字符乱序
	for (i = 0; i < 32; i++){ 
		j = rand()%(_ks_key_len);
		k = key[j];
		key[j] = key[i%_ks_key_len];
		key[i%_ks_key_len] = k;
	}
	key[_ks_key_len] = '\0';
}
 
 
int main(){
	srand(time(0));
	char szkey[_ks_key_len+1];
	FILE *fp;
	fp=fopen("random key.txt","w+");
	for (int i=0; i<16; i++){
		mkkey(szkey);
		printf("%s\n",szkey);
		fprintf(fp,"%s\n",szkey);
	}
	
	fclose(fp);
	return 0;
}
