//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

// Struktur Mahasiswa untuk merepresentasikan data mahasiswa
struct Mahasiswa {
    string nama; 
    long long nim; 
};

// Struktur Node untuk merepresentasikan elemen dalam antrian
struct Node {
    Mahasiswa data; 
    Node* next; 
};

// Kelas Queue untuk merepresentasikan sebuah antrian
class Queue {
private:
    Node* front; 
    Node* back; 
    int size; 

public:
    // Konstruktor untuk inisialisasi antrian kosong
    Queue() {
        front = nullptr; 
        back = nullptr; 
        size = 0; 
    }

    // Metode untuk menambahkan data mahasiswa ke dalam antrian
    void tambah(string nama, long long nim) {
        Node* newNode = new Node; 
        newNode->data.nama = nama; 
        newNode->data.nim = nim; 
        newNode->next = nullptr; 
        
        // Jika antrian kosong, maka node baru menjadi elemen pertama dan terakhir
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else { 
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    // Metode untuk mengurangi elemen pertama dari antrian
    void kurang() {
        
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else { 
            Node* temp = front; 
            front = front->next; 
            delete temp; 
            size--; 
        }
    }

    // Metode untuk menghitung jumlah elemen dalam antrian
    int count() {
        return size; // Mengembalikan ukuran antrian
    }

    // Metode untuk menghapus seluruh elemen dari antrian
    void clearQueue() {
        while (!isEmpty()) { // Selama antrian tidak kosong, hapus elemen pertama
            kurang();
        }
    }

    // Metode untuk menampilkan seluruh elemen dalam antrian beserta data mahasiswa
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

    // Metode untuk memeriksa apakah antrian kosong
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

   