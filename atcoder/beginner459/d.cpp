#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = sz(s);

    int cnt_odd = n/2;
    int cnt_even = n - cnt_odd;

    vector<int> cnt(26);

    for(int i = 0; i < n; i++){
        cnt[s[i] - 'a']++;
    }
    vector<char>ans(n);

   priority_queue<pair<int, int>> pq;
   for(int i = 0; i < 26; i++) if(cnt[i]) pq.push({cnt[i], i});

   int lst = -1;
   int curr = 0;
   while(!pq.empty()){
        auto [c, i] = pq.top(); pq.pop(); 
        if(pq.empty()){
            if(i == lst) {
                cout << "No" << endl;
                return;
            }
            ans[curr++] = i+'a';
            if(c > 1) pq.push({c-1, i});
            lst = i;
        } else{
            auto [c2, i2] = pq.top(); pq.pop();
            if(i == lst){
                swap(i2, i);
                swap(c2, c);                                
            }
            ans[curr++] = i + 'a';
            if(c > 1) pq.push({c -1, i}) ;
            lst = i;
            pq.push({c2, i2});
        }
   }

    cout << "Yes" << endl;
    for(auto c : ans) cout << c;
    cout << endl;
}

signed main(){
    darvem;
    
    int t;
    cin >> t;
    while(t--)solve();

}