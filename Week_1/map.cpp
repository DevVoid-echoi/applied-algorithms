#include <bits/stdc++.h>

using namespace std;

int main(){
    map <string, int> m;
    m["abc"] = 1;
    m["def"] = 2;
    m["ghi"] = 3;
    string s1 = "abc";
    cout << "Value of key " << s1 << " is " << m[s1] << endl;
    map <string, int> :: iterator p;
    for (p=m.begin(); p!=m.end(); p++){
        cout << "Value of key " << p->first << " is " << p->second << endl;
    }
    string s2 = "xyz";
    cout << "Value of key " << s2 << " is " << m[s2] << endl; // Nếu chưa có sẽ gán cặp key, value mới

    string s3 = "mno";

   p = m.begin();
   p->second = 5;
   for (p=m.begin(); p!=m.end(); p++){
        cout << "Value of key " << p->first << " is " << p->second << endl;
    }

    p = m.find(s3);
    if (p!=m.end()){
        cout << p-> second;
    }
    else {
        cout << "Không tìm thấy " << s3;
    }
}