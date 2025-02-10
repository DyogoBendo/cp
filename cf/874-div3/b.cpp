#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --){
        int n, k;
        cin >> n >> k;        

        vector<pair<int, int>> o;
        vector<int> e;
        vector<int> a(n, 0);

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            o.push_back({x, i});
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            e.push_back(x);
        }

        sort(o.begin(), o.end());
        sort(e.begin(), e.end());

        for (int i = 0; i < n; i++)
        {
            auto r = o[i];
            a[r.second] = e[i];
        }
        
        for (auto r : a)
        {
            cout << r << " ";
        }
        cout << endl;
    }   

}