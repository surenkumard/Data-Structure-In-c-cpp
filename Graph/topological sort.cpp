#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int inDegree;
};

class Graph{
    public:
        int vertices;
        vector<vector<int>> adjList;
        vector<Edge> in_degree;
    public:
        Graph(int x = 0){
            vertices = x;
            adjList.resize(x);
            in_degree.resize(x);
            for(int i = 0; i < vertices; i++){
                in_degree[i].inDegree = 0;
            }
        }

        void addEdge(int u, int v){
            adjList[u].push_back(v);
            in_degree[v].inDegree++;
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
                cout << "Vertices V" << i << " = ";;
                for(int j = 0; j < adjList[i].size(); j++){
                    cout << "V" << adjList[i][j] << ", ";
                }
                cout << endl;
            }
        }

        void Topological(){
            queue<int> q;

            for(int i = 0; i < vertices; i++){
                if(in_degree[i].inDegree == 0){
                    q.push(i);
                }
            }

            vector<int> res;
            int count = 0;
            while(!q.empty()){
                int current = q.front();
                q.pop();

                res.push_back(current);
                
                for(int w: adjList[current]){
                    if(--in_degree[w].inDegree == 0){
                        q.push(w);
                    }
                }

                print_inDegree();
                count++;
            }
            
            if(count != vertices){
                cout << "Graph is not a DAG" << endl;
            }
            else{
                cout << "Topological Sort: ";
                for(int i = 0; i < res.size(); i++){
                    cout << "V" << res[i] << " - ";
                }
            }
        };

        void print_inDegree(){
            for(int i = 0; i < vertices; i++){
                cout<< endl << "vertices " << i + 1 << ": " << in_degree[i].inDegree << endl;
            }
        }
};

int main(){
    int x;
    cout << "Enter number of Vertices : ";
    cin >> x;
    Graph g(x);

    g.getEdge();
    g.Topological();
    return 0;
}