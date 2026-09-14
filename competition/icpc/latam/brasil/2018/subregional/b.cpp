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

const int N = 101;
const int INF = 3*N;
int dp[N][N];

signed main(){
    darvem;

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(i == 0 or j == 0 or i == j) dp[i][j] = INF;
            else{
                vector<int> mex(INF + 1);
                for(int k = 0; k < i; k++) mex[dp[k][j]] = 1;
                for(int k = 0; k < j; k++) mex[dp[min(i, k)][max(i, k)]] = 1;                
                for(int k = 1; k <= i; k++) mex[dp[i - k][j - k]] = 1;                

                int curr=0;
                while(mex[curr]) curr++;
                dp[i][j] = curr;
            }
        }
    }

    int n;
    cin >> n;

    int ans = 0;

    bool won = false;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        if(a > b) swap(a, b);
        if(dp[a][b] == INF) won = true;
        else ans ^= dp[a][b];                
    }    

    cout << ((ans or won) ? "Y" : "N") << endl;
}