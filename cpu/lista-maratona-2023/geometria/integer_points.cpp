#include <bits/stdc++.h>


using namespace std;

int main(){
    long long t, n, m, n_even, n_odd, m_even, m_odd, tmp;
    cin >> t;

    while(t){
        t --;
        n_even = 0;
        n_odd = 0;
        m_even = 0;
        m_odd = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {            
            cin >> tmp; 
            if(tmp & 1){
                n_odd ++;
            } else{
                n_even ++;
            }
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            if(tmp & 1){
                m_odd ++;
            } else{
                m_even ++;
            }
        }
        
        cout << m_odd * n_odd + n_even * m_even << endl;        
    }
}