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

#define DEBUG

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int long long


class Data{
public:
    int cnt;
    int r;
    int l;
    int bst;
    vector<int> special;
    Data(){
        cnt=0;
        r=0;
        l=0;
        bst=0;
    }
};

class Segtree{
public:
    int n;
    Data neutral;
    vector<Data> t;
    Segtree(){
        Data nn;
        neutral = nn;
        n = 1;
        while (8000 >= n) n <<= 1;
        t.resize(2*n, neutral);
    }

    Data op(Data l, Data r){
        Data m;
        m.cnt = l.cnt + r.cnt;
        m.r = max(l.r, r.r);
        m.l = max(l.l, r.l);
        for (auto x: l.special) m.special.push_back(x);
        for (auto x: r.special) m.special.push_back(x);
        m.bst = max(l.bst, r.bst);
        return m;
    }

    Data query(int l, int r, int idx, int a, int b){
        if (r < a || b < l) return neutral;
        if (l <= a && b <= r) return t[idx];
        int m = (a+b)/2;
        return op(query(l, r, 2*idx, a, m), query(l, r, 2*idx+1, m+1, b));
    }
    Data query(int l, int r){ return query(l, r, 1, 0, n-1); }

    void set(int idx, Data v){
        if (idx < 0 || idx >= n) return;
        t[idx += n] = v;
        for (idx >>= 1; idx; idx >>= 1) t[idx] = op(t[2*idx], t[2*idx+1]);
    }
};


vector<int> get_d(int x){
    vector<int> ans;
    for (int i=0; i<4; i++){
        ans.push_back(x%10);
        x /= 10;
    }
    reverse(all(ans));
    return ans;
}

vector<string> units = {
    "",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX"
};

vector<string> tens = {
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC"
};

vector<string> hundreds = {
    "",
    "C",
    "CC",
    "CCC",
    "CD",
    "D",
    "DC",
    "DCC",
    "DCCC",
    "CM"
};

vector<string> thousands = {
    "",
    "M",
    "MM",
    "MMM"
};


vector<char> order = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

bool ir(int l, int r, int x){
    return l <= x && x <= r;
}


void solve(){
    
    int n = 4000;
    vector<pair<int, string>> roman;
    for (int i=1; i<n; i++){
        vector<int> d = get_d(i);
        string s = "";
        s += thousands[d[0]];
        s += hundreds[d[1]];
        s += tens[d[2]];
        s += units[d[3]];
        roman.push_back({i, s});
    }

    vector<Segtree> segs (sz(order));
    for (int i=0; i<sz(order); i++){
        for (auto [j, s]: roman){
            Data cur;
            for (auto c: s){
                if (c != order[i]) break;
                cur.r++;
            }
            for (int k=sz(s)-1; k>=0; k--){
                if (s[k] != order[i]) break;
                cur.l++;
            }

            int tot=0, val=0;
            char prev = -1;
            for (auto c: s){
                if (c == prev) val++;
                else val = 1;
                prev = c;
                cur.bst = max(cur.bst, val);
            }
    
            if (cur.l == sz(s)){
                cur.cnt = cur.l;
                cur.l = cur.r = 0;
            }

            if (cur.l && cur.r){
                cur.special.push_back(max(cur.l, cur.r));
                cur.l = cur.r = 0;
            }

            segs[i].set(j, cur);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int best=0;
        for (int i=0; i<sz(order); i++){
            
            Data cur;
            cur = segs[i].query(l, r);

            sort(rall(cur.special));
            for (auto x: cur.special){
                if (cur.r < x) cur.r = x;
                else if (cur.l < 1) cur.l = 1;
            }

            best = max({best, cur.l + cur.cnt + cur.r, cur.bst});
        }
        cout << best << '\n';
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}