
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 26
#define n 1

struct incidence_pair{
  char c[26];                                        // Letter in the cipher text
  double freq[26];                                   // Incidence percentage of each letter
};
  
struct incidence_pair getIncidence(char*);           // Computing a histogram of the incidence each letter (ignoring all non alphabet characters)
char* monoalphabetic_substitution(char*, char*);     // Takes a partial mono-alphabetic substitution (subs)  and a ciphertext and returns a potential plaintext

//add_function
char getkey_s(char, char*);
char getkey_l(char, char*);

int main(int argc, char *argv[]){
  
  char ciphertext[1024] = "ztmn pxtne cfa peqef kecnp cjt tmn zcwsenp ontmjsw tf wsvp xtfwvfefw, c feb fcwvtf, xtfxevqea vf gvoenwk, cfa aeavxcwea wt wse rntrtpvwvtf wscw cgg lef cne xnecwea eymcg.";
  char plaintext[1024] = "";
  char subs[26] = "";


  struct incidence_pair ip = getIncidence(ciphertext);

  if(argc != 2){
    printf("Not enough or too many arguments!\n");
    exit(1);
  }

  strcpy(subs, argv[1]);
  if(strcmp(subs, "") == 0){
    for(int i = 0; i < 26; i++)
      printf("%c:%5f\n", ip.c[i], ip.freq[i]);
  }
  

  strcpy(plaintext, monoalphabetic_substitution(ciphertext, subs));
  printf("Potential Plaintext: %s\n", plaintext);
  return 0;
}


struct incidence_pair getIncidence(char *ciphertext){

  struct incidence_pair data;
  char chara;
  char *alphabet,change_character;
  int i=0;
  double tmp,cnt=0;
  
  //アルファベットの格納
  for(chara='a';chara<='z';++chara){
    data.c[i]=chara;
    i++;
  }

  //代入
  alphabet=data.c;
  
  //アルファベットが何文字含まれているかを調べる
  printf("\n");
  for(int j=0;j<N;j++){
    cnt=0;
    for(int k=0;k<=strlen(ciphertext);k++){
      if((ciphertext[k]>='a' && ciphertext[k]<='z') || (ciphertext[k]>='A' && ciphertext[k]<='Z')){
        if(data.c[j]==ciphertext[k]){//文字が一致したら
          cnt++;
          data.freq[j]=cnt;
          // printf("一致\t%c\n", ciphertext[k]);
        }
      }
      //printf("%c",alphabet[j]);
    }
  }
  //printf("dataのなかみ\n");
  for(int i=0;i<N;i++){
    // printf("%c\t%1.0f\n",data.c[i],data.freq[i]);
    data.freq[i]/=138;//スペースを含まない文字の数
  }

/*降順そーと*/
//数字変える時に文字も一緒に変える。
for (int i=0; i<N; ++i) {
    for (int j=i+1; j<N; ++j) {
      if (data.freq[i] < data.freq[j]) {
        tmp =  data.freq[i];
        change_character = data.c[i];

        data.freq[i] = data.freq[j];
        data.c[i] = data.c[j];

        data.freq[j] = tmp;
        data.c[j] = change_character;
      }
    }
  }
return data;
  
}

//入力した文字を変換できるようにする
char* monoalphabetic_substitution(char *ciphertext, char *subs){
  /*
  ciphertextの文字をsubsで指定した文字を使ってアルファベットの順番を変更したい。
  方法：
  アルファベットとsubsの配列を用意する。それぞれ要素は26個ずつ。
  ciphertextの配列をアルファベットの配列と一文字ずつ比較して、アンダースコアじゃない時にアルファベットを進めて大文字で返す
  */
  char *plaintext = (char *)malloc(strlen(ciphertext));

   for(int i=0;i<=strlen(ciphertext);i++){
    if(ciphertext[i]>='a' && ciphertext[i]<='z'){
      plaintext[i]=getkey_s(ciphertext[i],subs);

    }else if (ciphertext[i]>='A' && ciphertext[i]<='Z'){
      plaintext[i]=getkey_l(ciphertext[i],subs);

    }else{
      plaintext[i]=ciphertext[i];
    }
    //printf("%c ", plaintext[i]);
  }
return plaintext;
}

char getkey_s(char cipher_alpha, char *subs){

  int c=0;
  char search;

  c=(int)(cipher_alpha-'a');
  search=subs[c];

  for(int i=0; i<N; i++){
    if(search>='a' && search <='z' && search!='_'){
      return search;
    }  
  }

  return cipher_alpha;
}

char getkey_l(char cipher_alpha, char *subs){

  int c=0;
  char search;

  c=(int)(cipher_alpha-'A');
  search=subs[c];

  for(int i=0; i<N; i++){
    if(search>='A' && search <='Z' && search!='_'){
      return search;
    }  
  }

  return cipher_alpha;
}
