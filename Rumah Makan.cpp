#include <iostream>
#include <string>
using namespace std;

int main(){

	int pilih[3],jumlah[3],sub_total[20],harga[20];
	string menu[50];
	int total_bayar;
	int i=0;
	bool selesai=false;


	cout<<"\t*****Selamat Datang di Rumah Makan Sederhana*****\n";
    cout<<"\nDaftar Menu Makanan dan Minuman :\n";
    cout<<"1. Goreng ikan laut     Rp15000\n";
    cout<<"2. Gulai ikan laut      Rp15000\n";
    cout<<"3. Rendang              Rp15000\n";
    cout<<"4. Ayam Pop             Rp15000\n";
    cout<<"5. Asam Padeh           Rp15000\n";
    cout<<"6. Ayam Goreng          Rp15000\n";
    cout<<"7. Ayam Bakar           Rp20000\n";
    cout<<"8. Dendeng Balado       Rp20000\n";
    cout<<"9. Gulai Tunjang        Rp20000\n";
    cout<<"10. Telur Dadar         Rp20000\n";
    cout<<"11. Sambal Campur       Rp20000\n";
    cout<<"12. Kikil               Rp20000\n";
    cout<<"13. Tauco               Rp20000\n";
    cout<<"14. Semur Jengkol       Rp20000\n";
    cout<<"15. Cumi Saus Tiram     Rp18000\n";
    cout<<"16. Ikan Bakar          Rp18000\n";
    cout<<"17. Ayam Gulai          Rp18000\n";
    cout<<"18. Jengkol Balado      Rp18000\n";
    cout<<"19. Air Mineral         Rp8000\n";
    cout<<"20. Teh                 Rp12000\n";
    cout<<"21. Kopi                Rp10000\n";
    cout<<"22. Jus                 Rp15000\n";
    cout<<"23. Lemon Tea           Rp13000\n";
    cout<<"24. Kopi Susu           Rp13000\n";
    cout<<"25. Jeruk Peras         Rp13000\n";
    cout<<"0.  Selesai Memesan              \n";
    cout<<"--------------------------------------------"<<endl;


	cout<<"Tekan 0 jika selesai melakukan pemesanan"<<endl<<endl;

    while(selesai==false){

    	cout<<"Pilih Menu : ";
    	cin>>pilih[i];

    	if (pilih[i]<=25){

    		if (pilih[i]==0){
    			selesai=true;
			}else {
				switch (pilih[i]){
		    		case 1 : menu[i]="Greng Ikan Laut      "; harga[i]=15000; break;
		    		case 2 : menu[i]="Gulai Ikan Laut      "; harga[i]=15000; break;
		    		case 3 : menu[i]="Rendang              "; harga[i]=15000; break;
		    		case 4 : menu[i]="Ayam Pop             "; harga[i]=15000; break;
		    		case 5 : menu[i]="Asam Padeh           "; harga[i]=15000; break;
		    		case 6 : menu[i]="Ayam Goreng          "; harga[i]=15000; break;
		    		case 7 : menu[i]="Ayam Bakar           "; harga[i]=20000; break;
		    		case 8 : menu[i]="Dendeng Balado       "; harga[i]=20000; break;
		    		case 9 : menu[i]="Gulai Tunjang        "; harga[i]=20000; break;
		    		case 10 : menu[i]="Telur Dadar         "; harga[i]=20000; break;
		    		case 11 : menu[i]="Sambal Campur       "; harga[i]=20000; break;
		    		case 12 : menu[i]="Kikil               "; harga[i]=20000; break;
		    		case 13 : menu[i]="Tauco               "; harga[i]=20000; break;
		    		case 14 : menu[i]="Semur Jengkol       "; harga[i]=20000; break;
		    		case 15 : menu[i]="Cumi Saus Tiram     "; harga[i]=18000; break;
		    		case 16 : menu[i]="Ikan Bakar          "; harga[i]=18000; break;
		    		case 17 : menu[i]="Ayam Gulai          "; harga[i]=18000; break;
		    		case 18 : menu[i]="Jengkol Balado      "; harga[i]=18000; break;
		    		case 19 : menu[i]="Air Mineral         "; harga[i]=8000; break;
		    		case 20 : menu[i]="Teh                 "; harga[i]=12000; break;
		    		case 21 : menu[i]="Kopi                "; harga[i]=10000; break;
		    		case 22 : menu[i]="Jus                 "; harga[i]=15000; break;
		    		case 23 : menu[i]="Lemon Tea           "; harga[i]=13000; break;
		    		case 24 : menu[i]="Kopi Susu           "; harga[i]=13000; break;
		    		case 25 : menu[i]="Jeruk Peras         "; harga[i]=13000; break;



		    		default : menu[i]="";harga[i]=0;
				}
                cout<<menu[i]<<endl;
				cout<<"Jumlah Porsi "<<menu[i]<<" : ";
		    	cin>>jumlah[i];
		    	cout<<endl;

		    	sub_total[i]=jumlah[i]*harga[i];

		    	total_bayar+=sub_total[i];
	    		i++;
			}
		} else {
			cout<<"Menu yang dipilih tidak sesuai"<<endl;
			cout<<endl;
		}

	}

	cout<<endl;
	cout<<"                         TOTAL PESANAN ANDA "<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"No	Nama Menu    	  	Harga		Jumlah        Sub Total "<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	for (int a=0;a<i;a++){
		  cout<<a+1<<"	"<<menu[a]<<"	"<<harga[a]<<"		"<<jumlah[a]<<"		"<<sub_total[a]<<endl;
	}

	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"Total Bayar :                                                Rp "<<total_bayar<<endl;
	cout<<"\n\n\n\n";
	cout<<"                 TERIMA KASIH... SELAMAT DATANG KEMBALI"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;

}
