#include<bits/stdc++.h>
#include<unordered_map>
#include<cstring>
using namespace std;

const string key = "goodday";

// key must be less than or equal to 25 letters
vector<vector<char> > polyfairSquare(string key) {
    vector<vector<char> > vv;
    vector<char> temp;
    unordered_map<char, bool> umap;
    string abc = "abcdefghiklmnopqrstuvwxyz";
    string tkey = key + abc;
    string newkey;
    for (int i = 0; i < tkey.size(); i++) {
        if (tkey[i] == 'j')
            tkey[i] = 'i';
        if (umap.find(tkey[i]) == umap.end()) {
            umap[tkey[i]] = true;
            newkey.push_back(tkey[i]);
        }
    }

    int c = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp.push_back(newkey[c++]);
        }
        vv.push_back(temp);
        temp.clear();
    }

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << vv[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return vv;
}

unordered_map<char, pair<int, int> > letterRowAndCol(vector<vector<char> > vv) {
    unordered_map<char, pair<int, int> > umap;
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            if (vv[i][j] == 'j')
                vv[i][j] = 'i';
            umap[vv[i][j]] = make_pair(i, j);
        }
    }
    return umap;
} 

vector<vector<char> > sq;
unordered_map<char, pair<int, int> > rcmap;

string getCipherPair(char a, char b) {
    string cipherpair = "";  

    pair<int, int> pa = rcmap[a];
    pair<int, int> pb = rcmap[b];

    if (pa.first == pb.first) {
        // row is same
        cipherpair.push_back(sq[pa.first][(pa.second + 1) % 5]);
        cipherpair.push_back(sq[pb.first][(pb.second + 1) % 5]);
    } else if (pa.second == pb.second) {
        // col is same
        cipherpair.push_back(sq[(pa.first + 1) % 5][pa.second]);
        cipherpair.push_back(sq[(pb.first + 1) % 5][pb.second]);
    } else {
        // row and col not same
        cipherpair.push_back(sq[pa.first][pb.second]);
        cipherpair.push_back(sq[pb.first][pa.second]);
    }
    return cipherpair;   
}

string getCiphertext(string plaintext) {
    string ciphertext = "";
    if (plaintext.length() & 1)
        plaintext += "x"; // if odd length plaintext string 
    
    for (int i = 0; i < plaintext.length(); i += 2) {
        char a = plaintext[i];
        char b = plaintext[i + 1];
        if (a == b) {
            ciphertext += getCipherPair(a, 'x');
            ciphertext += getCipherPair(b, 'x');
        } else {
            ciphertext += getCipherPair(a, b);
        }
    }

    return ciphertext;
}

string uppercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}
int main() {
    sq = polyfairSquare(key);
    rcmap = letterRowAndCol(sq);

    string plaintext;
    cout << "Enter plaintext: ";
    cin >> plaintext;
    cout << uppercase(getCiphertext(plaintext));
    return 0;
}