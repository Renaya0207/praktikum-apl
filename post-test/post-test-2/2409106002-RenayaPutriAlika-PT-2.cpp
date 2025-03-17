#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_PEGAWAI = 100;

int main() {
    string username, nim;
    int login_attempts = 0;
    const string correct_username = "Renaya Putri Alika";
    const string correct_nim = "2409106002";

    while (login_attempts < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, username);
        cout << "Masukkan NIM: ";
        cin >> nim;
        cin.ignore();

        if (username == correct_username && nim == correct_nim) {
            break;
        } else {
            cout << "Login gagal! Coba lagi.\n";
            login_attempts++;
        }
    }

    if (login_attempts == 3) {
        cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    string nama[MAX_PEGAWAI];
    string waktu_masuk[MAX_PEGAWAI];
    string waktu_keluar[MAX_PEGAWAI];
    string hasil_kerja[MAX_PEGAWAI];
    int jumlah_pegawai = 0;
    int pilihan;

    do {
        cout << "\n=== Menu Manajemen Pegawai ===" << endl;
        cout << "1. Tambah Pegawai" << endl;
        cout << "2. Tampilkan Pegawai" << endl;
        cout << "3. Update Pegawai" << endl;
        cout << "4. Hapus Pegawai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlah_pegawai < MAX_PEGAWAI) {
                    cout << "Masukkan Nama Pegawai: ";
                    getline(cin, nama[jumlah_pegawai]);
                    cout << "Masukkan Waktu Kehadiran: ";
                    getline(cin, waktu_masuk[jumlah_pegawai]);
                    waktu_keluar[jumlah_pegawai] = "-";
                    hasil_kerja[jumlah_pegawai] = "-";
                    jumlah_pegawai++;
                } else {
                    cout << "Data penuh!" << endl;
                }
                break;
            case 2:
                cout << "\nDaftar Pegawai:\n";
                cout << "+----+----------------------+----------------+----------------+----------------+" << endl;
                cout << "| No | Nama                 | Waktu Masuk    | Waktu Keluar   | Hasil Kerja    |" << endl;
                cout << "+----+----------------------+----------------+----------------+----------------+" << endl;
                for (int i = 0; i < jumlah_pegawai; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(20) << nama[i] 
                         << " | " << setw(14) << waktu_masuk[i] 
                         << " | " << setw(14) << waktu_keluar[i] 
                         << " | " << setw(14) << hasil_kerja[i] << " |" << endl;
                }
                cout << "+----+----------------------+----------------+----------------+----------------+\n";
                break;
            case 3:
                int index_update;
                cout << "Masukkan nomor pegawai yang ingin diperbarui: ";
                cin >> index_update;
                cin.ignore();
                if (index_update > 0 && index_update <= jumlah_pegawai) {
                    cout << "Masukkan Waktu Keluar: ";
                    getline(cin, waktu_keluar[index_update - 1]);
                    cout << "Masukkan Hasil Kerja: ";
                    getline(cin, hasil_kerja[index_update - 1]);
                } else {
                    cout << "Nomor pegawai tidak valid!" << endl;
                }
                break;
            case 4:
                int index_hapus;
                cout << "Masukkan nomor pegawai yang ingin dihapus: ";
                cin >> index_hapus;
                cin.ignore();
                if (index_hapus > 0 && index_hapus <= jumlah_pegawai) {
                    for (int i = index_hapus - 1; i < jumlah_pegawai - 1; i++) {
                        nama[i] = nama[i + 1];
                        waktu_masuk[i] = waktu_masuk[i + 1];
                        waktu_keluar[i] = waktu_keluar[i + 1];
                        hasil_kerja[i] = hasil_kerja[i + 1];
                    }
                    jumlah_pegawai--;
                    cout << "Pegawai berhasil dihapus." << endl;
                } else {
                    cout << "Nomor pegawai tidak valid!" << endl;
                }
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}