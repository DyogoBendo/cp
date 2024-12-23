#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    sort(a.begin(), a.end());

    int possible = 0;

    int c = 1;
    int current = a[n - 1];
    for (int i =  n - 2; i >= 0; i--)
    {        
        if(a[i] == current) c ++;
        else{
            if(c % 2) possible = 1;
            c = 1;
            current = a[i];
        }
    }


    if(c % 2) possible = 1;
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}