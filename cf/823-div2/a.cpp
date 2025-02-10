#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, c;
    cin >> n >> c;

    vector<int> orbits(100, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        orbits[--a] ++;
    }
    
    int total_planets = 0;
    int total_cost = 0;

    for (int i = 0; i < 100; i++)
    {
        if(orbits[i] > c){
            total_planets += orbits[i];
            total_cost += c;
        }
    }

    cout << total_cost + n - total_planets << endl; 
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}