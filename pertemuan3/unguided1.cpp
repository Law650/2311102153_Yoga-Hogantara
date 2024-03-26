#include <iostream>
#include <iomanip>//library buat setw, buat merapihkan
using namespace std;

//deklarasi struct NODE
struct node{
    int umur153;
    string nama153;
    node *next;
};
    node*head;
    node*tail;

//inisialisasi noe
void init(){
    head=NULL;
    tail=NULL;
}
//pengecekan
bool isempty(){
    if(head==NULL)
    return true;
    else
    return false;
}
void tambahdepan(string nama,int umur){
    //buat node baru
    node*baru=new node;
    baru->nama153=nama;
    baru->umur153=umur;
    baru->next=NULL;
    if(isempty()==true){
        head=tail=baru;
        tail->next=NULL;
    }
    else{
        baru->next=head;
        head=baru;
    }
}

void tambahbelakang(string nama,int umur){
    //buat node baru
    node *baru=new node;
    baru->nama153=nama;
    baru->umur153=umur;
    baru->next = NULL;
    if(isempty()==true){
        head=tail=baru;
        tail->next=NULL;
    }
    else{
        tail->next = baru;
        tail=baru;
    }

}
//hitung jumlh list
int hitunglist(){
    node *hitung;
    hitung=head;
    int jumlah=0;
    while(hitung !=NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//tambah tengah
void tambahtengah(string nama,int umur,int posisi){
    if(posisi <1 || posisi>hitunglist()){
        cout<<"Posisi diluar nalar\n";
    }
    else if(posisi==1){
        cout<<"Posisi bukan ditengah\n";
    }
    else{
        node *baru,*bantu;
        baru=new node();
        baru->nama153=nama;
        baru->umur153=umur;
        // transversing
        bantu = head;
        int nomor=1;
        while(nomor<posisi-1){
            bantu=bantu->next;
            nomor++;
        }
        baru->next=bantu->next;
        bantu->next=baru;
    }
}
//hapus depan
void hapusdepan(){
    node *hapus;
    if(isempty()==false){
        if(head->next !=NULL){
            hapus = head;
            head= head->next;
            delete hapus;
        }
        else{
            head=tail=NULL;
        }
    }
    else{
        cout<<"LIST KOSONG\n";
    }
}
//hapus belakang
void hapusbelakang(){
    node *hapus;
    node *bantu;
    if(isempty()==false){
        if(head !=tail){
            hapus=tail;
            bantu=head;
            while(bantu->next!=tail){
                bantu = bantu->next;
            }
            tail=bantu;
            tail->next=NULL;
        delete hapus;
        }
        else{
            head = tail=NULL;
        }
    }
    else{
        cout<<"LIST KOSONG\n";
    }
}

//hapus tengah
void hapustengah(int posisi){
    node*hapus, *bantu,*bantu2;
    if(posisi<1||posisi>hitunglist()){
        cout<<"POSISI DILUAR NALAR\n";
    }
    else if(posisi==1){
        cout<<"POSISI BUKAN DITENGAH\n";
    }
    else{
        int nomor = 1;
        bantu = head;
        while(nomor<=posisi){
            if(nomor==posisi-1){
                bantu2=bantu;
            }
            if(nomor==posisi){
                hapus=bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next=bantu;
    delete hapus;
    }
}

//ubah depan
void ubahdepan(string nama,int umur){
    if(isempty()==false){
        head->nama153=nama;
        head->umur153=umur;
    }
    else{
        cout<<"LIST MASIH KOSONGG\n";
    }
}
//ubah tengah
void ubahtengah(string nama,int umur,int posisi){
    node *bantu;
    if(isempty()==false){
        if(posisi<1||posisi>hitunglist()){
            cout<<"Posisi DILURA NALAR\n";
        }
        else if(posisi=1){
            cout<<"POSISI BUKAN DITENGAH\n";
        }
    }
    else{
        bantu=head;
        int nomor=1;
        while(nomor<posisi){
            bantu = bantu->next;
            nomor++;
        }
        bantu->nama153=nama;
        bantu->umur153=umur;
    }
}
//ubah belakang
void ubahbelakang(string nama,int umur){
    if(isempty()==false){
        tail->nama153=nama;
        tail->umur153=umur;

    }
    else{
        cout<<"LIST MASIH KOSONG\n";
    }
}
//hapus list
void hapuslist(){
    node*bantu,*hapus;
    bantu=head;
    while(bantu!=NULL){
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = tail=NULL;
    cout<<"LIST BERHASIL TERHAPUSS\n";
}
void tampil(){
    node *bantu;
    bantu=head;
    cout<<left<<setw(10)<<"nama"<<setw(10)<<"Umur"<<endl;
    if(isempty()==false){
        while(bantu != NULL){
            cout<<left<<setw(10)<< bantu->nama153<<setw(10)<<bantu->umur153<<endl;
            bantu = bantu->next;
        }
        cout<<endl;
    }
    else{
        cout<<"LIST MASIH KOSONG\n";
    }
}

int main(){
    init();
    cout<<"A. NAMA & UMUR\n";
    tambahdepan("Karin",18);
    tambahdepan("Hoshino",18);
    tambahdepan("akechi",20);
    tambahdepan("yusuke",19);
    tambahdepan("michael",18);
    tambahdepan("jane",20);
    tambahdepan("john",19);
    tambahdepan("Yoga",18);
    tampil();
    cout<<"B.HAPUS DATA AKECHI\n";
    hapustengah(6);
    tampil();
    cout<<"C.TAMBAHKAN DATA Futaba,18 DIANTARA JOHN DAN JANE\n";
    tambahtengah("Futaba",18,3);
    tampil();
    cout<<"D.TAMBAHKAN DATA IGOR,20 DIAWAL\n";
    tambahdepan("Igor",20);
    tampil();
    cout<<"E.UBAH DATA MICHAEL MENJADI REYN,18\n";
    ubahtengah("reyn",18,6);
    tampil();
    cout<<"F.MENAMPILKAN SELURUH DATA\n";
    tampil();

    return 0;
}