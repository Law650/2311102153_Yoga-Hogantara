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

   