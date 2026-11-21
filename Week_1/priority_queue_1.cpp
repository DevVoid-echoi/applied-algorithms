#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue <int> pq;
    pq.push(10); pq.push(15); pq.push(5);
    while (!pq.empty()){
        int e = pq.top();
        pq.pop();
        cout << "PQ POP " << e << endl;
    }
}