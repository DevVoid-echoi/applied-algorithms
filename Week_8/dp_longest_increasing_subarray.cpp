#include <bits/stdc++.h>

using namespace std;

long long a[100005], mem[100005];

int lis(int i){
    if(mem[i] != -1) return mem[i];

    int res = 1;
    for(int j=1; j<i; j++){
        if (a[j] < a[i]){
            res = max(res, 1 + lis(j));
        }
    }
    
    return mem[i] = res;
}

void trace(int i){
    for (int j=i-1; j>=1; j--){
        if (a[j] < a[i] && lis(i) == 1+lis(j)){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    memset(mem, -1, sizeof(mem));
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    int ans = 0; int pos = 0;
    for (int i=1; i<=n; i++){
        lis(i);
        if (ans < mem[i]){
            ans = mem[i];
            pos = i;
        }
    }
    cout << ans << endl;
    trace(pos);
}