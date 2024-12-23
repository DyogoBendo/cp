#include <bits/stdc++.h>

using namespace std;

#define int long long

bool compare(int a, int b){
    return a > b;
}

signed main(){
    int n;
    cin >> n;

    vector<int> a (n);
    vector<int> b (n);

    for (auto &x: a)
    {
        cin >> x;
    }
    for (auto &x: b)
    {
        cin >> x;
    }
    
    vector<pair<int, int>> positionValues;

    for (int i = 0; i < n; i++)
    {
        int ocurrences = (n - i) * (i + 1);
        int value = ocurrences * a[i];

        positionValues.push_back({value, i});
    }
    
    sort(positionValues.begin(), positionValues.end());
    
    int ans = 0;

    sort(b.begin(), b.end(), compare);
    for (int i = 0; i < n; i++)
    {                        
        int value = positionValues[i].first * b[i];
        ans += value;
    }

    cout << ans << endl;

}