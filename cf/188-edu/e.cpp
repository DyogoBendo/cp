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

const int MAX = 1e6;
int dp[MAX][10], digit_sum[MAX];

void init(){
    for(int i = 1; i < MAX; i++){
        int x = i;
        int curr = 0;
        while(x){
            int d = x%10;
            dp[i][d] ++;
            curr += d;
            x /= 10;
        }
        if(curr != i) for(int j = 0; j < 10; j++) dp[i][j] += dp[curr][j], digit_sum[i] = curr;
    }
}

void solve(){
    string s;
    cin >> s;

    if(sz(s) == 1){
        cout << s << endl;
        return;
    }

    int mx = 0;
    vector<int> cnt(10);
    for(int i = 0; i < sz(s); i++){
        mx += s[i] - '0';
        cnt[s[i] - '0']++;
    }

    for(int i = 1; i < mx; i++){
        vector<int> diff(10);
        bool possible = true;
        int sum = 0;
        for(int j = 0; j < 10 and possible; j++){
            if(dp[i][j] > cnt[j]){
                possible = false;
            }
            diff[j] = cnt[j] - dp[i][j];
            sum += diff[j] * j;
        }
        if(sum != i) possible = false;

        if(possible){
            for(int j = 1; j < 10; j++) for(int k = 0; k < diff[j]; k++) cout << j;
            for(int k = 0; k < diff[0]; k++) cout << 0;
            int curr = i;

            while(curr){
                cout << curr;
                curr = digit_sum[curr];
            }
            cout << endl;
            break;
        }
    }
}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}