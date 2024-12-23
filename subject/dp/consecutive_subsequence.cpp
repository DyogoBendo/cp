#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int, vector<int>> position;
    map<int, int> lis;

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        lis[x] = lis[x - 1] + 1;

        position[x].push_back(i);

        if(lis[x] > ans){
            ans = lis[x];
            p = x;
        }
    }
    cout << ans << endl;

    vector<int> a(ans);

    int curr = position[p][position[p].size() - 1];
    a[ans - 1] = curr;
    for (int i = 1; i < ans; i++)
    {
        
        int b = lower_bound(position[p - i].begin(), position[p - i].end(), curr) - position[p-i].begin(); 
        b--;
        curr = position[p - i][b];
        a[ans - 1 - i] = curr;
    }

    for (int i = 0; i < ans; i++)
    {
        cout << a[i] + 1 << " ";
    }
    
    cout << endl;
       
}