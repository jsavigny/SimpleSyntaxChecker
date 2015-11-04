#include "mesinkata1.h"
boolean EndKata;
Kata CKata;
void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC  BLANK atau CC = MARK */
{ /* Kamus Lokal */
/* Algoritma */
    if (CC=='{') {
        do{
            ADV();
        }while((CC!='}')&&(CC!= MARK ));
    }
    while (((CC == BLANK)||(CC=='\n')||(CC=='\t')||(CC=='}')) && (CC != MARK)) {
        ADV();
        IgnoreComment();
    } /* CC != BLANK or CC = MARK */
}
void IgnoreComment(){
    if (CC=='{') {
        do{
            ADV();
        }while((CC!='}')&&(CC!= MARK ));
    }
}
void IgnoreBlankCNF()
{ /* Kamus Lokal */
/* Algoritma */
    while (((CC == BLANK)||(CC == '~')||(CC==';')||(CC=='\n'))&& (CC != MARK)) {
        ADV();
    } /* CC != BLANK or CC = MARK */
}
void STARTKATA()
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
{ /* Kamus Lokal */
/* Algoritma*/
    START(1);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKata();
    }
}
void STARTKATACNF()
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
{ /* Kamus Lokal */
/* Algoritma*/
    START(0);
    IgnoreBlankCNF();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        EndKata = false;
        SalinKataCNF();
    }
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{   /* Kamus Lokal */
    int i = 1; /* inisialisasi */
    /* Algoritma*/
    for (;;) {
        CKata.TabKata[i] = CC;
        ADV();
        if ((CC == MARK) || (CC == BLANK)|| (CC == '\n')|| (CC == '\t') || (CC=='{')) {
            break;
        } else {
            i++;
        }
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i;
}
void SalinKataCNF()
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
{   /* Kamus Lokal */
    int i = 1; /* inisialisasi */
    /* Algoritma*/
    for (;;) {
        CKata.TabKata[i] = CC;
        ADV();
        if ((CC == MARK)|| (CC=='~') ||(CC==';')|| (CC == BLANK) || (CC=='\n')||(CC=='\t')) {
            break;
        } else {
            i++;
        }
    } /* CC = MARK or CC = BLANK */
    CKata.Length = i;
}
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
{   /* Kamus Lokal */
    /* Algoritma*/
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        SalinKata();
    }
}
void ADVCNF()
{   /* Kamus Lokal */
    /* Algoritma*/
    IgnoreBlankCNF();
    if (CC == MARK) {
        EndKata = true;
    } else /* CC != MARK */ {
        SalinKataCNF();
    }
}

boolean IsKataSama(Kata K1, Kata K2)
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */
{
    int i=1;
    boolean same=true;
    if (K1.Length==K2.Length){
        while ((same==true)&&(i<=K1.Length)){
            if (K1.TabKata[i]!=K2.TabKata[i]){
                same=false;
            }
            i++;
        }
    }
    else {
        same=false;
    }
    return same;
}
