#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_SIZE = 1e5 + 1;
const int MAX_VALUE = 2e9;

int valores[MAX_SIZE];
int n, m, l, r, minL, minR;

int check(int k){
    
    if(minL >= k) return 1;
    if(minR >= k) return 1;
    for (int i = 0; i < n - 1; i++)
    {

        int p1 = valores[i] + k;
        int p2 = valores[i + 1] - k;
        if((p1 < l || p1 > r) && (p2 < l || p2 > r)) continue;

        if(p1 <= p2) return 1;
    }

    return 0;
    
}

signed main(){
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        cin >> valores[i];
    }

    sort(valores, valores + n);    

    minL = MAX_VALUE;
    minR = MAX_VALUE;
    for (int i = 0; i < n; i++)
    {        
        minL = min(minL, abs(valores[i] - l));
        minR = min(minR, abs(valores[i] - r));
    }       

    int lo = 0;
    int hi = MAX_VALUE;

    while(lo < hi){        
        int mid = (hi - lo) / 2 + lo;

        if(check(mid)){
            lo = mid + 1;
        } else{
            hi = mid;
        }
    }
    
    lo --;
    cout << lo << endl;
    
}