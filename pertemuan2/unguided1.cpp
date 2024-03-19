//Yoga Hogantara 2311102153
#include <iostream>

using namespace std;

int main()
{
    int bil_153[10];
    
    cout<<"INPUT DATA ARRAY \n";//MENGINPUT ARRAY
    for(int y=1;y<=10;y++){
        cout<<"DATA ARRAY  "<<y<<" : ";
        cin>>bil_153[y];
    }
    cout<<endl;

    cout<<"DATA ARRAY : ";//MENAMPILKAN ARRAY
    for(int y=1;y<=10;y++){
        cout<<bil_153[y]<<" ";
    }
    cout<<endl;
    cout<<"Bilangan Genap : ";//MENCARI BILANGAN GENAP
    for(int y=1;y<=10;y++){
        if(bil_153[y]%2==0){
            cout<<bil_153[y]<<",";
        }
    }
    cout<<endl;

    cout<<"Bilangan Gajil : ";//MENCARI BILANGAN GANJIL
    for(int y=1;y<=10;y++){
        if(bil_153[y]%2!=0){
            cout<<bil_153[y]<<",";
        }
    }

return 0;
}
