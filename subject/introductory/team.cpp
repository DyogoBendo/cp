#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> a = vector(3, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j][i];
        }
        
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int condition = 0;
        for (int j = 0; j < 3; j++)
        {
            condition += a[j][i];
        }
        
        if(condition > 1) total ++;
    }

    cout << total << endl;
    
    
}