#include <bits/stdc++.h>

using namespace std;

vector <int> a;

int leftMidMax(int p, int k){
    int ans = a[k], sum=0;
    for (int i=k; i>=p; i--){
        sum += a[i];
        ans = max(ans, sum);
    }
    return ans;
}

int rightMidMax(int m, int q){
    int ans = a[m], sum=0;
    for(int i=m; i<=q; i++){
        sum += a[i];
        ans = max(ans, sum);
    }
    return ans;
}

int subsequentMax(int p, int q){
    if (p==q) return a[p];
    int k = (p+q)/2;
    int wl = subsequentMax(p, k);
    int wr = subsequentMax(k+1, q);

    int wlm = leftMidMax(p, k);
    int wrm = rightMidMax(k+1, q);
    int wmm = wlm + wrm;

    int ans = max({wl, wr, wmm});
    return ans;
}

int main(){
    int n; cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << subsequentMax(0, n-1);
}