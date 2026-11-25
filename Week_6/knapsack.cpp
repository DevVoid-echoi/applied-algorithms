#include <bits/stdc++.h>

using namespace std;

int n, b;
vector <pair<int, int>> items;

int greedy_1(){
    auto o1 = items;
    int load=0, val=0;
    sort(o1.begin(), o1.end(), [](auto&x, auto&y){return x.first > y.first;});
    for (auto& a: o1){
        if(a.second + load <= b){
            load += a.second;
            val += a.first;
        }
    }
    return val;
}

int greedy_2(){
    auto o2 = items;
    int load=0, val=0;
    sort(o2.begin(), o2.end(), [](auto& x, auto& y){return x.second < y.second;});
    for (auto& a: o2){
        if(a.second + load <= b){
            load += a.second;
            val += a.first;
        }
    }
    return val;
}

int greedy_3(){
    auto o3 = items;
    int load=0, val=0;
    sort(o3.begin(), o3.end(), [](auto& x, auto& y){return x.first * y.second > y.first * x.second;});
    for (auto& a: o3){
        if (a.second + load <= b){
            load += a.second;
            val += a.first;
        }
    }
    return val;
}

int main(){
    cin >> n >> b;
    items.resize(n);
    for (auto& [c, w]: items){
        cin >> c >> w;
    }
   
    int g1 = greedy_1(); int g2 = greedy_2();
    int g3 = greedy_3(); int g4 = max({g1, g2, g3});

    printf("Greedy1 (gia tri)    = %d\nGreedy2 (trong luong) = %d\nGreedy3 (C/W)        = %d\n"
           "Greedy4 (max)        = %d", g1, g2, g3, g4);
}