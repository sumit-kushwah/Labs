#include<bits/stdc++.h>
using namespace std;
typedef priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> >  PQ;

void showpq(PQ pq) {
     while(!pq.empty()) {
        cout << "(" << pq.top().first << " " << pq.top().second << ") ";
        pq.pop();
    }
}

int sites_count;

vector<PQ> sites_queue;

int timestamp = 1;

map<int, int> site_timestamp;

int checkCriticalSection() {
    int site_id = 0;
    for (int i = 0; i < sites_count; i++) {
        if (sites_queue[i].empty()) {
            return 0;
        }
        if (i > 0 && sites_queue[i].top().first != sites_queue[i - 1].top().first) {
            return 0;
        } else {
            site_id = sites_queue[i].top().second;
        }
    }
    return site_id;
}

void release(int site_id) {
    for (int i = 0; i < sites_count; i++) {
        sites_queue[i].pop();
        site_timestamp.erase(site_id);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cout << "Enter number of sites or processes: "; cin >> sites_count; 
    sites_queue.resize(sites_count);
    
    while(true) {
        cout << endl;
        int from_site, to_site;
        cout << "Enter request" << endl;
        cout << "from: "; cin >> from_site; cout << "to: "; cin >> to_site;
        cout << endl;
        if (site_timestamp.find(from_site) == site_timestamp.end()) {
            site_timestamp[from_site] = timestamp;
            sites_queue[from_site - 1].push(make_pair(timestamp, from_site));
            sites_queue[to_site - 1].push(make_pair(timestamp, from_site));
            timestamp++;
        } else {
            sites_queue[to_site - 1].push(make_pair(site_timestamp[from_site], from_site));
        }

        while(checkCriticalSection()) {
            int site_id = checkCriticalSection();
            cout << "Site " << site_id << " can enter in critical section." << endl;
            cout << "Sending release request to all other sites...." << endl;
            release(site_id);
            cout << "Release completed successfully." << endl;
        }

        cout << "Sites Queue status" << endl;
        for (int i = 0; i < sites_count; i++) {
            cout << i + 1 << ": ";
            showpq(sites_queue[i]);
            cout << endl;
        }

    }

    return 0;
}