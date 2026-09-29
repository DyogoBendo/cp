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

const int MOD = 1e9 + 7;
const int S = 5001;
const int B = 5001;

int dp[B][S];

signed main(){
    darvem;        
    int s, b;
    cin >> s >> b;      
    
    for(int j = 1; j <= s; j++){
        dp[0][j] = 1;
    }

    for(int i = 1; i <= b - s; i++){
        int sum_diag = 0;
        for(int j = 1; j <= s; j++){       
            if(i >= j) sum_diag = (sum_diag + dp[i-j][j]) % MOD;
            dp[i][j] = (dp[i][j - 1] + sum_diag) % MOD;            
        }        
    }        

    cout << ( b - s >= 0 ? dp[b-s][s] : 0) << endl;
}