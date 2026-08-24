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

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

int inpol(pt p, pt a, pt b) { // O(1)	    
    if(a == b) return 0;
    if (p.y == a.y and p.y == b.y) return 0;
    bool baixo = a.y < p.y;
    if (baixo == (b.y < p.y)) return 0;
    auto t = (p-a)^(b-a);    
    if (baixo == (t > 0)){
        if(baixo) return 1;
        return -1;
    } 

	return 0;
}


signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<pt> points(n);
    for(int i = 0; i < n; i++) cin >> points[i];

    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int k;
    cin >> k;

    
    while(k--){
        pt pt;
        cin >> pt;

        vector<int> visited(n);
        vector<int> acc(n+2);
        bool found = false;
        function<void(int, int, int)> dfs = [&](int curr, int p, int d){
            acc[d] = acc[d-1] + inpol(pt, points[p], points[curr]);            
            if(visited[curr]){                            
                if(acc[d] - acc[visited[curr]] and d - visited[curr] > 2) found = true;
                return;
            }   

            visited[curr] = d;
            for(auto e : g[curr]) if(e != p) dfs(e, curr, d+1);
        };

        for(int i = 0; i < n; i++) if(!visited[i]) dfs(i, i, 1);

        cout << (found ? 'P' : 'G');
    }
    cout << endl;
}