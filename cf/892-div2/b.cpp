#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    vector<pair<long long, long long>> smaller;
    long long smallest = 1000000000 + 1;
    long long smallest_second = 1000000000 + 1;
    long long smallest_second_p = -1;
    for (long long i = 0; i < n; i++)
    {
        long long m;
        cin >> m;
        vector<long long> current;
        for (long long j = 0; j < m; j++)
        {
            long long x;
            cin >> x;
            current.push_back(x);
        }
        sort(current.begin(), current.end());

        smaller.push_back({current[0], current[1]}); 
        if(current[0] < smallest){
            smallest = current[0];            
        }
        if(current[1] < smallest_second){
            smallest_second = current[1];
            smallest_second_p = i;
        }
    }

    long long ans = smallest;

    for (long long i = 0; i < n; i++)
    {
        if(i == smallest_second_p) continue;
        ans += smaller[i].second;
    }
    
    cout << ans << endl;
    
}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();
}