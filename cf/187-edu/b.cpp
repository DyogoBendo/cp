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

int sum_digits(ll x){
    int sum = 0;

    while(x){
        int d = x % 10L;
        sum += d;
        x /= 10;
    }
    return sum;
}

bool is_beatiful(ll x){
    int s = sum_digits(x); 
    return s == sum_digits(s);
}

void solve(){
    ll x;
    cin >> x;

    vector<int> can_remove;
    int s = 0;
    while(x){
        int d = x % 10L;
        if(x >= 10) can_remove.push_back(d);
        else can_remove.push_back(d-1);
        s += d;
        x /= 10;
    }    

    sort(can_remove.begin(), can_remove.end());
    int ans = 0;
    while(s > 9){
        s -= can_remove.back();
        can_remove.pop_back();
        ans++;

    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}