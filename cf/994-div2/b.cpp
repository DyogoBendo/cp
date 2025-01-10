#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    
    vector<int> action(n, 0);
    int possible = 1;

    vector<pair<int, int>> interval;

    for (int i = 0; i < n; i++)
    {
            if(s[i] == 'p'){
                interval.push_back({0, i});
            } else if(s[i] == 's') interval.push_back({i, n - 1});
    }

    for (int i = 0; i < interval.size(); i++)
    {
        int b1 = interval[i].first;
        int e1 = interval[i].second;
        //cout << "b1: " << b1 << " e1: " << e1 << endl;
        for (int j = i + 1; j < interval.size(); j++)
        {
            int b2 = interval[j].first;
            int e2 = interval[j].second;
            //cout << "b2: " << b2 << " e2: " << e2 << endl;            

            if(b1 > b2){
                if(!(b1 <= e2 && e1 <= e2)) possible = 0;
            } else if(b2 > b1){
                if(!(b2 <= e1 && e2 <= e1)) possible = 0;                
            }
        }       
        //cout << endl; 
    }
   
    if(possible){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}