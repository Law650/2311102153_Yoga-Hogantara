# <h1 align="center">Laporan Praktikum Modul 2 - ARRAY</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

Array merupakan struktur data yang memiliki elemen dengan tipe data yang sama. Array biasa digunakan untuk menyimpan elemen dengan tipe data yang sama dan jumlah atau ukuran yang sudah diketahui.
Array terdiri dari beberapa jenis
1. Array satu Dimensi
   Array satu dimensi merupakan suatu tipe variabel yang terdiri dari satu dimensi dengan tipe yang sama dan disusun dalam    satu baris.
2. Array dua Dimensi
   Array satu dimensi merupakan suatu tipe variabel yang terdiri dari dua dimensi dengan tipe yang sama dan disusun dalam     suatu baris dan kolom.
3. Array Multidimensi
   Array multidimensi merupakan suatu tipe variabel yang memiliki kapasitas memori yang lebih besar. Array multidimensi       memiliki kesamaan dengan array sebelumya namun dengan indeks yang lebih banyak.

## Guided 

### 1. [Program Input Array Tiga Dimensi]

```C++
 #include <iostream>
 
 using namespace std;
 // PROGRAM INPUT ARRAY 3 DIMENSI
 int main()
 {
 
 // Deklarasi array
 int arr[2][3][3];

 // Input elemen
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
 // Output Array
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
 // Tampilan array
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 3; y++){
            for (int z = 0; z < 3; z++){
                cout << arr[x][y][z] <<" "<< ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}




```
Kode di atas menampilkan Array 3 dimensi dengan ukuran 2x3x3 yang nilai nilai nya di inputkan oleh user. program diatas menggunakan nested for yang asing masing memiliki fungsi yang berbeda. Pada nested for yang pertama berfungsi untuk menginputkan nilai kedalam array, nested for kedua berfungsi untuk menampilkan nilai yang sudah diinputkan, nested for ketiga berfungsi untuk menampilkan array dengan tata letak yang rapi

### 2. [ Program Mencari Nilai Maksimal pada Array]

```C++
 #include <iostream>
 using namespace std;
 int main()
 {
 
    int maks, a, i = 1, lokasi;
    //MENGINPUT PANJANG ARRAY
    cout << "Masukkan panjang array: ";
    cin >> a;
    //MENGINPUTKAN ARRAY
    int array[a];
    cout << "Masukkan " << a << " angka\n";
        for (i = 0; i < a; i++){
            cout << "Array ke-" << (i) << ": ";
            cin >> array[i];
        }
    maks = array[0]; //MENCARI NILAI MAX DAN LOKASI
        for (i = 0; i < a; i++){
            if (array[i] > maks){
                 maks = array[i];
                    lokasi = i;
            }
        }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl; //OUTPUT
 }

```
Kode di atas berfungsi untuk mencari nilai maksimum dan lokasi dari nilai maksimum pada array. nilai dan panjang dari array diinputkan oleh user, dengan menggunakan perulangan for untuk menginputkan array dan mencari nilai maksimum pada array yang sudah diinputkan.

## Unguided 

### 1. [ Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

int main()
{
    int bil_153[10];
    
    cout<<"INPUT DATA ARRAY \n";//MENGINPUT ARRAY
    for(int y=1;y<=10;y++){
        cout<<"DATA ARRAY  "<<y<<" : ";
        cin>>bil_153[y];
    }
    cout<<endl;

    cout<<"DATA ARRAY : ";//MENAMPILKAN ARRAY
    for(int y=1;y<=10;y++){
        cout<<bil_153[y]<<" ";
    }
    cout<<endl;
    cout<<"Bilangan Genap : ";//MENCARI BILANGAN GENAP
    for(int y=1;y<=10;y++){
        if(bil_153[y]%2==0){
            cout<<bil_153[y]<<",";
        }
    }
    cout<<endl;

    cout<<"Bilangan Gajil : ";//MENCARI BILANGAN GANJIL
    for(int y=1;y<=10;y++){
        if(bil_153[y]%2!=0){
            cout<<bil_153[y]<<",";
        }
    }

return 0;
}

```
#### Output:
![pertemuan2/OUTPUT/unguided1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan2/OUTPUT/unguided1.png)

Kode di atas berfungsi untuk mencari suatu bilangan ganjil dan genap dari nilai yang diinputkan oleh user dan disimpan didalam array. Dengan menggunakan perulangan for dan pengkondisian if untuk mencari suatu bilangan genap dan ganjil dalam suatu array.

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]
```C++
//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

int main() {
    //VARIABLE MENYINMPAN ARRAY 
    int xu_153, yu_153, zu_153;

    // MENGINPUTKAN ARRAY
    cout << "INPUT UKURAN x : "; 
    cin>>xu_153;
    cout << "INPUT UKURAN y : "; 
    cin>>yu_153;
    cout << "INPUT UKURAN z : "; 
    cin>>zu_153;
   
    //DEKLARASI ARRAY
    int arr[xu_153][yu_153][zu_153];

    // MENGISI DATA ARRAY OLEH USER
    for (int x=0;x<xu_153;x++) {
        for (int y=0;y<yu_153;y++) {
            for (int z=0;z<zu_153;z++) {
                cout << "Input Array["<<x<<"]["<<y<<"]["<<z<<"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //MENAMPILKAN ARRAY BESERTA INDEKS
    for (int x=0;x<xu_153;x++) {
        for (int y=0;y<yu_153;y++) {
            for (int z=0;z<zu_153;z++) {
                cout << "Data Array["<<x<<"]["<<y<<"]["<<z<<"] = "<< arr[x][y][z]<< endl;
            }
        }
    }
    cout << endl;

    //MENAMPILKAN ARRAY 3 D
    for (int x=0;x<xu_153;x++) {
        for (int y=0;y<yu_153;y++) {
            for (int z=0;z<zu_153;z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}


```
#### Output:
![pertemuan2/OUTPUT/unguided2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan2/OUTPUT/unguided2.png)
![pertemuan2/OUTPUT/unguided2,1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan2/OUTPUT/unguided2,1.png)

Kode di atas menampilkan array 3 Dimensi yang diinputkan oleh user dan ditampilkan isi array dan indeksnya. Dengan menggunakan 3 nested loop yang masing masing memiliki fungsi yang berbeda. Nested loop pertama berfungsi untuk menginputkan array oleh user, nested loop kedua untuk menampilkan array beserta indeks, nested loop ketiga untuk menampilkan array.

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata– rata dari suatu array dengan input yang dimasukan oleh user!]
```C++
//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;
 
int main() {
    
    int bil_153=10; 
    int Menu_153[bil_153]={}; 
    int pil_153; 
    //PERULANGAN AGAR PROGRAM BERJALAN SETIDAKNYA 1 KALI
    do{ 
        cout << "-----Menu-----\n"; 
        cout << "1. Input Array\n"; 
        cout << "2. Cari Nilai Minimum\n"; 
        cout << "3. Cari Nilai Maksimum\n"; 
        cout << "4. Hitung Rata-Rata\n"; 
        cout << "5. Exit\n"; 
        cout << "Masukan Pilihan: "; 
        cin>> pil_153; //INPUT MENU

        switch(pil_153){ //MEMILIH MENU
    case 1: 
        cout<<"Input Array \n"; //MENGINPUT ARRAY
        for(int y=0; y<bil_153; y++){ 
            cout<<"Bil "<<y+1<<" : "; 
            cin>>Menu_153[y]; 
        } 
        break; 
    
    case 2:{ 
        int minimum_153=Menu_153[0]; //MENCARI NILAI MINIMUM
        for(int y=1;y<bil_153;y++){ 
            if(Menu_153[y]<minimum_153){ 
                minimum_153=Menu_153[y]; 
            } 
        } 
        cout<<"Nilai Minimum dari bil yang di input = "<<minimum_153<<endl; //OUTPUT MINIMUM
        break; 
    } 
    case 3:{ 
        int max_153=Menu_153[0]; //MENCARI NILAI MAKSIMUM
        for(int y=0;y<bil_153;y++){ 
            if(Menu_153[y]>max_153){ 
                max_153=Menu_153[y]; 
            } 
        } 
       cout<<"Nilai Maksimum dari bil yang di input ="<<max_153<<endl; //OUTPUT MAKSIMUM
       break; 
    } 
    case 4:{ //MENCARI RATA-RATA
        float rata2_153; 
        float total_153=0; 
        for(int y=0;y<bil_153;y++){ 
            total_153=total_153+Menu_153[y]; 
        } 
        rata2_153=(total_153/bil_153); 
        cout<<"rata rata : "<<rata2_153<<endl; //OUTPUT
        break; 
    } 
    case 5:{ 
            cout<<"==============================\n"; 
            cout<<"TY cuy\n"; 
            return 0; 
            break; 
    } 
    default: 
        cout<<"Pilih lagi cuyy\n"; 
        break; 
        } 
    } 
    while(pil_153 !=0);
 
return 0; 
} 


```
#### Output:
![pertemuan2/OUTPUT/unguided3.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan2/OUTPUT/unguided3.png)

Kode diatas akan menampilkan menu yang dapat dipilih oleh user, setiap menu memiliki kegunaan yang berbeda. Dengan menggunakan loop do-while yang memungkinkan program berjalan sesuai yang diinginkan, dan menggunakan percabangan switch agar user dapat memilih menu. Pada switch case 1 untuk menginputkan array oleh user, case 2 untuk mencari nilai minimum yang diinputkan pada array, case 3 untuk mencari nilai maksimum pada array yang diinputkan, case 4 untuk mencari nilai rata-rata, setiap case menggunakan perulangan for.



## Kesimpulan
Array merupakan suatu struktur data yang memungkinkan untuk menyimpan elemen dengan tipe data yang sama dengan jumlah atau ukuran yang telah diketahui. Array berguna dalam membuat matrix.

## Referensi
[1] Pratama, Muhammad A. “STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.” OSF Preprints, 29 Mar. 2020. Web.


