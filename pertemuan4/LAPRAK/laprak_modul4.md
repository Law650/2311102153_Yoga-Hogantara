# <h1 align="center">Laporan Praktikum Modul 4 - Single Linked List Circular dan Non Circular</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

Linked list merupakan Struktur data yang dikenal sebagai daftar terkait adalah kumpulan elemen data di mana tiap elemen (node) saling berhubungan atau dihubungkan dengan elemen lain melalui pointer. Alamat elemen data yang tersimpan di mermori dikenal sebagai pointer.
Semua pointer terdiri dari head dan tail. Pointer head berfungsi sebagai awal akses ke seluruh data dalam daftar terhubung, dan pointer tail berfungsi sebagai penanda akhir urutan pointer. Jika daftar terhubung memiliki elemen kosong, pointer head akan menunjuk ke NULL, dan begitu juga pointer berikutnya dari tail.

Linked list tidak perlu menyimpan memori secara berurutan atau berdekatan. Mereka juga memiliki ukuran elemen yang dapat berubah secara dinamis dan mudah untuk menyisipkan dan menghapus elemen.

1. Linked List Non-Circular
   Linked list non-circular adalah struktur data dinamis di mana setiap elemen atau node terhubung ke node berikutnya     dalam satu arah. Perbedaan utama dari linked list circular adalah bahwa node terakhir (tail) tidak terhubung kembali ke    head. Dengan demikian, linked list non-circular memungkinkan penambahan dan penghapusan elemen secara dinamis tanpa perlu menghubungkan kembali tail ke head. Penanda NULL pada ujung menunjukan bahwa elemen tidak dapat ditambahkan atau dihapus.
   
2. Linked List Circular
   Linked list circular membutuhkan dummy node atau node tambahan untuk digunakan. Linked list circular tidak memiliki akhir karena node terakhir (tail) terhubung dengan node pertama (head) dan tidak bernilai "NULL". pengecoh, yang biasanya disebut sebagai node saat ini, supaya program dapat berhenti menghitung data ketika node saat ini mencapai node pertama (kepala). Daftar lingkaran terkait dapat digunakan untuk menyimpan informasi yang perlu diakses secara berulang, seperti daftar pesan dalam antrian, daftar putar lagu, atau penggunaan memori berulang dalam aplikasi.

## Guided 

### 1. [Linked List Non Circular]

```C++
#include <iostream>

using namespace std;

// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi struct node
struct Node
{
    int data;
    Node *next;
};

Node *head; // Deklarasi head
Node *tail; // Deklarasi tail

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekkan apakah linked list kosong
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    // Tambah depan
    void insertDepan(int nilai)
    {

        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            baru->next = head;
            head = baru;
        }
    }

    // Tambah belakang
    void insertBelakang(int nilai)
    {
        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }

    // Hitung jumlah list
    int hitungList()
    {
        Node *hitung;
        hitung = head;
        int jumlah = 0;
        while (hitung != NULL)
        {
            jumlah++;
            hitung = hitung->next;
        }
        return jumlah;
    }

    // Tambah tengah
    void insertTengah(int data, int posisi)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *baru, *bantu;
            baru = new Node();
            baru->data = data;

            // tranversing
            bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }

    // Hapus depan
    void hapusDepan()
    {
        Node *hapus;
        if (isEmpty() == false)
        {
            if (head->next != NULL)
            {
                hapus = head;
                head = head->next;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus belakang
    void hapusBelakang()
    {
        Node *hapus;
        Node *bantu;
        if (isEmpty() == false)
        {
            if (head != tail)
            {
                hapus = tail;
                bantu = head;
                while (bantu->next != tail)
                {
                    bantu = bantu->next;
                }
                tail = bantu;
                tail->next = NULL;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }
    // Hapus tengah
    void hapusTengah(int posisi)
    {
        Node *hapus, *bantu, *sebelum;
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            int nomor = 1;
            bantu = head;
            while (nomor <= posisi)
            {
                if (nomor == posisi - 1)
                {
                    sebelum = bantu;
                }
                if (nomor == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                nomor++;
            }
            sebelum->next = bantu;
            delete hapus;
        }
    }

    // ubah depan
    void ubahDepan(int data)
    {
        if (isEmpty() == 0)
        {
            head->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah tengah
    void ubahTengah(int data, int posisi)
    {
        Node *bantu;
        if (isEmpty() == 0)
        {
            if (posisi < 1 || posisi > hitungList())
            {
                cout << "Posisi di luar jangkauan" << endl;
            }
            else if (posisi == 1)
            {
                cout << "Posisi bukan posisi tengah" << endl;
            }
            else
            {
                int nomor = 1;
                bantu = head;
                while (nomor < posisi)
                {
                    bantu = bantu->next;
                    nomor++;
                }
                bantu->data = data;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah belakang
    void ubahBelakang(int data)
    {
        if (isEmpty() == 0)
        {
            tail->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus list
    void clearList()
    {
        Node *bantu, *hapus;
        bantu = head;
        while (bantu != NULL)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
        cout << "List berhasil terhapus!" << endl;
    }

    // Tampilkan list
    void tampilList()
    {
        Node *bantu;
        bantu = head;
        if (isEmpty() == false)
        {
            while (bantu != NULL)
            {
                cout << bantu->data << " ";
                bantu = bantu->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    int main()
    {
        init();
        insertDepan(3);
        tampilList();
        insertBelakang(5);
        tampilList();
        insertDepan(2);
        tampilList();
        insertDepan(1);
        tampilList();
        hapusDepan();
        tampilList();
        hapusBelakang();
        tampilList();
        insertTengah(7, 2);
        tampilList();
        hapusTengah(2);
        tampilList();
        ubahDepan(1);
        tampilList();
        ubahBelakang(8);
        tampilList();
        ubahTengah(11, 2);
        tampilList();

        return 0;
    }

```
Kode di atas digunakan untuk mengelola daftar data . Program ini memungkinkan Anda melakukan hal-hal seperti menambahkan node di depan, di belakang, dan di tengah, menghapus node di depan, di belakang, dan di tengah, dan mengubah nilai data pada node di depan, di belakang, dan di tengah. struktur node dibuat, yang akan menyimpan pointer dan data ke node berikutnya. Para variabel head dan tail diinisialisasi dengan nilai NULL untuk menunjukkan bahwa list tersebut kosong. Selain itu, ada fungsi-fungsi yang dapat digunakan untuk menambahkan data ke depan, belakang, dan tengah, menghitung jumlah elemen, menghapus elemen di tempat yang berbeda, mengubah data, menghapus semua elemen, dan menampilkan isi list.

### 2. [Linked List Circular]

```C++
#include <iostream>

using namespace std;

// Deklarasi Struct Node


struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

//Inisialisasi node head & tail
void init(){
    head = NULL;
    tail = head;
}

//Pengecekan isi list
int isEmpty(){
    if (head == NULL){
        return 1; // true
    } else {
        return 0; // false
    }
}

//Buat Node Baru
void buatNode(string data){
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//Hitung List
int hitungList(){
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

//Tambah Depan
void insertDepan(string data){
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head){
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

//Tambah Belakang
void insertBelakang(string data){
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head){
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

//Tambah Tengah
void insertTengah(string data, int posisi){
    if (isEmpty() == 1){
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus){
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang(){
    if (isEmpty() == 0){
        hapus = head;
        tail = head;
        if (hapus->next == head){
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head){
                hapus = hapus->next;
            }
            while (tail->next != hapus){
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi){
    if (isEmpty() == 0){
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1){
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList(){
    if (head != NULL){
        hapus = head->next;
        while (hapus != head){
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil(){
    if (isEmpty() == 0){
        tail = head;
        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main(){
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    
    return 0;
}

```
Kode di atas merupakan implementasi dari list linked single circular dalam bahasa C++. List linked ini menggunakan struktur data Node, yang memiliki dua atribut: pointer next yang menunjuk ke Node berikutnya dan data bertipe string. Disebutkan sebagai pointer, variabel head, tail, new, help, dan delete digunakan untuk mengakses dan mengelola daftar yang terhubung.


## Unguided 

### 1. [Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1]

```C++
#include <iostream>

using namespace std;

struct Node
{
    string nama;
    long long int NIM;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void tambahdepan(string nama, long long int NIM)//tambah depan
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->NIM = NIM;
        newNode->next = head;
        head = newNode;
    }

    void tamnbahbelakang(string nama, long long int NIM)//tambah belakang
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->NIM = NIM;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void tambahtengah(string nama,long long int NIM, int posisi)//mennambah di tegah
    {
        if (posisi <= 0)
        {
            cout << "POSISI HARUS LEBIH DARI 0\n";
            return;
        }
        if (posisi == 1)
        {
            tambahdepan(nama, NIM);
            return;
        }
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->NIM = NIM;
        Node *current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "POSISI KEGEDEAN\n";
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    Node *search(string nama)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->nama == nama)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void remove(string nama)// menghapus nama
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->nama == nama)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->nama == nama)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void tampil()//menampilkan data
    {
        Node *current = head;
        cout << "DATA\n";
        cout << "NAMA\tNIM" << endl;
        while (current != nullptr)
        {
            cout << current->nama << "\t" << current->NIM << endl;
            current = current->next;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    Node *getFrontNode()
    {
        return head;
    }
};

int main()
{
    LinkedList list;

    while (true)
    {
        int opsi;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. TAMBAH DEPAN\n";
        cout << "2. TAMBAH BELAKANG\n";
        cout << "3. TAMBAH TENGAH\n";
        cout << "4. UBAH DEPAN\n";
        cout << "5. UBAH BELAKANG\n";
        cout << "6. UBAH TENGAH\n";
        cout << "7. DELETE DEPAN\n";
        cout << "8. DELETE BELAKANG\n";
        cout << "9. DELETE TENGAH\n";
        cout << "10. DELETE \n";
        cout << "11. TAMPILKAN\n";
        cout << "0. KELUAR\n";
        cout << "Pilih (1-11): ";
        cin >> opsi;
        cin.ignore();

        switch (opsi){
        
        case 1:
        {
            string nama;//tambah depan
            long long int NIM;
            cout << "-=-TAMBAH DEPAN-=-\n";
            cout << "INPUT NAMA: ";
            cin >> nama;
            cout << "INPUT NIM: ";
            cin >> NIM;
            list.tambahdepan(nama, NIM);
            cout << "BERHASIL TER INPUT!\n";
            break;
        }
        case 2:
        {
            string nama;//tambah belakang
            long long int NIM;
            cout << "-=-TAMBAH BELAKANG-=-\n";
            cout << "INPUT NAMA: ";
            getline(cin, nama);
            cout << "INPUT NIM: ";
            cin >> NIM;
            cin.ignore();
            list.tamnbahbelakang(nama, NIM);
            cout << "BERHASIL TER INPUT\n";
            break;
        }
        case 3:
        {
            string nama;//tambah tangah
            long long int NIM;
            int posisi;
            cout << "-=-TAMBAH TENGAH-=-\n";
            cout << "IPUT NAMA: ";
            getline(cin, nama);
            cout << "INPUT NIM: ";
            cin >> NIM;
            cout << "INPUT POSISI: ";
            cin >> posisi;
            cin.ignore();
            list.tambahtengah(nama, NIM, posisi);
            cout << "BERHASIL DITAMBAH\n";
            break;
        }
        case 4:
        {//ubah depan
            if (list.isEmpty())
            {
                cout << "LIST KOSONG, GABISA DIUBAH.\n";
                break;
            }
            string namaBaru;
            long long int NIMBaru;
            cout << "-=-UBAH DEPAN-=-\n";
            cout << "INPUT NAMA BARU : ";
            getline(cin, namaBaru);
            cout << "INPUT NIM BARU: ";
            cin >> NIMBaru;
            cin.ignore();
            Node *frontNode = list.getFrontNode();
            frontNode->nama = namaBaru;
            frontNode->NIM = NIMBaru;
            cout << "DATA BERHASIL TERUBAH\n";
            break;
        }
        case 5:
        {//ubah belakang
            if (list.isEmpty())
            {
                cout << "LIST KOSONG, GABISA DIUBAH.\n";
                break;
            }
            string namaBaru;
            long long int NIMBaru;
            cout << "-=-UBAH BELAKANG-=-\n";
            cout << "INPUT NAMA BARU: ";
            getline(cin, namaBaru);
            cout << "INPUT NIM BARU: ";
            cin >> NIMBaru;
            cin.ignore();
            Node *current = list.getFrontNode();
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->nama = namaBaru;
            current->NIM = NIMBaru;
            cout << "DATA BERHASIL TERUBAH\n";
            break;
        }
        case 6:
        {//ubah tengah
            if (list.isEmpty())
            {
                cout << "LIST KOSONG, GABISA DIUBAH.\n";
                break;
            }
            int posisi;
            cout << "-=-UBAH TANGAH-=-\n";
            cout << "INPUT POSISI NODE YANG DIUBAH";
            cin >> posisi;
            cin.ignore();
            if (posisi <= 0)
            {
                cout << "POSISI HARUS LEBIH DARI 0\n";
                break;
            }
            Node *current = list.getFrontNode();
            for (int i = 1; i < posisi && current != nullptr; ++i)
            {
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "POSISI KEGEDEAN\n";
                break;
            }
            string namaBaru;
            long long int NIMBaru;
            cout << "INPUT NAMA BARU: ";
            getline(cin, namaBaru);
            cout << "INPUT NIM BARU: ";
            cin >> NIMBaru;
            cin.ignore();
            current->nama = namaBaru;
            current->NIM = NIMBaru;
            cout << "DATA POSISI " << posisi << " TERUBAH.\n";
            break;
        }
        case 7:
        {//menghapus list depan
            if (list.isEmpty())
            {
                cout << "LIST KOSONG GABISA DIHAPUS\n";
                break;
            }
            string nama = list.getFrontNode()->nama;
            list.remove(nama);
            cout << "DATA DEPAN "<< nama<< " TERHAPUS.\n";
            break;
        }
        case 8:
        {
            string nama;
            if (list.isEmpty())
            {//menghapus list belakang
                cout << "LIST KOSONG GABISA DIHAPUS\n";
                break;
            }
            Node *prev = nullptr;
            Node *current = list.getFrontNode();
            while (current->next != nullptr)
            {
                prev = current;
                current = current->next;
            }
            if (prev == nullptr)
            {
                // If there's only one node in the list
                list.remove(current->nama);
            }
            else
            {
                // If there are multiple nodes in the list
                prev->next = nullptr;
                delete current;
            }
            cout << "DATA BELAKANG "<< current->nama <<"TERHAPUS.\n";
            break;
        }
        case 9:
        {
            if (list.isEmpty())
            {
                cout << "LIST KOSONG GABISA DIHAPUS\n";
                break;
            }
            int posisi;
            cout << "INPUT POSISI NODE YANG DIHAPUS: ";
            cin >> posisi;
            cin.ignore();
            if (posisi <= 0)
            {
                cout << "POSISI HARUS LEBIH DARI 0\n";
                break;
            }
            Node *prev = nullptr;
            Node *current = list.getFrontNode();
            for (int i = 1; i < posisi && current != nullptr; ++i)
            {
                prev = current;
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "POSISI KEGEDAN\n";
                break;
            }
            if (prev == nullptr)
            {
                // If removing the first node
                list.remove(current->nama);
            }
            else
            {
                // If removing a node in the middle
                prev->next = current->next;
                delete current;
            }
            cout << "DATA BERHASIL TERHAPUS PADA POSISI " << posisi << "\n";
            break;
        }
        case 10:
        {
            if (list.isEmpty())
            {
                cout << "LIST SUDAH KOSONG\n";
                break;
            }
            while (!list.isEmpty())
            {
                Node *temp = list.getFrontNode();
                list.remove(temp->nama);
            }
            cout << "SELURUH DATA TERHAPUS.\n";
            break;
        }
        case 11:
        {
            list.tampil();
            break;
        }
        case 0:
        {
            cout << "TY CUYY\n";
            exit(0);
        }
        default:
        {
            cout << "KAGA NGOTAK\n";
            break;
        }
        }
    }

    return 0;
}
```
#### Output:
![pertemuan4/OUTPUT/1.1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.1.png)
![pertemuan4/OUTPUT/1.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.2.png)
![pertemuan4/OUTPUT/1.3.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.3.png)
![pertemuan4/OUTPUT/1.4.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.4.png)
![pertemuan4/OUTPUT/1.5.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.5.png)
![pertemuan4/OUTPUT/1.6.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.6.png)
![pertemuan4/OUTPUT/1.7.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.7.png)
![pertemuan4/OUTPUT/1.8.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.8.png)
![pertemuan4/OUTPUT/1.9.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.9.png)
![pertemuan4/OUTPUT/1.10.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.10.png)
![pertemuan4/OUTPUT/1.11.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan4/OUTPUT/1.11.png)

Kode di atas menggunakan linked list non circular. yang dapat menambah, menghapus, mengubah suatu data yang berada didepan, belakang, dan tengah yang diinputkan oleh user. Terdapat beberapa fungsi pada program diatas yang berfungsi untuk mengedit data yang diinputkan oleh user dengan menggunakan fungsi tambahdepan ( untuk menambahkan data pada awal ), tambahbelakang ( untuk menambahkan data pada akhir ), tambahtengah ( untuk menambahkan data diantara data yang sudah ada ), remove( untuk menghapus data ), tampil( untuk menampilkan data yang sudah diinputkan ). Fungsi tersebut di implementasikan dalam metode kelas linked list dan terdapat perulangan agar program berjalan dengan sesuai


## Kesimpulan
Linked list merupakan struktur data yang terdiri dari node-node yang saling tehubung melalui alamat pointer.
pada linked list non-circular setiap node terhubung kenode berikutnya namun tail tidak terhubung ke node head dan penanda untuk menandakan akhir dari linked list menggunakan NULL. Linked list circular node terakhir kembali terhubung ke node pertama sehingga membentuk lingkaran dengan menggunakan node tambahan yang digunakan dalam linked list circular. pada linked list circular tidak ada nilai NULL untuk menandakan akhir, dan penggunaan node saat ini yang digunakan untuk menghentikan perulangan.

## Referensi
[1] Mutaz Rasmi Abu sara, Mohammad F.J.Klaib, dan Masud Hasan, Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. telkomuniversity; 2020.

[2] Abu Sara, M. R., Klaib, M. F. J., & Hasan, M. (2021). Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. Indonesia Journal on Computing (Indo-JC), 5(3), 47-62.
