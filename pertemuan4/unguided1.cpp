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