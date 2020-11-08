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
string plaintext;
string ciphertext = "";

string uppercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

char substitute(char plainchar, char keychar) {
    int asc = ((int (plainchar) + int (keychar) - 194) % 26) + 97;
    return char(asc);
}

int main() {
    cout << "Enter plaintext(lowercase): ";
    cin >> plaintext;
    for (int i = 0; i < plaintext.length(); i++) {
        ciphertext.push_back(substitute(plaintext[i], key[i % keylen]));
    }
    cout << uppercase(ciphertext) << endl;
    return 0;
}