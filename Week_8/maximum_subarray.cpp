#include <bits/stdc++.h>

using namespace std;

long long a[100005];
long long mem[100005];
bool mark[100005];

long long maxSum(int v){
    if (v==1) return a[1];
    if (mark[v] == true) return mem[v];
    mark[v] = true;
    return mem[v] = max(a[v], a[v] + maxSum(v-1));
}

int main(){
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    maxSum(n);

    long long ans=a[1], pos=1;
    for(int i=2; i<=n; i++){
        if(ans<mem[i]){
            ans=mem[i];
            pos = i;
        }
    }
    cout << ans << endl;

    int left = pos, right = pos;
    long long sum = a[left];
    while (sum != ans){
        left--;
        sum += a[left];
    }
    cout << left << " " << right;
}