// https://codeforces.com/contest/1291/problem/D

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> psum(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        for (int j = 0; j < 26; j++)
        {
            psum[i + 1][j] = psum[i][j];
        }        
        psum[i + 1][c - 'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;

        bool possible = false;

        vector<int> qtd(26, 0);
        int total = 0;
        int diff = 0;
        int biggest = 0;
        for (int i = 0; i < 26; i++)
        {
            int x = psum[r][i] - psum[l - 1][i];            
            total += x;
            if(x) diff++;
            biggest = max(x, biggest);
        }        

        if(total== 1 || s[l - 1] != s[r - 1] || diff > 2) cout << "Yes";
        else cout << "No";
        cout << endl;         
    }
    
}