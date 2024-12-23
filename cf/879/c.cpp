#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int count = 0;
    int count_reverse = 0;

    for (int i = 0; i < n; i++)
    {
        if(s1[i] == s2[i]) continue;
        count ++;
    }

    for (int i = 0; i < n; i++)
    {
        if(s1[n - 1 - i] == s2[i]) continue;
        count_reverse ++;
    }

    int result_count = (2 * count) - (count % 2);
    int result_count_rev = (2 * count_reverse) - (1 - (count_reverse % 2));
    if(result_count_rev == -1) result_count_rev = 2;

    cout << min(result_count, result_count_rev) << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}