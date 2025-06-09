#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

int m1[2][2] = {{1, 0}, {0, 1}};
int m2[2][2] = {{0, 1}, {1, 1}};

void mul(int m1[2][2], int m2[2][2],  int m){
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
}

//  p^2 - 1 é um limite superior de um número que o período de qualquer primo divide, com exceção de 5 que é 20
int prime_period(int p){    
    return p == 5? 20 : p*p-1;
}

int fast_expo1(int a, int b, int period){ 
    int ans = 1;               
    while(b){
        if(b%2){                
            ans = (__int128) a * ans % period;
        }            
        a = (__int128) a * a % period;
        b/=2;            
    }
    return ans;
}

void fast_expo2(int x, int m){                
    while(x){
        if(x%2){                
            mul(m1, m2, m);
        }            
        mul(m2, m2, m);
        x/=2;            
    }
};


signed main(){
    // darvem;

    int a, b, m;
    cin >> a >> b >> m;    

    int x = m;
    int period = 1;    
    for (int p = 2; p * p <= x; p++)
    {        
        if(x % p) continue;
        int e, pow;
        for (e = 0, pow=1; x%p == 0; e++, pow*=p, x/=p);

        // por CRT, sabemos que pi(mn) se m e n são coprimos, é lcm(pi(m), pi(n))
        //  p^k = pi(p) * p ^ (k-1)  é divisível pelo perído
        period = lcm(period, prime_period(p) * (pow/p)); 
    }
    
    if(x != 1) period = lcm(period, prime_period(x));            
    
    int n = fast_expo1(a, b, period);           
    fast_expo2(n, m);    

    cout << m1[1][0] << endl;
}