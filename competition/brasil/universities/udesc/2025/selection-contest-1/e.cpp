#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()


void solve(){
    int x, y;
    cin >> x >> y;

    int a = (x + y) / 2;
    int b = x - a;
    cout << a << " " << b << endl;

}

signed main(){
    fastio;
    int t=1;
    for (int i=0; i<t; i++) solve();
}