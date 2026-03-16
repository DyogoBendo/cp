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

bool is_numeric(string s){
    if(s[0] == '0') return false;
    for(int i = 0; i < sz(s); i++){
        if(s[i] < '0' or s[i] > '9') return false;
    }
    return true;
}

string transform(string a){
    if(!is_numeric(a)) return a;

    int cnt = 0;
    string ans = "";
    for(int i = sz(a) - 1; i >= 0; i --){
        if(cnt and cnt % 3 == 0) ans += "'";
        ans += a[i];
        cnt++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main(){
    darvem;
    string s;
    cin >> s;

    string a, b, c;
    int equal_pos = s.find('=');
    a = s.substr(0, equal_pos);
    s = s.substr(equal_pos+1);

    int plus_pos = s.find('+');
    b = s.substr(0, plus_pos);
    c = s.substr(plus_pos+1);

    cout << a + "=" << transform(b) << "+" << transform(c) << endl;
}