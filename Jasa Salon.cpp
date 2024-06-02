#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){

	//deklarasi variabel

	int pilih[100],Jasa_Pelayanan[100],tgl,thn,faktur;
	string menu[100],bln;
	char nama[50];
	int total_bayar;
	int i=0;
	bool selesai=false;

    cout<<"\t============================";
    cout<<"\n\t*****Program Jasa Salon*****";
    cout<<"\n\t============================";
    cout<<"\n";
    cout<<"Silahkan mengisi data pelayanan\n";
    cout<<"Nama    : ";
    gets(nama);
    cout<<"Tanggal (ex: 05)  : ";cin>>tgl;
    cout<<"Bulan (ex: Juli)  : ";cin>>bln;
    cout<<"Tahun (ex: 2022)  : ";cin>>thn;
    cout<<"Faktur(ex: 00145) : ";cin>>faktur;

    cout<<"\nDaftar Jenis Pelayanan dan Jasa Pelayanan :\n";
    cout<<"1. Smothing             Rp200000\n";
    cout<<"2. Rebonding            Rp250000\n";
    cout<<"3. Bleaching            Rp100000\n";
    cout<<"0. Selesai Memesan              \n";
    cout<<"--------------------------------------------"<<endl;
    cout<<"Tekan 0 jika selesai melakukan pemesanan"<<endl<<endl;

    while(selesai==false){

    	cout<<"Pilih Pelayanan : ";
    	cin>>pilih[i];

    	if (pilih[i]<=3){

    		if (pilih[i]==0){
    			selesai=true;
			}else {
				switch (pilih[i]){
		    		case 1 : menu[i]="Smothing             "; Jasa_Pelayanan[i]=200000; break;
		    		case 2 : menu[i]="Rebonding            "; Jasa_Pelayanan[i]=250000; break;
		    		case 3 : menu[i]="Bleaching            "; Jasa_Pelayanan[i]=100000; break;
                   default : menu[i]="";Jasa_Pelayanan[i]=0;
				}
                cout<<menu[i]<<endl;
		    	cout<<"Tarif obat    Rp 50000"<<endl;

		    	total_bayar+=Jasa_Pelayanan[i]+50000;;
	    		i++;
			}
		} else {
			cout<<"Menu yang dipilih tidak sesuai"<<endl;
			cout<<endl;
		}

	}

	cout<<endl;
	cout<<"\n\n\n_______________________________________________________________________"<<endl;
	cout<<"Nama       : "<<nama<<"                                                       "<<endl;
	cout<<"Tanggal    : "<<tgl<<"/"<<bln<<"/"<<thn<<"                                    "<<endl;
	cout<<"No. Faktur : "<<faktur<<"                                                     "<<endl;
	cout<<"                         TOTAL PESANAN ANDA                                   "<<endl;
	cout<<"------------------------------------------------------------------------      "<<endl;
	cout<<"No	Nama Menu    	  	Jasa Pelayanan		                                 "<<endl;
	cout<<"------------------------------------------------------------------------      "<<endl;
	for (int a=0;a<i;a++){
		  cout<<a+1<<"	"<<menu[a]<<"	    "<<Jasa_Pelayanan[a]<<"             "<<endl;
	}

	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"Biaya Pelayanan :                Rp "<<total_bayar<<"                   "<<endl;
	cout<<"\n\n\n\n";
	cout<<"                 TERIMA KASIH... SELAMAT DATANG KEMBALI                 "<<endl;
    cout<<"________________________________________________________________________"<<endl;

}
