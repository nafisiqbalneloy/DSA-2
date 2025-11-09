#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Graph{
    int n;
    vector< vector<int> > w; 
    vector<int> key, p, q;
    bool directed; 
public:
    Graph(int n, bool dir): n(n), directed(dir){
        w = vector< vector<int> >(n, vector<int> (n, 0));
    }

    void addEdge(int u, int v, int weight){
        w[u][v] = weight;
        if(!directed) w[v][u] = weight;
    }

    bool isEdge(int u, int v){
        if(w[u][v] != 0) return true;
        return false;
    }

    int ExtractMin(){
        int m = INT_MAX, idx = -1;
        for(int i = 0; i<n; i++){
            if(q[i] == 1 && key[i]<m){
                m = key[i];
                idx = i;
            }
        }
        return idx;
    }

    void MST_Prim(int r){      
        key = vector<int>(n, INT_MAX);
        p = vector<int>(n, -1);
        q = vector<int>(n, 1);
        key[r] = 0;

        for(int i = 1; i<=n; i++){
            int u = ExtractMin();
            if(u == -1) break;
            q[u] = 0;
            for(int v = 0; v<n; v++){
                if(isEdge(u, v)){
                    if(q[v] == 1 && w[u][v] < key[v]){
                        key[v] = w[u][v];
                        p[v] = u;
                    }
                }
            }
        }

        cout<<"The following bridges should be built:"<<endl;
        int cost = 0;
        for(int i = 0; i<n; i++){
            if(p[i] != -1){
                char u = 'A' + p[i];
                char v = 'A' + i;
                cout<<u<<"->"<<v<<" : "<<key[i]<<endl;
                cost += key[i];
            }
        }
        cout<<"\nMinimum cost to connect islands: "<<cost<<endl;
    }
};

int main(){


    Graph g(6, false);
    g.addEdge(3, 4, 1); // D-E
    g.addEdge(2, 3, 2); // C-D
    g.addEdge(0, 1, 3); // A-B
    g.addEdge(0, 2, 7); // A-C
    g.addEdge(0, 3, 6); // A-D
    g.addEdge(0, 5, 8); // A-F
    g.addEdge(1, 3, 7); // B-D
    g.addEdge(1, 4, 5); // B-E
    g.addEdge(1, 5, 7); // B-F
    g.addEdge(4,5,4);   // E-F

  

    g.MST_Prim(0); 
}


