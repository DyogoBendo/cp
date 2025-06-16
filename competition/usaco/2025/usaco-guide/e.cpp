#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int n;
int check(vector<int> &v, int idx){
    int s, b;
    int sz = 0;
    int mx_idx = n+1;
    for (int i = 0; i < n; i++)
    {
        if(i == idx) continue;
        if(sz == 0){
            s = v[i];
            b = v[i];
        }
        if(v[i] <= s){
            if(v[idx] <= s && v[idx] > v[i]) mx_idx= i;
            s = v[i];            
        } else if(v[i] >= b){
            if(v[idx] >= b && v[idx] < v[i]) mx_idx = i;
            b = v[i];
        } else{
            return 0;
        }
        sz++;
    }    
    return idx < mx_idx;
}

void solve(){
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, check(v, i));
    }
    
    cout << (ans ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}