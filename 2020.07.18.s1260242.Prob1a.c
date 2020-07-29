
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Caesar Encryption */
char* CaesarEncrypt(int, char *);
/* Caesar Decryption */
char* CaesarDecrypt(int, char *);

int main(){
  char plaintext[1024];
  char ciphertext[1024];
  char decrypttext[1024];
  //add
  char *str_ci;
  char *str_dec;
  
  int key;

  /*
    Input plaintex and key.
    Check the validity of key (key must be an interger number between 0 ~ 25)
  */
 
 
  //Plaintextの入力部
  printf("Input plaintext:");
  fgets(plaintext,sizeof(plaintext),stdin);//scanfだとどうやらよくないらしい

  printf("Input key (an integer from 1 to 25):");
  scanf("%d",&key);

    /*
    Perform Caesar Encryption: CaesarEncrypt(key, plaintext) and print out the ciphertext
  */ 

  str_ci=CaesarEncrypt(key, plaintext);
  strcpy(plaintext,str_ci);
  printf("Ciphertext: %s",plaintext);//ポインタに受け渡すときはいつも通りで大丈夫。

  /*
    Perform Caesar Decryption: CaesarDecrypt(key, ciphertext) and print out the decryted ciphertext (decrypttext)
  */
 
  str_dec=CaesarDecrypt(key, plaintext);
  strcpy(decrypttext,str_dec);
  printf("Decrypted plaintext: %s",decrypttext);

/***********ここまではProblem-c***************/

/*
  //add for Problem-d at lab1
  //Ciphertextの入力部
  printf("Input ciphertext:");
  fgets(ciphertext,sizeof(ciphertext),stdin);//scanfだとどうやらよくないらしい

  printf("Input key (an integer from 1 to 25):");
  scanf("%d",&key);


  str_ci=CaesarEncrypt(key, plaintext);
  strcpy(plaintext,str_ci);
  printf("Plaintext: %s",plaintext);//ポインタに受け渡すときはいつも通りで大丈夫。

  
//add for Problem1-d at lab1
  str_dec=CaesarDecrypt(key, ciphertext);
  strcpy(decrypttext,str_dec);
  printf("Decrypted plaintext: %s",decrypttext);
*/

 
 return 0;
}


char* CaesarEncrypt(int key, char *plaintext){
int i=0;

while(plaintext[i]!='\n'){
  
  if(plaintext[i]>= 'A' && plaintext[i]<='Z'){
   plaintext[i]=(plaintext[i]-'A'+key)%26+'A';
  }else if(plaintext[i]>= 'a' && plaintext[i]<='z'){
   plaintext[i]=(plaintext[i]-'a'+key)%26+'a';
  }

 i++;
}
  return plaintext;
}

char* CaesarDecrypt(int key, char *ciphertext){
  int i=0;

  while(ciphertext[i]!='\n'){
  
  if(ciphertext[i]>= 'A' && ciphertext[i]<='Z'){
   ciphertext[i]=(ciphertext[i]-'Z'-key)%26+'Z';
  }else if(ciphertext[i]>= 'a' && ciphertext[i]<='z'){
   ciphertext[i]=(ciphertext[i]-'z'-key)%26+'z';
  }
 i++;
}

return ciphertext;
}

/*シーザー暗号*/
