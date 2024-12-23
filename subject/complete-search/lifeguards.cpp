#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("lifeguards");

    int n;
    cin >> n;

    vector<pair<int, int>> cows (n);
    
    for (auto &cow: cows)
    {
        cin >> cow.first >> cow.second;
    }

    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        int left = -1;
        int right = 0;
        for (int j = 0; j < n; j++)
        {
            if( j != i ){
                if(cows[j].first > right){
                    total += (right - left);
                    left = cows[j].first;
                    right = cows[j].second;
                } else if (cows[j].second > right){
                    right = cows[j].second;
                }            
            }
        }
        total += (right - left) - 1;
        ans = max(total, ans);
    }
    
    cout << ans << endl;
}