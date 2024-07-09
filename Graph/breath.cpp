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
            adjList[v].push_back(u);
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

        void depth(int current){
            int visited[vertices] = {0};

            stack<int> s;
            s.push(current);
            visited[current] = 1;

            while(!s.empty()){
                current = s.top();
                s.pop();
                cout << current << " ";

                for(int i : adjList[current]){
                    if(visited[i] == 0){
                        visited[i] = 1;
                        s.push(i);
                    }
                }
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
    cout << endl;

    g.depth(0);
    return 0;
}
