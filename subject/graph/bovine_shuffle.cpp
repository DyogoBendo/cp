#include <bits/stdc++.h>

using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> f;
vector<int> visited;

int find_cycle(int i){
    int x = i, y = i, conta = 0, conta2 = 0;
    do
    {
        if(visited[x]) return 0;        
        conta ++;
        visited[x] = 1;
        x = f[x];
        y = f[f[y]];
    } while (x != y);    
        
    while(!visited[y]){                
        conta ++;
        visited[y] = 1;
        y = f[y];
    }

    y = i;

    while(y != x){        
        conta2 ++;
        y = f[y];
        x = f[x];
    }

    return conta - conta2;
    
}

int main() {
	setIO("shuffle");

    int n;
    cin >> n;

    f.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        f[i]--;
    }    

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]) ans += find_cycle(i);
    }
    
    
    cout << ans << endl;
}