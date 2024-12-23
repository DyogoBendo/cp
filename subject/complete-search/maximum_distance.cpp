#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        y.push_back(a);
    }

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            m = max(m, dx * dx + dy *dy);    
        }
        
    }
    cout << m << endl;
    
    
    
}