#include <bits/stdc++.h>
using namespace std;

template <class T1>
class Graph{
    public:
        int vertices;
        vector<vector<T1>> adjList;
    public:
        Graph(int x = 0){
            vertices = x;
            adjList.resize(x);
        }

        void addEdge(int u, int v){
            adjList[u].push_back(v);
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

        void printList(){
            for(int i = 0; i < vertices; i++){
                cout << "Vertices V" << i << " = ";;
                for(int j = 0; j < adjList[i].size(); j++){
                    cout << "V" << adjList[i][j] << ", ";
                }
                cout << endl;
            }
        }

        void unweighted(int current){
            vector<bool> known(vertices, false);
            vector<int> dist(vertices, INT_MAX);
            vector<int> path(vertices, 0);

            queue<int> s;
            s.push(current);

            known[current] = true;
            dist[current] = 0;

            while(!s.empty()){
                current = s.front();
                s.pop();
                known[current] = true;

                for(int w: adjList[current]){
                    if(known[w] == false && dist[w] == INT_MAX){
                        dist[w] = dist[current] + 1;
                        s.push(w);
                        path[w] = current;
                    }
                }
                print_dist(dist, path, known);
            }
        }

        void print_dist(vector<int> dist, vector<int> path, vector<bool> known){
            cout << "Vertices  known  distance  path " << endl << endl;
            for(int i = 0; i <vertices; i++){
                cout << i + 1 << "\t" << known[i] << "\t" << dist[i] << "\t" << path[i] << endl;
            }
        }
};

int main(){
    int x;
    cout << "Enter number of Vertices : ";
    cin >> x;
    Graph<int> g(x);
    g.getEdge();
    g.printList();

    g.unweighted(0);
    cout << endl;

    return 0;
}