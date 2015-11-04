#ifndef CYK_H
#define CYK_H
#include "mesinkata1.h"
#include <string.h>
#include <stdio.h>
#define NA 110 //JUMLAH ATURAN PRODUKSI
typedef struct{ //S->A B ekivalen S A~B; (di .txt)
    Kata LHS; //KIRI (S)
    Kata RHS[3]; //KANAN (A dan B)
} Rule;
Rule ArRule[NA+1]; //ARRAY DARI ATURAN PRODUKSI
typedef Kata ArKata[200];
typedef ArKata MKata[100];
ArKata ArIn; // ARRAY DARI INPUTAN
Kata M3C[200][200][200]; //MATRIKS UTUK PARSING CYK
int MaxLHS; // JUMLAH MAKSIMUM KATA DALAM SUATU SEL DALAM MATRIKS CYK
void CNF2Ar(); //Memindahkan CNF dari txt ke Array
void Inputan2Ar(int *c); //Memindahkan inputan yang akan di cek dari txt ke Array
void Baris1(int c); //Menginisialisasi baris 1 matriks CYK
void PrintKata(Kata K); //Menampilkan Kata
void GetLHS(Rule AR[NA+1], Kata Kanan, ArKata *ArKiri);
/*Mencari LHS dari RHS yang sudah diketahui
Contoh : S -> A B
         C -> A
Maka LHS dari A adalah S dan C */
void Gabung(ArKata K1, ArKata K2, ArKata *KH, int *q);
/*
Mencari LHS yang sama dari dua RHS
*/
void CYKS1(int x, int y);
/*
Melakukan iterasi CYK dalam satu tempat
*/
void CYKS(int c);
/*
Parsing CYK di semua tempat yang mungkin
*/
void InitM(int c);
/*
Menginisialisasi elemen dalam Matriks CYK
*/
int max2(int a,int b);
#endif



