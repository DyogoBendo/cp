#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> company;
vector<int> ans;

int calculate(int curr){
    int c = 0;

    for (auto v : company[curr])
    {
        c += calculate(v) + 1;
    }

    ans[curr] = c;
    return c;
}

int main(){
    int n;
    cin >> n;

    company.resize(n);
    ans.resize(n);

    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a --;

        company[a].push_back(i);
    }
    
    calculate(0);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
    

}