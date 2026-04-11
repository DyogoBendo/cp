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

vector<int> suffix_array(vector<int> s) {
	s.push_back(0);
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

vector<int> kasai(vector<int> s, vector<int> sa) {
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

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >>v[i];

    int prev = 0, prev_cnt = 0;
    vector<int> v2;
    for(int i = 0; i < n; i++){
        if(v[i] == prev)prev_cnt++;
        else{
            if(prev){
                if(prev_cnt > prev) v2.push_back(prev+1), v2.push_back(1);
                if(prev_cnt >= prev) v2.push_back(prev+1);
                else v2.push_back(1);
            }

            prev_cnt = 1;
        }
        prev = v[i];
    }
    if(prev_cnt > prev) v2.push_back(prev+1), v2.push_back(1);
    if(prev_cnt >= prev) v2.push_back(prev+1);
    else v2.push_back(1);
    
    auto sa = suffix_array(v2);
    vector<int> lcp = kasai(v2, sa);

    vector<int> zerofree(sz(v2));
    int curr = 0;
    for(int i = sz(v2)-1; i >= 0; i--){
        if(v2[i] == 1) curr = 0;
        else curr++;

        zerofree[i] = curr;
    }

    ll ans = 0;
    for(int i = 0; i < sz(v2); i++){
        int l = i > 0 ? lcp[i-1] : 0;
        int z = zerofree[sa[i]];

        dbg(i, sa[i], l, z);

        ans += max(0, z - l);
    }   

    cout << ans << endl;
}