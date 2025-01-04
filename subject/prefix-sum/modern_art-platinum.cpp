#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("art");

    int n;
    cin >> n;

    vector<int> colors(n*n, 1);
    vector<int> left(n*n, n);    
    vector<int> right(n*n, -1);    
    vector<int> bot(n*n, -1);    
    vector<int> top(n*n, n);    

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            x--;
            grid[i][j] = x;            
            if(x != -1){
                left[x] = min(left[x], j);
                right[x] = max(right[x], j);

                top[x] = min(top[x], i);
                bot[x] = max(bot[x], i);
            }
        }
        
    }

    vector<vector<int>> psum(n, vector<int>(n, 0));
    int appear = 0;

    for (int i = 0; i < n * n; i++)
    {
        int l = left[i], r = right[i], b = bot[i], t = top[i];
        if(b == -1) continue;
        appear ++;
        psum[t][l] ++;
        
        if(r < n - 1) psum[t][r + 1] --;
        if(b < n - 1) psum[b + 1][l] --;
        if(b < n - 1 && r < n - 1) psum[b + 1][r + 1] ++;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = psum[i][j];
            if(i > 0) sum += psum[i - 1][j];
            if(j > 0) sum += psum[i][j - 1];
            if(i > 0 && j > 0) sum -= psum[i - 1][j-1];
            psum[i][j] = sum;

            if(sum > 1) colors[grid[i][j]] = 0;
        }        
    }
    
    int ans = 0;    
    for (int i = 0; i < n * n; i++)
    {
        ans += colors[i];
    }    
    if(appear == 1) ans --;
    
    cout << ans << endl;
    
}