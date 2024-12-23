#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void solve(int c){
    ofstream myfile;

    myfile.open ("output.txt", ios_base::app);    
    myfile << "Case #" << c << endl;    
    myfile.close();

}

int main(){
    int t;
    int c = 0;
    cin >> t;
    while(t--) solve(++c);    
}