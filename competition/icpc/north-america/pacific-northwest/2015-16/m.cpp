#include <bits/stdc++.h>

using namespace std;

int execute(int &v, string a, int x){
    if(a == "ADD"){
        v += x;
        return v >= 0;
    }
    if(a == "SUBTRACT"){
        v -= x;
        return v >= 0;
    }
    if(a == "MULTIPLY"){
        v *= x;
        return v >= 0;
    }
    if(v % x) return 0;
    v /= x;
    return v >= 0;
}

int main(){
    int n;
    cin >> n;

    vector<pair<string, int>> actions(n);

    for (int i = 0; i < n; i++)
    {
        cin >> actions[i].first; cin >> actions[i].second;
    }

    int ans = 0;
    for (int i =1; i <= 100; i++)
    {
        int v = i;
        bool valid = true;
        for (auto a : actions)
        {
            if(!execute(v, a.first, a.second)){
                valid = false;
                break;
            }
        }
        if(!valid) ans ++;        
    }

    cout << ans << endl;
    
    
}