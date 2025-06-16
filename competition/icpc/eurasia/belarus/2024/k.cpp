#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> psum(n+1);
    for (int i = 0; i < n; i++)
    {
        psum[i+1] = psum[i] + v[i];
    }
            
    while(m--){
        int sd, sm, ed, em;
        cin >> sd >> sm >> ed >> em;

        if(ed >= sd && em == sm){
            cout << ed - sd + 1 << endl;
        } else if(em > sm){
            cout << psum[em-1] - psum[sm-1] - sd + ed + 1 << endl;
        } else{
            cout << psum[n] - psum[sm-1] - sd + psum[em-1] + ed + 1 << endl;
        }
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}