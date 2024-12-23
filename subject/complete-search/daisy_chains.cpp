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

    vector<int> flowers (n);
    for (auto &x: flowers)
    {
        cin >> x;
    }
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int total = 0;
            for (int k = i; k <= j; k++)
            {
                total += flowers[k];
            }

            if(total % (j - i + 1)) continue;
            int average = total / (j - i + 1);

            int possible = 0;
            
            for (int k = i; k <= j; k++)
            {
                if(flowers[k] == average) possible = 1;
            }
            
            if (possible) ans ++;
            
        }
        
    }
    
    cout << ans << endl;
    
}