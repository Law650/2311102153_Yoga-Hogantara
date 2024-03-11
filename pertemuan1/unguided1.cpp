<<<<<<< HEAD
//unguided1_ tipe data primitif min2 fungsi dan bebas
#include <iostream>

using namespace std;

int angka1,angka2;
int pilih;

//fungsi untuk penjumlahan agar lebih mudah
int jumlah(int y,int h){
    return y + h;
}
//fungsi pengurangan, sama seperti diatas
int kurang(int y,int h){
    return y - h;
}
//fungsi perkalian,sama seperti diatas
int kali(int y, int h){
    return y*h;
}


int main(){

    cout<<"xxx+++---+++xxx\n";
    cout<<"1.PENJUMLAHAN \n";
    cout<<"2.PENGURANGAN \n";
    cout<<"3.PERKALIAN \n";
    cout<<"PILIH : ";
    cin>>pilih;
    cout<<"\n";

    switch(pilih){//untuk memilih pilihan di atas ^
        case 1://jika memilih 1 maka akan meng outpukan penjumlahan
        cout<<"MASUKAN ANGKA 1 : ";
        cin>>angka1;
        cout<<"MASUKAN ANGKA 2 : ";
        cin>>angka2;
        cout<<"HASIL PENJUMLAHAN : "<<jumlah(angka1,angka2);
        break;
        case 2://jika memilih 2 maka akan meng outputkan pengurangan
        cout<<"MASUKAN ANGKA 1 : ";
        cin>>angka1;
        cout<<"MASUKAN ANGKA 2 : ";
        cin>>angka2;
        cout<<"HASIL PENGURANGAN : "<<kurang(angka1,angka2);
        break;
        case 3://jika memilih 3 maka akan meng outputkan perkalian
        cout<<"MASUKAN ANGKA 1 : ";
        cin>>angka1;
        cout<<"MASUKAN ANGKA 2 : ";
        cin>>angka2;
        cout<<"HASIL PERKALIAN : "<<kali(angka1,angka2);
        break;
        default://jika tidak memilih maka akan mengoutpukan "UNKNOWN"
        cout<<"UNKNOWN";
    }

return 0;
}
=======
//unguided1_ tipe data primitif min2 fungsi dan bebas
#include <iostream>

using namespace std;

int angka1,angka2;
int pilih;

//fungsi untuk penjumlahan agar lebih mudah
int jumlah(int y,int h){
    return y + h;
}
//fungsi pengurangan, sama seperti diatas
int kurang(int y,int h){
    return y - h;
}
//fungsi perkalian,sama seperti diatas
int kali(int y, int h){
    return y*h;
}


int main(){

    cout<<"xxx+++---+++xxx\n";
    cout<<"1.PENJUMLAHAN \n";
    cout<<"2.PENGURANGAN \n";
    cout<<"3.PERKALIAN \n";
    cout<<"PILIH : ";
    cin>>pilih;
    cout<<"\n";

    switch(pilih){//untuk memilih pilihan di atas ^
        case 1://jika memilih 1 maka akan meng outpukan penjumlahan
        cout<<"MASUKAN ANGKA 1 : ";
        cin>>angka1;
        cout<<"MASUKAN ANGKA 2 : ";
        cin>>angka2;
        cout<<"HASIL PENJUMLAHAN : "<<jumlah(angka1,angka2);
        break;
        case 2://jika memilih 2 maka akan meng outputkan pengurangan
        cout<<"MASUKAN ANGKA 1 : ";
        cin>>angka1;
        cout<<"MASUKAN ANGKA 2 : ";
        cin>>angka2;
        cout<<"HASIL PENGURANGAN : "<<kurang(angka1,angka2);
        break;
        case 3://jika memilih 3 maka akan meng outputkan perkalian
        cout<<"MASUKAN ANGKA 1 : ";
        cin>>angka1;
        cout<<"MASUKAN ANGKA 2 : ";
        cin>>angka2;
        cout<<"HASIL PERKALIAN : "<<kali(angka1,angka2);
        break;
        default://jika tidak memilih maka akan mengoutpukan "UNKNOWN"
        cout<<"UNKNOWN";
    }

return 0;
}
>>>>>>> 8cdf8a82430e4374359c0ac436634c2dcb89ba83
