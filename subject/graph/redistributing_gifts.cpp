#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n;

    vector<vector<int>> gifts(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            gifts[i].push_back(x);
        }
        
    }
    

    vector<vector<int>> graph(n);
       
}