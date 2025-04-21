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

// deklarasi fungsi
void registerUser(User users[], int &jumlah_user);
bool loginUser(User users[], int jumlah_user, string &loggedInUser);
void menuPegawai(Pegawai pegawai[], int &jumlah_pegawai);
void tambahPegawai(Pegawai pegawai[], int &jumlah_pegawai);
void tampilkanPegawaiRekursif(Pegawai pegawai[], int index, int jumlah_pegawai);
void updatePegawai(Pegawai pegawai[], int jumlah_pegawai);
void hapusPegawai(Pegawai pegawai[], int &jumlah_pegawai);
void tampilkanPegawai(Pegawai pegawai[], int jumlah_pegawai); // overloading 1
void tampilkanPegawai(Pegawai pegawai[], int jumlah_pegawai, string nama); // overloading 2
void cariDanTampilkanPegawai(Pegawai pegawai[], int jumlah_pegawai); // fungsi lihat detail
void resetDataPegawai(Pegawai *pegawai, int *jumlah_pegawai); 

// program utama
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

        switch (pilihan) {
            case 1:
                registerUser(users, jumlah_user);
                break;
            case 2:
                if (loginUser(users, jumlah_user, loggedInUser)) {
                    menuPegawai(pegawai, jumlah_pegawai);
                }
                break;
            case 3:
                cout << "Program berhenti.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
}

void registerUser(User users[], int &jumlah_user) {
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
}

bool loginUser(User users[], int jumlah_user, string &loggedInUser) {
    string username, nim;
    int attempt = 0;
    while (attempt < 3) {
        cout << "\n=== Login ===\nMasukkan Nama: ";
        getline(cin, username);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        for (int i = 0; i < jumlah_user; i++) {
            if (users[i].username == username && users[i].nim == nim) {
                loggedInUser = username;
                return true;
            }
        }
        cout << "Login gagal!\n";
        attempt++;
    }
    cout << "Anda gagal login 3 kali. Program berhenti.\n";
    exit(0);
}

void menuPegawai(Pegawai pegawai[], int &jumlah_pegawai) {
    int pilihan;
    do {
        cout << "\n=== Menu Manajemen Pegawai ===\n";
        cout << "1. Tambah\n2. Tampilkan\n3. Update\n4. Hapus\n";
        cout << "5. Lihat Detail Pegawai\n6. Reset Data\n7. Logout\nPilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
                tambahPegawai(pegawai, jumlah_pegawai);
                break;
                case 2:
                int subPilihan;
                cout << "\n1. Tampilkan Semua Pegawai\n2. Cari Pegawai Berdasarkan Nama\nPilihan: ";
                cin >> subPilihan;
                cin.ignore();
                if (subPilihan == 1) {
                    tampilkanPegawai(pegawai, jumlah_pegawai); // overloading 1
                } else if (subPilihan == 2) {
                    string namaCari;
                    cout << "Masukkan nama pegawai yang dicari: ";
                    getline(cin, namaCari);
                    tampilkanPegawai(pegawai, jumlah_pegawai, namaCari); // overloading 2
                }
                 else {
                    cout << "Pilihan tidak valid.\n";
                }
                break;            
            case 3:
                updatePegawai(pegawai, jumlah_pegawai);
                break;
            case 4:
                hapusPegawai(pegawai, jumlah_pegawai);
                break;
            case 5:
                cariDanTampilkanPegawai(pegawai, jumlah_pegawai);
                break;
            case 6:
                resetDataPegawai(pegawai, &jumlah_pegawai);
                break;
        }
    } while (pilihan != 7);
}

void tambahPegawai(Pegawai pegawai[], int &jumlah_pegawai) {
    if (jumlah_pegawai < MAX_PEGAWAI) {
        cout << "Nama Pegawai: ";
        getline(cin, pegawai[jumlah_pegawai].nama);
        cout << "Waktu Masuk: ";
        getline(cin, pegawai[jumlah_pegawai].waktu_masuk);
        cout << "Waktu Keluar: ";
        getline(cin, pegawai[jumlah_pegawai].waktu_keluar);
        cout << "Hasil Kerja: ";
        getline(cin, pegawai[jumlah_pegawai].hasil_kerja);
        jumlah_pegawai++;
        cout << "Pegawai ditambahkan.\n";
    } else {
        cout << "Data pegawai penuh!\n";
    }
}

void tampilkanPegawaiRekursif(Pegawai pegawai[], int index, int jumlah_pegawai) {
    if (index == 0) {
        cout << left << setw(5) << "No"
             << setw(20) << "Nama"
             << setw(15) << "Waktu Masuk"
             << setw(15) << "Waktu Keluar"
             << setw(20) << "Hasil Kerja" << endl;
        cout << string(75, '-') << endl;
    }

    if (index >= jumlah_pegawai) return;

    cout << left << setw(5) << index + 1
         << setw(20) << pegawai[index].nama
         << setw(15) << pegawai[index].waktu_masuk
         << setw(15) << pegawai[index].waktu_keluar
         << setw(20) << pegawai[index].hasil_kerja << endl;

    tampilkanPegawaiRekursif(pegawai, index + 1, jumlah_pegawai);
}

void updatePegawai(Pegawai pegawai[], int jumlah_pegawai) {
    if (jumlah_pegawai == 0) {
        cout << "Tidak ada data pegawai.\n";
        return;
    }
    tampilkanPegawai(pegawai, jumlah_pegawai);
    int idx;
    cout << "Masukkan nomor pegawai: ";
    cin >> idx; cin.ignore();
    if (idx > 0 && idx <= jumlah_pegawai) {
        cout << "Nama Baru: "; getline(cin, pegawai[idx - 1].nama);
        cout << "Waktu Masuk Baru: "; getline(cin, pegawai[idx - 1].waktu_masuk);
        cout << "Waktu Keluar Baru: "; getline(cin, pegawai[idx - 1].waktu_keluar);
        cout << "Hasil Kerja Baru: "; getline(cin, pegawai[idx - 1].hasil_kerja);
        cout << "Data diperbarui.\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void hapusPegawai(Pegawai pegawai[], int &jumlah_pegawai) {
    if (jumlah_pegawai == 0) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    tampilkanPegawai(pegawai, jumlah_pegawai);
    int idx;
    cout << "Masukkan nomor pegawai: ";
    cin >> idx; cin.ignore();
    if (idx > 0 && idx <= jumlah_pegawai) {
        for (int i = idx - 1; i < jumlah_pegawai - 1; i++) {
            pegawai[i] = pegawai[i + 1];
        }
        jumlah_pegawai--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

// fungsi overloading
void tampilkanPegawai(Pegawai pegawai[], int jumlah_pegawai) {
    for (int i = 0; i < jumlah_pegawai; i++) {
        cout << i + 1 << ". " << pegawai[i].nama << endl;
    }
}

void tampilkanPegawai(Pegawai pegawai[], int jumlah_pegawai, string nama) {
    bool ditemukan = false;
    cout << "Mencari pegawai bernama: " << nama << endl;
    for (int i = 0; i < jumlah_pegawai; i++) {
        if (pegawai[i].nama == nama) {
            cout << i + 1 << ". " << pegawai[i].nama
                 << ", Masuk: " << pegawai[i].waktu_masuk
                 << ", Keluar: " << pegawai[i].waktu_keluar
                 << ", Hasil: " << pegawai[i].hasil_kerja << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Pegawai dengan nama '" << nama << "' tidak ditemukan.\n";
    }
}

// fungsi lihat detail (overloading ke-2)
void cariDanTampilkanPegawai(Pegawai pegawai[], int jumlah_pegawai) {
    if (jumlah_pegawai == 0) {
        cout << "Tidak ada data pegawai.\n";
        return;
    }
    
    cout << "\n=== Detail Data Pegawai ===\n";
    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "Waktu Masuk"
         << setw(15) << "Waktu Keluar"
         << setw(20) << "Hasil Kerja" << endl;
    cout << string(75, '-') << endl;
    
    for (int i = 0; i < jumlah_pegawai; i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << pegawai[i].nama
             << setw(15) << pegawai[i].waktu_masuk
             << setw(15) << pegawai[i].waktu_keluar
             << setw(20) << pegawai[i].hasil_kerja << endl;
    }
}

// fungsi reset data menggunakan pointer
void resetDataPegawai(Pegawai *pegawai, int *jumlah_pegawai) {
    char konfirmasi;
    cout << "Apakah Anda yakin ingin mereset semua data pegawai? (y/n): ";
    cin >> konfirmasi;
    cin.ignore();
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        *jumlah_pegawai = 0;
        cout << "Seluruh data pegawai berhasil di-reset.\n";
    } else {
        cout << "Reset dibatalkan.\n";
    }
}