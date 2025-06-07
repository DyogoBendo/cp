#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int a, b, m;
    cin >> a >> b >> m;    

    int m1[2][2] = {{0, 1}, {1, 1}};
    int m2[2][2] = {{0, 1}, {1, 1}};

    auto mul = [&](int m1[2][2], int m2[2][2]){
        int tmp[2][2];        
        
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                tmp[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    tmp[i][j] += (m1[i][k] * m2[k][j]) % m;
                    tmp[i][j] %= m;
                }                
            }            
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                m1[i][j] = tmp[i][j];
            }
            
        }
                
    };

    auto fast_expo1 = [&](int x){        
        int tmp[2][2] = {{0, 1}, {1, 1}};
        while(x){
            if(x%2){                
                mul(m2, tmp);
            }            
            mul(tmp, tmp);
            x/=2;            
        }
    };

    auto fast_expo2 = [&](int x){                
        while(x){
            if(x%2){                
                mul(m1, m2);
            }            
            mul(m2, m2);
            x/=2;            
        }
    };
    
    fast_expo1(a%m);        
    fast_expo2(b%m);    

    cout << m1[0][0] << endl;
}