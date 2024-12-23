#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cowqueue");

    int n;
    cin >> n;

    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cows.push_back({a, b});
    }

    sort(cows.begin(), cows.end());


    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        current_time = max(cows[i].first, current_time);
        current_time += cows[i].second;
    }

    cout << current_time << endl;
    
    
  
}