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

const int MAX = 1e5 + 10;
const int LINF = 1e9;

// Area da Uniao de Retangulos
//
// O(n log(n))
// 5d8d2f

namespace seg {
	pair<int, ll> seg[4*MAX];
	ll lazy[4*MAX], *v;
	int n;
 
	pair<int, ll> merge(pair<int, ll> l, pair<int, ll> r){
		if (l.second == r.second) return {l.first+r.first, l.second};
		else if (l.second < r.second) return l;
		else return r;
	}
 
	pair<int, ll> build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = {1, v[l]};
		int m = (l+r)/2;
		return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, ll* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p].second += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	pair<int, ll> query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, LINF};
		int m = (l+r)/2;
		return merge(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	pair<int, ll> update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = merge(update(a, b, x, 2*p, l, m),
				update(a, b, x, 2*p+1, m+1, r));
	}
};
 
ll seg_vec[MAX];
 
ll area_sq(vector<pair<pair<int, int>, pair<int, int>>> &sq){
	vector<pair<pair<int, int>, pair<int, int>>> up;
	for (auto it : sq){
		int x1, y1, x2, y2;
		tie(x1, y1) = it.first;
		tie(x2, y2) = it.second;
		up.push_back({{x1+1,  1}, {y1, y2}});
		up.push_back({{x2+1, -1}, {y1, y2}});
	}
	sort(up.begin(), up.end());
	memset(seg_vec, 0, sizeof seg_vec);
	ll H_MAX = MAX;
	seg::build(H_MAX-1, seg_vec);
	auto it = up.begin();
	ll ans = 0;
	while (it != up.end()){
		ll L = (*it).first.first;
		while (it != up.end() && (*it).first.first == L){
			int x, inc, y1, y2;
			tie(x, inc) = it->first;
			tie(y1, y2) = it->second;
			seg::update(y1+1, y2, inc);
			it++;
		}
		if (it == up.end()) break;
		ll R = (*it).first.first;
 
		ll W = R-L;
		auto jt = seg::query(0, H_MAX-1);
		ll H = H_MAX - 1;
		if (jt.second == 0) H -= jt.first;
		ans += W*H;
	}
	return ans;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<int, int>>> lines(n);

    for(int i = 0; i < n; i++){
        cin >> lines[i].first.first >> lines[i].first.second >> lines[i].second.first >> lines[i].second.second;
    }

    int p;
    cin >> p;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll tot_area = 1LL * (x2 - x1) * (y2 - y1);

    auto check = [&](int d){
        vector<pair<pair<int, int>, pair<int, int>>> rect;
        for(int i = 0; i < n; i++){
            int mn_x = min(lines[i].first.first, lines[i].second.first) - d;
            int mn_y = min(lines[i].first.second, lines[i].second.second) - d;

            int mx_x = max(lines[i].first.first, lines[i].second.first) + d;
            int mx_y = max(lines[i].first.second, lines[i].second.second) + d;

            mn_x = max(mn_x, x1);
            mx_x = min(mx_x, x2);
            mn_y = max(mn_y, y1);
            mx_y = min(mx_y, y2);

            if(mn_x < mx_x and mn_y < mx_y) rect.push_back({{mn_x, mn_y}, {mx_x, mx_y}});
        }

        ll area = area_sq(rect);

        return p*tot_area <= 100*area;
    };

    int lo = 0, hi = 1e5 + 10;
    while(lo < hi){
        int m = (hi - lo) / 2 + lo;

        if(check(m)) hi = m;
        else lo = m + 1;        
    }

    cout << hi << endl;
}