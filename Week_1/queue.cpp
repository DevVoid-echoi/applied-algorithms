#include <bits/stdc++.h>

using namespace std;

int main(){
    queue <int> q;
    for (int i=1; i<=10; i++){
        q.push(i);
        cout << "QUEUE PUSH " << i << " ";
        cout << "QUEUE SIZE " << q.size() << endl;
    }
    while (!q.empty()){
        int e = q.front();
        q.pop();
        cout << "QUEUE POP " << e << " ";
        cout << "QUEUE SIZE " << q.size() << endl;
    }
}