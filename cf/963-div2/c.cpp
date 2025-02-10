#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;

    cin >> n >> k;

    vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    int start = values[n - 1];

    int mi = start;
    int ma = start + k - 1;

    for (size_t i = 0; i < n - 1; i++)
    {
        int b = (start - values[i]) / k;
        if((start - values[i]) % k == 0){        
            if(b % 2 != 0){
                mi = ma + 1;
            }
        } else{
            if(b % 2 == 1){
                int c = values[i]  + ((b + 1) * k);
                mi = max(mi, c);
            } else{
                int c = values[i]  + ((b + 1)  * k) - 1;
                ma = min(ma, c);
            }
        }        
    }
    

    if(mi > ma){
        cout << -1 << endl;
    } else{
        cout << mi << endl;
    }
       
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}