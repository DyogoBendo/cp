#include <bits/stdc++.h>

using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("outofplace");

    int n;
    cin >> n;

    vector<int> cows;
    vector<int> sorted_cows;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cows.push_back(x);
        sorted_cows.push_back(x);
    }

    sort(sorted_cows.begin(), sorted_cows.end());
    
    
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if(sorted_cows[i] != cows[i]) ans ++;
    }
    
    cout << ans << endl;
}