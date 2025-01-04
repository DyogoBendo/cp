#include <bits/stdc++.h>

using namespace std;

int qtd = 0;
int b1 = 0, b2 = 0, b3 = 0;
int i1 = -1, i2 = -1, i3 = -1;

void add(int x){
    qtd ++;
    if(x > b1){
        b3 = b2;
        b2 = b1;
        b1 = x;

        i3 = i2;
        i2 = i1;
        i1 = qtd;

        return;
    }
    if(x > b2){
        b3 = b2;
        b2 = x;

        i3 = i2;
        i2 = qtd;
        return;
    }
    if(x > b3){
        b3 = x;
        i3 = qtd;
    }

}

int main(){
    int n;
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;

        if(x) add(x);
        else{
            if (qtd == 0) cout << "0" << endl;
            else if(qtd == 1){
                cout << "pushStack" << endl;
                cout << "1 popStack" << endl;
            }
            else if(qtd == 2){                
                cout << "pushStack" << endl;
                cout << "pushQueue" << endl;
                cout << "2 popStack popQueue" << endl;
            } else{
                int i = 1;
                vector<int> idxes(3);
                idxes[0] = i1;
                idxes[1] = i2;
                idxes[2] = i3;
                sort(idxes.begin(), idxes.end());                

                while(i < idxes[0]){
                    cout << "pushStack" << endl;
                    i ++;
                }
                cout << "pushQueue" << endl;
                i++;
                while(i < idxes[1]){
                    cout << "pushQueue" << endl;
                    i++;
                }
                cout << "pushStack" << endl;
                i++;

                while(i < idxes[2]){
                    cout << "pushQueue" << endl;
                    i++;
                }
                cout << "pushFront" << endl;
                i++;
                
                while(i <= qtd){
                    cout << "pushQueue" << endl;
                    i++;
                }

                cout << "3 popStack popQueue popFront" << endl;
            }
            qtd = 0;
            i1 = i2 = i3 = -1 ;            
            b1 = b2 = b3 = 0;
        }
    }

    while(qtd--){
        cout << "pushQueue" << endl;
    }
    
}