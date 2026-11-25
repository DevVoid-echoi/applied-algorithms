#include <bits/stdc++.h>

using namespace std;

vector <int> a;

void merge(vector <int> &a, int p, int q, int r){
    int i=p, j=q+1;
    vector <int> tmp;
    while(i<=q && j<=r){
        tmp.push_back((a[i] <= a[j]) ? a[i++]: a[j++]);
    }
    while(i<=q){
        tmp.push_back(a[i++]);
    }
    while(j<=r){
        tmp.push_back(a[j++]);
    }
    for (int k=0; k<tmp.size(); k++){
        a[p+k] = tmp[k];
    }
}

void merge_sort(vector <int> &a, int p, int r){
    if (p>=r) return;
    int q = (p+r)/2;
    merge_sort(a, p, q);
    merge_sort(a, q+1, r);
    merge(a, p, q, r);
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    merge_sort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}