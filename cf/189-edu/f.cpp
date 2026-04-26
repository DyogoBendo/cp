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

int t = 1;

vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

vector<int> kasai(string s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;

	for (int i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) { k = 0; continue; }
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

void solve(){
    int n, l, k;
    string s;
    cin >> n >> l >> k >> s;
    
    int max_can = n/l;
    if(max_can < k){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    if(k == 1){
        cout << s << endl;
        return;
    }

    auto sa = suffix_array(s);
    auto lcp = kasai(s, sa);

    bool found = false;
    int pos_ans = -1, tam_ans = -1, tam_lcp = n;
    for(int i = sz(sa) - 1; i >= 0; i--){
        // dbg(i, sa[i], s.substr(sa[i]));
        int tam = n - sa[i];
        if(tam < l) continue;
        if(sa[i] and sa[i] < l) continue;                
        
        int bef = min(sa[i] / l, k-1);
        
        int parts = k - bef;
        int need= parts*l;        
        
        // dbg(parts, need);
        
        if(tam < need) continue;
        need -= l;
        
        if(!found or (tam_lcp >= tam_ans and tam-need > tam_ans)){            
            found = true;
            pos_ans = i;
            tam_ans = tam - need;
            if(i > 0) tam_lcp = lcp[i - 1];                        
        }
        if(i > 0) tam_lcp = min(tam_lcp, lcp[i-1]);
    }

    cout << s.substr(sa[pos_ans], tam_ans) << endl;
}


signed main(){
    darvem;    
    int tot = 0;
    cin >> tot;    

    while(tot--) t++, solve();
}