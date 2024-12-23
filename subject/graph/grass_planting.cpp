#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("planting");
    int n;
    cin >> n;

    vector<int> edges_order(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        edges_order[--a] ++;
        edges_order[--b] ++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, edges_order[i]);
    }
    
    cout << ans + 1 << endl;
    
}