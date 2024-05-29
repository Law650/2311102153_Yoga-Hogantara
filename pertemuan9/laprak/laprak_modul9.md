# <h1 align="center">Laporan Praktikum Modul 9 - GRAPH AND TREE</h1>
<p align="center">Yoga Hogantara - 2311102153</p>

## Dasar Teori

Graph
Graph sendiri merupakan suatu struktur data yang digunakan untuk mempresentasikan hubungan antara pasangan objek. Graph terdiri dari berbagai kumpulan node dan edges yang menghubungkan suatu node node tersebut. Komponen graph terdiri dari: 
1. vortex(node) yang merupakan titik atau simpul dalam grpah yang       mempresentasikan objek
2. edge garis atau busur yang meghubungkan suatu node dan mempresentasikan hubungkan antara objek tersebut.

Graph memiliki beberapa jenis diantaranya :
1. graph tak beraarah : dimana graph edge pada graph tidak memiliki arah dan hubungan antara dua node bersifat dua arah.
2. graph berarah : dimana edge pada graph memiliki arah dan hubungan antara dua node bersifat satu arah.
3. graph berbobot : dimana setiap edge pada graph memiliki nilai bobot yang mempresentasikan jarak antara dua node
4. graph tidak berbobot : dimana edge pada graph tidak memiliki nilai bobot.

Tree
tree merupakan suatu struktur data yang terdiri dari node node yang mana setiap node memiliki satu parent dan bisa memiliki beberapa children. Komponen pada tree terdiri dari:

1. root : Node paling atas pada tree yang tidak memiliki parent atau orang tua
2. parent : node yang memiliki anak
3. child : node yang merupakan keturunan dari node parent
4. leaf : node yang tidak memiliki anak
5. subtree : pohon kecil yang merupakan bagian dari tree yang lebib besaar
6. edge : hubungan antara node dengan child


## Guided 

### 1. [PROGRAM GRAPH]

```C++
#include <iostream>
#include <iomanip>

using namespace std;
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph() {
    for (int baris=0; baris<7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom=0; kolom<7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ") ";
            }
        } cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}

```
Kode di atas digunakan untuk mempresentasikan dan menampilkan suatu graf berarah yang mempunyai suatu bobot dengan simpul dan busur yang diberikan. Pada array simpul[7] berisi nama nama kota yang sudah diisi, array busur berisi matrix 2D yang menyimpan bobot antara simpul simpul yang ada. Dengan menggunakan fungsi tampilGraph() untuk menampilkan graf yang sudah dibuat.

### 2. [PROGRAM TREE]

```C++
#include <iostream>
#include <iomanip>
using namespace std;
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    Pohon *nodeD = insertLeft('D', nodeB);
    Pohon *nodeE = insertRight('E', nodeB);
    Pohon *nodeF = insertLeft('F', nodeC);
    Pohon *nodeG = insertLeft('G', nodeE);
    Pohon *nodeH = insertRight('H', nodeE);
    Pohon *nodeI = insertLeft('I', nodeG);
    Pohon *nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);

    retrieve(nodeC);
    find(nodeC);

    characteristic();

    cout << "\nPreOrder :\n ";
    preOrder(root);
    cout << "\n\nInOrder :\n ";
    inOrder(root);
    cout << "\n\nPostOrder :\n ";
    postOrder(root);

    cout << endl;
    return 0;
}

```
Kode di atas merupakan implementasi dari pohon binner yang mencakup fungsi untuk membuat, memodifikasi, dan penelusuran pada pohon biner, dengan menggunakan struktur pohon ,char data untuk menyimpan data, pointer *left,*right,*parent untuk pointer ke- anak kanan, kiri, dan orang tua. Fungsi init() untuk menginisialisasi pohon dengan mengatur sebuah root ke NULL. isEmpty() untuk mengecek pohon kosong atau tidak. buatNode() untuk membuat simpul baru sebagai root jika pada phon kosong. update() untuk mengganti data pada simpul yang ditentukan. retrieve untuk menampilkan data yang ditentukan. find() untuk menampilkan informasi tentang simpul yang ditentukan. deleteTree() untuk menghapus keseluruhan pohon. deleteSub() menghapus subtree. clear() untuk menghapus seluruh pohon dan menampilkan suatu pesan jika pohon telah terhapus atau belum dibuat sama sekali.


## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. Output Program ]

```C++
#include <iostream> 
#include <iomanip> 
#include <vector> 
#include <string> 
using namespace std; 
//YOGA HOGANTARA 2311102153
int main() 
{ 
    int jmlhssimpul153; 
    cout << "IPUT JUMLAH SIMPUL: "; 
    cin >> jmlhssimpul153; 
    vector<string> simpul(jmlhssimpul153); //UNTUK MENYIMPAN NAMA NAMA SIMPUL
    vector<vector<int>> busur(jmlhssimpul153, // MATRIX 2D UNTUK MENYIMPAN BOBOT BUSUR ANTAR SIMPUL
    vector<int>(jmlhssimpul153, 0)); 
    
    cout << "INPUT NAMA SIMPUL " << endl; 
    //LOOP FOR UNTUK MENGITERASI PASANGAN SIMPUL
    for (int i = 0; i < jmlhssimpul153; i++) { 
        cout << "SIMPUL KE-" << (i + 1) << ": "; 
        cin >> simpul[i]; 
        } 
        cout << "INPUT BOBOT SIMPUL" << endl; 
    
    for (int i = 0; i < jmlhssimpul153; i++) { 
        for (int j = 0; j < jmlhssimpul153; j++) 
        { 
            cout << simpul[i] << " --> " << simpul[j] << " = "; 
            cin >> busur[i][j];
             }
        } 
             cout << endl; 
             cout << setw(7) << " "; 
             for (int i = 0; i < jmlhssimpul153; i++) {
                cout << setw(8) << simpul[i]; 
            } 
                cout << endl; 
                for (int i = 0; i < jmlhssimpul153; i++) 
                { 
                    cout << setw(7) << simpul[i]; 
                    for (int j = 0; j < jmlhssimpul153; j++) 
                {
                    cout << setw(8) << busur[i][j];
                } 
                cout << endl; 
            } 
        }
```
#### Output:
![pertemuan9/OUTPUT/1.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/1.png)

Kode di atas menampilkan graph berarah dan berbobot berdasarkan inputan dari user. Dengan user meng Inputkan jumlah simpul dan memasukkan nama nama simpul untuk disimpan pada vektor dan matriks. dan pada program dapat menampilkan tabel dengan nama nama simpul dan bobot yang sudah di-isi oleh user . Dengan menggunakan vector<string>simpul(jmlhsimpul153) untuk menyimpan nama simpul. vector<vector<int>>busur(jmlhsimpul153, vector<int>(jmlhsimpul153,0)) matriks 2D yang menyimpan bobot busur antar simpul.

### 2. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. Output Program ]

```C++
#include <iostream>  
#include <iomanip>   
using namespace std; 

// STRUCT POHON
struct tree153 {
    char char153; 
    tree153 *left, *right, *parent; 
};

tree153 *root, *baru; 

// MENGINISIALISASI POHON
void init() {
    root = NULL; 
}

// MENGECEK POHON APAKAH KOSONG
bool isEmpty() {
    return root == NULL; 
}

// MEMBUAT NODE BARU
void buatNode(char char153) {
    if (isEmpty()) { 
        root = new tree153(); 
        root->char153 = char153; 
        root->left = NULL; 
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << char153 << " berhasil dibuat sebagai root." << endl; 
    } else { 
        cout << "\n Tree sudah ada!" << endl;
    }
}

// MENAMBAH NODE KIRI
tree153* insertLeft(char char153, tree153 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) { 
            cout << "\n Node " << node->char153 << " sudah ada child kiri !" << endl;
            return NULL;
        } else {
            tree153 *baru = new tree153(); 
            baru->char153 = char153; 
            baru->left = NULL; 
            baru->right = NULL; 
            baru->parent = node;
            node->left = baru; 
            cout << "\n Node " << char153 << " berhasil ditambahkan ke child kiri " << baru->parent->char153 << endl; // Pesan sukses
            return baru; 
        }
    }
}

// MENAMBAH NODE KANAN
tree153* insertRight(char char153, tree153 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) { 
            cout << "\n Node " << node->char153 << " sudah ada child kanan !" << endl; 
            return NULL;
        } else {
            tree153 *baru = new tree153(); 
            baru->char153 = char153; 
            baru->left = NULL; 
            baru->right = NULL; 
            baru->parent = node; 
            node->right = baru; 
            cout << "\n Node " << char153 << " berhasil ditambahkan ke child kanan " << baru->parent->char153 << endl;
            return baru; 
        }
    }
}

// MENGUBAH DATA NODE
void update(char char153, tree153 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (!node) { 
            cout << "\n Node yang ingin diganti tidak ada!!" << endl; 
        } else {
            char temp = node->char153; 
            node->char153 = char153; 
            cout << "\n Node " << temp << " berhasil diubah menjadi " << char153 << endl; 
        }
    }
}

// MENAMPILKAN DATA NODE
void retrieve(tree153 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data node : " << node->char153 << endl;
        }
    }
}

// MECARI DAN MENAMILKAN DATA NODE
void find(tree153 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) { 
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->char153 << endl; 
            cout << " Root : " << root->char153 << endl; 
            if (!node->parent) 
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->char153 << endl; 
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) 
                cout << " Sibling : " << node->parent->left->char153 << endl; 
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) 
                cout << " Sibling : " << node->parent->right->char153 << endl; 
            else
                cout << " Sibling : (tidak punya sibling)" << endl; 
            if (!node->left) 
                cout << " Child Kiri : (tidak punya Child kiri)" << endl; 
            else
                cout << " Child Kiri : " << node->left->char153 << endl; 
            if (!node->right) 
                cout << " Child Kanan : (tidak punya Child kanan)" << endl; 
            else
                cout << " Child Kanan : " << node->right->char153 << endl; 
        }
    }
}

// TRAVERSAL PREORDER
void preOrder(tree153 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (node != NULL) { 
            cout << " " << node->char153 << ", "; 
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// TRAVERSAL INORDER
void inOrder(tree153 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (node != NULL) { 
            inOrder(node->left); 
            cout << " " << node->char153 << ", "; 
            inOrder(node->right); 
        }
    }
}

// TRAVERSAL POSTORDER
void postOrder(tree153 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
    } else {
        if (node != NULL) { 
            postOrder(node->left); 
            postOrder(node->right); 
            cout << " " << node->char153 << ", "; 
        }
    }
}

// MENGHAPUS POHON
void deleteTree(tree153 *node) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) { 
            if (node != root) { 
                node->parent->left = NULL; 
                node->parent->right = NULL; 
            }
            deleteTree(node->left); 
            deleteTree(node->right); 
            if (node == root) { 
                delete root; 
                root = NULL; 
            } else {
                delete node; 
            }
        }
    }
}

// MEGHAPUS SUBPOHON
void deleteSub(tree153 *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left); 
        deleteTree(node->right); 
        cout << "\n Node subtree " << node->char153 << " berhasil dihapus." << endl;
    }
}

// MENGHAPUS SEMUA NODE POHON
void clear() {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!!" << endl; 
    } else {
        deleteTree(root); 
        cout << "\n Pohon berhasil dihapus." << endl; 
    }
}

// MENGHITUNG UKURAN POHON
int size(tree153 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!!" << endl; 
        return 0;
    } else {
        if (!node) { 
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// MEGHITUNG TINGGI POHON
int height(tree153 *node = root) {
    if (isEmpty()) { 
        cout << "\n Buat tree terlebih dahulu!" << endl; 
        return 0;
    } else {
        if (!node) { 
            return 0;
        } else {
            int heightKiri = height(node->left); 
            int heightKanan = height(node->right); 
            if (heightKiri >= heightKanan) {
                return heightKiri + 1; 
            } else {
                return heightKanan + 1; 
            }
        }
    }
}

// MENAMPILKAN KARAKTERISTIK POHON
void characteristic() {
    cout << "\n Size Tree : " << size() << endl; 
    cout << " Height Tree : " << height() << endl; 
    cout << " Average Node of Tree : " << size() / height() << endl; 
}

// MENAMPILKAN CHILDREN DARI NODE
void displayChildren(tree153 *node) {
    if (node) { 
        cout << "\nChildren of Node " << node->char153 << ": "; 
        if (node->left) 
            cout << "Left: " << node->left->char153 << " "; 
        else
            cout << "Left: NULL "; 
        if (node->right) 
            cout << "Right: " << node->right->char153 << " ";
        else
            cout << "Right: NULL "; 
        cout << endl; 
    } else { 
        cout << "\nNode tidak ditemukan!" << endl; 
    }
}

// MENAMPILKAN KETURUNAN DARI NODE
void displayDescendants(tree153 *node) {
    if (node) { 
        cout << "\nDescendants of Node " << node->char153 << ": "; 
        preOrder(node->left); 
        preOrder(node->right); 
        cout << endl; 
    } else { 
        cout << "\nNode tidak ditemukan!" << endl; 
    }
}

// MENEMUKAN NODE BERDASAR DATA
tree153* findNode(char char153, tree153 *node = root) {
    if (!node)
        return NULL;
    if (node->char153 == char153) 
        return node;
    tree153 *left = findNode(char153, node->left);
    if (left) 
        return left;
    return findNode(char153, node->right); 
}



int main() {
    init(); 
    int pilih153; 
    char char153, parentData; 
    tree153 *parentNode = NULL; 

    do {
        //MENU
        cout << "\n_+_+_+_+_+_+_+_+_+_+_+__+_\n"; 
        cout << "1. BUAT NODE ROOT\n";
        cout << "2. INSERT NODE KIRI\n";
        cout << "3. INSERT NODE KANAN\n";
        cout << "4. UPDATE NODE\n";
        cout << "5. RETRIEVE NODE\n";
        cout << "6. CARI NODE\n";
        cout << "7. DISPLAY CHILDREN\n";
        cout << "8. DISPLAY DESCENDANT\n";
        cout << "9. TRAVERSAL PRE-ORDER\n";
        cout << "10. TRAVERSAL IN-ORDER\n";
        cout << "11. TRAVERSAL POST-ORDER\n";
        cout << "12. DELETE TREE\n";
        cout << "13. KARAKTERISTIKK TREE\n";
        cout << "0. EXIT\n";
        cout << "PILIH CUUY : ";
        cin >> pilih153;

        //PILIHAN DARI MENU
        switch (pilih153) {
            case 1: 
                cout << "Masukkan data untuk root: ";
                cin >> char153; 
                buatNode(char153); 
                break;
            case 2: 
                cout << "Masukkan data untuk node kiri: ";
                cin >> char153; 
                cout << "Masukkan data parent: ";
                cin >> parentData; 
                parentNode = findNode(parentData); 
                insertLeft(char153, parentNode); 
                break;
            case 3: 
                cout << "Masukkan data untuk node kanan: ";
                cin >> char153; 
                cout << "Masukkan data parent: ";
                cin >> parentData; 
                parentNode = findNode(parentData); 
                insertRight(char153, parentNode); 
                break;
            case 4: 
                cout << "Masukkan data baru: ";
                cin >> char153; 
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parentData;
                parentNode = findNode(parentData); 
                update(char153, parentNode); 
                break;
            case 5:
                cout << "Masukkan data node yang ingin di-retrieve: ";
                cin >> char153; 
                parentNode = findNode(char153); 
                retrieve(parentNode); 
                break;
            case 6: 
                cout << "Masukkan data node yang ingin di-find: ";
                cin >> char153; 
                parentNode = findNode(char153); 
                find(parentNode); 
                break;
            case 7:
                cout << "Masukkan data node untuk menampilkan children: ";
                cin >> char153; 
                parentNode = findNode(char153); 
                displayChildren(parentNode); 
                break;
            case 8: 
                cout << "Masukkan data node untuk menampilkan descendants: ";
                cin >> char153; 
                parentNode = findNode(char153); 
                displayDescendants(parentNode); 
                break;
            case 9: 
                cout << "\nPreOrder :\n ";
                preOrder(root); 
                cout << endl; 
                break;
            case 10: 
                cout << "\nInOrder :\n ";
                inOrder(root); 
                cout << endl;
                break;
            case 11: 
                cout << "\nPostOrder :\n ";
                postOrder(root); 
                cout << endl; 
                break;
            case 12: 
                clear(); 
                break;
            case 13:
                characteristic(); 
                break;
            case 0: 
                cout << "Terima kasih!\n";
                return 0;
                break;
            default: 
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih153 != 0); 
}

```
#### Output:
![pertemuan9/OUTPUT/2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.2.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.3.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.4.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.5.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.6.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.7.png)
![pertemuan9/OUTPUT/2.2.png](https://github.com/Law650/2311102153_Yoga-Hogantara/blob/main/pertemuan9/OUTPUT/2.8.png)

Kode di atas dapat menambahkan, membuat, menghapus, mencari, dan traversal node, serta dapat menampilkan karakteristik dari pohon tersebut. Dengan menggunakan init() untuk menginisialisasi pohon dengan mengatur root ke NULL . isEmpty() untuk mengecek pohon kosong atau tidak, buatNode() untuk membuat node root jika pohon kosong. insertLeft() dan insertRight() untuk menambah node baru sebagai anak kiri atau kanan dari node yang diberikan. update() mengubah data dari node yang diberikan. findNode() untuk mencari node berdasarkan data yang diberikan. traversal preorder, postorder, inorder untuk melakukan traversal pada urutan preorder, inorder, post order. deleteTree() untuk menghapus seluruh pohon, deleteSub() untuk menghapus sub pohon. main() merupakan sebuah fungsi utama yang menampilkan menu pada program tersebut. 

## Kesimpulan
Graph dan tree merupakan struktur data yang berfungsi untuk mempresentasikan hubungan antara objek. graph dapat mempresentasikan hubungan yang lebih kompleks dan digunakan dalam berbagai aplikasi. Tree merupakan bentuk khusus dari graph tanpa siklus yang digunakan dalam berbagai aplikasi juga.

## Referensi
[1] Blumenthal, D. B., Bougleux, S., Gamper, J., & Brun, L. (2019, May).GEDLIB: A C++ library for graph edit distance computation. In International Workshop on Graph-Based Representations in Pattern Recognition (pp. 14-24). Cham: Springer International Publishing.

[2] Karumanchi, N. (2020). Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles (6th ed.). Careermonk Publications.
