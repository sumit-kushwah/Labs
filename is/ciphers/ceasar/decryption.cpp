// this is cipher in which each character replaced by 3rd letter on

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    string ciphertext;
    cout << "Enter ciphertext: ";
    cin >> ciphertext;
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        int ss = ciphertext[i];
        ss -= 65;
        ss = (ss - 3 + 26) % 26;
        plaintext.push_back(s[ss]);
    }
    cout << "Plaintext: ";
    cout << plaintext << endl;

}