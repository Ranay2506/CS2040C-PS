// Copy paste this C++ Template and save it as "Labor.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here:
// write your name here:
// write list of collaborators here:
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

typedef pair<int, int> ii;

// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
// But if you want to refactor this template code to avoid any global variable, you can do so
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge
array<int,1000> nodedistance[1000]; // Store the distance of each node from source
void PreProcess() {
  // Write necessary code to preprocess the graph, if needed
  //
  // write your answer here
  //------------------------------------------------------------------------- 
  for(int it = 0;it < V;it++) {
    // it is which source it is
    bool visted[1000]; // Check if node is visted
    for(int i = 0;i < V;i++) {
      visted[i] = false; // Every node is marked as unvisted
    }
    nodedistance[it].fill(-1); // Set distance to be -1 for every node
    visted[it] = true; // Set source to be visted
    queue<int> qu;
    qu.push(it);
    nodedistance[it][it] = 0;

    while(!qu.empty()) {
      int cur = qu.front();
      qu.pop();
      for(auto v: AdjList[cur]) {
        if(!visted[v.first]) {
          nodedistance[it][v.first] = nodedistance[it][cur] + v.second;
          visted[v.first] = 1;
          qu.push(v.first);
        }
      }
    }
  }
  //------------------------------------------------------------------------- 

  //------------------------------------------------------------------------- 
}

int Query(int s, int t, int k) {
  // s is source, t is destination, k is the limit
  // You have to report the shortest path from Steven and Grace's current position s
  // to reach their chosen hospital t, output -1 if t is not reachable from s
  // with one catch: this path cannot use more than k vertices
  //
  // write your answer here
    return nodedistance[s][t]; 
}

// You can add extra function(s) if needed
// --------------------------------------------



// --------------------------------------------

int main() {
  int TC;
  scanf("%d", &TC);

  while (TC--) {
    int j, k, w;
    scanf("%d", &V);
    // clear the graph and read in a new graph as Adjacency List
    AdjList.assign(V, vector<ii>());
    for (int i = 0; i < V; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d %d", &j, &w);
        AdjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
      }
    }

    PreProcess(); // optional

    int source, destination, required_k;
    scanf("%d", &Q);
    while (Q--) {
      scanf("%d %d %d", &source, &destination, &required_k);
      printf("%d\n", Query(source, destination, required_k));
    }

    if (TC)
      printf("\n");
  }
  return 0;
}