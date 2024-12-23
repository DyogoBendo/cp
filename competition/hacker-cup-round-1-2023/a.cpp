#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void solve(int c){         
    int n;    
    scanf("%d", &n);    
    vector<int> elvs;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);        
        elvs.push_back(x);
    }

    sort(elvs.begin(), elvs.end());

    double first = elvs[0];
    double second = elvs[1];
    double last = elvs[n - 1];
    double last1 = elvs[n - 2];
    double result = 0;
    if(n == 5){
        double third = elvs[2];
        double r1 = ((last + last1) / 2) - ((first + third) / 2) ;
        double r2 = ((last + third) / 2) - ((first + second) / 2);
        result = max(r1, r2);
    } else{
        result = ((last + last1) / 2) -  ((first + second) / 2);
    }
    
    ofstream myfile;

    myfile.open ("output.txt", ios_base::app);    
    myfile << fixed << "Case #" << c << ": " << result << endl;    
    myfile.close();    

}

int main(){
    FILE * ret = freopen("in.txt", "r", stdin);
    if(ret == NULL){
       printf("failed to open file");            
    }
    int t;
    int c = 0;
    scanf("%d", &t);
    while(t--) solve(++c);  
    fclose (stdout);  
}