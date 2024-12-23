#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("diamond");
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> sufix_max(n, 1);

    int right = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int current = v[i];
        while(v[i] + k < v[right]){
            right --;
        }

        sufix_max[i] = max(sufix_max[i + 1], right - i + 1);
    }
    
    int ans = 0;
    right = 0;
    for (int i = 0; i < n; i++)
    {
        while(v[i] + k >= v[right] && right < n){
            right ++;
        }
        right --;        

        int q1 = right - i + 1;
        int q2 = 0;
        if(right < n - 1) q2 = sufix_max[right + 1];

        ans = max(ans, q1 + q2);
    }
    
    cout << ans << endl;
}