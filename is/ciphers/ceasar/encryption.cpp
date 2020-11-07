// this is cipher in which each character replaced by 3rd letter on

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plaintext;
    cout << "Enter plaintext(all character should be lowercase): ";
    cin >> plaintext;
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        int ss = plaintext[i];
        ss -= 97;
        ss = (ss + 3) % 26;
        ciphertext.push_back(s[ss]);
    }
    cout << "Ciphertext: ";
    cout << ciphertext << endl;

}