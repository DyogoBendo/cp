#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main (){
    int n; 
    cin >> n;
    vector<int> numbers;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
        m = min(m, x);
    }

    int ans = m, current =0;

    for (int i = 0; i < n; i++)
    {        
        current += numbers[i];
        if(current < 0){
            ans = max(ans, current);
            current = 0;
        } else{
            ans = max(ans, current);
        }

    }

    cout << ans << endl;
}