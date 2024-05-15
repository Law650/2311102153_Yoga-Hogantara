//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

// Struktur untuk merepresentasikan elemen dalam antrian
struct Node {
    string data; 
    Node* next; 
};

// Kelas untuk merepresentasikan sebuah antrian
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

    // Metode untuk menambahkan data ke dalam antrian
    void tambah(string nama) {
        Node* newNode = new Node; 
        newNode->data = nama; 
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

    // Metode untuk mengurangi elemen dari antrian
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

    // Metode untuk menghitung jumlah elemen dalam antrian
    int count() {
        return size; 
    }

    // Metode untuk menghapus seluruh elemen dalam antrian
    void clearQueue() {
        while (!isEmpty()) { 
            kurang();
        }
    }

    // Metode untuk menampilkan seluruh elemen dalam antrian
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

    // Metode untuk memeriksa apakah antrian kosong
    bool isEmpty() {
        return size == 0; 
    }
};

// Fungsi utama program
int main() {
    Queue queue_153; 

    // Menambahkan beberapa data ke dalam antrian
    queue_153.tambah("Andi");
    queue_153.tambah("Maya");
    // Menampilkan antrian
    queue_153.viewQueue();
    cout << "JUMLAH = "<<queue_153.count()<<endl;
    // Mengurangi satu elemen dari antrian dan menampilkan hasilnya
    queue_153.kurang();
    queue_153.viewQueue();
    cout << "JUMLAH = "<<queue_153.count()<<endl;
    // Menghapus seluruh elemen dari antrian dan menampilkan hasilnya
    queue_153.clearQueue();
    queue_153.viewQueue();
    cout << "JUMLAH = "<<queue_153.count()<<endl;

    return 0;
}