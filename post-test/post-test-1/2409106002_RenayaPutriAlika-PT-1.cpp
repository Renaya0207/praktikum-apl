#include <iostream>
#include <limits>
 
using namespace std;

int main() {
    string nama, nim;
    int percobaan = 0;
    const string Nama = "Renaya Putri Alika";
    const string NIM = "2409106002";

    // Sistem Login
    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nama == Nama && nim == NIM) {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login gagal. Coba lagi.\n";
            percobaan++;
        }
    }

    if (percobaan == 3) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    // Menu Konversi
    int pilihan;
    do {
        cout << "\nMenu Konversi Satuan Panjang\n";
        cout << "1. Konversi Meter\n";
        cout << "2. Konversi Centimeter\n";
        cout << "3. Konversi Mile\n";
        cout << "4. Konversi Foot\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        // Validasi input menu
        while (cin.fail() || pilihan < 1 || pilihan > 5) {
            cin.clear(); // Menghapus error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Pilihan tidak valid. Masukkan angka antara 1 dan 5: ";
            cin >> pilihan;
        }

        switch (pilihan) {
            case 1: {
                double meter;
                cout << "Masukkan nilai dalam meter: ";
                cin >> meter;
                // Validasi input angka
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Masukkan angka untuk meter: ";
                    cin >> meter;
                }
                cout << meter << " meter = " << meter * 100 << " cm\n";
                cout << meter << " meter = " << meter * 0.000621371 << " mile\n";
                cout << meter << " meter = " << meter * 3.28084 << " foot\n";
                break;
            }
            case 2: {
                double cm;
                cout << "Masukkan nilai dalam centimeter: ";
                cin >> cm;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Masukkan angka untuk centimeter: ";
                    cin >> cm;
                }
                cout << cm << " cm = " << cm / 100 << " meter\n";
                cout << cm << " cm = " << cm * 0.0000062137 << " mile\n";
                cout << cm << " cm = " << cm * 0.0328084 << " foot\n";
                break;
            }
            case 3: {
                double mile;
                cout << "Masukkan nilai dalam mile: ";
                cin >> mile;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Masukkan angka untuk mile: ";
                    cin >> mile;
                }
                cout << mile << " mile = " << mile * 1609.34 << " meter\n";
                cout << mile << " mile = " << mile * 160934 << " cm\n";
                cout << mile << " mile = " << mile * 5280 << " foot\n";
                break;
            }
            case 4: {
                double foot;
                cout << "Masukkan nilai dalam foot: ";
                cin >> foot;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input tidak valid. Masukkan angka untuk foot: ";
                    cin >> foot;
                }
                cout << foot << " foot = " << foot * 0.3048 << " meter\n";
                cout << foot << " foot = " << foot * 30.48 << " cm\n";
                cout << foot << " foot = " << foot * 0.000189394 << " mile\n";
                break;
            }
            case 5:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}

