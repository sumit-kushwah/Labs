#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main() {

    srand(time(0)); 
    cout << endl;
    cout << "**********************************************" << endl;
    cout << "      LRU Page replacement algorithm" << endl;
    cout << "**********************************************\n" << endl;
    // phyical memory size in terms of page frames
    int memory_size = 4;
    cout << "Enter Number of slots in Phyical Memory: ";
    // cin >> memory_size;
    
    int n = 10;
    cout << "Enter Page reference array size: ";
    // cin >> n;
    int pages[n];
    for (int i = 0; i < n; ++i) {
        pages[i] = rand() % 10;
        // cin >> pages[i];
    }

    cout << "\nRandom generated page reference array: \n";
    for (int i = 0; i < n; ++i) {
        cout << pages[i] << " ";
    }
    cout << endl;

    cout << "Page Replacements: \n" << endl;
    list<int> q;
    unordered_map<int, list<int>::iterator> umap;
    int page_faults = 0;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        // hit 
        if (umap.find(pages[i]) != umap.end()) {
            found = true;
            q.erase(umap[pages[i]]);
        } else {
            page_faults++;
            if (q.size() == memory_size) {
                int last = q.back();
                q.pop_back();
                umap.erase(last);
            }
        }
        q.push_front(pages[i]);
        umap[pages[i]] = q.begin();
        cout << pages[i] << " -> ";
        for (auto itr = q.begin(); itr != q.end(); itr++) {
            cout << *itr  << " ";
        }
        cout << " " << (found ? "(Hit)" : "(Miss)") << endl;
        cout << endl;
    }

    float hit_ratio = (float(n - page_faults) / float(n)) * float(100);
    cout << endl;
    cout << "Summary:" << endl;
    cout << endl;
    cout << "Number of page faults: " << page_faults << endl;
    cout << "Hit ratio " << fixed << setprecision(2) << hit_ratio << " %" << endl;
}

