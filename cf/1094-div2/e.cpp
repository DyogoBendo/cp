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

// insert x into s, return sz(s)
int insert(ll x){
    int ans;
    cout << "I " << x << endl;
    cin >> ans;
    return ans;
}

// query how many are >= y
int query(ll y){
    int ans;
    cout << "Q " << y << endl;
    cin >> ans;
    return ans;
}

void answer(ll k, ll c){
    cout << "A " << k << " " << c << endl;
}

void solve(){
    int n;
    cin >> n;

    cout << 0 << endl; // init set

    ll k, c;

    const ll INF = (1LL << n);

    int sz1 = insert(0);
    if(sz1 == 1){ // inserimos 0 de novo, logo era operação and
        k = 1;

        // vamos colocar o valor de c no set agora
        insert(INF - 1);

        ll lo = 1, hi = INF;

        while(lo < hi){
            ll mid = (hi - lo) / 2 + lo;

            // quantos caras são maiores do que o número que pedimos, se for 1 quer dizer que tem alguém maior que é o número que estamos procurando
            if(query(mid) == 1) lo = mid+1;
            else hi = mid;
        }
        c = hi-1;
    } else{
        ll lo = 1, hi = INF;
        
        while(lo < hi){
            ll mid = (hi - lo) / 2 + lo;
                    
            // quantos caras são maiores do que o número que pedimos, se for 1 quer dizer que tem alguém maior que é o número que estamos procurando
            if(query(mid) == 1) lo = mid+1;
            else hi = mid;
        }
        c = hi-1;

        if(c == INF - 1){
            int sz2 = insert(1);
            if(sz2 == 2) k = 2;
            else k = 3;            
        } else{
            // inserimos 11111...111 se for or vamos ter ele agora no vetor se for xor não
            insert(INF - 1);

            if(query((INF - 1))) k = 2;
            else k = 3;
        }
    }

    answer(k, c);
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}