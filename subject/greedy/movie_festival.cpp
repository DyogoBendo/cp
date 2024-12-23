#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> m(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m[i].second >> m[i].first;
    }

    sort(m.begin(), m.end());


    int current_end = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i].second >= current_end){
            current_end = m[i].first;
            ans ++;        
        }
    }
    
    cout << ans << endl;
}