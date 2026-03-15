#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

//#define DEBUG

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int long long

const int MAX = 1e9;
int cnt = 0;

int query(ll el, ll er, ll fl, ll fr){
    cnt++;    

    cout << "? " << el << " " << fl << " " << er << " " << fr << endl;
    ll k;
    cin >> k;

    ll tot = (er - el + 1) * (fr - fl + 1);
    return k - tot;
}

void answer(pair<int, int> p1, pair<int, int> p2){
    cout << "! " << p1.first << " " << p2.first << " " << p1.second << " " <<  p2.second << endl;    
}

int solve_e1(int l, int r){
    int s = r-l+1;    
    if(s <= 1) return l;

    int m = (r - l) / 2 + l;
    int k = query(l, m, 1, MAX);

    if(k == 1){
        return solve_e1(l, m);
    } else{
        return solve_e1(m+1, r);
    }
}

pair<int, int> solve_e2(int l, int r){
    int s = r-l+1;

    if(s <= 1) return make_pair(l, r);

    int m = (r - l) / 2 + l;
    int k = query(l, m, 1, MAX);

    if(k == 1){
        int ans1 = solve_e1(l, m);
        int ans2 = solve_e1(m+1, r);
        return make_pair(ans1, ans2);
    } else if(k == 2){
        return solve_e2(l, m);
    } else{
        return solve_e2(m+1, r);
    }
}

pair<int, int> solve_e(){
    return solve_e2(1, MAX);
}

int solve_f1(int l, int r, int ex){
    int s = r-l+1;
    if(s <= 1) return l;

    int m = (r - l) / 2 + l;
    int k = query(ex, ex, l, m);

    if(k == 1){
        return solve_f1(l, m, ex);
    } else{
        return solve_f1(m+1, r, ex);
    }
}

pair<int, int> solve_f2(int l, int r, int ex){
    int s = r-l+1;
    if(s <= 1) return make_pair(l, r);

    int m = (r - l) / 2 + l;
    int k = query(ex, ex, l, m);

    if(k == 2){
        return solve_f2(l, m, ex);
    } else if(k == 1){
        int ans1 = solve_f1(l, m, ex);
        int ans2 = solve_f1(m+1, r, ex);
        return make_pair(ans1, ans2);
    } else{
        return solve_f2(m+1, r, ex);
    }    
}

void solve(){
    pair<int, int> pe = solve_e();    

    if(pe.first == pe.second) return answer(pe, solve_f2(1, MAX, pe.first));
    else{
        int f1 = solve_f1(1, MAX, pe.first);
        int f2 = solve_f1(1, MAX, pe.second);
    
        answer(pe, make_pair(f1, f2));
    }

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}