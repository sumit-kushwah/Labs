#include<bits/stdc++.h>
#include<unordered_map>
#include<cstring>
using namespace std;

const string key = "goodday";

string lowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

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

string getPlainPair(char a, char b) {
    string plainpair = "";  

    pair<int, int> pa = rcmap[a];
    pair<int, int> pb = rcmap[b];

    if (pa.first == pb.first) {
        // row is same
        plainpair.push_back(sq[pa.first][(pa.second + 4) % 5]);
        plainpair.push_back(sq[pb.first][(pb.second + 4) % 5]);
    } else if (pa.second == pb.second) {
        // col is same
        plainpair.push_back(sq[(pa.first + 4) % 5][pa.second]);
        plainpair.push_back(sq[(pb.first + 4) % 5][pb.second]);
    } else {
        // row and col not same
        plainpair.push_back(sq[pa.first][pb.second]);
        plainpair.push_back(sq[pb.first][pa.second]);
    }
    return plainpair;   
}

string getPlaintext(string ciphertext) {
    ciphertext = lowercase(ciphertext);
    string plaintext = "";
    
    for (int i = 0; i < ciphertext.length(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        plaintext += getPlainPair(a, b);
    }

    return plaintext;
}

int main() {
    sq = polyfairSquare(key);
    rcmap = letterRowAndCol(sq);

    string ciphertext;
    cout << "Enter ciphertext: ";
    cin >> ciphertext;
    cout << getPlaintext(ciphertext);
    return 0;
}