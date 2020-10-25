#include<bits/stdc++.h>
using namespace std;

int findindex(deque<int> q, int query) {
    for (int i = 0; i < q.size(); ++i) {
        if (q[i] == query) {
            return i;
        }
    }
    return -1;
}

int main() {

    srand(time(0)); 
    cout << endl;
    cout << "**********************************************" << endl;
    cout << "      LRU Page replacement algorithm" << endl;
    cout << "**********************************************\n" << endl;
    // phyical memory size in terms of page frames
    int memory_size;
    cout << "Enter Number of slots in Phyical Memory: ";
    cin >> memory_size;
    
    int n;
    cout << "Enter Page reference array size: ";
    cin >> n;
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
    deque<int> q;
    int page_faults = 0;
    for (int i = 0; i < n; ++i) {
        int found = findindex(q, pages[i]);
        if (q.empty() || found == -1) {
            page_faults++;
            if (q.size() < memory_size) {
                q.push_back(pages[i]);
            } else {
                q.pop_front();
                q.push_back(pages[i]);
            }
        } else {
            int usedpage = q[found];
            q.erase(q.begin() + found);
            q.push_back(usedpage);
        }
        
        cout << pages[i] << " -> ";
        for (int i = 0; i < q.size(); ++i) {
            cout << q[i] << " ";
        }
        cout << " " << (found != -1 ? "(Hit)" : "(Miss)") << endl;
        cout << endl;
    }

    float hit_ratio = (float(n - page_faults) / float(n)) * float(100);
    cout << endl;
    cout << "Summary:" << endl;
    cout << endl;
    cout << "Number of page faults: " << page_faults << endl;
    cout << "Hit ratio " << fixed << setprecision(2) << hit_ratio << " %" << endl;
}