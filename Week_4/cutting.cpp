#include <bits/stdc++.h>

using namespace std;

int H, W, n;
int h[20], w[20];
bool mark[100][100];
int found = 0;

void sizeOf(int k, int o, int &hk, int &wk){
    hk = h[k];
    wk = w[k];
    if (o==1){
        swap(hk, wk);
    }
}

bool check(int x, int y, int hk, int wk){
    if (x+wk > W || y+hk > H){
        return false;
    }
    for (int r=x; r < x+wk; r++){
        for (int c=y; c < y+hk; c++){
            if (mark[r][c] == true){
                return false;
            }
        }
    }
    return true;
}

void doMark(int x, int y, int hk, int wk, bool val){
    for(int r=x; r < x+wk; r++){
        for(int c=y; c < y+hk; c++){
            mark[r][c] = val;
        }
    }
}

void TRY(int k){
    for(int o=0; o<2; o++){
        if(o==1 && h[k]==w[k]){
            break;
        }
        int hk, wk;
        sizeOf(k, o, hk, wk);
        for(int x=0; x+wk <= W; x++){
            for(int y=0; y+hk <= H; y++){
                if (!check(x, y, hk, wk)){
                    continue;
                }
                doMark(x, y, hk, wk, true);
                if (k==n){
                    found += 1;
                    
                }
                else{
                    TRY(k+1);
                }
                doMark(x, y, hk, wk, false);
            }
        }
    }
}

int main(){
    cin >> H >> W >> n;
    int area = 0;
    for (int i=1; i<=n; i++){
        cin >> h[i] >> w[i];
        area += h[i] * w[i];
    }
    if (area > H * W){
        cout << 0;
        return 0;}
    TRY(1);
    cout << found;
}