#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("sort");

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i});
    }

    sort(v.begin(), v.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            } 
            return p1.first < p2.first;
        }
    );

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int position = v[i].second;                
        ans = max(ans, position - i);
    }
    
    cout << ans + 1 << endl;
    
}