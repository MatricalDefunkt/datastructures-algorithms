#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Graph
{
private:
  unordered_map<int, vector<pair<int, int>>> adj_list;

public:
  void add_node(int node)
  {
    if (adj_list.find(node) == adj_list.end())
    {
      adj_list[node] = vector<pair<int, int>>();
    }
  }

  void add_edge(int src, int dest, int weight)
  {
    add_node(src);
    add_node(dest);
    adj_list[src].push_back(make_pair(dest, weight));
    adj_list[dest].push_back(make_pair(src, weight));
  }

  void delete_node(int node)
  {
    adj_list.erase(node);
    for (auto &it : adj_list)
    {
      auto &vec = it.second;
      vec.erase(remove_if(vec.begin(), vec.end(), [node](const pair<int, int> &p)
                          { return p.first == node; }),
                vec.end());
    }
  }

  void delete_edge(int src, int dest)
  {
    auto &vec = adj_list[src];
    vec.erase(remove_if(vec.begin(), vec.end(), [dest](const pair<int, int> &p)
                        { return p.first == dest; }),
              vec.end());
    auto &vec2 = adj_list[dest];
    vec2.erase(remove_if(vec2.begin(), vec2.end(), [src](const pair<int, int> &p)
                         { return p.first == src; }),
               vec2.end());
  }

  void display()
  {
    for (auto &it : adj_list)
    {
      cout << it.first << ": ";
      for (auto &p : it.second)
      {
        cout << "(" << p.first << ", " << p.second << ") ";
      }
      cout << endl;
    }
  }

  void DFS(int start)
  {
    unordered_map<int, bool> visited;
    DFSHelper(start, visited);
  }

  void DFSHelper(int node, unordered_map<int, bool> &visited)
  {
    visited[node] = true;
    cout << node << " ";
    for (auto &p : adj_list[node])
    {
      if (!visited[p.first])
      {
        DFSHelper(p.first, visited);
      }
    }
  }

  void BFS(int start)
  {
    unordered_map<int, bool> visited;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      cout << node << " ";
      for (auto &p : adj_list[node])
      {
        if (!visited[p.first])
        {
          visited[p.first] = true;
          q.push(p.first);
        }
      }
    }
  }

  void kruskals()
  {
    vector<pair<int, pair<int, int>>> edges;
    for (auto &it : adj_list)
    {
      int src = it.first;
      for (auto &p : it.second)
      {
        int dest = p.first;
        int weight = p.second;
        edges.push_back(make_pair(weight, make_pair(src, dest)));
      }
    }
    sort(edges.begin(), edges.end());
    unordered_map<int, int> parent;
    for (auto &it : adj_list)
    {
      parent[it.first] = it.first;
    }
    int cost = 0;
    for (auto &p : edges)
    {
      int weight = p.first;
      int src = p.second.first;
      int dest = p.second.second;
      int srcParent = find(parent, src);
      int destParent = find(parent, dest);
      if (srcParent != destParent)
      {
        cout << src << " - " << dest << " : " << weight << endl;
        cost += weight;
        parent[srcParent] = destParent;
      }
    }
    cout << "Total cost: " << cost << endl;
  }

  int find(unordered_map<int, int> &parent, int node)
  {
    if (parent[node] == node)
    {
      return node;
    }
    return find(parent, parent[node]);
  }

  void prims(int start)
  {
    unordered_map<int, int> key;
    unordered_map<int, bool> mstSet;
    unordered_map<int, int> parent;
    for (auto &it : adj_list)
    {
      key[it.first] = INT_MAX;
      mstSet[it.first] = false;
    }
    key[start] = 0;
    parent[start] = -1;
    for (int i = 0; i < adj_list.size() - 1; i++)
    {
      int u = min_key(key, mstSet);
      mstSet[u] = true;
      for (auto &p : adj_list[u])
      {
        int v = p.first;
        int weight = p.second;
        if (!mstSet[v] && weight < key[v])
        {
          parent[v] = u;
          key[v] = weight;
        }
      }
    }
    for (auto &it : adj_list)
    {
      int node = it.first;
      if (node != start)
      {
        cout << parent[node] << " - " << node << " : " << key[node] << endl;
      }
    }
  }

  int min_key(unordered_map<int, int> &key, unordered_map<int, bool> &mstSet)
  {
    int min = INT_MAX, minIndex;
    for (auto &it : adj_list)
    {
      int node = it.first;
      if (!mstSet[node] && key[node] < min)
      {
        min = key[node];
        minIndex = node;
      }
    }
    return minIndex;
  }

  void print_mst(int parent[])
  {
    for (int i = 1; i < adj_list.size(); i++)
    {
      cout << parent[i] << " - " << i << " : " << adj_list[i][parent[i]].first << ", " << adj_list[i][parent[i]].second << endl;
    }
  }

  void dijkstras(int start)
  {
    unordered_map<int, int> dist;
    unordered_map<int, bool> visited;
    for (auto &it : adj_list)
    {
      int node = it.first;
      dist[node] = INT_MAX;
      visited[node] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < adj_list.size() - 1; i++)
    {
      int u = min_dist(dist, visited);
      visited[u] = true;
      for (auto &p : adj_list[u])
      {
        int v = p.first;
        int weight = p.second;
        if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
          dist[v] = dist[u] + weight;
        }
      }
    }
    for (auto &it : adj_list)
    {
      int node = it.first;
      if (node != start)
      {
        cout << start << " - " << node << " : " << dist[node] << endl;
      }
    }
  }

  int min_dist(unordered_map<int, int> &dist, unordered_map<int, bool> &visited)
  {
    int min = INT_MAX, minIndex;
    for (auto &it : adj_list)
    {
      int node = it.first;
      if (!visited[node] && dist[node] < min)
      {
        min = dist[node];
        minIndex = node;
      }
    }
    return minIndex;
  }
};

int main()
{
  Graph g;
  int choice, start;
  do
  {
    cout << "1. Add edge\n";
    cout << "2. Print graph\n";
    cout << "3. Find shortest path using Dijkstra's algorithm\n";
    cout << "4. Find minimum spanning tree using Prim's algorithm\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      int u, v, w;
      cout << "Enter source, destination and weight: ";
      cin >> u >> v >> w;
      g.add_edge(u, v, w);
      break;
    case 2:
      g.display();
      break;
    case 3:
      cout << "Enter starting node: ";
      cin >> start;
      g.dijkstras(start);
      break;
    case 4:
      cout << "Enter starting node: ";
      cin >> start;
      g.print_mst(&start);
      break;
    case 5:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice. Try again.\n";
    }
  } while (choice != 5);

  return 0;
}
