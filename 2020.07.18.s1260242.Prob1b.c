

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/* Caesar Decryption */
char* CaesarDecrypt(int, char*);
/* BruteForceAttack */
void BruteForceAttack(char*, char*); 

int main(){
 
  char ciphertext[1024];  
  char keyword[1024];

  /*
    Input ciphertext and keyword. 
    If keyword is not specified (no keyword), press ENTER
  */

 printf("Input ciphertext: ");
 fgets(ciphertext,sizeof(ciphertext),stdin);
 
 printf("Input keyword: ");
 fgets(keyword,sizeof(keyword),stdin);
  

  BruteForceAttack(ciphertext,keyword);
  return 0;

}

char* CaesarDecrypt(int key, char *ciphertext){
  //printf("%d\t%s\n",key, ciphertext);
  /*Prob1bの方法だと、同じ文章を二回表示することになってしまう。理由はわからない*/
  char *plaintext=(char *)malloc(strlen(ciphertext));

  for(int i=0; i<strlen(ciphertext); i++){
      if(ciphertext[i]>= 'A' && ciphertext[i]<='Z'){
    plaintext[i]=(ciphertext[i]-'Z'-key)%26+'Z';
  }else if(ciphertext[i]>= 'a' && ciphertext[i]<='z'){
    plaintext[i]=(ciphertext[i]-'z'-key)%26+'z';
  }else{
      plaintext[i]=ciphertext[i];
  }
  }
  return plaintext;
}



void BruteForceAttack(char *ciphertext, char *keyword){
  //add
  char decrypttext[1024];
  char *str_dec;
  int cnt=0;
  
  if(keyword==NULL){
    for(int key=1; key<26; key++){
      str_dec=CaesarDecrypt(key,ciphertext);
      strcpy(decrypttext,str_dec);
      //free(str_dec);
      printf("Key: %2d plaintext: %s",key,decrypttext);
    }
  }else{
    for(int key=1; key<26; key++){
      str_dec=CaesarDecrypt(key, ciphertext);
      if(strstr(str_dec,keyword)==NULL){//not find
        cnt++;
      }else{
        printf("Key: %2d plaintext: %s",key,str_dec);
        //continue;
      }
      //free(str_dec);
    }

     if(cnt==25){
       printf("There is no decryption for keyword %s", keyword);
     }

  }
}
