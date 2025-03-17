// // #include <iostream>
// // #include <string>
// // using namespace std;

// // int main() {
// //     string nama[4] = {"Haqi", "Dzaki", "Melchi"};
// //     int angka[5];
// //     angka[0] = 10;
// //     angka[1] = 19;
// //     angka[2] = 30;
// //     angka[3] = 40;
// //     angka[4] = 50;
// // }

// // array 1 dimensi

// #include <iostream>
// #include <string>

// #define MAX_BUAH 100 // Ukuran maksimum array buah

// using namespace std;

// int main() {
//     int panjang = 0; // Jumlah elemen saat ini
//     string buah[MAX_BUAH]; // Array dengan ukuran tetap
//     int pilihan, index;

//     do {
//         system("clear"); // Untuk Linux/Mac, gunakan system("cls"); jika di Windows
//         cout << "Menu Program" << endl;
//         cout << "1. Tampilkan Buah" << endl;
//         cout << "2. Tambah Buah" << endl;
//         cout << "3. Ubah Buah" << endl;
//         cout << "4. Hapus Buah" << endl;
//         cout << "5. Keluar" << endl;
//         cout << "Pilihan: ";
//         cin >> pilihan;
//         cin.ignore(); // Menghindari masalah buffer input

//         switch (pilihan) {
//             case 1:
//                 // *Menampilkan buah*
//                 if (panjang == 0) {
//                     cout << "Belum ada buah" << endl;
//                 } else {
//                     for (int i = 0; i < panjang; i++) {
//                         cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
//                     }
//                 }
//                 break;

//             case 2:
//                 // *Menambah buah*
//                 if (panjang < MAX_BUAH) {
//                     cout << "Masukkan nama buah: ";
//                     getline(cin, buah[panjang]);
//                     panjang++;
//                     cout << "Buah berhasil ditambahkan" << endl;
//                 } else {
//                     cout << "Kapasitas penuh! Tidak bisa menambah buah lagi." << endl;
//                 }
//                 break;

//             case 3:
//                 // *Mengubah buah*
//                 if (panjang == 0) {
//                     cout << "Belum ada buah untuk diubah." << endl;
//                 } else {
//                     for (int i = 0; i < panjang; i++) {
//                         cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
//                     }
//                     cout << "Masukkan nomor buah yang akan diubah: ";
//                     cin >> index;
//                     cin.ignore(); // Mencegah masalah dengan getline

//                     if (index > 0 && index <= panjang) {
//                         cout << "Masukkan nama buah baru: ";
//                         getline(cin, buah[index - 1]);
//                         cout << "Buah berhasil diubah" << endl;
//                     } else {
//                         cout << "Nomor buah tidak valid" << endl;
//                     }
//                 }
//                 break;

//             case 4:
//                 // *Menghapus buah*
//                 if (panjang == 0) {
//                     cout << "Belum ada buah untuk dihapus." << endl;
//                 } else {
//                     for (int i = 0; i < panjang; i++) {
//                         cout << "Buah ke-" << i + 1 << ": " << buah[i] << endl;
//                     }
//                     cout << "Masukkan nomor buah yang akan dihapus: ";
//                     cin >> index;

//                     if (index > 0 && index <= panjang) {
//                         for (int i = index - 1; i < panjang - 1; i++) {
//                             buah[i] = buah[i + 1]; // Menggeser elemen ke kiri
//                         }
//                         panjang--;
//                         cout << "Buah berhasil dihapus" << endl;
//                     } else {
//                         cout << "Nomor buah tidak valid" << endl;
//                     }
//                 }
//                 break;

//             case 5:
//                 cout << "Program selesai" << endl;
//                 break;

//             default:
//                 cout << "Pilihan tidak valid" << endl;
//                 break;
//         }
//         cout << "\nTekan Enter untuk melanjutkan...";
//         cin.ignore();
//         cin.get();
//     } while (pilihan != 5);

//     return 0;
// }

//array 2 dimensi 
#include <iostream>
using namespace std;
// int main(){
//     int matriks[2][2] = {
//         {1, 2},
//         {3, 4}
//         };
//         cout << matriks[0][0] << endl;

// }
