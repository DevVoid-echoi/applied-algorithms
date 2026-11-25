#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector <pair<int, int>> a(n);
    vector <pair<int, int>> res;
    for (auto& i: a){
        cin >> i.first >> i.second;
    }

    sort(a.begin(), a.end(), [](auto x, auto y){return x.second < y.second;});

        int last = INT_MIN;

    for(auto i: a){
        if (i.first >= last){
            last = i.second;
            res.push_back(i);
        }
    }
    
    cout << res.size() << endl;
    for(auto i: res){
        cout << "[" << i.first << ";" << i.second << "] ";
    }
}