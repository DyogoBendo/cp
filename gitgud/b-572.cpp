#include <bits/stdc++.h>

using namespace std;

struct CompareByBigger {
    bool operator()(const int &a, const int &b) const {
        return a > b; // Sort in descending order
    }
};

int main(){
    int n, s;
    cin >> n >> s;    

    map<int, int, CompareByBigger> buy;
    map<int, int> sell;

    for (int i = 0; i < n; i++)
    {
        char d;
        int p, q;
        cin >> d >> p >> q;

        if(d == 'B'){
            buy[p] += q;
        }else{
            sell[p] += q;
        }
    }

    int k = 0;
    vector<pair<int, int>> ans;
    for (auto x : sell)
    {        
        ans.push_back(x);
        k++;
        if(k == s) break;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << "S " << ans[i].first << " " << ans[i].second << endl;
    }
    
    
    k = 0;
    for (auto x : buy)
    {        
        cout << "B " << x.first << " " << x.second << endl;
        k++;
        if(k == s) break;
    }
    
    
}