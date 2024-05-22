# <h1 align="center">Laporan Praktikum Modul 8 - ALGORITMA SEARCHING</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

SEARCHING
Searching merupakan suatu proses mengumpulkan informasi dari Kumpulan data yang telah disimpan dengan menggunakan kunci tertentu. 

Terdapat beberapa jenis Searching diantaranya yaitu:

1. Sequential Search
   Metode ini mencari data dengan membandingkan setiap komponen struktur data dengan nilai yang dicari, dimulai dari awal hingga akhir. Jika tidak ada data yang ditemukan, proses pencarian berakhir.
Konsep dasar:
   1. Terdapat sebuah larik yang berisi n buah data ( L[0], L[1], … , L[n-1])
   2. i adalah bilangan indeks terkecil , yang memenuhi kondisi 0 ≤ k ≤ n-1
   3. k adalah data yang dicari L[i]=k
  
2. Binary Search
   Metode ini mengumpulkan data dengan membagi struktur data menjadi dua bagian dan membandingkan nilai yang dicari dengan nilai tengah. Jika nilai yang dicari lebih kecil dari nilai tengah, proses pencarian dilakukan di bagian kiri, dan jika nilainya lebih besar, maka proses pencarian dilakukan di bagian kanan. Sampai data ditemukan atau tidak ditemukan, proses ini berulang.

Kelebihan dan Kekurangan dari Searching

Kelebihan:
   1. meningkatkan efisiensi pencarian data tertentu
   2. memungkinkan penggunaan struktur data yang lebih kompleks dan efisien
   3. dapat digunakan dalam berbagai aplikasi pemrograman.
Kekurangan:
   1. proses pencarian dapat memakan waktu yang lebih lama
   2. dapat menjadi lebih kompleks jika digunakan dalam struktur data yang besar dan kompleks.

## Guided 

### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]

```C++
#include <iostream>

using namespace std;

int main(){
    int n = 10;
    int data[n] = {9,4,1,7,5,12,4,13,4,10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu = true;
            break;
        }
    }

    cout << "Program Sequential Search" << endl;
    cout << "data : {9,4,1,7,5,12,4,13,4,10}" << endl;

    if (ketemu){
        cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
    }else{
        cout << "data tidak ditemukan" << endl;
    }

return 0;
}

```
Kode di atas digunakan untuk mencari keberadaan angka pada data yang sudah ada. Dengan menggunakan metode sequential search yang memungkinkan mencari data dari data array yang sudah ada, angka yang dicari pada program diatas adalah angka 10, sequential search mencari angka 10 dengan menggunakan perulangan for. 

### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.]

```C++
#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void Selection_Sort(){
    int temp, min, i, j;
    for(i = 0; i < 7; i++){
        min = i;
        for(j = i + 1; j < 7; j++){
            if(dataArray[j] < dataArray[min]){
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void BinarySearch(){
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6;
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2;
        if(dataArray[tengah] == cari){
            b_flag = true;
        } else if(dataArray[tengah] < cari){
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag){
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort();

    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    BinarySearch();
    _getche();
return 0;
}

```
Kode di atas merupakan implementasi dari Selection sort dan binary search yang memungkinkan user dapat mencari data yang ingin dicari, dengan menggunakan array untuk menyimpan data, menggunakan fungsi Selection_Sort untuk mengurutkan dataArray, dan menggunakan fungsi BinarySearch() untuk mencari nilai dari dataArray yang sudah diurutkan menggunakan algoritma binary search.


## Unguided 

### 1. [Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1]

```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// BINARYSEARCH PADA STRING YANG DIURUTKAN
bool binarySearch_153(const string &sortedstr, char target) {
    int kiri = 0;
    int kanan = sortedstr.length() - 1;

    while (kiri <= kanan) {
        int center = kiri + (kanan - kiri) / 2;

        if (sortedstr[center] == target) {
            return true;  
        }
        if (sortedstr[center] < target) {
            kiri = center + 1;
        } else {
            kanan = center - 1;
        }
    }

    return false;
}

// MENCARI SEMUA HURUF PADA INDEKS KALIMAT ASLI
vector<int> findIndices_153(const string &originalstr, char target) {
    vector<int> indices;
    for (size_t i = 0; i < originalstr.length(); ++i) {
        if (originalstr[i] == target) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    string input;
    char target;
    char pilih;

    do {
        
        cout << "INPUT KALIMAT: ";
        getline(cin, input);

       
        cout << "INPUT HURUF YANG DICARI: ";
        cin >> target;
        cin.ignore(); 

        // MEMBUAT SALINAN PADA INPUTAN
        string originalinput = input;

        // MENGURUTKAN STRING
        sort(input.begin(), input.end());

        // BINARYSEARCH
        bool ketemu = binarySearch_153(input, target);

        // HASIL PENCARIAN
        if (ketemu) {
            cout << "HURUF '" << target << "' KETEMU DI KALIMAT.\n";

            // MENCARI DAN MEAMPILKAN HURUF
            vector<int> indices = findIndices_153(originalinput, target);
            cout << "HURUF '" << target << "' ADA DI INDEKS : ";
            for (size_t i = 0; i < indices.size(); ++i) {
                cout << indices[i];
                if (i < indices.size() - 1) {
                    cout << ", ";  // JIKA BUKAN INDEKS TERAKHIR MENAMBAHKAN KOMA
                }
            }
            cout << endl;
        } else {
            cout << "HURUF '" << target<< "' GA KETEMU DI KALIMAT.\n";
        }

        // LAGI ATAU ENGGA
        cout << "LAGI ? (y/n): ";
        cin >> pilih;
        cin.ignore(); // MEMBERSIHKAN BUFFER
    } while (pilih == 'y' || pilih == 'Y');

    return 0;
}
```
#### Output:
![pertemuan8/OUTPUT/1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan8/OUTPUT/1.png)

Kode di atas menggunakan binary search untuk emncari huruf dari suatu kalimat yang di inputkan. Dengan menggunakan binarySearch_153 untuk mencari karakter yang dicari, fungsi findIndices_153 untuk mengembalikan vektor yang berisi semua dimana target ditemukan. Program ini berguna untuk mencari keberadaan dan posisi suatu karakter dalam sebuah string dengan menggunakan binary search.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
#include <iostream>
#include <string>
using namespace std;

// MERIKSA HURUF VOKAL ATAU BUKAN
bool vokal(char huruf) {
    // MENGKONVERSI KE HURUF KECIL
    huruf = tolower(huruf);
    // MERIKSA HURUF TERMASUK HURUF VOKAL
    return (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u');
}

// MENGHITUNG BANYAKNYA HURUF VOKAL
int itungvokal(const string &kalimat) {
    int count = 0;
    for (char huruf : kalimat) {
        if (vokal(huruf)) {
            count++;
        }
    }
    return count;
}
int main() {
    string sentence;
    cout << "INPUT KALIMAT: ";
    getline(cin, sentence); // Membaca input kalimat dari pengguna

    int vokal2 = itungvokal(sentence);
    cout << "HURUF VOKAL YANG ADA PADA KALIMAT " << sentence <<" : "<< vokal2 << endl;

    return 0;
}
```
#### Output:
![pertemuan8/OUTPUT/2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan8/OUTPUT/2.png)

Kode di atas digunakan untuk mencari huruf vokal dan jumlah huruf vokal yang di inputkan oleh user. Dengan menggunakan fungsi vokal untuk mengkonversikan ke huruf kecil dan memeriksa apakah karakter termasuk kedalam huruf vokal atau tidak, dan fungsi itungvokal untuk menghitung berapa huruf vokal pada karakter

### 3. [ Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search! ]

```C++
#include <iostream>

using namespace std;

int main(){
    int n = 10;//MAKS JUMLAH DATA
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};//DATA
    int cari = 4;//YANG MAU DICARI
    int ketemu =0;
    int i;
    //ALGORITMA SEQUENTIAL SEARCH
    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu++;

        }
    }

    cout << "SEQUENTIAL SEARCH\n";
    cout << "DATA : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}\n";

    if (ketemu){
        cout << "ANGKA " << cari << " ADA SEBANYAK " << ketemu << endl;
    }else{
        cout << "data tidak ditemukan\n" ;
    }

return 0;
}
```
#### Output:
![pertemuan8/OUTPUT/3.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan8/OUTPUT/3.png)

Kode di atas menggunakan sequential search unutk mencari jumlah angka dalam data array yang sudah ada. Program diatas mencari berapa banyaknya angka 4 yang ada pada data array (9, 4, 1, 4, 7, 10, 5, 4, 12, 4) dengan 10 elemen, dengan menggunakan algoritma Sequential Search untuk mencari nilai dan jumlah angka yang ketemu sehingga menghasilkan angka dan jumlah angka yang dicari.


## Kesimpulan
Searching digunakan untuk menemukan data dalam kumpulan data yang memiliki tipe data sama, yang mempunyai 2 metode pencarian yang umum yaitu:

1. sequential search
    Metode ini mencari data dengan membandingkan setiap komponen struktur data dengan nilai yang dicari, dimulai dari awal hingga akhir. Jika tidak ada data yang ditemukan, proses pencarian berakhir

2. Binary Search
     Metode ini mengumpulkan data dengan membagi struktur data menjadi dua bagian dan membandingkan nilai yang dicari dengan nilai tengah. Jika nilai yang dicari lebih kecil dari nilai tengah, proses pencarian dilakukan di bagian kiri, dan jika nilainya lebih besar, maka proses pencarian dilakukan di bagian kanan. Sampai data ditemukan atau tidak ditemukan, proses ini berulang.

## Referensi
[1] Asisten Praktikum, “Modul 8 SORTING", Learning Management System, 2023.

[2] Meidyan Permata Putri, Guntoro Barovih, Rezania Agramanisti Azdy, Yuniansyah, Andri Saputra, Yesi Sriyeni, Arsia Rini, Fadhila Tangguh Admojo (2022). ALGORITMA DAN STRUKTUR DATA.  Widina Bhakti Persada Bandung.
