#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int INF = 1e9+7;

struct dsu {
	vector<int> id, cap, tot, go;

	dsu(int n, vector<int> c, vector<int> g) : id(n) {
        iota(id.begin(), id.end(), 0); 
        cap = c;
        tot = vector<int>(n);
        go = g;
    }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }	

    void op(int a, int x){
        a = find(a);    
        int lst = id.size() - 1;    
        if(a == lst) return;
        while(a != lst and tot[a] + x > cap[a]){                    
            x -= cap[a] -   tot[a];
            tot[a] = cap[a];

            id[a] = find(go[a]);
            a = find(go[a]);
        }
        if(a != lst) tot[a] += x;
    }

    int get(int a){
        return tot[a];
    }

};

signed main(){
    darvem;

    int n, queries;
    cin >> n >> queries;

    vector<int> v(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    v[n] = INF;    

    vector<int> go(n+1);
    stack<pair<int, int>> st;
    st.push({INF, n});
    for(int i = n-1; i >= 0; i--){        
        while(st.top().first < v[i]) st.pop();
        go[i] = st.top().second;        
        st.push({v[i], i});
    }

    dsu d(n+1, v, go);
    
    while(queries--){
        char c;
        int a, b;
        cin >> c >> a;        
        a--;
        if(c == '?') cout << d.get(a) << endl;
        else{
            cin >> b;                
            d.op(a, b);
        }
    }
}