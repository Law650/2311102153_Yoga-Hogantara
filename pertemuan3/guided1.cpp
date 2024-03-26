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
