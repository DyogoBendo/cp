#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e5 + 1;
const int MAX_VALUE = 1e6 + 1;

int vmax[MAX_SIZE];
int vmin[MAX_SIZE];
int n, m;

class Node{
    public:
    int v, b; // v indica o valor e b indica o balde
    Node(int v1, int b1){
        v = v1;
        b = b1;
    }
    Node(){
        v = -1;
        b = -1;
    }
};

class IntNode{
    public:
    Node n1, n2;

    IntNode(Node no1, Node no2){
        n1 = no1;
        n2 = no2;
    }

    IntNode(){
        n1 = Node();
        n2 = Node();
    }

};

IntNode segmin[4*MAX_SIZE];
IntNode segmax[4*MAX_SIZE];


IntNode build_min(int p = 1, int l = 0, int r = n - 1){
    if(l == r){
        Node n1(vmin[l], l);
        Node n2(MAX_VALUE, -1);
        IntNode in(n1, n2);
        return segmin[p] = in; 
    }
    int mid = (l + r) / 2;

    IntNode left = build_min(2*p, l, mid);
    IntNode right = build_min(2*p + 1, mid + 1, r);  

    Node n1, n2;

    if(left.n1.v < right.n1.v){
        n1 = left.n1;
        if(left.n2.v < right.n1.v){
            n2 = left.n2;
        } else{
            n2 = right.n1;
        }
    } else{
        n1 = right.n1;
        if(right.n2.v < left.n1.v){
            n2 = right.n2;
        } else{
            n2 = left.n1;
        }
    }

    IntNode ans(n1,n2);

    return segmin[p] = ans;
}

IntNode build_max(int p = 1, int l = 0, int r = n - 1){
   if(l == r){
        Node n1(vmax[l], l);
        Node n2(-1, -1);
        IntNode in(n1, n2);

        return segmax[p] = in; 
    }
    int mid = (l + r) / 2;

    IntNode left = build_max(2*p, l, mid);
    IntNode right = build_max(2*p + 1, mid + 1, r);  

    Node n1, n2;

    if(left.n1.v > right.n1.v){
        n1 = left.n1;
        if(left.n2.v > right.n1.v){
            n2 = left.n2;
        } else{
            n2 = right.n1;
        }
    } else{
        n1 = right.n1;
        if(right.n2.v > left.n1.v){
            n2 = right.n2;
        } else{
            n2 = left.n1;
        }
    }

    IntNode ans(n1,n2);

    return segmax[p] = ans;
}

IntNode update_min(int k, int u, int p = 1, int l = 0, int r = n - 1){
    Node t1(MAX_VALUE, -1);
    Node t2(MAX_VALUE, -1);
    if(l > r) return IntNode(t1, t2);
    if(u > r) return IntNode(t1, t2);
    if(u < l) return IntNode(t1, t2);

    if(l == r){
        vmin[u] = min(vmin[u], k);

        Node n1(vmin[u], u);
        return segmin[p] = IntNode(n1, t2);
    } 

    int mid = (l + r) / 2;

    IntNode left = segmin[2*p];
    IntNode right = segmin[2*p + 1];

    if(u <= mid){
        left = update_min(k, u, 2*p, l, mid);
    } else{
        right = update_min(k, u, 2*p + 1, mid + 1, r);
    }

    Node n1, n2;

    if(left.n1.v < right.n1.v){
        n1 = left.n1;
        if(left.n2.v < right.n1.v){
            n2 = left.n2;
        } else{
            n2 = right.n1;
        }
    } else{
        n1 = right.n1;
        if(right.n2.v < left.n1.v){
            n2 = right.n2;
        } else{
            n2 = left.n1;
        }
    }

    IntNode ans(n1,n2);

    return segmin[p] = ans;
}

IntNode update_max(int k, int u, int p = 1, int l = 0, int r = n - 1){
    Node t1(-1, -1);
    Node t2(-1, -1);
    if(l > r) return IntNode(t1, t2);
    if(u > r) return IntNode(t1, t2);
    if(u < l) return IntNode(t1, t2);

    if(l == r){
        vmax[u] = max(vmax[u], k);

        Node n1(vmax[u], u);
        return segmax[p] = IntNode(n1, t2);
    } 

    int mid = (l + r) / 2;

    IntNode left = segmax[2*p];
    IntNode right = segmax[2*p + 1];

    if(u <= mid){
        left = update_max(k, u, 2*p, l, mid);
    } else{
        right = update_max(k, u, 2*p + 1, mid + 1, r);
    }

    Node n1, n2;

    if(left.n1.v > right.n1.v){
        n1 = left.n1;
        if(left.n2.v > right.n1.v){
            n2 = left.n2;
        } else{
            n2 = right.n1;
        }
    } else{
        n1 = right.n1;
        if(right.n2.v > left.n1.v){
            n2 = right.n2;
        } else{
            n2 = left.n1;
        }
    }
    IntNode ans(n1,n2);

    segmax[p] = ans;
    return ans;
}

IntNode query_min(int a, int b, int p = 1, int l = 0, int r = n - 1){
    Node t1(MAX_VALUE, -1);
    Node t2(MAX_VALUE, -1);
    if(l > r) return IntNode(t1, t2);
    if(a > r) return IntNode(t1, t2);
    if(b < l) return IntNode(t1, t2);

    if(l >= a && r <= b) return segmin[p];

    int mid = (l + r) / 2;

    IntNode left = query_min(a, b, 2*p, l, mid);
    IntNode right = query_min(a, b, 2*p + 1, mid + 1, r);

    Node n1, n2;

    if(left.n1.v < right.n1.v){
        n1 = left.n1;
        if(left.n2.v < right.n1.v){
            n2 = left.n2;
        } else{
            n2 = right.n1;
        }
    } else{
        n1 = right.n1;
        if(right.n2.v < left.n1.v){
            n2 = right.n2;
        } else{
            n2 = left.n1;
        }
    }

    IntNode ans(n1,n2);

    return ans;
}

IntNode query_max(int a, int b, int p = 1, int l = 0, int r = n - 1){
    Node t1(-1, -1);
    Node t2(-1, -1);
    if(l > r) return IntNode(t1, t2);
    if(a > r) return IntNode(t1, t2);
    if(b < l) return IntNode(t1, t2);

    if(l >= a && r <= b){
        return segmax[p];
    } 

    int mid = (l + r) / 2;

    IntNode left = query_max(a, b, 2*p, l, mid);
    IntNode right = query_max(a, b, 2*p + 1, mid + 1, r);

    Node n1, n2;


    if(left.n1.v > right.n1.v){
        n1 = left.n1;
        if(left.n2.v > right.n1.v){
            n2 = left.n2;
        } else{
            n2 = right.n1;
        }
    } else{
        n1 = right.n1;
        if(right.n2.v > left.n1.v){
            n2 = right.n2;
        } else{
            n2 = left.n1;
        }
    }

    IntNode ans(n1,n2);

    return ans;
}


int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> vmin[i];
        vmax[i] = vmin[i];
    }

    build_max();
    build_min();

    while(m--){
        int o, a, b;
        cin >> o >> a >> b;

        if(o == 1){
            b --;
            update_max(a, b);
            update_min(a, b);
        } else{
            a--;
            b--;
            IntNode maxNode = query_max(a, b);
            IntNode minNode = query_min(a, b);

            if(maxNode.n1.b != minNode.n1.b){
                cout << maxNode.n1.v - minNode.n1.v << endl;
            } else{
                int best = max(maxNode.n2.v - minNode.n1.v, maxNode.n1.v - minNode.n2.v);
                cout << best << endl;
            }
        }
    }
    
    
}