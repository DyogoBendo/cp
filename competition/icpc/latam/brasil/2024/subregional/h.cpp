#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string m, n;
    cin >> m >> n;

    int x = 0, y = 0;

    reverse(m.begin(), m.end());
    reverse(n.begin(), n.end());

    vector<int> v1, v2;
    for (int i = 0; i < max(m.size(), n.size()); i++)
    {
        int curr = (1 << i);
        if(i < m.size()){
            if(m[i] == '1'){
                x += curr;
            } else if(m[i] == '*'){
                v1.push_back(curr);
            }
        }
        if(i < n.size()){
            if(n[i] == '1'){
                y += curr;
            } else if(n[i] == '*'){
                v2.push_back(curr);
            }
        }
    }

    vector<int> all_n, all_m;

    all_m.push_back(x);
    all_n.push_back(y);
    for (int v : v1)
    {
        vector<int> tmp;

        for (auto k : all_m)
        {
            tmp.push_back(k + v);
        }
        for (auto k : tmp)
        {
            all_m.push_back(k);
        }
    
    }
    for (int v : v2)
    {
        vector<int> tmp;

        for (auto k : all_n)
        {
            tmp.push_back(k + v);
        }
        for (auto k : tmp)
        {
            all_n.push_back(k);
        }
    }

    for (auto a : all_m)
    {
        for (auto b : all_n)
        {
            if(a % b == 0){
                vector<int> ans;
                for (int i = 0; i < m.size(); i++)
                {
                    if((1 << i) & a) ans.push_back(1);
                    else ans.push_back(0);
                }

                reverse(ans.begin(), ans.end());

                for (auto an : ans)
                {
                    cout << an;
                }
                cout << endl;
    
                return 0;
            }
        }
        
    }
    
}