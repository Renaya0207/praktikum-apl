#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_USERS = 10;
const int MAX_PEGAWAI = 100;

struct Pegawai {
    string nama;
    string waktu_masuk;
    string waktu_keluar;
    string hasil_kerja;
};

struct User {
    string username;
    string nim;
};

int main() {
    User users[MAX_USERS];
    Pegawai pegawai[MAX_PEGAWAI];
    int jumlah_user = 0, jumlah_pegawai = 0;
    int pilihan;
    string loggedInUser;

    while (true) {
        cout << "\n=== Sistem Manajemen Pegawai ===\n";
        cout << "1. Register\n2. Login\n3. Keluar\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (jumlah_user < MAX_USERS) {
                cout << "\n=== Register Akun ===\nMasukkan Nama: ";
                getline(cin, users[jumlah_user].username);
                cout << "Masukkan NIM: ";
                getline(cin, users[jumlah_user].nim);
                jumlah_user++;
                cout << "Registrasi berhasil! Silakan login.\n";
            } else {
                cout << "Jumlah user maksimal telah tercapai!\n";
            }
        } else if (pilihan == 2) {
            string username, nim;
            int login_attempts = 0;
            while (login_attempts < 3) {
                cout << "\n=== Login ===\nMasukkan Nama: ";
                getline(cin, username);
                cout << "Masukkan NIM: ";
                getline(cin, nim);
                bool found = false;
                for (int i = 0; i < jumlah_user; i++) {
                    if (users[i].username == username && users[i].nim == nim) {
                        loggedInUser = username;
                        found = true;
                        break;
                    }
                }
                if (found) break;
                cout << "Login gagal! Coba lagi.\n";
                login_attempts++;
            }
            if (login_attempts == 3) {
                cout << "Anda telah gagal login sebanyak 3 kali. Program berhenti.\n";
                return 0;
            }
            do {
                cout << "\n=== Menu Manajemen Pegawai ===\n1. Tambah Pegawai\n2. Tampilkan Pegawai\n3. Update Pegawai\n4. Hapus Pegawai\n5. Logout\nPilihan: ";
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    if (jumlah_pegawai < MAX_PEGAWAI) {
                        cout << "Masukkan Nama Pegawai: ";
                        getline(cin, pegawai[jumlah_pegawai].nama);
                        cout << "Masukkan Waktu Kehadiran: ";
                        getline(cin, pegawai[jumlah_pegawai].waktu_masuk);
                        cout << "Masukkan Waktu Keluar: ";
                        getline(cin, pegawai[jumlah_pegawai].waktu_keluar);
                        cout << "Masukkan Hasil Kerja: ";
                        getline(cin, pegawai[jumlah_pegawai].hasil_kerja);
                        jumlah_pegawai++;
                        cout << "Pegawai berhasil ditambahkan.\n";
                    } else {
                        cout << "Data pegawai penuh!\n";
                    }
                } else if (pilihan == 2) {
                    cout << "\nDaftar Pegawai:\n+----+----------------------+----------------+----------------+----------------+\n";
                    cout << "| No | Nama                 | Waktu Masuk    | Waktu Keluar   | Hasil Kerja    |\n";
                    cout << "+----+----------------------+----------------+----------------+----------------+\n";
                    for (int i = 0; i < jumlah_pegawai; i++) {
                        cout << "| " << setw(2) << i + 1 << " | " << setw(20) << pegawai[i].nama
                             << " | " << setw(14) << pegawai[i].waktu_masuk
                             << " | " << setw(14) << pegawai[i].waktu_keluar
                             << " | " << setw(14) << pegawai[i].hasil_kerja << " |\n";
                    }
                    cout << "+----+----------------------+----------------+----------------+----------------+\n";
                } else if (pilihan == 3 || pilihan == 4) {
                    if (jumlah_pegawai == 0) {
                        cout << "Tidak ada pegawai yang dapat diperbarui atau dihapus!\n";
                        continue;
                    }
                    cout << "\nDaftar Pegawai:\n";
                    for (int i = 0; i < jumlah_pegawai; i++) {
                        cout << i + 1 << ". " << pegawai[i].nama << endl;
                    }
                    int index;
                    cout << "Masukkan nomor pegawai: ";
                    cin >> index;
                    cin.ignore();
                    if (index > 0 && index <= jumlah_pegawai) {
                        if (pilihan == 3) {
                            cout << "Masukkan Nama Pegawai: ";
                            getline(cin, pegawai[index - 1].nama);
                            cout << "Masukkan Waktu Kehadiran: ";
                            getline(cin, pegawai[index - 1].waktu_masuk);
                            cout << "Masukkan Waktu Keluar: ";
                            getline(cin, pegawai[index - 1].waktu_keluar);
                            cout << "Masukkan Hasil Kerja: ";
                            getline(cin, pegawai[index - 1].hasil_kerja);
                            cout << "Data pegawai diperbarui.\n";
                        } else {
                            for (int i = index - 1; i < jumlah_pegawai - 1; i++) {
                                pegawai[i] = pegawai[i + 1];
                            }
                            jumlah_pegawai--;
                            cout << "Pegawai berhasil dihapus.\n";
                        }
                    } else {
                        cout << "Nomor pegawai tidak valid!\n";
                    }
                }
            } while (pilihan != 5);
        } else if (pilihan == 3) {
            cout << "Program berhenti.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}