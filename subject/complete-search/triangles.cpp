/*
USACO 2020 January Contest, Bronze
Problem 1. Word Processor
*/

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("triangles");

    int n;
    cin >> n;
    vector<pair<int, int>> points (n);

    for (auto &p : points)
    {
        cin >> p.first >> p.second;
    }

    int ans = 0;
    for (auto p1 : points)
    {

        for (auto p2 : points)
        {
            if(p2.second == p1.second){
                for (auto p3: points)
                {
                    if(p3.first == p1.first){
                        int area = (abs(p3.second - p1.second)) * (abs(p2.first - p1.first));
                        ans = max(area, ans);
                    }
                }
            }
            
        }
        
    }
    
    cout << ans << endl;
    
}