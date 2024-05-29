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