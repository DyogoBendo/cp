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
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s[0] == 'a' or s[0] == 'b' or s[0] == 'c') cout << 2;
        else if(s[0] == 'd' or s[0] == 'e' or s[0] == 'f') cout << 3;
        else if(s[0] == 'g' or s[0] == 'h' or s[0] == 'i') cout << 4;
        else if(s[0] == 'j' or s[0] == 'k' or s[0] == 'l') cout << 5;
        else if(s[0] == 'm' or s[0] == 'n' or s[0] == 'o') cout << 6;
        else if(s[0] == 'p' or s[0] == 'q' or s[0] == 'r' or s[0] == 's') cout << 7;
        else if(s[0] == 't' or s[0] == 'u' or s[0] == 'v') cout << 8;        
        else cout << 9;
    }
    cout << endl;
}