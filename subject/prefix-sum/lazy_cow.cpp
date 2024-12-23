#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    // setIO("lazy");

    int n, k;
    cin >> n >> k;

    int n2 = 2 * n - 1;

    vector<vector<int>> grass(n2, vector<int>(n2, -1));
    vector<vector<int>> prefix_sum(n2, vector<int>(n2, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grass[i + j][-i + j + n - 1];
        }        
    }
        
    int ans = 0;
    for (int i = 0; i < n2; i++)
    {        
        for (int j = 0; j < n2; j++)
        {
            int current = max(grass[i][j], 0);

            if(i) current += prefix_sum[i - 1][j];
            if(j) current += prefix_sum[i][j - 1];
            if(i && j) current -= prefix_sum[i - 1][j - 1];

            prefix_sum[i][j] = current;            
        }                
    }    
    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%3d ", prefix_sum[i][j]);
        }

        cout << endl;
    }
    
    cout << endl;

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(grass[i][j] == -1) continue;

            int right = min(n2 - 1, j + k);
            int left = max(0, j - k - 1);
            int top = max(0, i - k - 1);
            int bot = min(n2 - 1, i + k);
            int total = prefix_sum[right][bot] - prefix_sum[right][top] - prefix_sum[left][bot] + prefix_sum[left][top];

            ans = max(total, ans);
        }
        
    }
    
    cout << ans << endl;
    
}