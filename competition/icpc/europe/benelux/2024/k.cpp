#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

template<int MOD> struct str_hash{
    vector<ll> h, p;
    str_hash(string s, int P) : h(s.size()), p(s.size()){

        p[0] = 1, h[0] = s[0];
        for(int i = 1; i < s.size(); i++) p[i] = p[i-1]*P%MOD, h[i] = (h[i - 1] * P + s[i]) % MOD;
    }
    ll operator()(int l, int r){
        ll hash = h[r] - (l ? h[l-1] * p[r - l + 1] % MOD : 0);
        return hash < 0 ? hash + MOD : hash;
    }
};

const int M1 = 1e9+7;
const int M2 = 1e9+9;
const int M3 = 1e9+696969;
const int P1 = uniform(256, M1 - 1);
const int P2 = uniform(256, M2 - 1);
const int P3 = uniform(256, M3 - 1);

void solution(){
    string s;
    cin >> s;

    int n = sz(s);
    str_hash<M1> s1(s, P1);
    str_hash<M2> s2(s, P2);
    str_hash<M2> s3(s, P3);

    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        map<tuple<int, int, int>, int> lst_pos;        
        map<tuple<int, int, int>, int> occ;        
        dbg(i);
        for(int j = 0; j <= n - i; j++){
            int h1 = s1(j, j+i - 1);
            int h2 = s2(j, j+i - 1);
            int h3 = s3(j, j+i - 1);

            tuple<int, int, int> curr = {h1, h2, h3};

            dbg(i, j);
            //print(curr);
            if(!lst_pos[curr] or j >= lst_pos[curr]){
                occ[curr] ++;
                lst_pos[curr] = j + i;
                dbg(occ[curr], i + n + occ[curr] - (i * occ[curr]));
                ans = min(ans, i + n + occ[curr] - (i * occ[curr]));

            } 
            dbg("######");            
        }
        dbg("--------");
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    

}