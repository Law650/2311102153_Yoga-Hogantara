//program struct dan class
#include  <iostream>

using namespace std;

class gitar{//class gitar 
    public:
    string merek;
    string series;
    float harga;
};

struct senar{//struct senar
    string msenar;
    int ukuran;
};

int main(){

    cout<<"--CLASS--\n"; //deklarasi class yang menampilkan merek dan series dari gitar
    gitar guitar;
    guitar.merek ="Cort";
    guitar.series ="ad810op";
    cout<<"MEREK GITAR : "<<guitar.merek<<endl;
    cout<<"SERIES GITAR: "<<guitar.series<<endl;

    cout<<"++STRUCT++\n";//deklarasi struct yang menampilkan senar dan ukuran senar
    senar steel{"Elixir",10};
    cout<<"MEREK SENAR : "<<steel.msenar<<endl;
    cout<<"UKURAN SENAR : "<<steel.ukuran<<endl;
    return 0;
}