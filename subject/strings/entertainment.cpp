#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n >> s;

    int invert = 0;

    for (int i = 0; i < s.size() / 2; i++)
    {
        if(s[i] < s[s.size() - 1 - i]){
            break;
        } else if(s[i] > s[s.size() - 1 - i]){
            invert = 1;
            break;
        }
    }
    

    if(!invert){
        cout << s << endl;
    } else{
        string s2 = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            s2 += s[i];
        }
        
        cout << s2 << s << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}