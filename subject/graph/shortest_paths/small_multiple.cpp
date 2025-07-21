#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 1e9;

signed main(){
    darvem;

    int k;
    cin >> k;
    
    vector<int> v(k, INF);    
    deque<pair<int, int>> q;                        
    q.push_front({1, 1});
    v[1] = 1;
    while(!q.empty()){
        auto [m, d] = q.front(); q.pop_front();                  
        int add = (m+1) % k;
        int mul = (m*10) % k;

        if(v[mul] > v[m]){
            v[mul] = d;
            q.push_front({mul, d});
        } 
        if(v[add] > v[m] + 1){
            v[add] = d+1;
            q.push_back({add, d+1});
        }         
    } 

    cout << v[0] << endl;

}