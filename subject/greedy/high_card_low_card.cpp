#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cardgame");

    int n;
    cin >> n;

    vector<int> cards(2*n + 1, 0);
    vector<int> elsie;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cards[x] = 1;
        elsie.push_back(x);
    }
    
    vector<int> bessie;

    for (int i = 1; i <= 2 * n; i++)
    {
        if(!cards[i]) bessie.push_back(i);
    }
    
    sort(bessie.begin(), bessie.end());

    set<int> highest;
    set<int> smallest;

    for (int i = 0; i < n /2; i++)
    {
        smallest.insert(bessie[i]);
    }
    for (int i = n/2; i < n; i++)
    {
        highest.insert(bessie[i]);
    }

    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        int current = elsie[i];

        auto defeat = highest.upper_bound(current);

        if(defeat != highest.end()){
            ans ++;
            highest.erase(defeat);
        }
    }
    for (int i = n/2; i < n; i++)
    {
        int current = elsie[i];

        auto defeat = smallest.upper_bound(current);

        if(defeat != smallest.begin()){
            ans ++;
            smallest.erase(--defeat);
        }
    }
    
    cout << ans << endl;
}