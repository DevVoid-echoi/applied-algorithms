#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int MINVAL = -1e9;

int n, a[MAXN], maxVal[4*MAXN];

void build(int id, int l, int r){
    if(l==r){
        maxVal[id] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(2*id, l, m);
    build(2*id+1, m+1, r);
    maxVal[id] = max(maxVal[2*id], maxVal[2*id+1]);
}

int getMaxNode(int id, int l, int r, int i, int j){
    if (i>r || j<l){
        return MINVAL;
    }
    else if (i<=l && j>=r){
        return maxVal[id];
    }
    int m = (l+r)/2;
    return max(getMaxNode(2*id, l, m, i, j), getMaxNode(2*id+1, m+1, r, i, j));
}

void updateFromNode(int id, int l, int r, int idx, int v){
    if (idx < l || idx > r){
        return;
    }
    else if (l==r){
        maxVal[id] = v;
        return;
    }
    int m = (l+r)/2;
    updateFromNode(2*id, l, m, idx, v);
    updateFromNode(2*id+1, m+1, r, idx, v);
    maxVal[id] = max(maxVal[2*id], maxVal[2*id+1]);
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    int m;
    cin >> m;
    while (m--){
        string cmd;
        int x, y;
        cin >> cmd >> x >> y;
        if (cmd == "u"){
            updateFromNode(1, 1, n, x, y);
        }
        else{
            cout << getMaxNode(1, 1, n, x, y) << "\n";
        }
    }
}