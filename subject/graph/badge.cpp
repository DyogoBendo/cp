#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int solve(int i){
    int a = i, b = i;
    
    do
    {
        a = v[a];
        b = v[v[b]];
    } while (a != b);
    

    while(i != a){
        i = v[i];
        a = v[a];
    }

    return i + 1;
}

int main(){
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] --;
    }

    for (int i = 0; i < n; i++)
    {
        cout << solve(i) << " ";
    }
    cout << endl;
    
    
}