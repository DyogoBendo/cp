#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, k;
    
    int soma[5000001];
    soma[0] = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;        
        soma[i] = soma[i - 1] + x;
    }

    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int resp = upper_bound(soma+i, soma+n+1, soma[i-1] + k) - lower_bound(soma+i, soma+n+1, soma[i-1] + k);
        ans += resp;
    }    
    
    cout << ans << endl;
    
}