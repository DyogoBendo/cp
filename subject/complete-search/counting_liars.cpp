#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    // setIO("promote");

    int n;
    cin >> n;

    vector<pair<int, char>> entries;

    for (int i = 0; i < n; i++)
    {
        char c;
        int v;
        cin >> c >> v;
        entries.push_back({v, c});
    }

    sort(entries.begin(), entries.end());

    vector<int> lying_left(n, 0);
    vector<int> lying_right(n, 0);
    for (int i = 1; i < n; i++)
    {
        lying_left[i] = lying_left[i - 1];

        if(entries[i - 1].second == 'L' && entries[i].first > entries[i - 1].first){
            lying_left[i]++;
        }
    }
    for (int i = n - 2; i > - 1; i --)
    {
        lying_right[i] = lying_right[i + 1];

        if(entries[i + 1].second == 'G' && entries[i].first < entries[i + 1].first){
            lying_right[i]++;
        }
    }
    
    int ans = n + 1;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, lying_left[i] + lying_right[i]);
    }

    cout << ans << endl;
    
    
}