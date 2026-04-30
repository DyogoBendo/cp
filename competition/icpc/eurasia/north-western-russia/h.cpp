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


signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    while(n--){
        int h;
        cin >> h;        

        if(h % 4){
            cout << -1 << endl;
            continue;
        }

        int curr_k = k;

        vector<int> ans;
        while(h and curr_k > 1){
            for(int i = (curr_k+1); i >= 2; i--){
                int mn = (1 << i) * (i-2);
                int mx = (1 << i) * (i-1);

                if(i == curr_k+1) mx -= 4;

                if(h > mx){
                    h -= mx;
                    curr_k--;                   
                    ans.push_back((1 << i));
                    break;
                }

                if(mn <= h and h <= mx){
                    h = 0;
                    ans.push_back((1 << i));
                    break;
                }
            }            

        }
        if(h) cout << -1 << endl;
        else{
            cout << sz(ans);
            for(auto x : ans) cout << " " << x;
            cout << endl;
        }
    }
}