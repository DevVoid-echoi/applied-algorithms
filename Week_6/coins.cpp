#include <bits/stdc++.h>

using namespace std;

int main(){
    int value; cin >> value;
    vector <int> c(value);
    for (int &v: c){
        cin >> v;
    }
    int amount; cin >> amount;
    sort(c.rbegin(), c.rend());
    
    int res = amount; int num = 0;
    for (int x: c){
        num = res / x;
        res %= x;
        cout << x << ": " << num << endl;
    }
    if (res > 0){
        cout << "The rest: " << res;
    }
}