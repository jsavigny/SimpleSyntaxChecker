#ifndef __MESINKATA1_H__
#define __MESINKATA1_H__
#include "mesinkar.h"
#define NMax 50
#define BLANK ' '
typedef struct {
char TabKata[NMax+1];
int Length;
} Kata;
/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;
void IgnoreBlankCNF();
void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC  BLANK atau CC = MARK */
void IgnoreBlankCNF();
void STARTKATACNF();
void STARTKATA();
/* I.S. : CC sembarang
F.S. : EndKata = true, dan CC = Mark;
atau EndKata = false, CKata adalah kata yang sudah
diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya,
mungkin MARK
Proses : Akuisisi kata menggunakan procedure SalinKata */
void ADVCNF();
void SalinKataCNF();
void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
I.S. : CC adalah karakter pertama dari kata
F.S. : CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang
diakuisisi */
void IgnoreComment();//Mengabaikan komentar berbentuk { }
boolean IsKataSama(Kata K1, Kata K2);
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan
urutan karakter yang menyusun kata juga sama */
#endif
