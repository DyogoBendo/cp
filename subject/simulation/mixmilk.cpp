/*
    USACO 2018 December Contest, Bronze
    Problem 1. Mixing Milk
*/

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("mixmilk");

    int c1, c2, c3, m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i = 0; i < 100; i++)
    {
        if(i % 3 == 0){
            if(m2 + m1 <= c2){
                m2 += m1;
                m1 = 0;
            } else{
                m1 = m1 + m2 - c2;
                m2 = c2;
            }
        } else if(i % 3 == 1){
            if(m3 + m2 <= c3){
                m3 += m2;
                m2 = 0;
            } else{
                m2 = m2 + m3 - c3;
                m3 = c3;
            }
        } else{
            if(m1 + m3 <= c1){
                m1 += m3;
                m3 = 0;
            } else{
                m3 = m3 + m1 - c1;
                m1 = c1;
            }
        }
    }
    
    cout << m1 << endl << m2 << endl << m3 << endl;
}