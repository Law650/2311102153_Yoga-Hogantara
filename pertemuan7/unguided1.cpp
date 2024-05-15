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