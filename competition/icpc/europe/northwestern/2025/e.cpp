#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int mx=101;
int vis[mx][mx][mx];

ld comb(int k, int n){
    ld res = 1;
    for(int i = n; i > max(k, n-k); i--) res *= i;
    for(int i = min(k, n-k); i > 1;i--) res /= i;
    return res;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    array<int, 3> st = {0, 0, 0};
    for (auto c: s){
        if (c == 'r') st[0]++;
        else if (c == 'g') st[1]++;
        else st[2]++;
    }
    sort(all(st));

    cout << fixed << setprecision(13);
    if(st[1] == 0){
        cout << 0 << endl;
        return;
    }

    if(st[0] == 0){
        cout << 3*st[1] << endl;
        return;
    }    

    ld ans = 1.5*st[0];

    ld div = (1LL) << st[0];
    ld sum = 0; 
    for(int a = 0; a <= st[0]; a++){
        int b = st[1] + a;
        int c = st[2] + st[0] - a;

        sum += comb(a, st[0]) * 3.0 * min(b, c);
    }

    ans += sum/div;

    cout << ans << endl;

}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases=1;
    //cin >> cases;
    for (int tt=0; tt<cases; tt++) solve();
}