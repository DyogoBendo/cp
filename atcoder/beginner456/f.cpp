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

const ll INF = 1e18;

template <class T, T (*op)(T, T)>
struct FoldableQueue
{
    queue<T> front_prod;
    vector<T> back_val;
    T back_prod;
    void push(const T &v)
    {
        back_prod = back_val.empty() ? v : op(back_prod, v);
        back_val.push_back(v);
    }
    void pop()
    {
        if (front_prod.empty())
        {
            for (int i = (int)back_val.size() - 1; i > 0; i--)
                back_val[i - 1] = op(back_val[i - 1], back_val[i]);
            for (int i = 0; i < (int)back_val.size(); i++)
                front_prod.push(back_val[i]);
            back_val.clear();
        }
        front_prod.pop();
    }
    size_t size() { return front_prod.size() + back_val.size(); }
    T all_prod() const
    {
        assert(!front_prod.empty() || !back_val.empty());
        if (front_prod.empty()) return back_prod;
        if (back_val.empty()) return front_prod.front();
        return op(front_prod.front(), back_prod);
    }
};

using M = array<array<ll, 2>, 2>;

M mul(M a, M b){        
    M c = {{{INF, INF}, {INF, INF}}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}

M op(M l, M r) { return mul(r, l); }


void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    FoldableQueue<M, op> q;
    auto calc= [&](int idx){
        ll dp0 = 0;
        ll dp1 = idx ? v[idx-1] : INF;

        M p = q.all_prod();       
        dbg(p[0][1], p[1][1], dp1); 
        return min(dp0 + p[1][0], dp1 + p[1][1]);
    };

    int i = 0;
    while(q.size() < k){
        array<ll, 2> dp0_trans = {INF, 0};
        array<ll, 2> dp1_trans = {v[i], v[i]};        
        q.push({dp0_trans, dp1_trans});        
        i++;
    }    

    ll ans = INF;
    for(; i < n; ){        
        ans = min(ans, calc(i - k));

        q.pop();
        array<ll, 2> dp0_trans = {INF, 0};
        array<ll, 2> dp1_trans = {v[i], v[i]};
        q.push({dp0_trans, dp1_trans});
        i++;
        
        dbg(i, sz(q), ans);
    }
    ans = min(ans, calc(i-k));

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}