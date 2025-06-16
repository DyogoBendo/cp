#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> removed(n);
    vector<int> left(n);
    vector<int> right(n);
    map<pair<int, int>, set<int>> M;

    int prev = -1;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;                
        v[i] = x;
        
        left[i] = i-1;
        right[i] = i+1;            
        if(i > 0){            
            M[{prev, x}].insert(i-1);
        }
        prev = x;
    }
    
    map<pair<int, int>, int> cnt;
    set<tuple<int, int, int>> S;
    for (auto [p, s] : M)
    {
        int sz = s.size();
        cnt[{p.first, p.second}] = sz;        
        if(p.first != p.second){
            S.insert({-sz, p.first, p.second});            
        }
    }    

    int curr = 255;
    vector<string> ans;
    while(k--){
        curr++;
        int l = get<1>(*S.begin());
        int r = get<2>(*S.begin());
        int qtd = -get<0>(*S.begin());
        if(qtd < 2) break;
        ans.push_back(to_string(l) + " " + to_string(r) + " " + to_string(qtd));        
        
        set<pair<int, int>> changed;
        for (auto idx : M[{l, r}])
        {                     
            if(left[idx] >= 0){                       
                int x1 = v[left[idx]], x2 = v[idx]; // esse par foi afetado pelo par que está sendo removido, ele passa a ser v[idx-1], 255+i                
                M[{x1, curr}].insert(left[idx]);
                M[{x1, x2}].erase(left[idx]);
                changed.insert({x1, x2});
                changed.insert({x1, curr});                
            }            
            v[idx] = curr;   
            int r1 = right[idx];         
            int r2 = right[r1];
            if(r2 < n){
                int x1 = v[r1], x2 = v[r2];                
                M[{curr, x2}].insert(idx);
                M[{x1, x2}].erase(r1);                
                changed.insert({x1, x2});
                changed.insert({curr, x2});
            }
            // remover cara da direita e transformar o da esquerda no valor novo
            v[idx]= curr;
            right[idx] = r2;
            if(r2 < n) left[r2] = idx;
            removed[r1] = 1;
        }        
        cnt[{l, r}] = 0;
        S.erase({-qtd, l, r});
        M[{l, r}].clear();
        for (auto [x, y] : changed)
        {
            int c = cnt[{x, y}];
            S.erase({-c, x, y});
            
            int sz = M[{x, y}].size();            
            cnt[{x, y}] = sz;
            if(x != y) S.insert({-sz, x, y});
        }                     
    }
    cout << ans.size() << endl;
    for (auto a : ans)
    {
        cout << a << endl;
    }

    for (int i = 0; i < n; i ++)
    {
        if(!removed[i]) cout << v[i] << " ";
    }
    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}