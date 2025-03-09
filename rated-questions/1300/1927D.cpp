#include <bits/stdc++.h>

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &x : v) cin >> x;

    int cnt = 0;
    vector<int> groups(n, 0);
    vector<int> st;
    st.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if(v[i] != v[i - 1]){
            cnt++;
            st.push_back(i);
        } 
        groups[i] = cnt;
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        
        l--; r--;        

        int a = groups[l];
        int b = groups[r];

        if(a == b){
            cout << -1 << " " << -1 << endl;
        } else{
            if(v[l] == v[r]){                          
                cout << st[a+1] + 1 << " " << r + 1 << endl;
            } else{
                cout << l + 1 << " " << r + 1 << endl;
            }
        }
    }
    cout << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}