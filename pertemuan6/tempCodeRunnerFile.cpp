#include <iostream>
#include <stack>
#include <string>

using namespace std;

//  menentukan kalimat polindrom
bool polindrom(string kalimat_153) {
    stack<char> stackchar;

    // INPUT KE STACK
    for (char &c : kalimat_153) {
        stackchar.push(c);
    }

    // BANDINGKAN KARAKTER
    while (!stackchar.empty()) {
        char topChar = stackchar.top();
        stackchar.pop();
        if (topChar != kalimat.front()) {
            return false; // JIKA BEDA BUKAN POLINDROM
        }
        kalimat_153.erase(0, 1); // HAPUS KARAKTER PERTAMA
    }

    return true;
}

int main() {
    string kalimat_153;

    while (true) {
        cout << "INPUT KALIMAT: ";
        getline(cin, kalimat_153);

        if (kalimat_153 == "0") {
            break;
        }
        if (polindrom(kalimat_153)) {
            cout << "KALIMAT TERSEBUT POLINDROM\n" ;
        } else {
            cout << "KALIMAT  TERSEBUT BUKAN PLINDROM\n" ;
        }
    }

    return 0;
}