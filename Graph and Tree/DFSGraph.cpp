#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Graph
{

  map<int, bool> visited;
  map<int, list<int>> adjList;
  // void DFSUtil(int vertice);

public:
  void addEdge(int src, int dest);
  void DFS(int start);
};

void Graph::addEdge(int src, int dest)
{
  adjList[src].push_back(dest);
}

//Below commented code is for Disconnected graph.

// void Graph::DFSUtil(int vertice)
// {
//   visited[vertice] = true;
//   cout<<vertice<<" ";
//   list<int>::iterator i;
//   for ( i = adjList[vertice].begin(); i != adjList[vertice].end(); i++)
//   {
//     if(!visited[*i])
//       DFSUtil(*i);
//   }

// }

// void Graph::DFS()
// {
//   for(auto i : adjList)
//   {
//     if(!visited[i.first == false])
//         DFSUtil(i.first);
//   }
// }

//Below DFS traversal works only for connected graph.

void Graph::DFS(int start)
{
  visited[start] = true;
  cout << start << " ";

  list<int>::iterator it;
  for (it = adjList[start].begin(); it != adjList[start].end(); it++)
  {
    if (!visited[*it])
    {
      DFS(*it);
    }
  }
}

int main()
{
  Graph g;
  // g.addEdge(0, 1);
  // g.addEdge(0, 9);
  // g.addEdge(1, 2);
  // g.addEdge(2, 0);
  // g.addEdge(2, 3);
  // g.addEdge(9, 3);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  cout << "Following is Depth First Traversal \n";

  g.DFS(2);
  return 0;
}