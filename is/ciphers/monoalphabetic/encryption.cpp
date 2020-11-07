// this is cipher in which each character replaced by 3rd letter on
// this is substitution cipher

#include <bits/stdc++.h>
using namespace std;

int main() {
    string key = "NRXKJMLDWQBEIVPYSAFCZUHGTO"; // key is 26 character long
    string plaintext;
    cout << "Enter plaintext(all character should be lowercase): ";
    cin >> plaintext;
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        int ss = plaintext[i];
        ss -= 97;
        ciphertext.push_back(key[ss]);
    }
    cout << "Ciphertext: ";
    cout << ciphertext << endl;

}