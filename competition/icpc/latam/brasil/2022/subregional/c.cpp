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

const int MAX = 1e3 + 10;

int grid[MAX][MAX];
int marked[MAX][MAX];

signed main(){
    darvem;

    int n;
    cin >> n;

	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	for(int i = 0; i < n-1; i++) marked[v[i].second][v[i].first] = grid[v[i].second][v[i].first] = 1;

	int ans = 0;
	for(int x = 0; x < MAX-1; x++){
		for(int y = 0; y < MAX-1; y++){						
			if(grid[y][x] and marked[y][x]){
				grid[y+1][x] ^= 1;
			}
			ans += grid[y][x];
			grid[y][x+1] ^= grid[y][x];
		}
	}

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) cout << grid[i][j] << " ";
		cout << endl;
	}

	cout << ans << endl;
}