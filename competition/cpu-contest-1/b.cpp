#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;

    int j = n - 1;
    int i = j;
    int curr = 0;

    while(i >= 0){
        curr += v[i];

        while(j >= i && curr > t){
            curr -= v[j];
            j --;            
        }

        ans = max(ans, j - i + 1);
        i--;
    }

    cout << ans << endl;
    
    
}