#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int &x: v) cin >> x;


    int start = n - 1;
    for (; start > 0; start--)
    {
        if(v[start - 1] > v[start]) break;
    }

    cout << start << endl;
}