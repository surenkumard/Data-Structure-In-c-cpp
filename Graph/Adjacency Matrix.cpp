#include <bits/stdc++.h>
using namespace std;

template <class T1>
class Graph{
    public:
        int vertices;
        vector<vector<T1>> adjMat;
    public:
        Graph(int x = 0){
            vertices = x;
            adjMat.resize(x, vector<T1>(x, 0));
        }

        void addEdge(int u, int v){
            adjMat[u][v] += 1;
            adjMat[v][u] += 1;
        }
        
        void getEdge(){
            int x;
            cout << "Enter a Number of Edges : ";
            cin >> x;
            
            int u, v;
            while(x--){
                cout << "Enter a Edge : " << endl;
                cin >> u >> v;
                addEdge(u, v);
            }
        }

        void printMat(){
            for(int i = 0; i < vertices; i++){
                for(int j = 0; j < vertices; j++){
                    cout << adjMat[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int x;
    cout << "Enter number of Vertices : ";
    cin >> x;
    Graph<int> g(x);
    g.getEdge();
    g.printMat();
    return 0;
}
