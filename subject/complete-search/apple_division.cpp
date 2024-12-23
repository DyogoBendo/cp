#include <bits/stdc++.h>

using namespace std;
long long ans;
int n;
vector<long long> apples;

void check(vector<int> *group, int k){
    if(k == n){
        long long g0 = 0;
        long long g1 = 0;

        for (int i = 0; i < n; i++)
        {
            if(group->at(i)){
                g0 += apples[i];
            } else{
                g1 += apples[i];
            }
        }
    
        ans = min(ans, abs(g0 - g1));
        return;
    }

    group->at(k) = 0;
    check(group, k + 1);

    group->at(k) = 1;
    check(group, k + 1);
}

int main(){
    cin >> n;

    ans = 0;
    for (int i = 0; i < n; i ++)
    {
        long long x;
        cin >> x;
        apples.push_back(x);
        ans += x;
    }
    
    vector<int> group (n, 0);
    check(&group, 0);

    cout << ans << endl;
}