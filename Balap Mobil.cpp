#include<stdio.h>
#include<string.h>

typedef struct peserta{
    int nomor;
    char nama[50];
    float lamaWaktu;
} PESERTA;

const int N=3;

PESERTA pesertaLombaBalapMobil[N];

bool input = false;

void inputPeserta(){
    int no;
    char nama[50];
    float waktu;

    for (int i=0; i<N; i++){
        printf("\n Input pembalap ke-%d", i+1);
        printf("\n\n");

        printf("Masukkan nomor pembalap          : ");
        fflush(stdin); scanf("%d",&no);

        printf("Masukkan nama pembalap           : ");
        fflush(stdin); scanf("%s",&nama);

        printf("Masukan Lama Waktu (Dalam detik) : ");
        fflush(stdin); scanf("%d",&waktu);

        printf("\n========================================\n");
        pesertaLombaBalapMobil[i].nomor = no;
        strcpy(pesertaLombaBalapMobil[i].nama, nama);
        pesertaLombaBalapMobil[i].lamaWaktu = waktu;


    }input = true;
}

void urutan(){
    if (input){
        printf("\nUrutan peserta berdasarkan waktu\n");

        PESERTA Temp;
        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                if (pesertaLombaBalapMobil[i].lamaWaktu > pesertaLombaBalapMobil[j].lamaWaktu){
                    Temp = pesertaLombaBalapMobil[i];
                    pesertaLombaBalapMobil[i] = pesertaLombaBalapMobil[j];
                    pesertaLombaBalapMobil[j] = Temp;
                }
            }
            printf("\n============================");
            printf("\nPeserta nomor     : %d", pesertaLombaBalapMobil[i].nomor);
            printf("\nNama pembalap     : %s", pesertaLombaBalapMobil[i].nama);
            printf("\nLama waktu adalah : %d detik", pesertaLombaBalapMobil[i].lamaWaktu);
            printf("\n");
            printf("\nPembalap mendapat juara : %d", i+1);
            printf("\n============================\n");

        }
    }else{
        printf("Belum ada data yang dimasukkan");
    }
}
void cari(){
    if(input){
        int nomor;
        printf("Masukkan nomor pembalap yang ingi dicari: ");
        scanf("%d",&nomor);

        for (int i=0;i<N;i++){
            if(pesertaLombaBalapMobil[i].nomor==nomor){
                printf("\n====================================");
                printf("\nPembalap nomor            : %d", pesertaLombaBalapMobil[i].nomor);
                printf("\nNama pembalap             : %s", pesertaLombaBalapMobil[i].nama);
                printf("\nWaktu yang ditempuh yaitu : %d detik", pesertaLombaBalapMobil[i].lamaWaktu);
                printf("\n\nPeserta mendapatkan juara ke %d", i+1);
                printf("\n====================================\n");
                break;
            }
        }

    }else{
        printf("\nBelum ada data yang dimasukkan");
    }
}

void exit(){
    printf("\nProgram telah selesai");
}

main(){
    int pilihan;
    printf("Menu");
    printf("\n1. Input data");
    printf("\n2. Tampilkan juara");
    printf("\n3. Cari data berdasarkan nomor pembalap");
    printf("\n4. EXIT");
    printf("\n===================\n");
    printf("Masukkan pilihan anda: ");
    scanf("%d",&pilihan);
    switch(pilihan){
        case 1:
            inputPeserta();
            main();
            break;
        case 2:
            urutan();
            main();
            break;
        case 3:
            cari();
            main();
            break;
        case 4:
            exit();
            break;
        default:
            printf("\nTidak ada pilihan tersebut di menu");
            main();
            break;
    }
    printf("\n-----------------------\n");
}
