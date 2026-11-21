#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    for(int i=3; i<=10; i++){
        a.push_back(i);
    }
    for (int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    a.erase(a.begin(), a.begin()+3);
    for (int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    } 
    cout << endl;
    return 0;
}