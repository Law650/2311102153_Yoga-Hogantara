//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

int main() {
    //VARIABLE MENYINMPAN ARRAY 
    int xu_153, yu_153, zu_153;

    // MENGINPUTKAN ARRAY
    cout << "INPUT UKURAN x : "; 
    cin>>xu_153;
    cout << "INPUT UKURAN y : "; 
    cin>>yu_153;
    cout << "INPUT UKURAN z : "; 
    cin>>zu_153;
   
    //DEKLARASI ARRAY
    int arr[xu_153][yu_153][zu_153];

    // MENGISI DATA ARRAY OLEH USER
    for (int x=0;x<xu_153;x++) {
        for (int y=0;y<yu_153;y++) {
            for (int z=0;z<zu_153;z++) {
                cout << "Input Array["<<x<<"]["<<y<<"]["<<z<<"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    //MENAMPILKAN ARRAY BESERTA INDEKS
    for (int x=0;x<xu_153;x++) {
        for (int y=0;y<yu_153;y++) {
            for (int z=0;z<zu_153;z++) {
                cout << "Data Array["<<x<<"]["<<y<<"]["<<z<<"] = "<< arr[x][y][z]<< endl;
            }
        }
    }
    cout << endl;

    //MENAMPILKAN ARRAY 3 D
    for (int x=0;x<xu_153;x++) {
        for (int y=0;y<yu_153;y++) {
            for (int z=0;z<zu_153;z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}