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

#define int long long

int read(){
    string s;
    cin >> s;
    int curr = 1;
    reverse(s.begin(), s.end());
    int tot = 0;
    for(int i = 0; i < sz(s); i++){
        if(s[i] == '.') continue;
        tot += curr * (s[i] - '0');
        curr*= 10;
    }
    return tot;
}

void print(int x){
    int cnt= 0;
    string ans = "";    
    while(x or cnt < 3){        
        cnt++;
        ans += to_string(x%10);
        if(cnt == 2) ans+='.';
        x/=10;
    }    
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
};

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = read();

    int tot = 0;
    for(int i = 0; i < n; i++) tot += v[i];

    int cnt3 = 0, cnt4 = 0;    
    for(int i = 0; i < n; i++){
        if(v[i]%5 <= 2) tot -= v[i] % 5;
        else if(v[i]%5 == 3) cnt3 ++;
        else cnt4++;
    }    

    int mn = min(cnt3, cnt4);
    tot -= 2*(mn);
    cnt3 -= mn;
    cnt4 -= mn;
    
    tot -= cnt4/3 * 2;
    tot -= cnt3/2;  
    

    print(tot);
}