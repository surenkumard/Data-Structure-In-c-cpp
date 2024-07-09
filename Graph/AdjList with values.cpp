#include <bits/stdc++.h>
using namespace std;

// Define a struct to represent an edge
template <class T2>
struct Edge {
    T2 value;
};

template <class T2>
class Graph{
public:
    int vertices;
    vector<vector<int>> adjList;
    vector<Edge<T2>> valList;

public:
    Graph(int x = 0){
        vertices = x;
        adjList.resize(x);
        valList.resize(x);
        for(int i = 0; i < x; i++){
            cout << "Enter vertices Values : ";
            cin >> valList[i].value;
        }
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }

    void getEdge(){
        int x;
        cout << "Enter a Number of Edges : ";
        cin >> x;

        int u, v;
        T2 value;
        while(x--){
            cout << "Enter an Edge : " << endl;
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    void printMat(){
        for(int i = 0; i < vertices; i++){
            cout << "Vertices V" << i << " = ";
            for(int j = 0; j < adjList[i].size(); j++){
                cout << "V" << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printVal(){
        for(int i = 0; i < vertices; i++){
            cout << "Vertices V" << i << " = ";
            cout << valList[i].value << endl;
        }
        cout<<endl;
    }

    void printFri(){
        for(int i = 0; i < vertices; i++){
            cout << valList[i].value << " Friend With = ";
            for(int j = 0; j < adjList[i].size(); j++){
                cout << valList[adjList[i][j]].value << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int x;
    cout << "Enter number of Vertices : ";
    cin >> x;
    Graph<string> g(x);
    g.getEdge();
    g.printMat();
    cout << endl;
    g.printVal();
    cout << endl;
    g.printFri();
    return 0;
}
