/*
USACO 2020 January Contest, Bronze
Problem 1. Word Processor
*/

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("buckets");
    int bi, bj, ri, rj, li, lj;
    for (int i = 0; i < 10; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 10; j++)
        {
            if(row[j] == 'B'){
                bi = i;
                bj = j;
            } else if(row[j] == 'L'){
                li = i;
                lj = j;
            } else if(row[j] == 'R'){
                ri = i;
                rj = j;
            }
        }
        
    }

    int dist = abs(bi - li) + abs(bj - lj) - 1;

    if(bi == li && ri == li && ((bj < rj && rj < lj) || (lj < rj && rj < bj)) ){
        dist += 2;
    }

    if(bj == lj && rj == lj && ((bi < ri && ri < li) || (li < ri && ri < bi)) ){
        dist += 2;
    }
    cout << dist << endl;
}