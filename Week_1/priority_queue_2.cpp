#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main(){
    priority_queue <pii> default_pq;
    default_pq.push(make_pair(9, -50)); default_pq.push(make_pair(3, 4)); default_pq.push(make_pair(10, -900));
    while (!default_pq.empty()){
        pii e = default_pq.top();
        default_pq.pop();
        cout << "(" << e.first << ", " << e.second << ")" << endl;
    }

    cout << endl;

    priority_queue <pii, vector<pii>, greater<pii>> decreased_pq;
    decreased_pq.push(make_pair(9, -50)); decreased_pq.push(make_pair(3, 4)); decreased_pq.push(make_pair(10, -900));
    while (!decreased_pq.empty()){
        pii e = decreased_pq.top();
        decreased_pq.pop();
        cout << "(" << e.first << ", " << e.second << ")" << endl;
    }
}