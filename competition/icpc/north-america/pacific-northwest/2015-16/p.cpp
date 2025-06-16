#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    string s;
    ll count = 0, erase = 0;
    cin >> s;

    vector<ll> active(26, 0);
    for (ll i = 0; i < s.size(); i++){
        int chr = s[i] - '0';
        chr = chr - 49;
        if(active[chr] == 0) {
            count++;
        }
        active[chr] += 1;
    }

    sort(active.begin(), active.end());

    for (ll i = 0; i < 26; i++) {
        if(count <= 2) break;
            if(active[i] != 0) {
                count--;
                erase += active[i];
            } 
    }

    cout << erase << endl;
}