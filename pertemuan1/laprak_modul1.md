# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

Tipe Data merupakan pengklasifikasian berdasar jenis suatu data agar compiler dapat mengetahui sebuah data yang digunakan.
1. Tipe data Primitif
    Tipe data Primitif sendiri merupakan tipe data yang sudah di tentukan oleh sistem. Contoh dari tipe data primitif yaitu:
   -int (menyimpan bilangan bulat)
   -float (menyimpan bilangan desimal)
   -char (menyimpan huruf)
   -boolean (menyimpan nilai boolean yang memiliki dua nilai)
2. Tipe data Abstrak
   Tipe data Abstrak merupakan tipe data yang dientuk oleh programer sendiri. Tipe data abstrak dapat berisi banyak tipe       data, sehingga nilainya dapat lebih dari satu.
3. Tipe data Koleksi
   Tipe data Koleksi merupakan tipe data yang digunkan untuk menyimpan atau mengelompokkan beberapa nilai. Sehingga pada 
   tipe data ini anda dapat menyimpan, mengelola, dan mengaksess sejumlah besar data.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    char op;
    float num1,num2;
    // it allows user to enter operator i.e. +,-,*,/

    cout<< "enter operation(+,-,*,/): ";
    cin>>op;

    //it allows user to enter the operand
    cout<<"enter two operands: ";
     cin >> num1 >> num2; 
 
    // Switch statement begins 
    switch (op) { 
        // If user enters + 
        case '+': 
            cout << "Result: " << num1 + num2; 
            break; 
        // If user enters - 
        case '-': 
            cout << "Result: " << num1 - num2; 
            break; 
        // If user enters * 
        case '*': 
            cout << "Result: " << num1 * num2; 
            break; 
        // If user enters / 
        case '/': 
            if (num2 != 0) { 
                cout << "Result: " << fixed << setprecision(2) << num1 / num2; 
            } else { 
                cout << "Error! Division by zero is not allowed."; 
            } 
            break; 
        // If the operator is other than +, -, * or /, 
        // error message will display 
        default: 
            cout << "Error! Operator is not correct"; 
    } // switch statement ends 
 
    return 0; 
} 


```
Kode di atas digunakan untuk memilih keempat operasi, program diatas menggunakan percabangan switch case sehingga user dapat menginputkan operasi yang dipilih, jika user menginputkan selain yang ada dimenu maka program akan menampilkan "Error! Operator is not correct" dan akan menghentikan program. Program diatas terdapat Tipe data Primitif yaitu char dan float.

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h> 
#include <string.h> 
 
//Struct 
struct Mahasiswa 
{ 
    char name[50]; 
    char address[100]; 
    int age; 
}; 
int main() 
{ 
// menggunakan struct 
    struct Mahasiswa mhs1, mhs2; 
    // mengisi nilai ke struct 
    strcpy(mhs1.name, "Dian"); 
    strcpy(mhs1.address, "Mataram"); 
    mhs1.age = 22; 
    strcpy(mhs2.name, "Bambang"); 
    strcpy(mhs2.address, "Surabaya"); 
    mhs2.age = 23; 
     
    // mencetak isi struct 
    printf("## Mahasiswa 1 ##\n"); 
    printf("Nama: %s\n", mhs1.name); 
    printf("Alamat: %s\n", mhs1.address); 
    printf("Umur: %d\n", mhs1.age); 
    printf ("\n"); 
    printf("## Mahasiswa 2 ##\n"); 
    printf("Nama: %s\n", mhs2.name); 
    printf("Alamat: %s\n", mhs2.address); 
    printf("Umur: %d\n", mhs2.age); 
    return 0; 
}

```
Kode di atas menggunakan struct untuk mengelompokkan data, dengan menggunakan struct pada program dapat menyimpan 2 variabel dengan tipe data yang berbeda. Pada struct diatas menggunakan tipe data char dan int. Struct mahasiswa pada program diatas memiliki 3 nilai,char name[50], char address[50], int age, pada main struct mahasiswa di isi dengan nama.

###3. Tipe Data Koleksi
```C++
#include <iostream> 
#include <array> 
using namespace std; 
 
int main() { 
    // Deklarasi dan inisialisasi array 
    int nilai[5]; 
    nilai[0] = 23; 
    nilai[1] = 50; 
    nilai[2] = 34; 
    nilai[3] = 78; 
    nilai[4] = 90; 
 
    // Mencetak array dengan tab 
    cout << "Isi array pertama  : " << nilai[0] << endl; 
    cout << "Isi array kedua    : " << nilai[1] << endl; 
    cout << "Isi array ketiga   : " << nilai[2] << endl; 
    cout << "Isi array keempat  : " << nilai[3] << endl; 
    cout << "Isi array kelima   : " << nilai[4] << endl; 
 
    return 0; 
}
```
Kode diatas menggunakan array untuk menyimpan nilai-nilai yang diinputkan. Array pada program diatas menampung 5 nilai (23,50,34,78,90) dan dideklarasikan dibawah.


## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
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

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
