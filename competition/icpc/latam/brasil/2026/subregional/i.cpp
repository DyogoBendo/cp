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

#define int ll

signed main(){
    darvem;

    int f, n;
    cin >> f >> n;
    
    vector<int> all_values, friend_group(n+1), idx_to_k(n+1);
    vector<pair<int, int>> entries;    
    for(int i = 1; i <= n; i++){
        int k, p;
        cin >> k >> p;

        idx_to_k[i] = k;
        all_values.push_back(k);        
        entries.push_back({k, p});
    }
    sort(all_values.begin(), all_values.end());

    map<int, int> mp;
    int cnt=1;
    for(int k : all_values) mp[k] = cnt++;
    for(auto [k, p] : entries) friend_group[mp[k]] = p;    

    vector<int>  status(n+1), depends(n+1, -1), arrival(n+1), duration(n+1);
    vector<int> dependents(n+1);

    for(int i = 1; i <= n; i++){
        char T;
        cin >> T;

        int k = mp[idx_to_k[i]];
        if(T == 'A'){
            int a, t;
            cin >> a >> t;
            status[k] = 1;
            arrival[k] = a;
            duration[k] = t;            
        } else if(T == 'T'){
            int x;
            cin >> x;
            x = mp[x];            
            depends[k] = x;
            dependents[x]++;
        }
    }    

    queue<int> q;
    for(int i = 1; i<= n; i++){
        if(dependents[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int curr = q.front(); q.pop();
        int dep = depends[curr];
        if(dep != -1){
            friend_group[dep] += friend_group[curr];
            dependents[dep] --;            
            if(dependents[dep] == 0) q.push(dep);
        }
    }    

    vector<tuple<int, int, int>> events;
    for(int i = 1; i <= n; i++){
        if(status[i] == 1){
            events.push_back({arrival[i], 1, friend_group[i]});
            events.push_back({arrival[i] + duration[i], 0, friend_group[i]});
        }
    }

    sort(events.begin(), events.end());

    ll ans = 0;   
    ll curr = 0; 
    for(auto [t, o, s] : events){
        if(o == 0) curr -= s;
        else curr += s;
        ans = max(ans, curr);
    }

    cout << ans << endl;
}