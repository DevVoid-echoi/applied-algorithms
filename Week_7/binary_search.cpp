#include <bits/stdc++.h>

using namespace std;

vector <int> a;

void binarySearch(vector <int> &a, int lo, int hi, int x){
    while (lo < hi){
        int mid = (lo+hi)/2;
        if (a[mid] < x){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    if (lo==hi && a[lo] >= x){
        cout << "The minimum index i such that a[i] >= " << x << " is " << lo << endl;
    }
    else{
        cout << "Cannot find a number that is greater than or equal to x";
    }
}

int main(){
    int n; cin >> n;
    a.resize(n);
    for (auto &i: a){
        cin >> i;
    }
    sort(a.begin(), a.end());

    int x; cin >> x;

    binarySearch(a, 0, n-1, x);
}