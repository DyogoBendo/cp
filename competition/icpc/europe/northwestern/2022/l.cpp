#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

const int INF = 1e5;

// Dinitz
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1: O(min(m sqrt(m), m * n^(2/3)))
// Todo vertice tem grau de entrada ou saida 1: O(m sqrt(n))

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};

// Recupera as arestas do corte s-t
vector<pair<int, int>> get_cut(dinitz& g, int s, int t) {
	g.max_flow(s, t);
	vector<pair<int, int>> cut;
	vector<int> vis(g.g.size(), 0), st = {s};
	vis[s] = 1;
	while (st.size()) {
		int u = st.back(); st.pop_back();
		for (auto e : g.g[u]) if (!vis[e.to] and e.flow < e.cap)
			vis[e.to] = 1, st.push_back(e.to);
	}
	for (int i = 0; i < g.g.size(); i++) for (auto e : g.g[i])
		if (vis[i] and !vis[e.to] and !e.res) cut.emplace_back(i, e.to);
	return cut;
}

signed main(){
    //freopen("l.in", "r", stdin);
    //freopen("l.out", "w", stdout);
    darvem;

    int g, l;
    cin >> g >> l;
    //cout << g << " " << l << endl;

    vector<int> letter_cnt(26, 0);
    vector<int> exactly_cnt(26, 0);
    vector<int> appeared(26, 0);    

    vector<vector<int>> letters_possibilities(l, vector<int>(26)); 
    vector<int> ans(l, -1);    

    for(int i = 0; i < g-1; i++){
        string s, r;
        cin >> s >> r;
        //cout << s << " " << r << endl;

        vector<int> curr_cnt(26);
        vector<int> fixed(26);
        for(int j = 0; j < l; j++){
            int c = s[j] - 'a';
            appeared[c] = 1;
            if(r[j] == 'B'){
                fixed[c] = 1;
                letters_possibilities[j][c] = 1;
            } else if(r[j] == 'Y'){
                curr_cnt[c]++;
                letters_possibilities[j][c] = 1;
            } else{                
                curr_cnt[c]++;
                ans[j] = c;                             
            }
        }
        for(int k = 0; k < 26; k++){
            if(fixed[k])exactly_cnt[k] = 1;                
            
            letter_cnt[k] = max(letter_cnt[k], curr_cnt[k]);
        }
    }

    int suml = 0;    
    vector<int> green(26);
    for(int i = 0; i < l; i++){        
        if(ans[i] != -1){
            green[ans[i]] ++;
            for(int j = 0; j < 26; j++){
                if(j != ans[i]) letters_possibilities[i][j] = 1;
            }
        } 
    }
    for(int i = 0; i < 26; i++){        
        letter_cnt[i] = max(letter_cnt[i], green[i]);
    }

    vector<vector<int>> letter_to_position(26);
    for(int i = 0; i < l; i++){        
        for(int j = 0; j < 26; j++){
            if(letters_possibilities[i][j] == 0) letter_to_position[j].push_back(i);
        }
    }
    
    dinitz d(29+l);
    for(int i = 0; i < 26; i++){                  
        d.add(0, i+2, letter_cnt[i]); // fluxo para cada letra é a quantidade de letras de cada um                
        d.add(1, i+2, exactly_cnt[i] ? 0 : l);        
        suml += letter_cnt[i];
    }        
    d.add(0, 1, l - suml);
    for(int i = 0; i < 26; i++){
        for(int k : letter_to_position[i]){
            //cout << "letter: " << (char)(i + 'a') << " to: " << k << endl;
            d.add(i+2, 28+k, 1); // podemos passar apenas uma letra para cada posição            
        }
        //cout << endl;
    }
    for(int i = 0; i < l; i++){
        d.add(28+i, 28+l, 1); // para cada posição, teremos uma única letra possível na configuração final        
    }

    d.max_flow(0, 28+l);    
        
    auto ans2 = ans;    
    auto prev = ans;
    for(int i = 0; i < 26; i++){        
        for(auto &e : d.g[i+2]){            
            if(e.flow == 1) ans[e.to - 28] = i;            
        }        
    }
    
    for(int i = 0; i < l; i++) cout << (char)(ans[i] + 'a');    
    cout << endl;
}