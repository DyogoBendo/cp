/*
USACO 2019 January Contest, Bronze
Problem 1. Shell Game
*/

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("shell");
    int position [3] = {0, 1, 2};
    int value[3] = {0, 0, 0};

    int a, b, c;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        swap(position[--a], position[--b]);        
        value[position[--c]] ++;
    }

    cout << max({value[0], value[1], value[2]}) << endl;
    
}
    