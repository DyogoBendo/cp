#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<int> permutations(n);    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;        
        permutations[v[i]] = i;
    }    
    cin >> s;

    vector<int> diffArray(n, 0);

    for (int i = 0; i < n; i++)
    {
        int l = min(i, permutations[i]);
        int r = max(i, permutations[i]);
        diffArray[l]++; diffArray[r]--;
    }
    for (int i = 1; i < n; i++)
    {
        diffArray[i] += diffArray[i - 1];
    }
    
    
    set<int> invalid;

    for (int i = 0; i < n - 1; i++)
    {
        if(diffArray[i] && (s[i] == 'L' && s[i + 1] == 'R' )){
            invalid.insert(i);
        }
    }

    while(q--){
        int x; 
        cin >> x;

        x--;

        if(s[x] == 'L') s[x] = 'R';
        else s[x] = 'L';

        if(x < n - 1 && s[x] == 'L' && s[x + 1] == 'R' && diffArray[x]){
            invalid.insert(x);
        } else{
            invalid.erase(x);
        }

        if(x > 0 && s[x - 1] == 'L' && s[x] == 'R' && diffArray[x - 1]){
            invalid.insert(x - 1);
        } else{
            invalid.erase(x - 1);
        }

        if(invalid.size()){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}