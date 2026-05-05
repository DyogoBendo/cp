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

int grid[MAX][MAX], visited[MAX][MAX];
int hcut[MAX][MAX], vcut[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

signed main(){
    darvem;

    int n;
    cin >> n;

	n++;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

	for(int j = 0; j < n-1; j++){
		auto [xa, ya] = v[j];
		auto [xb, yb] = v[j+1];		

		if(xa == xb){ // vertical cut
			for(int i = min(ya, yb); i < max(ya, yb); i++) vcut[i][xa] = 1;
		} else{ // horizontal cut
			for(int i = min(xa, xb); i < max(xa, xb); i++) hcut[ya][i] = 1;
		}
	}	

	auto check = [&](int x, int y){
		if(x < 0) return 0;
		if(x >= MAX) return 0;
		if(y < 0) return 0;
		if(y >= MAX) return 0;
		if(visited[y][x]) return 0;	
		return 1;
	};

	auto bfs = [&](int x, int y){
		if(!check(x, y)) return 0;				

		int tot = 0;
		visited[y][x] = 1;
		queue<pair<int, int>> q;
		q.push({x, y});
		while(!q.empty()){
			auto [cx, cy] = q.front(); q.pop();			
			tot++;			
			for(int i = 0; i < 4; i++){
				int gx = cx + dx[i];
				int gy = cy + dy[i];
				// dbg(x, y, i, gx, gy);
	
				if(check(gx, gy)){
					bool add = false;
					if(gx != cx and !vcut[gy][max(gx, cx)]) add = true;
					else if(gy != cy and !hcut[max(gy, cy)][gx]) add = true;					
					if(add){								
						q.push({gx, gy});
						visited[gy][gx] = 1;
					}
				}
			}
		}
		return tot;
	};

	bfs(0, 0);
	int bst = 0;
	for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++){
		bst = max(bst, bfs(i, j));
	}

	cout << bst << endl;
}