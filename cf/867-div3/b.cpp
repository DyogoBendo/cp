#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> v;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        
        // check the two biggest and two smallest

        long long m = 0;
      
        sort(v.begin(), v.end());
        long long smaller = v[0] * v[1];
        long long bigger = v[n - 1] * v[n - 2];
      
        m = max(smaller, bigger);

        cout << m << endl;

    }
}