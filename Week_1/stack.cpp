# include <bits/stdc++.h>

using namespace std;

int main(){
    stack <int> s;
    for (int i=1; i<=10; i++){
        s.push(i);
        cout << "STACK PUSH " << i << " ";
        cout << "STACK SIZE " << s.size() << endl;
    }
    while (!s.empty()){
        int e = s.top();
        s.pop();
        cout << "STACK POP " << e << " ";
        cout << "STACK SIZE " << s.size() << endl;
    }
}