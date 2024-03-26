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