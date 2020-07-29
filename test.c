#include<stdio.h>

int main(){
    //printf("hello\n");
    char chara,c[26];
    int i=0;
    for(chara='a';chara<='z';++chara){
        //printf("%c",chara);
        c[i]=chara;
        i++;
    }

    for(i=0;i<=26;i++)
        printf("%c",c[i]);

    printf("\n");
}