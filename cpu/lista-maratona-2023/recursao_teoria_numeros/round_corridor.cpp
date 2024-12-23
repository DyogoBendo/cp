#include <bits/stdc++.h>

using namespace std;

long long euclides(long long a, long long b){
    while(a % b){
        long long r = a % b;
        a = b;
        b = r;
    }
    return b;
}


int main(){
    long long n,m, q;
    cin >> n >> m >> q;

    long long mdc = euclides(n, m);
    
    long long nFactor = n/mdc;
    long long mFactor = m/mdc;    

    for (size_t i = 0; i < q; i++)
    {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        sy --;
        ey --;
        long long sRegion = sx == 1 ? sy / nFactor : sy / mFactor;
        long long eRegion = ex == 1 ? ey / nFactor : ey / mFactor;

        if(sRegion == eRegion){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
        
    }
    
}