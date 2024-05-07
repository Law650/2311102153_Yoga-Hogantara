# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

HASH TABLE
Hash table merupakan sebuah struktur data yang digunakan untuk menyimpan dan mengelola elemen data dalam list dengan waktu yang relatif konstan dengan memanipulasi key untuk mengidentifikasi lokasi dalam list. Hash Table sendiri memiliki waktu aksess yang cukup cepat, kapasitas tidak terbatas, dan mudah digunakan. Hash Table menggunakan memory penyimpanan utama berbentuk array dengan tambahan algoritma untuk mempercepat pemrosesan suatu data, namun ketika terdapat dua kunci hash code yang sama maka akan terjadi tabrakan yang dapat memperlambat operasi pada hash table.
![pertemuan5/OUTPUT/hash.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan5/OUTPUT/hash.png)

Operasi Hash Table
1. Insertion
   Memasukan data baru kedalam hash table
2. Deletion
   Menghapus data dari hash table
3. Searching
   Mencari data dari hash table
4. Update
   mempeebarui data dari hash table
5. Traversal
   memproses data melalui seluruh hash table

Collision Resolution
Ada dua teknik untuk menyelesaikan masalah dalam keterbatasan table hash yaitu:
1. Open Hashing (Chaining)
   Metode chaining menghindari korsleting dengan menyimpan semua item data dengan nilai indeks yang sama ke dalam sebuah daftar terkait, di mana setiap node dari daftar terkait berfungsi sebagai representasi dari satu item data. Saat terjadi pencarian atau penambahan item data, pencarian atau penambahan item data dilakukan pada daftar terkait yang sesuai dengan indeks yang telah dihitung dari kunci yang dihash. Jika daftar terkait memiliki banyak node, pencarian atau penambahan item data menjadi lebih lambat karena perlu mencari di seluruh daftar terkait.Karena keterbatasan array dihindari, chaining dapat mengatasi jumlah item data yang sangat besar.

2. Closed Hasing
   Linear probing, quadratic probing, dan double hashing adalah metode closed hashing yang menangani konflik dalam tabel     hash, di mana setiap item yang dikolisi disimpan di dalam tabel hash itu sendiri.
   1. Linear Probing
      Saat Collision, maka akan mencari posisi yang kosong dibawah tempat kejadian, jika masih penuh maka akan terus            mencari kebawah hingga ketemu tempat, namun jika tidak maka hash table penuh.

   2. Quadratic Probing
      mirip dengan linear probing, namun pada lompatan menggunakan increment quadratic(1^2,2^2,3^2....)

   3. Double Hashing
      saat collision, menggunakan fungsi hash kedua.
      
## Guided 

### 1. [Latihan Hash table]

```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Fungsi Hash Sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur Data Untuk Setiap Node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class Hash Table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << " : " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
Kode di atas merupakan implementasi dari struktur data data hash table. Pada program diatas terdapat fungsi hash sederhana yang berfungsi untuk menghasilkan suatu indeks dalam hash table berdasarkan kunci. struktur data untuk setiap node yang berfungsi untuk mempresentasikan elemen pada hash table, yang setiap node memiliki dua variabel data yang menunjuk ke node berikutnya jika terjadi tabrakan atau collision. Pada program tersebut memungkinkan user untuk menginput, mencari, menghapus, menampilkan data 

### 2. [Latihan Hash Table dengan Node]

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ukuran tabel hash
const int TABLE_SIZE = 11;

string name; //deklarasi variabel string name
string phone_number; //deklarasi variabel string phone_number

// Struktur Data Untuk Setiap Node
class HashNode
{
//deklarasi variabel name dan phone_number
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Class HashMap
class HashMap
{
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    // Fungsi Hash Sederhana
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Tambah data
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Hapus data
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Cari data berdasarkan nama
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    // Cetak data
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
        }
    }
};

int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}



```
Kode di atas digunakan untuk menyimpan dan mengelola data menggunakan hash table. Pada program tersebut terdapat struktur data HashNode yang berfungsi untuk menyimpan data berupa nama dan no telp. Class HashMap yang memiliki beberapa metode seperti hashFunc yang berfungsi untuk menghasilkan nilai dari kunci(name), Insert untuk menambahkan data, remove untuk menghapus data, searchByName untuk mencari no telp berdasarkan nama, print untuk mencetak/menampilkan seluruh data. Pada program tersebut user dapat menginput, menghapus, mencari, dan menampilkan data.


## Unguided 

### 1. [Soal Hash Table]
 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa
    memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,
    menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan
    nilai. Dengan ketentuan:
    1. setiap Mahasiswa memiliki NIM dan nilai.
    2. Program memiliki tampilan pilihan menu berisi poin c
    3. implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80-90).
```C++
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 10;

// STRUCT DATA NODE
struct Node {
    string NIM;
    string nama;
    int nilai;
    Node* next;
    Node(string NIM, string nama, int nilai) : NIM(NIM), nama(nama), nilai(nilai), next(nullptr) {}
};

// CLASS HASHTABLE
class HashTable {
private:
    Node** table;

public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // FUNGSI HASH 
    int hash(string NIM) {
        int sum = 0;
        for (char c : NIM) {
            sum += c;
        }
        return sum % MAX_SIZE;
    }

    // INSERT
    void insert(string NIM, string nama, int nilai) {
        int index = hash(NIM);
        Node* newNode = new Node(NIM, nama, nilai);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // MENGHAPUS
    void remove(string NIM) {
        int index = hash(NIM);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->NIM == NIM) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "NIM " << NIM <<" GA ADA\n";
    }

    // SEARCH berdasarkan NIM
    void searchNIM(string NIM) {
        int index = hash(NIM);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->NIM == NIM) {
                cout << "NIM : " << current->NIM << endl; cout << "NAMA: " << current->nama << endl; cout << "Nilai: " << current->nilai << endl;
                return;
            }
            current = current->next;
        }
        cout << "NIM : " << NIM <<" GA ADA" << endl;
    }

    // Searching by range of values (80-90)
    void searchRange() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->nilai >= 80 && current->nilai <= 90) {
                    cout << "NIM: " << current->NIM << ", NAMA: " << current->nama << ", Nilai: " << current->nilai << endl;
                }
                current = current->next;
            }
        }
    }

    // MENAMPILKAN DATA
    void display() {
        cout << "DATA MAHASISWA:\n";
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << "NIM: " << current->NIM << ", NAMA: " << current->nama << ", Nilai: " << current->nilai << endl;
                current = current->next;
            }
        }
    }


};

int main() {
    HashTable hashTable;

    int menu;
    string NIM, nama;
    int nilai;

    do {
        cout << "--====Menu====--\n";
        cout << "1. TAMBAH DATA\n";
        cout << "2. HAPUS DATAA\n";
        cout << "3. CARI NIM\n";
        cout << "4. CARI RENTANG NILAI (80-90)\n";
        cout << "5. MENAMPILKAN SEMUA DATA\n";
        cout << "6. EXIT\n";
        cout << "PILIH : ";
        cin >> menu;
        cout << "--============--\n";

        switch (menu) {
            case 1:
                cout << "INPUT NIM: ";
                cin >> NIM;
                cout << "INPUT NAMA: ";
                cin >> nama;
                cout << "INPUT NILAI: ";
                cin >> nilai;
                hashTable.insert(NIM, nama, nilai);
                break;
            case 2:
                cout << "INPUT NIM : ";
                cin >> NIM;
                hashTable.remove(NIM);
                break;
            case 3:
                cout << "INPUT NIM : ";
                cin >> NIM;
                hashTable.searchNIM(NIM);
                break;
            case 4:
                cout << "DATA NILAI 80-90: ";
                hashTable.searchRange();
                break;
            case 5:
                hashTable.display();
                break;
            case 6:
                cout << "TY.\n";
                break;
            default:
                cout << "MENU GA ADA!!.\n";
        }
    } while (menu != 6);

    return 0;
}
```
#### Output:
![pertemuan5/OUTPUT/1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan5/OUTPUT/1.png)
![pertemuan5/OUTPUT/2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan5/OUTPUT/2.png)


Kode di atas memungkinkan user untuk menginput, menghapus, mencari, dan menampilkan data mahasiswa menggunakan hash table. Pada program diatas terdapat struktur data Node yang berfungsi untuk mempresentasikan elemen pada hash table, setiap node terdapat variabel NIM,nama,nilai, *next. Class HashTable yang memiliki metode insert untuk menginput data, remove untuk menghapus data, searchNIM untuk mencari data berdasar NIM, searchRange untuk mencari data berdasarkan rentang nilai antara 80-90, Display unutk menampilkan seluruh data pada hash table.


## Kesimpulan
Hash table adalah struktur data yang digunakan dalam teknik hashing untuk menyimpan dan mengelola elemen data. Hash table memiliki beberapa keuntungan: mudah digunakan, kapasitas tidak terbatas, dan akses yang cepat. Namun, jika dua kunci hash code berada di lokasi yang sama dalam hash table, dapat terjadi tabrakan, yang dapat memperlambat operasi pada hash table.

Untuk menangani collision terdapat 2 teknk utama:
1. Open Hashing
   Metode chaining menghindari korsleting dengan menyimpan semua item data dengan nilai indeks yang sama ke dalam sebuah daftar terkait, di mana setiap node dari daftar terkait berfungsi sebagai representasi dari satu item data. Saat terjadi pencarian atau penambahan item data, pencarian atau penambahan item data dilakukan pada daftar terkait yang sesuai dengan indeks yang telah dihitung dari kunci yang dihash. Jika daftar terkait memiliki banyak node, pencarian atau penambahan item data menjadi lebih lambat karena perlu mencari di seluruh daftar terkait.Karena keterbatasan array dihindari, chaining dapat mengatasi jumlah item data yang sangat besar.
2. Closed Hashing
   Linear probing, quadratic probing, dan double hashing adalah metode closed hashing yang menangani konflik dalam tabel     hash, di mana setiap item yang dikolisi disimpan di dalam tabel hash itu sendiri.
   1. Linear Probing
      Saat Collision, maka akan mencari posisi yang kosong dibawah tempat kejadian, jika masih penuh maka akan terus            mencari kebawah hingga ketemu tempat, namun jika tidak maka hash table penuh.

   2. Quadratic Probing
      mirip dengan linear probing, namun pada lompatan menggunakan increment quadratic(1^2,2^2,3^2....)

   3. Double Hashing
      saat collision, menggunakan fungsi hash kedua.
      
## Referensi
[1] Ruli Manurung, Ade Azurat, IKI 20100: Struktur Data & Algoritma Hash Table.Fasilkom UI; 2010

[2] Mailund, T. (2019). The joys of hashing: hash table programming with C. Apress.

