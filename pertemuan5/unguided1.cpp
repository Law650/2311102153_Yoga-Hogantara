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