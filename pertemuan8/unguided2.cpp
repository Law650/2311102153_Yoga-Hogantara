#include <iostream>
#include <string>
using namespace std;

// MERIKSA HURUF VOKAL ATAU BUKAN
bool vokal(char huruf) {
    // MENGKONVERSI KE HURUF KECIL
    huruf = tolower(huruf);
    // MERIKSA HURUF TERMASUK HURUF VOKAL
    return (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u');
}

// MENGHITUNG BANYAKNYA HURUF VOKAL
int itungvokal(const string &kalimat) {
    int count = 0;
    for (char huruf : kalimat) {
        if (vokal(huruf)) {
            count++;
        }
    }
    return count;
}
int main() {
    string sentence;
    cout << "INPUT KALIMAT: ";
    getline(cin, sentence); // Membaca input kalimat dari pengguna

    int vokal2 = itungvokal(sentence);
    cout << "HURUF VOKAL YANG ADA PADA KALIMAT " << sentence <<" : "<< vokal2 << endl;

    return 0;
}