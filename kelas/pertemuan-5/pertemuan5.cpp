# include <iostream>
using namespace std;

struct Address{
    string kota;
    string provinsi;
    string negara;
};

int main(){
    // Deklarasi variabel dengan struct
    Address address1, address2;
    // Mengisi value untuk address1
    address1.kota = "Samarinda";
    address1.provinsi = "Kalimantan Timur";
    address1.negara = "Indonesia";

    // mengcopy value dari address1 ke address2
    address2 = address1;

    // mengganti value address1 ke address2
    address2.kota = "ikn";

    // value address1 
    cout<< address1.kota<< endl;
    // value address2
    cout<< address2.kota;
    return 0;
}