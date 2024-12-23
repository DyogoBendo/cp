#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> letters(26, 0);    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int i = 0; i < 26; i++)
        {
            if(letters[i] == a){
                char k = 'a' + i;
                cout << k;
                letters[i] ++;
                break;
            }
        }
        
    }
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}