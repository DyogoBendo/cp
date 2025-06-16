#include <bits/stdc++.h>

using namespace std;

int get_value(int a, int b){
    if(a != 6 && b != 6) return 6;
    if(a != 5 && b != 5) return 5;
    return 4;
}

int get_o(int i){
    if(i == 0) return 5;
    if(i == 5) return 0;
    if(i == 1) return 3;
    if(i == 3) return 1;
    if(i == 2) return 4;
    if(i == 4) return 2;
    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<array<int, 6>> v(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> v[i][j];
        }
        
    }


    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        int o = get_o(i);

        int a = v[0][i];
        int b = v[0][o];

        int curr = get_value(a, b);
        for (int j = 1; j < n; j++)
        {
            int p2 = -1;
            int o2 = -1;
            for (int k = 0; k < 6; k++)
            {
                if(v[j][k] == b){
                    p2 = k;
                    o2 = get_o(k);
                    break;
                }
            }
            a = v[j][p2];
            b = v[j][o2];
            curr += get_value(a, b);            
        }        

        ans = max(ans, curr);
        
    }
    

    cout << ans << endl;
    
}