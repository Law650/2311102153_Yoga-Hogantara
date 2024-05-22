# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

Queue merupakan struktur data yang menggunakan metode FIFO, atau First-In First-Out, di mana data pertama yang dimasukkan adalah yang pertama yang dikeluarkan. Queue itu seperti antrian sehari-hari, di mana pelanggan pertama akan dilayani terlebih dahulu. Implementasi queue terdiri dari dua pointer: front/head (elemen pertama) dan rear/back (elemen terakhir). Ini dapat dilakukan dengan array atau list yang terhubung.

Salah satu perbedaan utama antara queue dan stack adalah aturan penambahan dan penghapusan elemen. Pada queue, operasi dilakukan di satu ujung (LIFO—Last-In First-Out), di mana elemen pertama yang dimasukkan akan menjadi elemen pertama yang dikeluarkan; pada stack, operasi dilakukan di satu ujung (FIFO), di mana elemen pertama yang dimasukkan akan menjadi elemen pertama yang dikeluarkan.
Karena perubahan data selalu mengacu pada Head pada Queue, operasi tersebut dilakukan di tempat yang berbeda (melalui salah satu ujung).Pada kasus Queue, prosedur ini sering disebut sebagai Enqueue dan Dequeue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup tambahkan elemen setelah elemen terakhir Queue.

Operasi pada QUEUE
1. enqueue() :menambah data pada queue.
2. dequeue() :mengeluarkan data pada queue.
3. peek() :mengambil data dari queue tanpa menghapus.
4. isEmpty() :mengecek queue kosong atau tidak.
5. isFull() :mengecek apakah penuh.
6. size() :menghitung jumlah elemen pada queue.

## Guided 

### 1. [Queue]

```C++
#include <iostream>

using namespace std;

const int maksimalAntrian = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// menambah antrian
void tambahData(string nama)
{
    if (isFull())
    {
        queueTeller[0] = nama;
        front++;
        back++;
    }
    else
    {
        queueTeller[back] = nama;
        back++;
    }
}

// mengurangi antrian
void kurangAntrian()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

// menghitung banyak antrian
int count()
{
    return back;
}

// menghapus seluruh antrian
void clearQueue()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
            queueTeller[i] = "";
    }
    back = 0;
    front = 0;
}

// melihat antrian
void viewQueue()
{
    cout << "Data antrian: " << endl;
    for (int i = 0; i < maksimalAntrian; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". " << "antrian kosong" << endl;
        }
    }
}

int main()
{
    tambahData("Andi");
    tambahData("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    kurangAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    return 0;
}

```
Kode di atas menggunakan konsep queue yang digunakan untuk mengatur antrian dengan metode FIFO. Dengan menggunakaan tambah Data() untuk menambahkan data elemen pada kedalam queue atau antrean, kurangAntrian() untuk mengurangi elemen dari depan queue atau antrean, count() untuk menghitung jumlah elemen pada queue, clearQueue() untuk mengosongkan data elemen pada queue atau antrean, viewQueue() untuk menampilkan keseluruhan data pada queue atau antrean. Dengan demikian program akan berjalan dengan baik.


## Unguided 

### 1. [ Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

// STRUKTUR UNTUK ELEMENT QUEUE
struct Node {
    string data; 
    Node* next; 
};

// CLASS UNTUK MEMPRESENTASIKAN QUEUE
class Queue {
private:
    Node* front; 
    Node* back; 
    int size; 

public:
    // INISIALISASI QUEUE KOSONG
    Queue() {
        front = nullptr; 
        back = nullptr; 
        size = 0; 
    }

    // MENAMBAH DATA
    void tambah(string nama) {
        Node* newNode = new Node; 
        newNode->data = nama; 
        newNode->next = nullptr; 
        
        
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else { 
            back->next = newNode;
            back = newNode;
        }
        size++; 
    }

    // MENGURANG DATA
    void kurang() {
       
        if (isEmpty()) {
            cout << "queue kosong \n";
        } else {
            Node* temp = front; 
            front = front->next; 
            delete temp; 
            size--; 
        }
    }

    // MENGHINTUNG JUMLAH QUEUE
    int count() {
        return size; 
    }

    // MENGHAPUS SELURUH DATA
    void clearQueue() {
        while (!isEmpty()) { 
            kurang();
        }
    }

    // MENAMPILKAN DATA
    void viewQueue() {
        cout << "ANTRIAN: \n";
        Node* current = front; 
        for (int i = 1; i <= 5; i++) {
            if (current != nullptr) { 
                cout << i << ". " << current->data << endl; 
                current = current->next; 
            } else {
                cout << i << ". ANTRIAN KOSONG \n"; 
            }
        }
    }

    // MEMERIKSA QUEUE KOSONG
    bool isEmpty() {
        return size == 0; 
    }
};


int main() {
    Queue queue_153; 

    // MENAMBAH DATA
    queue_153.tambah("Andi");
    queue_153.tambah("Maya");
    // MENAMPILKAN DATA
    queue_153.viewQueue();
    cout << "JUMLAH = "<<queue_153.count()<<endl;
    // MENGURANGI 1 DATA PADA QUEUE
    queue_153.kurang();
    queue_153.viewQueue();
    cout << "JUMLAH = "<<queue_153.count()<<endl;
    // MENGHAPUS SEMUA DAN MENAMPILKAN DATA
    queue_153.clearQueue();
    queue_153.viewQueue();
    cout << "JUMLAH = "<<queue_153.count()<<endl;

    return 0;
}
```
#### Output:
![pertemuan7/OUTPUT/1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan7/OUTPUT/1.png)

Kode di atas menggunakan struktur data QUEUE dan linked list. Dengan menggunakan struct Node untun mendefinisikan elemen pada queue, tambah() untuk menambah data kedalam queue atau antrean,kurang() untuk mengurangi elemen pertama dalam queue, count() untuk menghitung jumlah queue, clearQueue() untuk menghapus keseluruhan elemen dalam queue sehingga data elemen pada queue akan kosong, viewQueue() untuk menampilkan elemen data dalam queue sehingga akan terlihat data pada queue. dengan menggunakan fungsi tersebut program dapat berjalan dengan baik.

### 2. [ Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]
```C++
//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

// MEMPRESENTASIKAN DATA MAHASISWA
struct Mahasiswa {
    string nama; 
    long long nim; 
};

// STRUKTUR UNTUK ELEMENT QUEUE
struct Node {
    Mahasiswa data; 
    Node* next; 
};

// CLASS UNTUK MEMPRESENTASIKAN QUEUE
class Queue {
private:
    Node* front; 
    Node* back; 
    int size; 

public:
    Queue() {
        front = nullptr; 
        back = nullptr; 
        size = 0; 
    }
    //NAMBAH DATA
    void tambah(string nama, long long nim) {
        Node* newNode = new Node; 
        newNode->data.nama = nama; 
        newNode->data.nim = nim; 
        newNode->next = nullptr; 
        
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else { 
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    // MENGURANGI DATA
    void kurang() {
        
        if (isEmpty()) {
            cout << "KOSONG\n";
        } else { 
            Node* temp = front; 
            front = front->next; 
            delete temp; 
            size--; 
        }
    }

    // MENGHITUNG QUEUE
    int count() {
        return size; 
    }

    //MENGHAPUS SEMUA DATA
    void clearQueue() {
        while (!isEmpty()) {
            kurang();
        }
    }

    // MENAMPILKAN DATA
    void viewQueue() {
        cout << "QUEUE: \n"; 
        Node* current = front; 
        for (int i = 1; i <= 5; i++) { 
            if (current != nullptr) { 
                cout << i << ". " << current->data.nama << " ( " << current->data.nim <<" )"<< endl; 
                current = current->next; 
            } else { 
                cout << i << ". KOSONG\n"; 
            }
        }
    }

    // MEMERIKSA ANTRIAN
    bool isEmpty() {
        return size == 0; 
    }
};

// Fungsi utama program
int main() {
    Queue queue_153;
    int pilihan_153;
    while (true)
    {
        cout << "QUEUE\n";
        cout << "1. TAMBAH ANTRI\n";
        cout << "2. HAPUS ANTRI\n";
        cout << "3. LIAT ANTRI\n";
        cout << "4. CLEAR ANTRIAN\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan_153;

        switch (pilihan_153)
        {
        case 1:
        {
            string nama;
            long long nim;
            cout << "INPUT NAMA: ";
            cin.ignore();
            getline(cin, nama);
            cout << "INPUT NIM: ";
            cin >> nim;
            queue_153.tambah(nama, nim);
            cout << nama << " TELAH TER INPUT\n";
            break;
        }
        case 2:
        {
            queue_153.kurang();
            break;
        }
        case 3:
        {
            queue_153.viewQueue();
            cout << "JUMLAH = " << queue_153.count() << endl;
            break;
        }
        case 4:
        {
            queue_153.clearQueue();
            cout << "Semua antrian telah dilayani";
            break;
        }
        case 5:
        {
            cout << "TY\n";
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak valid\n";
            break;
        }
        }
    }
}

   
```
#### Output:
![pertemuan7/OUTPUT/2.1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan7/OUTPUT/2.1.png)
![pertemuan7/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan7/OUTPUT/2.2.png)

Kode di atas menggunakan struktur data QUEUE dan linked list yang dapat menyimpan data mahasiswa dengan atribut nama dan nim. Dengan menggunakan struct untu mendefinisikan elemen data mahasiswa pada queue dengan nama dan nim, tambah() untuk menambah data mahasiswa kedalam queue atau antrean, kurang() untuk mengurangi elemen data pertama dalam queue, count() untuk menghitung jumlah data pada queue, clearQueue() untuk menghapus keseluruhan elemen dalam queue sehingga data elemen pada queue akan kosong, viewQueue() untuk menampilkan elemen data mahasiswa dalam queue sehingga akan terlihat data mahasiswa pada queue. Program tersebut memungkinkan untuk user dapat manambah, mengurangi, menampilkan, menghapus data yang di inginkan.


## Kesimpulan
Queue adalah struktur data yang menggunakan metode FIFO (First-In First-Out), di mana elemen yang pertama kali dimasukkan akan menjadi elemen pertama yang dikeluarkan, mirip dengan antrian sehari-hari, sehingga queue mengatur elemen berdasarkan urutan masuknya, memberikan prioritas kepada elemen yang lebih dulu dimasukkan untuk dikeluarkan terlebih dahulu, sesuai dengan konsep antrian di kehidupan pada nyata.

## Referensi
[1] Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY.

[2] Carroll, S., & Goponenko, A. (2019). A C++ implementation of a threadsafe priority queue based on multi-dimensional linked lists and MRLock.
