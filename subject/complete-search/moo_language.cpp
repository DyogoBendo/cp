#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int cows[20], stalls[101], price[10], be[10], en[10], cool[10], current[10];

void solve(int i){
    if(i == m){
        int covered_stalls[101] = {0};
        int current_price = 0;
        for (int j = 0; j < m; j++)
        {
            if(current[j]){
                current_price += price[j];
                for (int a = be[j], b = en[j]; a <= b; a++)
                {
                    covered_stalls[a] += cool[j];
                }
                
            }

        }

        int possible = 1;

        for (int j = 0; j < 101; j++)
        {
            if(covered_stalls[j] < stalls[j]){
                possible = 0;
                break;
            }
        }
        
        if(possible){
            ans = min(ans, current_price);
        }
        
        return;
    }
    current[i] = 1;
    solve(i + 1);
    current[i] = 0;
    solve(i + 1);
}

int main(){
    ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int s, t, c;
        cin >> s >> t >> c;
        for (int j = s; j <= t; j++)
        {
            stalls[j] = c;
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, p, c;
        cin >> a >> b >> p >> c;
        ans += c + 1;
        be[i] = a;
        en[i] = b;
        cool[i] = p;
        price[i] = c;
    }
    solve(0);
    cout << ans << endl;
    
}