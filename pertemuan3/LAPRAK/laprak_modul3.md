# <h1 align="center">Laporan Praktikum Modul 3 - Linked List</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

Linked list adalah struktur data yang terdiri dari kumpulan node yang saling terhubung secara sekuensial. Setiap node memiliki dua bagian utama: bagian data yang menyimpan nilai node tersebut, dan bagian pointer yang menunjukkan alamat node berikutnya atau sebelumnya dalam linked list.Linked List dapat digunakan untuk mewakili berbagai struktur data seperti stack dan queue, tetapi karena sifat dinamisnya, ukuran dan strukturnya dapat berubah seiring waktu, berbeda dengan array yang memiliki ukuran tetap.

Double Linked List memiliki struktur data yang mirip dengan Single Linked List, tetapi setiap simpul memiliki pointer tambahan yang menunjuk ke simpul sebelumnya, disebut pointer prev. Dengan adanya pointer prev, Double Linked List memungkinkan operasi seperti menambah dan menghapus simpul mana pun secara efisien.
Dalam Double Linked List, setiap simpul memiliki tiga komponen penting. yaitu  elemen data, pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya.

## Guided 

### 1. [Single Linked list]

```C++
#include <iostream>
using namespace std;

// Program Single Linked List Non-Circular
struct Node {
    int data;
    Node *next;
};

    Node *head;
    Node *tail;

//INISIALISASI NODE
void init() {
    head = NULL;
    tail = NULL;
}

//PENGECEKAN
bool isEmpty() {
    if(head == NULL)
    return true;
    else
    return false;
}

//TAMBAH DEPAN
void insertDepan(int nilai) {
    //BUAT NODE BARU
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty()==true) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

//TAMBAH BELAKANG
void insertBelakang(int nilai) {
    //BUAT NODE BARU
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty()==true) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

//HITUNG JUMLAH LIST
int hitungList() {
    Node *hitung ;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//TAMBAH TENGAH
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu; 
        baru = new Node();
        baru->data = data;
        //TRANSVERSING
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//HAPUS DEPAN
void hapusDepan() {
    Node *hapus;
    if (isEmpty()==false) {
        Node *hapus = head;
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        
        }
    } else {
        cout << "List kosong!" << endl;
    }
}
//HAPUS BELAKANG
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty()==false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}
//HAPUS TENGAH
void hapusTengah(int posisi) {
    Node *hapus,*bantu,*bantu2;
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//UBAH DEPAN
void ubahDepan(int data) {
    if (isEmpty()==false) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}
//UBAH TENGAH
void ubahTengah(int data, int posisi) {
    Node *bantu;
    if (isEmpty()==false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}
//UBAH BELAKANG
void ubahBelakang(int data) {
    if (isEmpty()==false) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}
//HAPUS LIST
void clearList() {
    Node *bantu,*hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//TAMPILKAN LIST
void tampil() {
    Node *bantu;
    bantu = head;
    if (isEmpty()==false) {
        while (bantu != NULL) {
            cout << bantu->data <<ends;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}


```
Kode di atas menggunakan single linked list non circular. program ini dapat melakukan beberapa operasi yang memungkinkan program dapat menambahkan data elemen (didepan, di tengah, di belakang), menghapus elemen (didepan, di tengah, di belakang), mengubah nilai (didepan, di tengah, di belakang).

### 2. [Double linked list]

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}

```
Kode di atas menggunakan Double linked list yang mirip mirip dengan single lingked list namun setiap node pada double linked list memiliki dua node yang menunjukan node sebelum dan berikutnya. Pada program diatas pengguna dapat melakukan operasi yang ada pada menu seperti menambah data(void push), menghapus(void deleteall), memperbarui(bool update, menampilkan data(void display).


## Unguided 

### 1. [Soal mengenai Single Linked List]
 Buatlah program menu Single Linked List Non-Circular untuk
 menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan
 dari user. Lakukan operasi berikut:
 A. Masukkan data sesuai urutan berikut. (Gunakan insert depan,belakang atau tengah). Data pertama yang dimasukkan adalah     nama dan usia anda.
 
 ![pertemuan3/OUTPUT/soalunguided1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/soalunguided1.png)
 
 B. Hapus data Akechi
 C. Tambahkan data berikut diantara John dan Jane : Futaba 18
 D. Tambahkan data berikut diawal : Igor 20
 E. Ubah data Michael menjadi : Reyn 18
 F. Tampilkan seluruh data
 
```C++
#include <iostream>
using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node {
    string nama153;
    int usia153;
    Node* next;
};

// Kelas untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di depan
    void tambahdepan(string nama153, int usia153) {
        Node* newNode = new Node;
        newNode->nama153 = nama153;
        newNode->usia153 = usia153;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang
    void tambahbelakang(string nama153, int usia153) {
        Node* newNode = new Node;
        newNode->nama153 = nama153;
        newNode->usia153 = usia153;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Fungsi untuk menambahkan node di tengah
    void tambahtengah(string nama153, int usia153, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih besar dari 0\n";
            return;
        }
        if (posisi == 1) {
            tambahdepan(nama153, usia153);
            return;
        }
        Node* newNode = new Node;
        newNode->nama153 = nama153;
        newNode->usia153 = usia153;
        Node* current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Posisi terlalu besar\n";
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk mencari node berdasarkan nama
    Node* search(string nama153) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama153 == nama153) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void remove(string nama153) {
        if (head == nullptr) {
            return;
        }
        if (head->nama153 == nama153) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->nama153 == nama153) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan seluruh data
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->nama153 << " " << current->usia153 << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Input data pengguna
    string namagw;
    int umurgw;

    // Input data pengguna sendiri
    cout << "INPUT NAMA LOE: ";
    cin >> namagw;
    cout << "INPUT USIA LOE: ";
    cin >> umurgw;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Masukkan data pengguna ke dalam linked list
    list.tambahdepan(namagw, umurgw);

    // Input data nama dan usia mahasiswa lain dari pengguna
    int jumlahMahasiswa;
    cout << "INPUT JUMLAH MAHASISWA YANG MAU DITAMBAH: ";
    cin >> jumlahMahasiswa;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        string namaMahasiswa;
        int umurMahasiswa;

        cout << "INPUT NAMA MAHASISWA KE-" << i+1 << ": ";
        cin>>namaMahasiswa;
        cout << "INPUT USIA MAHASISWA KE-" << i+1 << ": ";
        cin >> umurMahasiswa;
        cin.ignore(); // Membersihkan newline dari buffer stdin

        list.tambahbelakang(namaMahasiswa, umurMahasiswa);
    }

    // Tampilkan seluruh data
    cout << "Data mahasiswa:" << endl;
    list.display();
    cout << endl;

    // Menu operasi
    while(true){
    int menu;
    cout << "Menu\n";
    cout << "1. DELETE DATA MAHASISWA\n";
    cout << "2. NAMBAH DATA MAHASISWA DI DEPAN\n";
    cout << "3. NAMBAH DATA MAHASISWA DI TENGAH\n";
    cout << "4. NAMBAH DATA MAHASISWA DI BELAKANG\n";
    cout << "5. TAMPIL DATA\n";
    cout << "6. OUT\n";
    cout << "Pilih : ";
    cin >> menu;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Proses operasi sesuai dengan menu yang dipilih
    switch (menu) {
        case 1: {
            string hapusnama;
            cout << "INPUT NAMA MAHASISWA YANG INGIN DI HAPUS: ";
            cin>>hapusnama;
            list.remove(hapusnama);
            break;
        }
        case 2: {
            string namatambahdepan;
            int usiatambahdepan;
            cout << "INPUT NAMA MAHASISWA YANG INGIN DITAMBAH DI DEPAN: ";
            cin>>namatambahdepan;
            cout << "INPUT USIA MAHASISWA YANG INGIN DITAMBAH DI DEPAN: ";
            cin>> usiatambahdepan;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.tambahdepan(namatambahdepan, usiatambahdepan);
            break;
        }
        case 3: {
            string namaTambahTengah;
            int usiaTambahTengah;
            int posisiTambahTengah;
            cout << "INPUT NAMA MAHASISWA YANG INGIN DITAMBAH DI TENGAH: ";
            cin>>namaTambahTengah;
            cout << "INPUT USIA MAHASISWA YANG INGIN DITAMBAH DI TENGAH: ";
            cin >> usiaTambahTengah;
            cout << "INPUT POSISI MAHASISWA YANG INGIN DITAMBAH: ";
            cin >> posisiTambahTengah;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.tambahtengah(namaTambahTengah, usiaTambahTengah, posisiTambahTengah);
            break;
        }
        case 4: {
            string namaTambahBelakang;
            int usiaTambahBelakang;
            cout << "INPUT NAMA MAHASISWA YANG INGIN DITAMBAH DIBELAKANG: ";
            cin>>namaTambahBelakang;
            cout << "INPUT USIA MAHASISWA YANG INGIN DITAMBAH DIBELAKANG: ";
            cin >> usiaTambahBelakang;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.tambahbelakang(namaTambahBelakang, usiaTambahBelakang);
            break;
        }
        case 5: {
            cout << "DATA MAHASISWA:" << endl;
            list.display();
            break;
        }
        case 6 : {
            cout<<"ANDA TELAH KELUAR "<<endl;
            exit(0);
        }
        default:
            cout << "DILUAR NALAR" << endl;
    
    }
    }

    return 0;

}

```
#### Output:
![pertemuan3/OUTPUT/unguided1.1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/unguided1.1.png)
![pertemuan3/OUTPUT/unguided1.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/unguided1.2.png)
![pertemuan3/OUTPUT/unguided1.3.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/unguided1.3.png)
![pertemuan3/OUTPUT/unguided1.4.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/unguided1.4.png)

Kode di atas menggunakan single linked list yang menamilkan menu yang dapat dipilih oleh user. pada awal program dijalankan, user akan dimminta untuk menginputkan nama dan usia yang nantinya akan masuk ke dalam data yang nantinya akan di inputkan, pada program juga dapat menghapus data, menambahkan data di tengah, di depan, di belakang, dan dapat menampikan seluruh data yang sudah diedit atau diubah, ditambahkan dan di hapus. pada Program diatas terdapat fungsi untuk menghapus data dengan menggunakan fungsi remove(string nama153), dan menampilkan data menggunakan fungsi display().

### 2. [Soal mengenai Double Linked List]
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

![pertemuan3/OUTPUT/soalunguided2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/soalunguided2.png)
![pertemuan3/OUTPUT/soalunguided2.1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/soalunguided2.1.png)

 Case:

 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
 2. Hapus produk wardah
 3. Update produk Hanasui menjadi Cleora dengan harga 55.000
 4. Tampilkan menu seperti dibawah ini
 Toko Skincare Purwokerto
     1. Tambah Data
     2. Hapus Data
     3. Update Data
     4. Tambah Data Urutan Tertentu
     5. Hapus Data Urutan Tertentu
     6. Hapus Seluruh Data
     7. Tampilkan Data
     8. Exit
 Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini

 ![pertemuan3/OUTPUT/soalunguided2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/soalunguided2.2.png)

```C++
#include <iostream>

using namespace std;

class node {
public:
    string produk;
    int harga;
    node* prev;
    node* next;
};

class doublelinkedlist {
public:
    node *head;
    node* tail;
    doublelinkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string produk, int harga) {
        node* newNode = new node;
        newNode->harga = harga;
        newNode->produk = produk;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }

        node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int newHarga, string oldProduk, string newProduk) {
        node* current = head;
        while (current != nullptr) {
            if (current->produk == oldProduk) {
                current->produk = newProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void tambahData(int posisi, int harga, string produk) {
        if (posisi < 1) {
            cout << "Posisi harus lebih dari 0" << endl;
            return;
        }

        if (head == nullptr || posisi == 1) {
            push(produk, harga);
            return;
        }

        node* current = head;
        for (int y = 1; y < posisi - 1 && current->next != nullptr; y++) {
            current = current->next;
        }

        node* newNode = new node;
        newNode->harga = harga;
        newNode->produk = produk;
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void hapusData(int posisi) {
        if (posisi < 1) {
            cout << "Posisi harus lebih dari 0" << endl;
            return;
        }

        if (head == nullptr) {
            return;
        }

        if (posisi == 1) {
            node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        node* current = head;
        for (int i = 1; current != nullptr && i < posisi; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi panjang list" << endl;
            return;
        }

        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }

    void deleteAll() {
        node* current = head;
        while (current != nullptr) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        node* current = head;
        while (current != nullptr) {
            cout << current->produk << " " << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    doublelinkedlist list;
    cout << "menu\n";
    list.push("Hanasui", 30000);
    list.push("Wardah", 50000);
    list.push("Skintific", 100000);
    list.push("Somethinc", 150000);
    list.push("Originote", 60000);
    list.display();
    int pilih;
    while (true) {
        cout << "TOKO SKINCARE PURWOKERTO\n";
        cout << "1. TAMBAH DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. UPDATE DATA\n";
        cout << "4. TAMBAH DATA URUTAN TERTENTU\n";
        cout << "5. HAPUS DATA URUTAN TERTENTU\n";
        cout << "6. HAPUS SELURUH DATA\n";
        cout << "7. TAMPILKAN DATA\n";
        cout << "8. exit\n";
        cout << "PILIH : ";
        cin >> pilih;
        switch (pilih) {
            case 1: {
                int harga;
                string produk;
                cout << "INPUT NAMA PRODUK : ";
                cin>>produk;
                cout << "INPUT HARGA : ";
                cin >> harga;
                list.push(produk, harga);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                string oldProduk, newProduk;
                int newHarga;
                cout << "MASUKKAN PRODUK LAMA : ";
                cin>>oldProduk;
                cout << "MASUKKAN PRODUK BARU : ";
                cin>> newProduk;
                cout << "MASUKKAN HARGA PRODUK : ";
                cin >> newHarga;
                list.update(newHarga, oldProduk, newProduk);
                break;
            }
            case 4: {
                int posisi;
                int harga;
                string produk;
                cout << "INPUT NAMA PRODUK : ";
                cin>>produk;
                cout << "INPUT HARGA : ";
                cin >> harga;
                cout << "INPUT POSISI : ";
                cin >> posisi;
                list.tambahData(posisi, harga, produk);
                cout << "DATA BARU DITAMBAHKAN PADA POSISI : " << posisi;
                break;
            }
            case 5: {
                int posisi;
                cout << "POSISI DATA YANG DIHAPUS : ";
                cin >> posisi;
                list.hapusData(posisi);
                cout << "DATA " << posisi << " DIHAPUS\n";
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "MANA ADA CO\n";
                break;
            }
        }
    }
    return 0;
}

```
#### Output:
![pertemuan3/OUTPUT/unguided2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/unguided2.png)
![pertemuan3/OUTPUT/unguided2.1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan3/OUTPUT/unguided2.1.png)

Kode di atas menggunakan Double linked list yang mengharuskan user ming inputkan suatu pilihan menu untuk menambah, menghapus, memperbarui, menampilkan suatu data yang sudah ada. untuk menambahkan suatu data pada program menggunakan fungsi push(),menghapus seluruh data yang sudah ada menggunakan fungsi deleteall(), untuk memperbarui atau mengupdate data menggunakan update(). pada awal, program akan menampilkan data dan menu yang dapat di pilih oleh user dan melakukan sesuai pada menu.

## Kesimpulan
single linked list dan double linked list mempunyai kesamaan yaitu suatu kumpulan node yang saling terhubung, namun double linked list mempunyai tambahan pada bagian pointer yang menunjukan alamat dari alamat sebelumnya dan setelahnya yang memungkinkan dapat menghapus atau menambahkan data dimanapun secara efisien. Linked list sendiri mempunyai batas yang dinamis tidak seperti array namun dengan kapasitas yang semakin memori besar

## Referensi
[1] Mutaz Rasmi Abu sara, Mohammad F.J.Klaib, dan Masud Hasan, Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. telkomuniversity; 2020.

[2] Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY.
