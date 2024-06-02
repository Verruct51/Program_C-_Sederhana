/*
ALGORITMA Kalkulator Sederhana
1. Mulai
2. Masukkan pilihan, angka1, angka2 dengan tipe data "integer"
3. Masukkan hasil dengan tipe data "float"
4. Hitung operasi bilangan aritmatika dengan rumus yang telah di tentukan
5. Tamppilkan hasil operasi bilangan aritmatika yang telah dipilih pada menu pilihan
6. Selesai
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int pilihan,angka1,angka2;
    float hasil;
    cout<<"\t==============================\n";
    cout<<"\tNama : ALVIN ANUGERAH PRATAMA \n";
    cout<<"\tNIM  : 22343019\n";
    cout<<"\t==============================\n";
    cout<<"\n\n";

    cout<<"Masukkan angka 1 : ";
    cin>> angka1;
    cout<<"Masukkan angka 2 : ";
    cin>> angka2;
    cout<<"\n";

    cout<<"Kalkulator Sederhana \n";
    cout<<"1. Penjumlahan\n";
    cout<<"2. Pengurangan\n";
    cout<<"3. Perkalian\n";
    cout<<"4. Pembagian\n";
    cout<<"5. Modulus\n";
    cout<<"6. Persen\n";
    cout<<"\n";

    cout<<"Masukkan Pilihan Anda : ";
    cin>>pilihan;
    cout<<"\n";


    if (pilihan==1){
        hasil = angka1+angka2;
        cout<<"==================\n";
        cout<<"Hasil operasi    = "<<hasil<<endl;
        cout<<"==================\n";
    }

    else if (pilihan==2){
        hasil = angka1-angka2;
        cout<<"==================\n";
        cout<<"Hasil operasi    = "<<hasil<<endl;
        cout<<"==================\n";
    }

    else if (pilihan==3){
        hasil = angka1*angka2;
        cout<<"==================\n";
        cout<<"Hasil operasi    = "<<hasil<<endl;
        cout<<"==================\n";
    }

    else if (pilihan==4){
        hasil = angka1/angka2;
        cout<<"==================\n";
        cout<<"Hasil operasi    = "<<hasil<<endl;
        cout<<"==================\n";
    }

    else if (pilihan==5){
        hasil = angka1%angka2;
        cout<<"==================\n";
        cout<<"Hasil operasi    = "<<hasil<<endl;
        cout<<"==================\n";
    }

    else if (pilihan==6){
        hasil = angka1*(angka2*0.01);
        cout<<"==================\n";
        cout<<"Hasil operasi    = "<<hasil<<endl;
        cout<<"==================\n";
    }
    else {
        cout<<"Gilo ang yo anjiang pilihan sampai 6 se nyo kontol\n\n";
    }



}
