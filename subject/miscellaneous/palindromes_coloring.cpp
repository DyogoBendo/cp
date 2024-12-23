#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> qtd(26, 0);

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        qtd[s[i] - 'a'] ++;
    }

    int pairs = 0;

    for (int i = 0; i < 26; i++)
    {
        pairs += qtd[i] / 2;
    }

    pairs <<= 1;    
    
    int mn = pairs / k;

    if((mn + 1) * k <= n && mn % 2 == 0) mn ++;

    cout << mn << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}