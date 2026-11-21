#include <bits/stdc++.h>

using namespace std;

int main(){
    string s = "hello";
    string k = s + " world !";
    cout << k << endl;
    string k1 = k.substr(0, 5);
    string k2 = k.substr(4, 7);
    cout << k1 << endl << k2 << endl;
    string t1 = k.replace(6, 7, "abc");
    cout << t1 << endl << k;
}