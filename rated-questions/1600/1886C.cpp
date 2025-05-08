#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    string s;
    cin >> s;

    int p;
    cin >> p;

    int k = 0, sz = (ll) s.size();
    while(sz < p){
        k++;
        p -= sz;
        sz--;
    }
    
    stack<int> st;
    st.push(0);
    int r = 1;
    sz = s.length();
    while(k && r < sz){
        if(!st.empty() && s[st.top()] > s[r]){
            s[st.top()] = '#';
            st.pop();
            k --;
        } else{            
            st.push(r);
            r ++;            
        }
    }            
    int cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        if(s[i] != '#'){
            cnt ++;
            if(cnt == p){
                cout << s[i];
                break;
            } 
        }
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
    cout << endl;
}