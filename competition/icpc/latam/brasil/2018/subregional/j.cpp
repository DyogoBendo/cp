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

const int MAX = 100 + 1;
const int K = 10;
const ld LINF = 1e18;

int n; // numero de vertices
vector<pair<int, ld>> g[MAX]; // {vizinho, peso}
ld d[1 << K][MAX]; // dp[mask][v] = arvore minima com o subconjunto mask de S e o vertice v

ld steiner(const vector<int> &S) {
	int k = S.size(); // k--;
	for (int mask = 0; mask < (1 << k); mask++) for(int v = 0; v < n; v++) d[mask][v] = LINF;	
    for (int v = 0; v < n; v++) d[0][v] = 0;	
    for (int i = 0; i < k; ++i) d[1 << i][S[i]] = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
        int m =  __builtin_popcount(mask);
		for (int a = (mask - 1) & mask; a; a = (a - 1) & mask) {
			int b = mask ^ a;
			if (b > a) break;
			for (int v = 0; v < n; v++)
				d[mask][v] = min(d[mask][v], d[a][v] + d[b][v]);
		}
		priority_queue<pair<ld, int>> pq;
		for (int v = 0; v < n; v++) {   
			if (d[mask][v] == LINF) continue;
			pq.emplace(-d[mask][v], v);
		}
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[mask][u]) continue;            
            if((u < k) and m > 1) continue;            

			for (auto [idx, w] : g[u]) if (d[mask][idx] > d[mask][u] + w) {
				d[mask][idx] = d[mask][u] + w;
				pq.emplace(-d[mask][idx], idx);
			}
		}
	}
	return d[(1 << k) - 1][S[0]]; // S[k]
}


signed main(){
    darvem;
    int k;
    cin >> n >> k;

    vector<pair<int, int>> pos(n);
    for(int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ld dist = hypotl(pos[i].first - pos[j].first, pos[i].second - pos[j].second);
            if(i < k and j < k) continue;

            g[i].push_back({j, dist});
            g[j].push_back({i, dist});
        }
    }

    vector<int> S(k);
    iota(S.begin(), S.end(), 0);

    cout << fixed << setprecision(5) << steiner(S) << endl;
}