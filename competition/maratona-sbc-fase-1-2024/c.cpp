#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long
const int MAX = 1e5 + 10;

namespace seg{
    ll seg[4*MAX], lazy[4*MAX];
    int n, v[MAX];
    
    ll build(int p=1, int l=0, int r=n-1) {
        lazy[p] = 0;
        if (l == r) return seg[p] = v[l];
        int m = (l+r)/2;
        return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
    }
    void build(int n2) {
        n = n2;
        build();
    }
    void prop(int p, int l, int r) {
        seg[p] = max(seg[p], lazy[p]);
        if (l != r) lazy[2*p] = max(lazy[p], lazy[2*p]), lazy[2*p+1] = max(lazy[p], lazy[2*p+1]);
        lazy[p] = 0;
    }
    ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return 0;
        int m = (l+r)/2;
        return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
    }
    ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
        if (a <= l and r <= b) {
            lazy[p] = max(x, lazy[p]);
            prop(p, l, r);
            return seg[p];
        }
        if (b < l or r < a) return seg[p];
        int m = (l+r)/2;
        return seg[p] = max(update(a, b, x, 2*p, l, m),
            update(a, b, x, 2*p+1, m+1, r));
    }
};

// Suffix Array - O(n log n)
//
// kasai recebe o suffix array e calcula lcp[i],
// o lcp entre s[sa[i],...,n-1] e s[sa[i+1],..,n-1]
//
// Complexidades:
// suffix_array - O(n log(n))
// kasai - O(n)

vector<int> suffix_array(vector<int> s) {
	s.push_back(0);
	int n = s.size(), N = n + 10;
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

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    
    vector<int> sa = suffix_array(v);
    vector<int> lcp = kasai(v, sa);
    
    int ans = 0, cnt = 0;    
    vector<int> prev_ans(n+1, 0);    
    seg::n = n + 10; seg::build();
    for (int i = sa.size() - 1; i >= 0; i--, cnt++)
    {        
        ans += (n - sa[i]);
                        
        int prefix = lcp[i];        
        int curr = 0;
        int qtd = 0;
                
        int idx_prev= seg::query(prefix, prefix);        
        curr += prev_ans[idx_prev];
        qtd = cnt - idx_prev;        
        
        curr += qtd * prefix;              
        seg::update(prefix, n+1, cnt);
        prev_ans[cnt] = curr;        

        ans += 2*curr;        
             
    }

    int total = n * n;

    int g = __gcd(total, ans);
    
    cout << ans/g << "/" << total/g << endl;    
}