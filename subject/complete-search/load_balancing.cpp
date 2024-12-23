#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("balancing");
    
    int n, b;
    cin >> n;


    vector<pair<int, int>> cows;
    set<int> unique_x;
    set<int> unique_y;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        unique_x.insert(x + 1);
        unique_y.insert(y + 1);
        cows.push_back(make_pair(x, y));
    }

    int m = n + 1;
    
    for (auto ux: unique_x)
    {
        for (auto uy: unique_y)
        {
            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
            for (auto cow: cows)
            {
                if(cow.first < ux && cow.second < uy) q1 ++;
                if(cow.first < ux && cow.second > uy) q2 ++;
                if(cow.first > ux && cow.second < uy) q3 ++;
                if(cow.first > ux && cow.second > uy) q4 ++;
            }
            int tmp = max({q1, q2, q3, q4});
            m = min(tmp, m);
        }
        
    }
    cout << m << endl;   

}