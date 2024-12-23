#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("traffic");

    int LIMIT = 1e9;

    int n;
    cin >> n;
    vector<tuple<string, int, int>> queries;

    for (int i = 0; i < n; i++)
    {
        string s;
        int a, b;
        cin >> s >> a >> b;
        queries.push_back(tie(s, a, b));
    }
    
    int low = -LIMIT;
    int high = LIMIT;

    for (int i = n - 1; i >= 0; i--)
    {
        string s;
        int a, b;
        tie(s, a, b) = queries[i];

        if(s == "none"){
            low = max(low, a);
            high = min(high, b);
        } else if(s == "on"){
            low -= b;
            high -= a;
            low = max(0, low);
        } else{
            low += a;
            high += b;
        }
    }

    cout << low << " " << high << endl;

    low = -LIMIT;
    high = LIMIT;

    for (int i = 0; i < n; i++)
    {
        string s;
        int a, b;
        tie(s, a, b) = queries[i];

        if(s == "none"){
            low = max(low, a);
            high = min(high, b);
        } else if(s == "on"){
            low += a;
            high += b;
        } else{
            low -= b;
            high -= a;
            low = max(low, 0);
        }
    }
    cout << low << " " << high << endl;
     
}