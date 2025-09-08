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

class SuffixArray{
public:
    string s;
    vector<int> sa;    
    vector<vector<int>> rah;
    int n, N = 260;

    SuffixArray(string _s){
        s = _s + "$";
        n = sz(s), N = max(n, N);
        
        sa = vector<int>(n);        
        vector<int> ra(n);

        for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

        for(int k = 0; k < n; k ? k <<= 1 : k++) {
            vector<int> nsa(sa), nra(n), cnt(N);

            for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
            for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
            for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

            for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
                ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
            ra = nra;

            rah.push_back(ra);
        }
        sa = vector<int>(sa.begin()+1, sa.end());
    }

    // compara duas substrings, começando em i e j respectivamente, ambas com tamanho l
    int compare(int i, int j, int l){
        int k = __builtin_clz(1) - __builtin_clz(l);
        dbg(k);
        pair<int, int> a = {rah[k][i], rah[k][(i+l - (1 << k)) % n]};
        pair<int, int> b = {rah[k][j], rah[k][(j+l - (1 << k)) % n]};

        return a == b ? 0 : (a < b ? -1 : 1);
    }

    vector<int> kasai() {
        int k = 0;
        vector<int> rsa(n), lcp(n);
        for (int i = 0; i < n; i++) rsa[sa[i]] = i;

        for (int i = 0; i < n; i++, k -= !!k) {
            if (rsa[i] == n-1) { k = 0; continue; }
            int j = sa[rsa[i]+1];
            while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
            lcp[rsa[i]] = k;
        }
        return lcp;
    }

};


signed main(){
    darvem;

    string s;
    cin >> s;

    SuffixArray sa(s);
    for(int x:  sa.sa) cout << x << " ";
    cout << endl;
}