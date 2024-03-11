<<<<<<< HEAD
#include <iostream>
#include <map>//agar map dapat berjalan

using namespace std;

int main(){
    //map. int untuk kunci dan string untuk merek gitar
    map <int,string> gitar;
    gitar[1]="Yamaha";
    gitar[2]="Fender";
    gitar[3]="Squire";
    gitar[4]="Gibson";

    //for untuk menampilkan nomor dan kunci dari map
    for(int y = 1;y<=gitar.size();y++){
        cout<<y<<"."<<gitar[y]<<endl;
    }
return 0;
=======
#include <iostream>
#include <map>//agar map dapat berjalan

using namespace std;

int main(){
    //map. int untuk kunci dan string untuk merek gitar
    map <int,string> gitar;
    gitar[1]="Yamaha";
    gitar[2]="Fender";
    gitar[3]="Squire";
    gitar[4]="Gibson";

    //for untuk menampilkan nomor dan kunci dari map
    for(int y = 1;y<=gitar.size();y++){
        cout<<y<<"."<<gitar[y]<<endl;
    }
return 0;
>>>>>>> 8cdf8a82430e4374359c0ac436634c2dcb89ba83
}