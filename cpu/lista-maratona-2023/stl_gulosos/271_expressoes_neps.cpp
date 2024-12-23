#include <iostream>
#include <stack>

using namespace std;

int main(){
    int t;
    string a;
    cin >> t;

    for (int i = 0; i < t; i ++){
        string a;
        bool isValid = true;
        stack<char> st;
        cin >> a;
        
        for (char c : a){
            if (c == '{' || c == '[' || c == '('){
                st.push(c);
            } else{
                if (st.empty()){
                    isValid = false;
                } else{
                    char current = st.top();
                st.pop();

                if (current == '{' && c != '}'){
                    isValid = false;
                }
                if(current == '[' && c != ']'){
                    isValid = false;
                }
                if(current == '(' && c != ')'){
                    isValid = false;
                }
                }
                
            }
        }

        if (st.size() > 0){
            isValid = false;
        }

        if(isValid){
            cout << 'S' << endl;
        } else{
            cout << 'N' << endl;
        }

    }
}
