#include <iostream>
#include <string>
using namespace std;

struct Alamat {
    string jalan;
    int nomor;
    string kota;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
    Alamat alamat;
};

#define MAX_MAHASISWA 100
int panjang = 0; // Jumlah elemen saat ini
Mahasiswa mhs[MAX_MAHASISWA]; // Array dengan ukuran tetap

string tampilkanMahasiswa() {
    string output = "";
    if (panjang == 0) {
        output += "Belum ada mahasiswa.\n";
    } else {
        output += "Daftar Mahasiswa\n==================\n";
        for (int i = 0; i < panjang; i++) {
            output += "Mahasiswa ke-" + to_string(i + 1) + "\n";
            output += "Nama: " + mhs[i].nama + "\n";
            output += "Umur: " + to_string(mhs[i].umur) + "\n";
            output += "Jurusan: " + mhs[i].jurusan + "\n";
            output += "Alamat: " + mhs[i].alamat.jalan + " No. " + to_string(mhs[i].alamat.nomor) + ", " + mhs[i].alamat.kota + "\n\n";
        }
    }
    return output;
}

int tambahMahasiswa() {
    if (panjang < MAX_MAHASISWA) {
        cout << "Masukkan nama mahasiswa: ";
        cin.ignore();
        getline(cin, mhs[panjang].nama);
        cout << "Masukkan umur mahasiswa: ";
        cin >> mhs[panjang].umur;
        cin.ignore();
        cout << "Masukkan jurusan mahasiswa: ";
        getline(cin, mhs[panjang].jurusan);
        cout << "Masukkan alamat mahasiswa: " << endl;
        cout << "Jalan: ";
        getline(cin, mhs[panjang].alamat.jalan);
        cout << "Nomor: ";
        cin >> mhs[panjang].alamat.nomor;
        cin.ignore();
        cout << "Kota: ";
        getline(cin, mhs[panjang].alamat.kota);
        panjang++;
        return 1;
    }
    return 0;
}

int ubahMahasiswa() {
    if (panjang == 0) {
        return 0;
    }
    cout << tampilkanMahasiswa();
    int index;
    cout << "Masukkan nomor mahasiswa yang akan diubah: ";
    cin >> index;
    if (index > 0 && index <= panjang) {
        cin.ignore();
        cout << "Masukkan nama mahasiswa baru: ";
        getline(cin, mhs[index - 1].nama);
        return 1;
    }
    return 0;
}

int hapusMahasiswa() {
    if (panjang == 0) {
        return 0;
    }
    cout << tampilkanMahasiswa();
    int index;
    cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
    cin >> index;
    if (index > 0 && index <= panjang) {
        for (int i = index - 1; i < panjang - 1; i++) {
            mhs[i] = mhs[i + 1];
        }
        panjang--;
        return 1;
    }
    return 0;
}

int main() {
    int pilihan;
    do {
        cout << "\nMenu Program" << endl;
        cout << "1. Tampilkan Mahasiswa" << endl;
        cout << "2. Tambah Mahasiswa" << endl;
        cout << "3. Ubah Mahasiswa" << endl;
        cout << "4. Hapus Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << tampilkanMahasiswa();
                break;
            case 2:
                if (tambahMahasiswa()) {
                    cout << "Mahasiswa berhasil ditambahkan." << endl;
                } else {
                    cout << "Kapasitas penuh! Tidak bisa menambah mahasiswa lagi." << endl;
                }
                break;
            case 3:
                if (ubahMahasiswa()) {
                    cout << "Mahasiswa berhasil diubah." << endl;
                } else {
                    cout << "Belum ada mahasiswa untuk diubah." << endl;
                }
                break;
            case 4:
                if (hapusMahasiswa()) {
                    cout << "Mahasiswa berhasil dihapus." << endl;
                } else {
                    cout << "Belum ada mahasiswa untuk dihapus." << endl;
                }
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);
    return 0;
}