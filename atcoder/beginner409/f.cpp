#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

vector<pair<int,int>> v;
priority_queue<tuple<int, int, int>> pq;

int calc(pair<int, int> a, pair<int, int> b){
    return -(abs(a.first - b.first) + abs(a.second - b.second));
}

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}

    void add(){
        id.push_back(id.size());
        sz.push_back(1);
    }
    int merge(){
        if(pq.empty()) return -1;
    
        int k, x, y;
        bool found = false;
        while(!pq.empty()){
            auto [curr, x, y] = pq.top(); pq.pop();
            if(find(x) != find(y)){                
                unite(x, y);
                k = curr;
                found = true;
                break;
            } 
        }

        if(!found) return -1;
            
        while(!pq.empty()){
            auto [curr, x, y] = pq.top();

            if(curr != k) break;

            unite(x, y);

            pq.pop();
        }

        return -k;
    }
};


signed main(){
    darvem;
    int n, q;
    cin >> n >> q;
    v.resize(n);

    struct dsu groups(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            pq.push({calc(v[i], v[j]), i, j});
        }        
    }    

    while(q--){
        int t;
        cin >> t;

        if(t == 1){
            int a, b;
            cin >> a >> b;

            v.push_back({a, b});
            groups.add();
            for (int i = 0; i < n; i++)
            {
                pq.push({calc(v[i], v[n]), i, n});
            }
            n++;
        } else if(t == 2){
            cout << groups.merge() << endl;
        } else{
            int u, v;
            cin >> u >> v;
            u --; v--;

            if(groups.find(u) == groups.find(v)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

}