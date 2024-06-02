#include <iostream>

using namespace std;

//Struct Karyawan
struct Karyawan {
    int noKaryawan;
    string nama;
    string alamat;
};

// Fungsi untuk menghitung tunjangan berdasarkan lama bekerja
double hitungTunjangan(int gaji, int lamaBekerjaTahun) {
    int tunjangan;

    if (lamaBekerjaTahun <= 5) {
        tunjangan = 0.05 * gaji; // 5% dari gaji
    }
    else if (lamaBekerjaTahun > 5 && lamaBekerjaTahun <= 10) {
        tunjangan = 0.10 * gaji; // 10% dari gaji
    }
    else {
        tunjangan = 0.15 * gaji; // 15% dari gaji
    }

    return tunjangan;
}

int main() {
    int jumlahKaryawan;

    cout << "Masukkan jumlah karyawan: ";
    cin >> jumlahKaryawan;

    struct Karyawan daftarKaryawan[jumlahKaryawan];

    int gaji[jumlahKaryawan];
    int lamaBekerjaTahun[jumlahKaryawan];


    for (int i = 0; i < jumlahKaryawan; i++) {
        cout << "\nMasukkan Data Karyawan " << i + 1 << "\n";

        cout << "No Karyawan         : ";
        cin >> daftarKaryawan[i].noKaryawan;

        cin.ignore();

        cout << "Nama                : ";
        getline(std::cin, daftarKaryawan[i].nama);

        cout << "Alamat              : ";
        getline(std::cin, daftarKaryawan[i].alamat);

        cout << "Gaji (ex: 1000000)  : Rp ";
        cin >> gaji[i];

        cout << "Lama Bekerja (tahun): ";
        cin >> lamaBekerjaTahun[i];
    }

    system("cls");

    cout << "\nDATA SEMUA KARYAWAN";
    for (int i = 0; i < jumlahKaryawan; i++) {
        cout << "\n\n==============================================\n";
        cout << "Data Karyawan " << i + 1 << "\n";
        cout << "No Karyawan              : " << daftarKaryawan[i].noKaryawan << "\n";
        cout << "Nama                     : " << daftarKaryawan[i].nama << "\n";
        cout << "Alamat                   : " << daftarKaryawan[i].alamat << "\n";
        cout << "Gaji                     : Rp " << gaji[i] << "\n";
        cout << "Lama Bekerja             : " << lamaBekerjaTahun[i] << " tahun\n";

        // Menghitung Tunjangan
        int tunjangan = hitungTunjangan(gaji[i], lamaBekerjaTahun[i]);
        cout << "Tunjangan                : Rp " << tunjangan << "\n";

        // Menampilkan Total Gaji
        int totalGaji = gaji[i] + tunjangan;
        cout << "Total Gaji               : Rp " << totalGaji << "\n";

        // Menampilkan Pajak Penghasilan
        if (totalGaji > 8000000) {
            int pajak = 0.05 * totalGaji; // 5% pajak penghasilan
            cout << "Pajak Penghasilan        : Rp " << pajak << "\n";
            int totalGajiSetelahPajak = totalGaji - pajak;
            cout << "==============================================\n";
            cout << "Total Gaji Setelah Pajak : Rp " << totalGajiSetelahPajak << "\n";
            cout << "==============================================\n";
        }
        else {
            int pajak = 0 * totalGaji; // 5% pajak penghasilan
            cout << "Pajak Penghasilan        : Rp 0\n";
            int totalGajiSetelahPajak = totalGaji - pajak;
            cout << "==============================================\n";
            cout << "Total Gaji Setelah Pajak : Rp " << totalGajiSetelahPajak << "\n";
            cout << "==============================================\n";
        }
    }
    return 0;
}
