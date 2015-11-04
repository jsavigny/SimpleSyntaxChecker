#include "mesinkar.h"
#include "mesinkata1.h"
#include "CYK.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    int i,j,k;
    int countinput;
    int c;
    boolean Valid=false;
    Kata Mulai;
    CNF2Ar();
    Mulai=ArRule[1].LHS;
    for (i=1;i<=NA;i++){ //Menampilkan CNF
        printf("Aturan ke-%d :\n",i);
        printf("LHS : ");
        PrintKata(ArRule[i].LHS);
        printf("\n");
        printf("RHS : ");
        PrintKata(ArRule[i].RHS[1]);
        if (ArRule[i].RHS[2].Length>0){
            PrintKata(ArRule[i].RHS[2]);
        }
        printf("\n");
    }
    Inputan2Ar(&countinput); //Memasukkan Inputan yang ingin dicek dari file eksternal ke Array
    Baris1(countinput); //Mengisi baris pertama matriks CYK
    InitM(countinput); //Menginisialisasi matriks CYK (diatas baris pertama)
    printf("JUMLAH INPUTAN : %d\n",countinput);
    /*for (c=1;c<=countinput;c++){ //Menampilkan inputan
        PrintKata(ArIn[c]);
    }*/
    CYKS(countinput); //Melakukan algoritma CYK thdp matriks
    for (c=1;c<=NA;c++){ //Mengecek apakah mendapatkan S (start)
        if (IsKataSama((M3C[countinput][1][c]),Mulai)){
            Valid=true;
        }
    }
    printf("***** MENAMPILKAN TABEL PARSING CYK (BENTUK NONTERMINAL) *****\n");
    for (i=countinput;i>=1;i--){ //Menampilkan Tabel algoritma CYK (dalam bentuk Nonterminal)
        for (j=1;j<=countinput-i+1;j++){
            PrintKata(M3C[i][j][1]);
        }
        printf("\n");
    }

    printf("\n***** MENAMPILKAN TABEL PARSING CYK (BENTUK KOSONG ATAU ISI) *****\n");
    for (i=countinput;i>=1;i--){ //Menampilkan Tabel algoritma CYK (dalam bentuk kosong atau isi)
        for (j=1;j<=countinput-i+1;j++){
            if (M3C[i][j][1].Length!=0){
                printf("[O]");
            }else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
    printf("\n***** APAKAH VALID? *****\n");
    if (Valid){
        printf("Masukan Valid!\n");
    }else{
        printf("Masukan Tidak Valid!\n");
    }
    printf ( "Press any key to continue . . ." );
    getch();
    return 0;
}
