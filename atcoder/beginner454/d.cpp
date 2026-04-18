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

string simplify(string &s){
    string ax, tmp;
    int state = -1;
    int cnt_open = 0;    
    int pos = 0;
    for(auto c : s){
        if(c == '('){
            if(state != 0){
                if(sz(tmp)) ax += tmp.substr(pos);                    

                cnt_open = 1;
                tmp = "(";            
            } else{
                cnt_open ++;
                tmp += "(";
            }
            pos = 0;
            state = 0;            
        } else if(c == 'x'){
            if(state == 0){
                state = 1;
                tmp += "x";

            } else if(state == 1){
                state = 2;
                tmp += "x";                
            } else{
                state = -1;
                if(sz(tmp)) ax += tmp.substr(pos);
                ax += "x";

                tmp = "";
                cnt_open = 0;
            }
            pos = 0;
        } else if(c == ')'){
            if(state == 2){                
                pos++;                
                cnt_open--;
                if(cnt_open == 0){
                    ax += "xx";
                    pos = 0;
                    tmp = "";
                    state = -1;                
                } 
            } else{
                if(sz(tmp)) ax += tmp.substr(pos);
                ax += ")";
                tmp = "";
                pos = 0;
                cnt_open = 0;
                state = -1;
            }
        }
    }
    if(sz(tmp)) ax += tmp.substr(pos);    
    return ax;
}

void solve(){
    string a, b;
    cin >> a >> b;

    string ax = simplify(a);
    string bx = simplify(b);

    dbg(ax, bx);

    if(ax == bx) cout << "Yes" << endl;
    else cout << "No" << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}