#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int basicBinarySearch(vector <int> &a, int lo, int hi, int x){
    if (lo > hi) return -1;
    int mid = (lo+hi)/2;

    if (x==a[mid]) return mid;
    if (x<a[mid]) return basicBinarySearch(a, lo, mid-1, x);
    if (x>a[mid]) return basicBinarySearch(a, mid+1, hi, x);
    return -1;
}

int main(){
    int n; cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x; cin >> x;
    cout << basicBinarySearch(a, 0, n-1, x);
}