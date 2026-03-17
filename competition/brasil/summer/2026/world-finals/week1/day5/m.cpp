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

vector<int> divisors;

void init(){
    for(int i = 1; i <= 900; i++){
        if(900 % i == 0) divisors.push_back(i);
    }
}

void encode(){
    string s;
    cin >> s;

    int block_choice = sz(s) == 901 ? s.back() - 'a' +1: 0;

    int block_sz = divisors[block_choice];

    for(int i = 0; i < 900 / block_sz; i++){
        cout << s.substr(i*block_sz, block_sz) << endl;
    }
    cout << "#" << endl;
}

void decode(){
    string ans;
    string s;
    int l;
    do
    {
        l = sz(s);
        ans += s;
        cin >> s;    
    } while (s.back() != '#');    

    int pos;
    for(int i = 0; i < 27; i++){
        if(divisors[i] == l){
            pos = i;
            break;
        }
    }

    if(pos){    
        char c = ('a' + pos - 1);
        ans += c;
    }

    cout << ans << endl;
}

signed main(){
    init();
    darvem;
    string op;
    cin >> op;
    if(op == "encode") encode();
    else decode();
}