#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    // setIO("split");
    int n;
    cin >> n;


    vector<pair<int, int>> cow(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cow[i].first >> cow[i].second;
    }

    sort(cow.begin(), cow.end());

    int x1, x2, y1, y2;
    x1 = x2 = y1 = y2 = 0;

    for (int i = 0; i < n; i++)
    {
        if(cow[i].second > y1 ) y1 = cow[i].second, x1 = i;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(cow[i].second >= y2 ) y2 = cow[i].second, x2 = i;
    }

    int areaUnique = y1 * cow[n - 1].first;

    int ans = areaUnique;

    int currentMax = 0;
    for (int i = n - 1; i > x1; i--)
    {
        currentMax = max(currentMax, cow[i].second);
        int a1 = y1 * (cow[i - 1].first - cow[0].first + 1);
        int a2 = currentMax * (cow[n - 1].first - cow[i].first + 1);
    }
    

}