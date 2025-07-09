#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MAX = 55;

void print(deque<char> dq){
    for(int i = 0; i < sz(dq); i++){
        cout << dq[i];        
    } 
    cout << endl;
}

bool is_pal(deque<char> &s){
    for(int i = 0; i < sz(s) / 2; i++){
        if(s[i] != s[sz(s) - i - 1]) return false;
    }
    return true;
}

void solve(){
    string s;
    cin >> s;

    for(int i = min(sz(s), MAX); i > 0; i--){        
        map<deque<char>, int> st;
        deque<char> d, ans;
        for(int j = 0; j < sz(s); j++){
            d.push_back(s[j]);
            if(sz(d) > i) d.pop_front();

            if(sz(d) == i && is_pal(d)){
                int lst = st[d];                                
                if(lst){
                    if(lst <= j){
                        if(!sz(ans)) ans = d;                        
                        ans = min(ans, d);                                                
                    } 
                } else{
                    st[d] = i + j;
                }
            }
        }              
        if(sz(ans)){
            print(ans);
            return;
        }
    }
    cout << -1 << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}