#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;

    int current = 0;

    vector<char> letters = {'m', 'e', 'o', 'w'};
    

    int possible = 1;
    for (int i = 0; i < n; i++)
    {
        char c = tolower(s[i]);        
        if(c == letters[current]) continue;
        if(current == 3 || (current == 0 && i == 0)) {
            possible = 0; break;        
        }
        current ++;
        if(c == letters[current]) continue;
        possible = 0;
        break;
    }

    if(current != 3) possible = 0;
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        solve();
    }
}