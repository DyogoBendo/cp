#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;

    int a = 0;
    for (int i = 0; i < 5; i++)
    {
        if(s[i] == 'A') a++;
    }

    if(a > 2){
        cout << "A" << endl;
    } else{
        cout << "B" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}