#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Graph{
    int n;
    bool directed;
    vector<int> d,p,q;
    vector<vector<int>> w; //rep adjacency matrix
    public:
    Graph(int n,bool directed) : n(n),directed(directed){
        w = vector<vector<int> > (n,vector<int>(n,0));
    }

    void addEdge(int u,int v,int weight){
        w[u][v] = weight;
        if(!directed) w[v][u] = weight;
    }
    bool isEdge(int u,int v){
        if(w[u][v]!= 0) return true; //ache
        return false;
    }
    int extractMin(){
        int m = INT_MAX;
        int idx = -1;
        for(int i = 0;i<n;i++){
            if(q[i] == 1 && d[i]<m){
                m = d[i];
                idx = i;
            }
        }
        return idx;
    }
    void Dijkstra(int src){
        d = vector<int> (n,INT_MAX);
        p = vector<int> (n,-1);
        q = vector<int> (n,1);
        d[src] = 0;

        for(int i=1;i<n;i++){
           int u = extractMin();
           q[u] = 0;
           for(int v = 0;v<n;v++){
            if(isEdge(u,v)){
                if(d[u]+w[u][v]<d[v]){
                    d[v]= d[u]+w[u][v];
                    p[v]=u;
                }
            }
           }
        }
    }

    void printPath(int d){
        if(d==-1) return;
        printPath(p[d]);
        cout<<d<<" ";
        
    }
    void findPath(int src,int dest){
        Dijkstra(src);
        cout<<"path form "<<src<<" to "<<dest<<" : ";
        printPath(dest);
        cout<<"\nDistance from "<<src<<" to "<<dest<<" : "<<d[dest]<<endl;
        
    }

};

int main(){
    Graph g(5,true);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(3, 4, 1);

    g.findPath(0,4);

    return 0;
}