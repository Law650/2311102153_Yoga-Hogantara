# <h1 align="center">Laporan Praktikum Modul 6 - STACK</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

STACK
Stack merupakan struktur data sederhana yang digunakan untuk menyimpan data. Data penting datang dalam urutan tertentu dalam tumpukan. Sebuah tumpukan didefinisikan sebagai daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, yang disebut atas. Elemen pertama yang dihapus adalah yang terakhir yang dimasukkan. Oleh karena itu, daftar Last in First out atau LIFO.

Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada struktur data ini. 
Berikut adalah beberapa operasi umum pada stack:
1. Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling
 atas atau ujung.
2. Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
3. Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa
 menghapusnya.
4. IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.
5. IsFull (Penuh):Memeriksaapakah tumpukanpenuhatau tidak (terutamapada
 implementasitumpukandengankapasitasterbatas).
6. Size(Ukuran):Mengembalikanjumlahelemenyangadadalamtumpukan.
7. Peek (Lihat):Melihat nilai atau elemenpadaposisi tertentudalamtumpukan
 tanpamenghapusnya.
8. Clear (Hapus Semua): Mengosongkan ataumenghapus semua elemen dari
 tumpukan.
9. Search(Cari):Mencarikeberadaanelementertentudalamtumpukan.

Stack dapat di implementasi kan dengan array dan linked list
1. implementasi menggunakan array
   Array merupakan salah satu implementasi stack yang paling sederhana dan memberikan akses acak kepada pengguna berdasarkan indeks. Kelebihan implementasi stack menggunakan array adalah proses implementasinya yang mudah. Namun, array masih kurang fleksibel, dan ukuran array tidak dapat diubah secara dinamis selama proses.
2. implementasi menggunakan linked list
   seperti array. Mereka juga dapat menggunakan metode addEd Front untuk menggantikan operasi push dan fungsi untuk menghapus node depan dari linked list. Kelebihan implementasi stack menggunakan daftar terkait adalah kemampuan untuk bertambah dan berkurang sesuai dengan kebutuhan selama runtime. Namun, kekurangan implementasi stack menggunakan daftar terkait adalah bahwa prosesnya membutuhkan lebih banyak memori karena penggunaan pointer dalam daftar terkait. Untuk menghindari kesalahan saat menggunakan stack, pastikan untuk selalu memeriksa batasan stack, seperti stack penuh atau stack kosong.

## Guided 

### 1. [Linked List Non Circular]

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    destroyArraybuku();

    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}

```
Kode di atas menggunakan struktur data menggunakan stuck dengan prinsip LIFO ( Last In, First Out) yang mana element terakhir yang dimasukkan merupakan petama kali dikeluarkan. Dengan arrayBuku yang berfungsi untuk menyimpan data buku. maksimal merupakan variabel yang menunjukan batas maksimal. top, variabel yang menunjukan posisi teratas. isFull() berfungsi untuk mengecek apakah stack penuh. isEmpty() berfungsi mengecek stack kosong. cetakArrayBuku() berfungsi untuk mencetak atau menampilkan semua data buku yang berada dalam stack


## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya!]

```C++
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string ubahhuruf(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}
// MENENTUKAN PALINDROM
bool palindrom(string str) {
    stack<char> charStack;
    int length = str.length();

    for (int i = 0; i < length / 2; i++) {
        charStack.push(str[i]);
    }

    int start = length / 2;
    if (length % 2 != 0) {
        start++;
    }
    for (int i = start; i < length; i++) {
        if (charStack.empty() || str[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    char ulang;
    do {
        string kalimat;
        cout << "INPUT KATA ATAU KALIMAT : ";
        getline(cin, kalimat);

        string clearinput = ubahhuruf(kalimat);

        if (palindrom(clearinput)) {
            cout << "INPUTAN TERMASUK PALINDROM \n" ;
        } else {
            cout << "INPUTAN TERMASUK BUKAN PALINDROM \n" ;
        }

        cout << "ULANG ?? y/n";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}
```
#### Output:
![pertemuan6/OUTPUT/1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan6/OUTPUT/1.png)


Kode di atas berfungsi untuk mengecek suatu kata atau kalimat apakah masuk kedalam kalimat atau kata palindrom, dengan menggunakan ubahhuruf untuk membersihkan inputan dari non alphabet menjadi huruf kecil. palindrom yang berfungsi untuk membandingkan. user atau pengguna dapat meng inputkan kata atau kalimat yang ingin di cek apakah termasuk kedalam palindrom apa tidak.

### 2. [ Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakanstack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string clearwords(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}
//MEMBALIKAN KALIMAT
string reversewords(string kalimat) {
    stack<char> Karakter;
    string pembalikkalimat;

    kalimat = clearwords(kalimat);

    for (char c : kalimat) {
        if (c != ' ') {
            Karakter.push(c);
        } else {
            while (!Karakter.empty()) {
                pembalikkalimat += Karakter.top();
                Karakter.pop();
            }
            pembalikkalimat += ' ';
        }
    }

    while (!Karakter.empty()) {
       pembalikkalimat += Karakter.top();
        Karakter.pop();
    }

    return pembalikkalimat;
}

int main() {
    string sentence;
    char lanjut;

    do {
        cout << "INPUT MIN 3 KATA : \n";
        getline(cin, sentence);

        int jmlhspasi = count(sentence.begin(), sentence.end(), ' ');
        int jmlhkata = jmlhspasi + 1;

        if (jmlhkata < 3) {
            cout << "MIN 3 KATA WOOY!!!!!!!\n" ;
        } else {
            string pembalikkalimat = reversewords(sentence);
            cout << "KALIMAT TERBALIKK: " << pembalikkalimat << endl; 
        }
        cout << endl;
        cout << "MAU LAGI??????????????????????? (y/n): ";
        cin >> lanjut;
        cin.ignore();
    } 
    while (lanjut == 'y' || lanjut == 'Y');
    cout << "TY CUY\n";

    return 0;
}
```
![pertemuan6/OUTPUT/2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan6/OUTPUT/2.png)

Kode diatas berfungsi untuk membalikan urutan kalimat yang diinputkan oleh user, dengan menggunakan clearwords(string str) yang berfungsi untuk membersihkan string dari karakter selain huruf dan mengubah semua huruf menjadi huruf kecil. hal ini dilakukan dengan menggunakan loop untuk setiap karakter dalam string. reversewords(string kalimat) yang berfungsi untuk membalikan urutan kalimat yang di inputkan oleh user. pada main() user menginputkan sebuah kalimat minimal 3 kalimat sehingga program bisa berjalan.

## Kesimpulan
Prinsip Last In First Out (LIFO), di mana elemen terakhir yang dimasukkan adalah yang pertama kali dikeluarkan, digunakan dalam stack, yang merupakan struktur data sederhana. Stack memiliki banyak operasi umum, seperti Push (menambahkan), Pop (menghapus), Top (melihat elemen teratas), IsEmpty (memeriksa apakah kosong), IsFull (memeriksa apakah penuh), Size (ukuran), Peek (melihat nilai pada posisi tertentu), Clear (menghapus semua elemen), dan Search (mencari elemen tertentu).

Dua metode utama untuk mengimplementasikan Stack adalah array dan daftar terhubung. Metode pertama sederhana dan mudah digunakan, tetapi memungkinkan penambahan dan pengurangan elemen selama runtime, tetapi daftar terhubung membutuhkan lebih banyak memori.

## Referensi
[1] Johnson Sihombing, PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA. telkomuniversity; 2019.

[2] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta: Deepublish, 2021.
