#include <bits/stdc++.h>

using namespace std;

int main(){
    set <int> s, k;
    for (int i=1; i<=10; i++){
        s.insert(i);
        k.insert(2*i);
    }
    set <int> :: iterator p, t;
    p = s.upper_bound(4);
    cout << "upper_bound(4) is " << *p << endl; 
    p = s.upper_bound(11);
    if (p == s.end()){
        cout << "upper_bound(10) is s.end()" << endl;
    }

    t = k.lower_bound(5);
    cout << "lower_bound(5) is " << *t << endl; 
    t = k.lower_bound(4);
        cout << "lower_bound(4) is " << *t << endl; 
    t = k.lower_bound(11);
    cout << "lower_bound(11) is s.end()" << endl; 
}
