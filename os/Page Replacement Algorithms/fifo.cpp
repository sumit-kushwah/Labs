#include<bits/stdc++.h>
using namespace std;

bool find(deque<int> q, int query) {
    for (auto e : q) {
        if (e == query) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(0)); 

    cout << endl;
    cout << "**********************************************" << endl;
    cout << "      FIFO Page replacement algorithm" << endl;
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
        pages[i] = rand() % 9;
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
        bool found = find(q, pages[i]);
        if (q.empty() || !found) {
            page_faults++;
            if (q.size() < memory_size) {
                q.push_back(pages[i]);
            } else {
                q.pop_front();
                q.push_back(pages[i]);
            }
        }
        
        cout << pages[i] << " -> ";

        for (int i = 0; i < q.size(); ++i) {
            cout << q[i] << " ";
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