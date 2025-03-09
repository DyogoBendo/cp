#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long
const int INF = 3e15 + 10;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int biggest = -INF;    
    for(int i = 0; i <n; i++){
        biggest = max(biggest, a[i] - b[i]);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(a[i] - b[i] == biggest) ans.push_back(i +1);
    }
    cout << ans.size() << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;

}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}