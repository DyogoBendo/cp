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
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){cin >> v[i];}         

    int tot = 0;
    for(int i = 0; i < n; i++) tot += v[i];    

    if(tot % 2){
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> pdp(n+1, vector<int>(tot + 1));
    vector<vector<int>> sdp(n+1, vector<int>(tot + 1));

    pdp[0][0] = true;    
    for(int i = 0; i < n; i++){        
        pdp[i+1] = pdp[i];
        for(int j = tot - v[i]; j >= 0; j--){
            pdp[i+1][j + v[i]] |= pdp[i][j]; 
        }        
    }

    sdp[n][0] = true;
    for(int i = n-1; i >= 0; i--){        
        sdp[i] = sdp[i + 1];
        for(int j = tot - v[i]; j >= 0; j--){
            sdp[i][j + v[i]] |= sdp[i+1][j]; 
        }        
    }
    
    if(!pdp[n][tot/2]) cout << 0 << endl;
    else{
        cout << 1 << endl;
        for(int i = 0; i < n; i++){
            int s= tot - v[i]; // soma total 
            if(s % 2){
                cout << i+1 << endl;
                return;
            }

            bool possible = true;            
            for(int j = 0; j <= s / 2; j++){                
                if(pdp[i][j] && sdp[i+1][s/2 - j]) possible = false;
            }
            if(possible){
                cout << i+1 << endl;
                return;
            }
        }
    }
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}