//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;
 
int main() {
    
    int bil_153=10; 
    int Menu_153[bil_153]={}; 
    int pil_153; 
    //PERULANGAN AGAR PROGRAM BERJALAN SETIDAKNYA 1 KALI
    do{ 
        cout << "-----Menu-----\n"; 
        cout << "1. Input Array\n"; 
        cout << "2. Cari Nilai Minimum\n"; 
        cout << "3. Cari Nilai Maksimum\n"; 
        cout << "4. Hitung Rata-Rata\n"; 
        cout << "5. Exit\n"; 
        cout << "Masukan Pilihan: "; 
        cin>> pil_153; //INPUT MENU

        switch(pil_153){ //MEMILIH MENU
    case 1: 
        cout<<"Input Array \n"; //MENGINPUT ARRAY
        for(int y=0; y<bil_153; y++){ 
            cout<<"Bil "<<y+1<<" : "; 
            cin>>Menu_153[y]; 
        } 
        break; 
    
    case 2:{ 
        int minimum_153=Menu_153[0]; //MENCARI NILAI MINIMUM
        for(int y=1;y<bil_153;y++){ 
            if(Menu_153[y]<minimum_153){ 
                minimum_153=Menu_153[y]; 
            } 
        } 
        cout<<"Nilai Minimum dari bil yang di input = "<<minimum_153<<endl; //OUTPUT MINIMUM
        break; 
    } 
    case 3:{ 
        int max_153=Menu_153[0]; //MENCARI NILAI MAKSIMUM
        for(int y=0;y<bil_153;y++){ 
            if(Menu_153[y]>max_153){ 
                max_153=Menu_153[y]; 
            } 
        } 
       cout<<"Nilai Maksimum dari bil yang di input ="<<max_153<<endl; //OUTPUT MAKSIMUM
       break; 
    } 
    case 4:{ //MENCARI RATA-RATA
        float rata2_153; 
        float total_153=0; 
        for(int y=0;y<bil_153;y++){ 
            total_153=total_153+Menu_153[y]; 
        } 
        rata2_153=(total_153/bil_153); 
        cout<<"rata rata : "<<rata2_153<<endl; //OUTPUT
        break; 
    } 
    case 5:{ 
            cout<<"==============================\n"; 
            cout<<"TY cuy\n"; 
            return 0; 
            break; 
    } 
    default: 
        cout<<"Pilih lagi cuyy\n"; 
        break; 
        } 
    } 
    while(pil_153 !=0);
 
return 0; 
} 

