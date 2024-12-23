#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cownomics");

   int n, m;
   cin >> n >> m;

   vector<vector<int>> check_genes1(m, vector<int>(4, 0));
   vector<vector<int>> check_genes2(m, vector<int>(4, 0));


   for (int i = 0; i <  n; i++)
   {
    for (int j = 0; j < m; j++)
    {
        char c;
        cin >> c;

        int k;
        if(c == 'A') k = 0;
        else if (c == 'C') k = 1;
        else if(c == 'G') k = 2;
        else k = 3;

        check_genes1[j][k] = 1;
    }
    
   }

   for (int i = 0; i <  n; i++)
   {
    for (int j = 0; j < m; j++)
    {
        char c;
        cin >> c;

        int k;
        if(c == 'A') k = 0;
        else if (c == 'C') k = 1;
        else if(c == 'G') k = 2;
        else k = 3;

        check_genes2[j][k] = 1;
    }
    
   }

    int count = 0;
   for (int i = 0; i < m; i++)
   {
    int possible = 1;
    for (int j = 0; j < 4; j++)
    {
        if(check_genes2[i][j] && check_genes1[i][j]) possible = 0;
    }
    
    count += possible;
   }
   
   cout << count << endl;
    
}