#include <bits/stdc++.h>

using namespace std;

int a[101];

int main(){
    for (int i=0; i<=100; i++){
        a[i] = i;
    }
    int i = a[0];
    int j = a[100];

    int sum;
    cin >> sum;
    int res = 0;

    while (i<j){
        if (a[i] + a[j] == sum){
            res++;
            i++; j--;
        }
        else if(a[i] + a[j] < sum){
            i++;
        }
        else if(a[i] + a[j] > sum){
            j--;
        }
    }
    cout << res;
}