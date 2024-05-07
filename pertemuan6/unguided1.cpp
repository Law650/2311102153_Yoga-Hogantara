#include <iostream>
#include <string>
#include <stack>

using namespace std;

string ubahhuruf(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}
// MENENTUKAN PALINDROM
bool palindrom(string str) {
    stack<char> charStack;
    int length = str.length();

    for (int i = 0; i < length / 2; i++) {
        charStack.push(str[i]);
    }

    int start = length / 2;
    if (length % 2 != 0) {
        start++;
    }
    for (int i = start; i < length; i++) {
        if (charStack.empty() || str[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    char ulang;
    do {
        string kalimat;
        cout << "INPUT KATA ATAU KALIMAT : ";
        getline(cin, kalimat);

        string clearinput = ubahhuruf(kalimat);

        if (palindrom(clearinput)) {
            cout << "INPUTAN TERMASUK PALINDROM \n" ;
        } else {
            cout << "INPUTAN TERMASUK BUKAN PALINDROM \n" ;
        }

        cout << "ULANG ?? y/n";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');

    return 0;
}