#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> salt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        salt.push_back(x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        salt[i + 1] = max(salt[i + 1], salt[i] - m);
    }
    for (int i = n - 1; i > 0; i--)
    {
        salt[i - 1] = max(salt[i - 1], salt[i] - m);
    }
    

    for (int i = 0; i < n; i++)
    {
        cout << salt[i] << " ";
    }
    
    cout << endl;
    
}