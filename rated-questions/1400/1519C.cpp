#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    vector<int> student(n);
    vector<int> skill(n);

    for (int i = 0; i < n; i++)
    {
        cin >> student[i];
        student[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> skill[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        v[student[i]].push_back(skill[i]);
    }

    vector<vector<int>> psum(n);
    vector<pair<int, int>> uni_qtd;
    
    for (int i = 0; i < n; i++)
    {
        psum[i].push_back(0);  
        sort(v[i].begin(), v[i].end());
        
        for (int j = 0; j < v[i].size(); j++)
        {
            psum[i].push_back(psum[i].back() + v[i][j]);
        }        
        uni_qtd.push_back({v[i].size(), i});
    }
    
    sort(uni_qtd.begin(), uni_qtd.end());

    int l = 0;
    for (int i = 1; i <= n; i++)
    {               
        while(l < n && uni_qtd[l].first < i){            
            l++;      
        }         
        int curr = 0;
        for (int j = l; j < n; j++)
        {            
            int m = uni_qtd[j].first % i;                      
            int add = psum[uni_qtd[j].second][uni_qtd[j].first] - psum[uni_qtd[j].second][m];                   
            curr += add;            
        }        
        cout << curr << " ";
    }    
    cout << endl;

}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}