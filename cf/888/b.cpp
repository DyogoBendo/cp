#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int>numbers;    
    set<int> odd;
    set<int> even;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);

        if(x %2)odd.insert(i);
        else even.insert(i);
    }
    
    sort(numbers.begin(), numbers.end());

    int possible = 1;

    for (int i = 0; i < n; i++)
    {
        if(!possible) break;
        int curr = numbers[i];
        if(curr % 2 == 0){
            if(even.find(i) == even.end()) possible = 0;
        } else{
            if(odd.find(i) == odd.end()) possible = 0;
        }
    }
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}