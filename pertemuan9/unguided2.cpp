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
