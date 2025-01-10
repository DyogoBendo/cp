// https://usaco.org/index.php?page=viewproblem2&cpid=786

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define int long long

class Cow {
    public: 
        int l;
        int r;
};

signed main(){
    setIO("lifeguards");

    int n;
    cin >> n;

    vector<Cow> cows(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].l >> cows[i].r;
    }
    
    sort(cows.begin(), cows.end(), [](const Cow &c1, const Cow &c2){return c1.l < c2.l;});

    int total = 0;
    int right = 0;
    for (int i = 0; i < n; i++)
    {
        if(cows[i].r > right){
            int add = cows[i].r - max(right, cows[i].l);
            total += add;
            right = cows[i].r;
        }
    }


    int alone = total;
    right = 0;

    for (int i = 0; i < n; i++)
    {
        int prox_begin = i < n - 1? cows[i + 1].l : cows[i].r;
        int curr = max(min(prox_begin, cows[i].r) - max(right, cows[i].l), 0ll);

        alone = min(alone, curr);

        right = max(right, cows[i].r);
    }

    cout << total - alone << endl;
}