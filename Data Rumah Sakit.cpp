#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100;

struct Dokter {
    string nama;
    string spesialis;
};

struct Pasien {
    string nama;
    string alamat;
    int umur;
};

struct Penyakit {
    string nama;
};

struct Transaksi {
    string namaPasien;
    string namaPenyakit;
    double biaya;
};

Dokter daftarDokter[MAX_SIZE];
Pasien daftarPasien[MAX_SIZE];
Penyakit daftarPenyakit[MAX_SIZE];
Transaksi daftarTransaksi[MAX_SIZE];

int jumlahDokter = 0;
int jumlahPasien = 0;
int jumlahPenyakit = 0;
int jumlahTransaksi = 0;

void tambahDokter() {
    if (jumlahDokter >= MAX_SIZE) {
        cout << "Maaf, jumlah dokter telah mencapai batas maksimum." << endl;
        return;
    }

    Dokter dokter;
    cout << "Masukkan Nama Dokter         : ";
    getline(cin >> ws, dokter.nama);
    cout << "Masukkan Spesialisasi Dokter : ";
    getline(cin >> ws, dokter.spesialis);
    daftarDokter[jumlahDokter++] = dokter;
    cout << "Data dokter berhasil ditambahkan." << endl;
}

void tambahPasien() {
    if (jumlahPasien >= MAX_SIZE) {
        cout << "Maaf, jumlah pasien telah mencapai batas maksimum." << endl;
        return;
    }

    Pasien pasien;
    cout << "Masukkan Nama Pasien   : ";
    getline(cin >> ws, pasien.nama);
    cout << "Masukkan Alamat Pasien : ";
    getline(cin >> ws, pasien.alamat);
    cout << "Masukkan Umur Pasien   : ";
    cin >> pasien.umur;
    daftarPasien[jumlahPasien++] = pasien;
    cout << "Data pasien berhasil ditambahkan." << endl;
}

void tambahPenyakit() {
    if (jumlahPenyakit >= MAX_SIZE) {
        cout << "Maaf, jumlah penyakit telah mencapai batas maksimum." << endl;
        return;
    }

    Penyakit penyakit;
    cout << "Masukkan Nama Penyakit : ";
    getline(cin >> ws, penyakit.nama);
    daftarPenyakit[jumlahPenyakit++] = penyakit;
    cout << "Data penyakit berhasil ditambahkan." << endl;
}

void tambahTransaksi() {
    if (jumlahTransaksi >= MAX_SIZE) {
        cout << "Maaf, jumlah transaksi telah mencapai batas maksimum." << endl;
        return;
    }

    Transaksi transaksi;
    cout << "Masukkan Nama Pasien   : ";
    getline(cin >> ws, transaksi.namaPasien);
    cout << "Masukkan Nama Penyakit : ";
    getline(cin >> ws, transaksi.namaPenyakit);
    cout << "Masukkan Biaya         : ";
    cin >> transaksi.biaya;
    daftarTransaksi[jumlahTransaksi++] = transaksi;
    cout << "Transaksi berhasil ditambahkan." << endl;
}

void buatLaporanTagihan() {
    string namaPasien;
    cout << "Masukkan Nama Pasien: ";
    getline(cin >> ws, namaPasien);

    double totalBiaya = 0.0;
    cout << "\nLaporan Tagihan Biaya Pasien\n";
    cout << "---------------------------------------------\n";
    cout << "Nama Pasien: " << namaPasien << endl;
    cout << "---------------------------------------------\n";
    cout << "No.  Nama Penyakit         Biaya\n";
    cout << "---------------------------------------------\n";
    int no = 1;
    for (int i = 0; i < jumlahTransaksi; i++) {
        if (daftarTransaksi[i].namaPasien == namaPasien) {
            cout << setw(3) << no << ".  " << setw(20) << left << daftarTransaksi[i].namaPenyakit;
            cout << "Rp " << setw(10) << fixed << setprecision(2) << right << daftarTransaksi[i].biaya << endl;
            totalBiaya += daftarTransaksi[i].biaya;
            no++;
        }
    }
    cout << "---------------------------------------------\n";
    cout << "Total Biaya:             Rp " << setw(10) << fixed << setprecision(2) << right << totalBiaya << endl;
}

void tampilkanRekapitulasi() {
    cout << "\nRekapitulasi Tagihan Biaya Pasien per Hari\n";
    cout << "---------------------------------------------\n";
    cout << "No.  Nama Pasien          Biaya\n";
    cout << "---------------------------------------------\n";
    double totalBiaya = 0.0;
    int no = 1;
    for (int i = 0; i < jumlahPasien; i++) {
        double biayaPasien = 0.0;
        for (int j = 0; j < jumlahTransaksi; j++) {
            if (daftarTransaksi[j].namaPasien == daftarPasien[i].nama) {
                biayaPasien += daftarTransaksi[j].biaya;
            }
        }
        cout << setw(3) << no << ".  " << setw(20) << left << daftarPasien[i].nama;
        cout << "Rp " << setw(10) << fixed << setprecision(2) << right << biayaPasien << endl;
        totalBiaya += biayaPasien;
        no++;
    }
    cout << "---------------------------------------------\n";
    cout << "Total Biaya Hari Ini:    Rp " << setw(10) << fixed << setprecision(2) << right << totalBiaya << endl;
}

void tampilkanDaftarDokter() {
    cout << "\nDaftar Dokter\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < jumlahDokter; i++) {
        cout << "Nama Dokter  : " << daftarDokter[i].nama << endl;
        cout << "Spesialisasi : " << daftarDokter[i].spesialis << endl;
        cout << "---------------------------------------------\n";
    }
}

void tampilkanDaftarPasien() {
    cout << "\nDaftar Pasien\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < jumlahPasien; i++) {
        cout << "Nama Pasien : " << daftarPasien[i].nama << endl;
        cout << "Alamat      : " << daftarPasien[i].alamat << endl;
        cout << "Umur        : " << daftarPasien[i].umur << endl;
        cout << "---------------------------------------------\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "\nProgram Pengelolaan Data Pasien Rumah Sakit\n";
        cout << "-------------------------------------------\n";
        cout << "1. Tambah Data Dokter\n";
        cout << "2. Tambah Data Pasien\n";
        cout << "3. Tambah Data Penyakit\n";
        cout << "4. Tambah Transaksi Tagihan\n";
        cout << "5. Buat Laporan Tagihan Pasien\n";
        cout << "6. Tampilkan Rekapitulasi Tagihan per Hari\n";
        cout << "7. Tampilkan Daftar Dokter\n";
        cout << "8. Tampilkan Daftar Pasien\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahDokter();
                break;
            case 2:
                tambahPasien();
                break;
            case 3:
                tambahPenyakit();
                break;
            case 4:
                tambahTransaksi();
                break;
            case 5:
                buatLaporanTagihan();
                break;
            case 6:
                tampilkanRekapitulasi();
                break;
            case 7:
                tampilkanDaftarDokter();
                break;
            case 8:
                tampilkanDaftarPasien();
                break;
            case 0:
                cout << "Terima kasih. Sampai jumpa!";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
