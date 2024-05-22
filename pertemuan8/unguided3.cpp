#include <iostream>

using namespace std;

int main(){
    int n = 10;//MAKS JUMLAH DATA
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};//DATA
    int cari = 4;//YANG MAU DICARI
    int ketemu =0;
    int i;
    //ALGORITMA SEQUENTIAL SEARCH
    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu++;

        }
    }

    cout << "SEQUENTIAL SEARCH\n";
    cout << "DATA : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}\n";

    if (ketemu){
        cout << "ANGKA " << cari << " ADA SEBANYAK " << ketemu << endl;
    }else{
        cout << "data tidak ditemukan\n" ;
    }

return 0;
}