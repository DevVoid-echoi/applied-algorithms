#include <bits/stdc++.h>

using namespace std;

int main(){
    set <string> s;
    s.insert("abc");
    s.insert("def");
    s.insert("ghi");
    s.insert("def");

    set<string> :: iterator p;
    for (p=s.begin(); p!=s.end(); p++){
        cout << *p << " ";
    }
    cout << endl;
    string s1 = "def";
    string s2 = "abe";
    p = s.find(s2);
    if (p==s.end()){
        cout << "Không tìm thấy " << s2 << endl;
    }
    else {
        cout << "Tìm thấy " << s2 << endl;
    }
    s.erase(s1);
    for (p=s.begin(); p!= s.end(); p++){
        cout << *p << " ";
    }
}