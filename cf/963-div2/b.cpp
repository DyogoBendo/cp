#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> numbers (n);    
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int biggest_odd = 0;

    int biggest_even = 0;

    int count_even = 0;

    for (int i = 0; i < n; i++)
    {
        if(numbers[i] % 2) biggest_odd = numbers[i];
        if(numbers[i] % 2 == 0){
            biggest_even = numbers[i];
            count_even ++;
        }

    }

    for (int i = 0; i < n; i++)
    {
        if(numbers[i] % 2 == 0 && numbers[i] < biggest_odd){
            biggest_odd += numbers[i];
        }
    }
    

    int ans = count_even;

    if(biggest_odd == 0){   
        cout << 0 << endl;
        return;
    }

    if(biggest_odd < biggest_even) ans ++;
    
    cout << ans << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}