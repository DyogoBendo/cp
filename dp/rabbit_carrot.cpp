#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 3;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int>poles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> poles[i];
    }

    vector<int> keep;

    for (int i = 1; i <= n; i++)
    {
        if(poles[i - 1] <= i * m) keep.push_back(i * m - poles[i - 1]);
    }

    vector<int> lis(n, INF);

    int ans = -1;
    for (int i = 0; i < keep.size(); i++)
    {
        int p = upper_bound(lis.begin(), lis.end(), keep[i]) - lis.begin();

        ans = max(ans, p);
        lis[p] = keep[i];
    }
    
    cout << n - max(ans + 1, 0) << endl;
    
}