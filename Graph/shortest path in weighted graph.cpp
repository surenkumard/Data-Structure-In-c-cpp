#include <bits/stdc++.h>
using namespace std;


class Graph{
    public:
        int vertices;
        vector<vector<pair<int, int>>> adjList;
    public:
        Graph(int x = 0){
            vertices = x;
            adjList.resize(x);
        }

        void addEdge(int u, int v, int w){
            adjList[u].push_back({v, w});
        }
        
        void getEdge(){
            int x;
            cout << "Enter a Number of Edges : ";
            cin >> x;
            
            int u, v, w;
            while(x--){
                cout << "Enter a Edge and weight: " << endl;
                cin >> u >> v >> w;
                addEdge(u, v, w);
            }
        }

        int minVertices(vector<int> dist, vector<bool> known){
            int min = INT_MAX, min_index = 0;
            for(int i = 0; i < vertices; i++){
                if(known[i] == false && dist[i] < min){
                    min = dist[i];
                    min_index = i;
                }
            }

            return min_index;
        }

        void unweighted(int current){
            vector<bool> known(vertices, false);
            vector<int> dist(vertices, INT_MAX);
            vector<int> path(vertices, 0);

            known[current] = true;
            dist[current] = 0;

            for(int i = 0; i < vertices; i++){
                current = minVertices(dist, known);
                known[current] = true;

                for(auto &edges: adjList[current]){
                    int w = edges.first;
                    int wei = edges.second;

                    if(known[w] == false && dist[current] != INT_MAX && dist[current] + wei <= dist[w]){
                        dist[w] = dist[current] + wei;
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
    Graph g(x);
    g.getEdge();

    g.unweighted(0);
    cout << endl;

    return 0;
}