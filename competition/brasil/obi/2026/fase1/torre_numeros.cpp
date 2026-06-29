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

    int n;
    cin >> n;
    
    set<int> st;
    
    auto get_value = [&](string s2){
        int tot = 0;
        int p = 1;
        for(int i = sz(s2) - 1; i >= 0; i--){
            tot += (s2[i] - '0') * p;
            p *= 10;
        }
        return tot;
    };
    
    auto convert = [&](int x){
        string ans = "";
        while(x){
            char c = (x % 10) + '0'; 
            ans = c + ans;
            x /= 10;
        }
        
        while(sz(ans) < 4) ans = '0' + ans;
        return ans;
    };
    
    string s = convert(n);
    auto calc = [&](string s2){
        sort(s2.rbegin(), s2.rend());
        string s3 = s2;
        sort(s3.begin(), s3.end());

        int a1 = get_value(s2);
        int a2 = get_value(s3);
        int a3 = a1 - a2;

        return a3;
    };

    while(1){
        if(st.count(n)) break;
        cout << n << endl;
        st.insert(n);

        n = calc(s);
        s = convert(n);
    }
}