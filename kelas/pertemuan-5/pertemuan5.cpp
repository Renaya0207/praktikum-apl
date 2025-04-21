// Pointer adalah sebuah variabel khusus dalam bahasa pemrograman C++ yang digunakan untuk menyimpan alamat memori dari suatu data atau variabel lain.
// & mendapatkan alamat
// * mendapatkan nilai


// passByValue.cpp
# include <iostream>
using namespace std;
// struct Address{
//     string kota;
//     string provinsi;
//     string negara;
// };

int main()
{
    // // deklarasi variabel dengan struct
    // Address address1;
    
    // // mengisi value address1   
    // address1.kota = "Samarinda";
    // address1.provinsi = "Kalimantan Timur";
    // address1.negara = "Indonesia";
    
    // // mengcopy value address1 ke address2
    // address2 = address1;

    // // mengganti property kota dari samarinda ke ikn
    // address2.kota = "ikn";

    // // value address1
    // cout<< address1.kota<<endl;

    // // value address2
    // cout<< address2.kota;

    // Address *address2 = &address1;
    
    // // mengganti property kota dari samarinda ke ikn
    // address2->kota = "ikn";

    // // value address1
    // cout << address1.kota << endl;
    // // value address2
    // cout << address2->kota;


    // cout << "pointer yang menunjuk ke suatu array"<< endl;
    // int a[5] = {1,2,3,4,5};
    // int (*aPtr)[5] = &a;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << *aPtr << endl;
    //     aPtr++;
    // }

    // cout << "Pointer yang menunjuk ";
    // cout << "ke arah elemen array"<<endl;
    // int b[5] = {1,2,3,4,5,};
    // int *bPtr = b;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << *bPtr <<endl;
    //     bPtr++;
    // }


// int ubahNilai(int *a, int b){
//     return *a=b;
// }
    // int a,b;
    // a = 5;
    // b = 20;

    // ubahNilai( &a, b );

    // cout << a;
    // struct Menu {
    //         string nama;
    //         float harga;
    //     };
        
    //     Menu nasgor;
    //     Menu *nasgorPtr = &nasgor;
        
    //     nasgor.nama = "Nasi Goreng Cumi Hitam Pak Kris";
    //     nasgor.harga = 15000;
    //     cout << nasgor.nama << " " << nasgor.harga << endl;
        
    //     // kita bisa mengakses/manipulasi value variabel nasgor melalui variabel nasgorPtr
    //     nasgorPtr->nama = "Nasi Goreng Mawut";
    //     nasgorPtr->harga = 13000;
    //     cout << nasgor.nama << " " << nasgor.harga << endl;
    

return 0;
}