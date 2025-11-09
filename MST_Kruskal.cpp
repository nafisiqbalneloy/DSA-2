#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet{
    int n;
    vector<int> parent, Rank;
    public:
    DisjointSet(int n) : n(n){
        parent = vector<int> (n);
        Rank = vector<int> (n);
    }
    void MakeSet(int x){
        parent[x]=x;
        Rank[x]=0;
    }
    int Find(int x){
        if(x!=parent[x]){
        parent[x]=Find(parent[x]);
        }
        else{
        return parent[x];
        }
    }
    void Union(int a,int b){
        int x= Find(a);
        int y= Find(b);
        if(x==y) return;

        if(Rank[x]>Rank[y]){
            parent[y]=x;
        }
        else{
            parent[x]=y;
            if(Rank[x]==Rank[y])
        Rank[y]++;
        }
    }

};

class Graph{
    int n;
    vector<vector<int>>edges;
    public:
    Graph(int n): n(n){}
    void addEdge(int u,int v, int w){
        edges.push_back({w,u,v});

    }

    void MST_Kruskal(){
        vector<vector<int>> T;
        DisjointSet ds (n);

        for(int i= 0;i<n;i++){
            ds.MakeSet(i);
        }
        sort(edges.begin(),edges.end());
       
        for(int i=0;i<edges.size();i++){
            int w = edges[i][0];
            int u = edges [i][1];
            int v = edges [i][2];

            if(ds.Find(u)!=ds.Find(v)){
                T.push_back({u,v,w});
                ds.Union(u,v);

            }
            else{
                cout<<"cycle detected"<<endl;
            }
        }
        cout<<"chosen edges for MST:"<<endl;
        int cost = 0;
        for(int i=0;i<T.size();i++){
            int u = T[i][0];
            int v = T[i][1];
            int w = T[i][2];
            cout<<"("<<u<<", "<<v<<", "<<w<<")"<<endl;
            cost += w;
        }
        cout<<"cost of MST:"<<cost<<endl;
    }   

};

int main(){
    Graph g(3);
    g.addEdge(0,1,2);
    g.addEdge(1,2,6);
    g.addEdge(0,2,4);

    g.MST_Kruskal();
    return 0;
}