#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adj;

public:

    Graph(int n);
    void addEdge(int src, int dest);
    void BFS(int start);
};

Graph::Graph(int n)
{
    numVertices = n;
    adj = new list<int>[n];
}

void Graph::addEdge(int src, int dest)
{
    adj[src].push_back(dest);
}

void Graph::BFS(int start)
{
    bool check[numVertices];

    for(int i = 0; i<numVertices; i++) check[i] = false;

    check[start] = true;
    queue<int> q;
    q.push(start);

    list<int>::iterator itr;

    while(!q.empty())
    {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();

        for(itr = adj[curr].begin(); itr != adj[curr].end(); ++itr)
        {
            if(!check[*itr])
            {
                check[*itr] = true;
                q.push(*itr);
            }
        }
    }
}

int main()
{
    Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
    // g.addEdge(0, 3);
    // g.addEdge(0, 1);
    // g.addEdge(0, 8);
    // g.addEdge(1, 0);
    // g.addEdge(1, 7);
    // g.addEdge(3, 2);
    // g.addEdge(3, 4);
    // g.addEdge(3, 0);
    // g.addEdge(8, 0);
    // g.addEdge(8, 4);
    // g.addEdge(7, 1);
    // g.addEdge(7, 2);
    // g.addEdge(2, 3);
    // g.addEdge(2, 5);
    // g.addEdge(5, 2);
    // g.addEdge(5, 6);
    // g.addEdge(4, 3);
    // g.addEdge(4, 8);
    // g.addEdge(6, 5);


	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

    return 0;
}