#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> planks;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x --;
        planks.push_back(x);
    }

    vector<int> biggest(k, 0);
    vector<int> sbiggest(k, 0);
    vector<int> current_position(k, -1);

    for (int i = 0; i < n; i++)
    {
        int c = planks[i];
        int last = current_position[c];
        int distance = (i - last - 1);

        if(distance >= biggest[c]){
            sbiggest[c] = biggest[c];
            biggest[c] = distance;
        } else{
            if(distance > sbiggest[c]) sbiggest[c] = distance;
        }

        current_position[c] = i;
    }
    
    for (int i = 0; i < k; i++)
    {
        int distance = n - current_position[i] - 1;
        if(distance >= biggest[i]){
            sbiggest[i] = biggest[i];
            biggest[i] = distance;
        } else{
            if(distance > sbiggest[i]) sbiggest[i] = distance;
        }
    }
    
    int smaller = n + 1;
    for (int i = 0; i < k; i++)
    {
        int current = max(biggest[i] / 2, sbiggest[i]);
        smaller = min(smaller, current);
    }
    
    cout << smaller << endl;
}

int main(){
    int t;

    cin >> t;
    while(t--) solve();
}