// this is cipher in which each character replaced by 3rd letter on

#include <bits/stdc++.h>
using namespace std;

string key = "NRXKJMLDWQBEIVPYSAFCZUHGTO"; // key is 26 character long
string decc = "abcdefghijklmnopqrstuvwxyz";

int main() {
    unordered_map<char, char> umap;
    for (int i = 0; i < 26; i++) {
        umap[key[i]] = decc[i];
    }

    string ciphertext;
    cout << "Enter ciphertext: ";
    cin >> ciphertext;
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext.push_back(umap[ciphertext[i]]);
    }
    cout << "Plaintext: ";
    cout << plaintext << endl;

}