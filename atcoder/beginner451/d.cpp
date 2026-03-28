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

int cnt_num_dig(int x){
    int cnt = 0;
    while(x){
        x /= 10;
        cnt++;
    }    
    return cnt;
}

void solve(){
    int n;
    cin >> n;
    
    queue<pair<int, int>> q;
    q.push({0, 0});

    set<int> st;

    vector<int> num_dig(31);
    for(int i = 0; i <= 30; i++){        
        num_dig[i] = cnt_num_dig((1 << i));
    }

    vector<int> ten_pow(9);
    int p = 1;
    for(int i = 0; i < 9; i++){
        ten_pow[i] = p;
        p *= 10;
    }

    while(!q.empty()){
        auto [curr, d] = q.front(); q.pop();        

        for(int i = 0; i < 30; i++){
            int x = (1 << i);     

            if(d + num_dig[i] < 10){                
                int tmp;
                if(num_dig[i] == 9){
                    tmp = x;
                } else{
                    tmp = curr * ten_pow[num_dig[i]] + x;
                }

                if(!st.count(tmp)){
                    st.insert(tmp);
                    q.push({tmp, d + num_dig[i]});
                }
            }
        }
    }

    vector<int> ans(sz(st));
    int pos = 0;
    for(auto x : st){
        ans[pos++] = x;
    }    

    cout << ans[n-1] << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}