#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string clearwords(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}
//MEMBALIKAN KALIMAT
string reversewords(string kalimat) {
    stack<char> Karakter;
    string pembalikkalimat;

    kalimat = clearwords(kalimat);

    for (char c : kalimat) {
        if (c != ' ') {
            Karakter.push(c);
        } else {
            while (!Karakter.empty()) {
                pembalikkalimat += Karakter.top();
                Karakter.pop();
            }
            pembalikkalimat += ' ';
        }
    }

    while (!Karakter.empty()) {
       pembalikkalimat += Karakter.top();
        Karakter.pop();
    }

    return pembalikkalimat;
}

int main() {
    string sentence;
    char lanjut;

    do {
        cout << "INPUT MIN 3 KATA : \n";
        getline(cin, sentence);

        int jmlhspasi = count(sentence.begin(), sentence.end(), ' ');
        int jmlhkata = jmlhspasi + 1;

        if (jmlhkata < 3) {
            cout << "MIN 3 KATA WOOY!!!!!!!\n" ;
        } else {
            string pembalikkalimat = reversewords(sentence);
            cout << "KALIMAT TERBALIKK: " << pembalikkalimat << endl; 
        }
        cout << endl;
        cout << "MAU LAGI??????????????????????? (y/n): ";
        cin >> lanjut;
        cin.ignore();
    } 
    while (lanjut == 'y' || lanjut == 'Y');
    cout << "TY CUY\n";

    return 0;
}