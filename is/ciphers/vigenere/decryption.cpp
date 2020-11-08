/*
    it is simplest polyalphabetic substitution cipher
    i am using convention that plaintext is written in lowercase AND
    ciphertext should be written in upper case
    it makes cryptoanalysis hard 
*/

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

string key = "deceptive";
int keylen = key.length();
string plaintext = "";
string ciphertext;

string lowercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

char substitute(char cipherchar, char keychar) {
    int asc = ((int (cipherchar) - int (keychar) + 26) % 26) + 97;
    return char(asc);
}

int main() {
    cout << "Enter ciphertext: ";
    cin >> ciphertext;
    ciphertext = lowercase(ciphertext);
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext.push_back(substitute(ciphertext[i], key[i % keylen]));
    }
    cout << plaintext << endl;
    return 0;
}