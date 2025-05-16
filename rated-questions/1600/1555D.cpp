#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXN = 2e5 + 10;

int prefixList[6][MAXN];

void solve(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    string base = "abc";
    int cnt = 0;
    do
    {
        for (int i = 0; i < n; i++)
        {
            prefixList[cnt][i+1] = prefixList[cnt][i] + (base[i%3] != s[i]);
        }
        cnt++;
    } while (next_permutation(base.begin(), base.end()));
    

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        int ans= n;
        for (int i = 0; i < 6; i++)
        {
            ans = min(ans, prefixList[i][r] - prefixList[i][l]);
        }
    
        cout << ans << endl;
    }
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}