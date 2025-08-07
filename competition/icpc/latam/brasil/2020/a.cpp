#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()


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

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    double p = (1.0) /( double (b - a + 1)); 
    vector<double> dp1(n+1), dp2(n+1);    
    double curr = 1;
    if(a == 0){
        for(int i = 1; i<= n; i++){
            dbg(dp1[i-1-b], i-1-b);
            if(i > b) dp2[i] = dp2[i-1] - dp1[i-1-b] + dp1[i - a - 1];
            else if(i >= a) dp2[i] = dp2[i-1] + dp1[i-a-1];
            
            dp1[i] = (dp2[i] + (b - a + 1)) / (b-a);
            dbg(i, dp2[i], dp1[i]);
        }
    } else{
        for(int i = 1; i<= n; i++){
            dbg(dp1[i-1-b], i-1-b);
            if(i > b) dp2[i] = dp2[i-1] - dp1[i-1-b] + dp1[i - a];
            else if(i >= a) dp2[i] = dp2[i-1] + dp1[i-a];
            
            dp1[i] = (dp2[i]) / (b-a+1) + 1;
            dbg(i, dp2[i], dp1[i]);
        }
    }

    cout << setprecision(12) << dp1.back() << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}