#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){    
    vector<int> values = {4, 8, 15, 16, 23, 42};
    vector<int>ans;

    map<int, pair<int, int>> m;

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            m[values[i] * values[j]] = {values[i], values[j]};
        }        
    }        

    cout << "? 1 2" << endl;
    fflush(stdout);
    
    int x1, x2, x3, x4;
    cin >> x1;
    
    set<int> s;
    s.insert(m[x1].first);
    s.insert(m[x1].second);
    
    cout << "? 1 3" << endl;
    fflush(stdout);
    
    cin >> x2;
    int f1 = m[x2].first, f2 = m[x2].second;
    
    if(s.count(f1)){
        ans.push_back(f1);
        ans.push_back(x1/f1);
        ans.push_back(f2);

        s.insert(f2);
        s.insert(x1/f1);        
    } else{
        ans.push_back(f2);
        ans.push_back(x1/f2);
        ans.push_back(f1);        

        s.insert(x1/f2);        
        s.insert(f1);
    }
    
    cout << "? 1 4" << endl;
    fflush(stdout);    
    
    cin >> x3;
    ans.push_back(x3/ans[0]);
    s.insert(x3/ans[0]);
    
    cout << "? 1 5" << endl;
    fflush(stdout);
    
    cin >> x4;
    ans.push_back(x4/ans[0]);
    s.insert(x4/ans[0]);
    
    for (int v : values)
    {
        if(!s.count(v)){
            ans.push_back(v);
            break;
        }
    }
    cout << "! ";
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;    
    fflush(stdout);

}

signed main(){    
    int t = 1;    

    while(t--) solve();
}