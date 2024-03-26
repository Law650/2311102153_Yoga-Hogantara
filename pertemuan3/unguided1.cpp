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
    cout << "Masukkan nama Anda: ";
    cin >> namagw;
    cout << "Masukkan usia Anda: ";
    cin >> umurgw;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Masukkan data pengguna ke dalam linked list
    list.tambahdepan(namagw, umurgw);

    // Input data nama dan usia mahasiswa lain dari pengguna
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa lain: ";
    cin >> jumlahMahasiswa;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        string namaMahasiswa;
        int umurMahasiswa;

        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        getline(cin, namaMahasiswa);
        cout << "Masukkan usia mahasiswa ke-" << i+1 << ": ";
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
    cout << "Menu Operasi:" << endl;
    cout << "1. Hapus data mahasiswa" << endl;
    cout << "2. Tambahkan data mahasiswa di depan" << endl;
    cout << "3. Tambahkan data mahasiswa di tengah" << endl;
    cout << "4. Tambahkan data mahasiswa di belakang" << endl;
    cout << "5. Tampilkan data" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih : ";
    cin >> menu;
    cin.ignore(); // Membersihkan newline dari buffer stdin

    // Proses operasi sesuai dengan menu yang dipilih
    switch (menu) {
        case 1: {
            string hapusnama;
            cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
            cin>>hapusnama;
            list.remove(hapusnama);
            break;
        }
        case 2: {
            string namatambahdepan;
            int usiatambahdepan;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di depan: ";
            cin>>namatambahdepan;
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di depan: ";
            cin>> usiatambahdepan;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.tambahdepan(namatambahdepan, usiatambahdepan);
            break;
        }
        case 3: {
            string namaTambahTengah;
            int usiaTambahTengah;
            int posisiTambahTengah;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di tengah: ";
            cin>>namaTambahTengah;
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di tengah: ";
            cin >> usiaTambahTengah;
            cout << "Masukkan posisi untuk menambahkan mahasiswa di tengah: ";
            cin >> posisiTambahTengah;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.tambahtengah(namaTambahTengah, usiaTambahTengah, posisiTambahTengah);
            break;
        }
        case 4: {
            string namaTambahBelakang;
            int usiaTambahBelakang;
            cout << "Masukkan nama mahasiswa yang ingin ditambahkan di belakang: ";
            cin>>namaTambahBelakang;
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di belakang: ";
            cin >> usiaTambahBelakang;
            cin.ignore(); // Membersihkan newline dari buffer stdin
            list.tambahbelakang(namaTambahBelakang, usiaTambahBelakang);
            break;
        }
        case 5: {
            cout << "Data mahasiswa setelah operasi:" << endl;
            list.display();
            break;
        }
        case 6 : {
            cout<<"Anda telah keluar dari menu!"<<endl;
            exit(0);
        }
        default:
            cout << "Opsi tidak valid" << endl;
    
    }
    }

    return 0;

}