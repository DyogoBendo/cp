#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    vector<int> ans;
    vector<int> possible(n, 1);
    for (int i = 0; i < c; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < b; j++)
        {
            int x;
            cin >> x;
            possible[x - 1] = 0;
        }        
    }

    for (int i = 0; i < n; i++)
    {
        if(possible[i]) cout << i + 1 << endl;
    }
    
}