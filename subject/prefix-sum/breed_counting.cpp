#include <bits/stdc++.h>
using namespace std;


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("bcount");

    int n, q;
    cin >> n >> q;

    vector<vector<int>> cow_counting(3, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x--;
        cow_counting[x][i] ++;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cow_counting[i][j] += cow_counting[i][j-1];
        }
        
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        for (int i = 0; i < 3; i++)
        {
            cout << cow_counting[i][r] - cow_counting[i][l - 1];
            if(i < 2) cout << " ";
        }
        cout << endl;        
    }
    
    
}