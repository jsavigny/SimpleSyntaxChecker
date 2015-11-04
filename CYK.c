#include "mesinkata1.h"
#include "CYK.h"
#include <string.h>
void InitM(int c){
    int i,j,k;
    for (i=2;i<=c;i++){
        for (j=1;j<=c-i+1;j++){
            for (k=1;k<=c;k++)
                M3C[i][j][k].Length=0;
        }
    }
}
void CNF2Ar(){
    int i;
    STARTKATACNF();
    ArRule[1].LHS=CKata;
    ADVCNF();
    ArRule[1].RHS[1]=CKata;
    while (CC=='~'){
        ADVCNF();
        ArRule[1].RHS[2]=CKata;
    }
    for (i=2;i<=NA;i++){
        ADVCNF();
        ArRule[i].LHS=CKata;
        ADVCNF();
        ArRule[i].RHS[1]=CKata;
        while (CC=='~'){
            ADVCNF();
            ArRule[i].RHS[2]=CKata;
        }
    }
}
void Inputan2Ar(int *c){
    int i=1;
    STARTKATA();
    ArIn[i]=CKata;
    i++;
    while (!EOP){
        ADVKATA();
        ArIn[i]=CKata;
        i++;
    }
    *c=i-1;
}
void Baris1(int c){
    int j;
    int k;
    for (j=1;j<=c;j++){
        GetLHS(ArRule,ArIn[j],&M3C[1][j]);
    }
}
void Gabung(ArKata K1, ArKata K2, ArKata *KH,int *q){
    int i,j,k;
    int l=(*q);
    for (i=1;i<=NA;i++){
        for (j=1;j<=MaxLHS;j++){
            for (k=1;k<=MaxLHS;k++){
                if (((IsKataSama(ArRule[i].RHS[1],K1[j]))&&(IsKataSama(ArRule[i].RHS[2],K2[k])))) {
                    l++;
                    (*KH)[l]=ArRule[i].LHS;
                    MaxLHS=max2(MaxLHS,l);
                }
            }
        }
    }
}
 void CYKS1(int x, int y){
    int a,b,c;
    int i=0;
    ArKata temp;
    for (a=x-1;a>=1;a--){
        b=y+a;
        c=x-a;
        Gabung(M3C[a][y],M3C[c][b],&M3C[x][y],&i);
    }
}
void CYKS(int c){
    int i,j;
    for (i=2;i<=c;i++){
        for (j=1;j<=c-i+1;j++){
            CYKS1(i,j);
        }
    }
}
void GetLHS(Rule AR[NA+1], Kata Kanan, ArKata *ArKiri){
    int i;
    int j=0;
    for (i=1;i<=NA;i++){
        if ((IsKataSama(Kanan,AR[i].RHS[1]))||(IsKataSama(Kanan,AR[i].RHS[2]))){
            j++;
            (*ArKiri)[j]=AR[i].LHS;
        }
    }
    MaxLHS=max2(MaxLHS,j);
}
void PrintKata(Kata K){
    int i;
    if (K.Length>=1){
        for (i=1;i<=K.Length;i++){
                printf("%c",K.TabKata[i]);
        }
        printf(" ");
    }

}
int max2(int a,int b){
    if (a>=b) return a;
    else return b;
}
