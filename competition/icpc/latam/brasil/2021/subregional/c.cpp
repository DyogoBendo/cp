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

    ll b, l;
    cin >> b >> l;

    vector<ll> ds(l);
    for(int i = 0; i < l; i++) cin >> ds[i];

    vector<int> odd(b), even(b);
    for(int i = 0; i < b; i++) even[i] = (b*i) % (b + 1) ;
    for(int i = 0; i < b; i++) odd[i] = ((b * b % (b + 1)) * i) % (b + 1);

    vector<ll> pb(l+1);
    ll curr=1;
    ll tot = 0;
    for(int i = l-1; i >= 0; i--){
        pb[l - i - 1] = curr;
        tot += curr * ds[i];
        tot %= (b+1);

        curr = (curr * b) % (b+1);
    }

    dbg(tot);
    if(tot == 0){
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    dbg(curr);

    int parity = l & 1;
    int lst_o = 0, lst_e = 0;
    for(int i = 0; i < l; i++){
        if(parity){
            int found = -1;
            while(lst_o <= ds[i] and lst_o < b){
                if(odd[lst_o] == tot) found = lst_o;
                lst_o++;
            }
            if(found != -1){
                cout << (i+1) << " " << ds[i] - found << endl;
                return 0;
            }
        } else{
            int found = -1;
            while(lst_e <= ds[i] and lst_e < b){
                if(even[lst_e] == tot) found = lst_e;
                lst_e++;
            }
            dbg(i, lst_e, ds[i]);
            if(found != -1){
                cout << (i+1) << " " << ds[i] - found << endl;
                return 0;
            }
        }
        parity ^= 1;
    }
    
    cout << -1 << " " << -1 << endl;
}