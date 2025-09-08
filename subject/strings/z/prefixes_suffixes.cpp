#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    vector<int> z(n);
    z[0] = n;

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        z[i] = max(0, min(r - i + 1, z[i - l]));

        while(z[i] + i < n && s[z[i]] == s[z[i] + i]){
            l = i;
            r = z[i] + i;
            z[i] ++;
        }


    }

    vector<int> psum(n + 1, 0);
    vector<int> ans(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {        
        int p = z[i];
        psum[p] ++;    
        if(i + p == n){            
            ans[p] = 1;
        }
    }
    
    int current = 0;
    vector<pair<int, int>> a;
    for (int i = n; i >= 0; i--)
    {
        current += psum[i];
        if(ans[i]){
            a.push_back({i, current});
        }
    }

    reverse(a.begin(), a.end());

    cout << a.size() << endl;
    for (auto as : a)
    {
        cout << as.first << " " << as.second << endl;
    }
    

}