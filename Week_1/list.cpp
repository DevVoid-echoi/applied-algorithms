#include <bits/stdc++.h>

using namespace std;

int main(){
    list <int> l;
    for (int i=1; i<=10; i++){
        l.push_back(i);
    }
    list <int> :: iterator p;
    p = l.begin();
    advance(p, 2);
    l.insert(p, 3, 9);
    for (p=l.begin(); p!=l.end(); p++) cout << *p << " ";
    cout << endl;
    auto first = l.begin();
    auto last = l.begin();
    advance(first, 2);
    advance(last, 5);
    l.erase(first, last);
    for (p=l.begin(); p!=l.end(); p++) cout << *p << " ";
}