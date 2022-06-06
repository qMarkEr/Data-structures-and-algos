#include <iostream>
#include <cstdlib>

using namespace std;

class Graph {


public:
    int** matrix;
    int n;
    bool* vis;

    Graph();
    void DFS(int v, int **matrix);
    bool Connectedness();
    int Origin();
    friend ostream& operator<<(ostream& out, Graph g) {
        for (int i = 0; i < g.n; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < g.n; j++)
            {
                if (g.matrix[i][j] != 0)
                {
                    cout << j << " ";
                }

            }
            out << endl;

        }
        return out;
    }
};
bool Graph::Connectedness() {
    int** inv = this->matrix;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            if (inv[i][j] != inv[j][j])
            {
                inv[i][j] = 1;
                inv[j][i] = 1;
            }

        }

    }
    DFS(0, inv);
    for (int i = 0; i < n; i++)
    {
        if (!this->vis[i]){
            return false;
        }
    }
    
    return true;

}
void Graph::DFS(int v, int** matrix) {
    vis[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] != 0 && vis[i] != true)
        {
            DFS(i, matrix);
        }
    }
};
int Graph::Origin(){
    int count = 0;
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = true;
        DFS(i, this->matrix);
        for (int j = 0; j < this->n; j++)
        {
            if (!this->vis[j])
            {
                flag = false;
                break;
            }
            
        }
        if (flag)
        {
            count++;
        }
        for (int j = 0; j < this->n; j++)
        {
            this->vis[j] = false;
        }
        

    }
    return count;
    
}
Graph::Graph() {
    cin >> n;
    vis = new bool[n];
    matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }

    }
};
int main() {
    Graph g;
    cout << g;
    cout << g.Origin() << endl;
    cout << g.Connectedness();
}