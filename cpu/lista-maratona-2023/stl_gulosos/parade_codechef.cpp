    #include <iostream>
    #include <stack>
    #include <vector>
    #include <queue>

    using namespace std;

    int main(){
        int t, n;
        stack<int> s;

        cin >> t;
        
        for (size_t i = 0; i < t; i++)
        {
            bool isPossible = true;
            cin >> n;
            queue<int>q;
            int truck;
            for (size_t j = 0; j < n; j++)
            {
                cin >> truck;
                q.push(truck);
            }
            

            int currentValue = 1;
            while(!q.empty())
            {
                int truck = q.front();                
                if (truck == currentValue)
                {
                    currentValue ++;
                    q.pop();
                } else{
                    if (!s.empty())
                    {
                        if (s.top() == currentValue)
                        {
                            s.pop();
                            currentValue ++;
                        } else{
                            s.push(truck);
                            q.pop();
                        }
                    }else{
                        s.push(truck);
                        q.pop();
                    }                    
                    
                }
            }            

            if (!s.empty())
            {
                int lastValue = s.top();
                s.pop();
                while (!s.empty())
                {            
                    int newValue = s.top();
                    s.pop();
                    if (newValue < lastValue )
                    {
                        isPossible = false;
                    }
                    lastValue = newValue;
                    
                }
            }        

            if (isPossible)
            {
                cout << "yes" << endl;
            } else{
                cout << "no" << endl;
            }
                    
        }
        
    }