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
  //------------------------------------------------------------------------- 

  //------------------------------------------------------------------------- 
}
struct IntegerTriple {
    int dist;
    int hops;
    int node;

    void insertvalue(int d, int h, int n) {
        dist = d;
        hops = h;
        node = n;
    }
};

struct myfunction {
    bool operator() (const IntegerTriple& a, const IntegerTriple& b) {
        return a.dist < b.dist;
    }
};

int Query(int s, int t, int k) {
  // s is source, t is destination, k is the limit
  // You have to report the shortest path from Steven and Grace's current position s
  // to reach their chosen hospital t, output -1 if t is not reachable from s
  // with one catch: this path cannot use more than k vertices
  //
  // write your answer here
    int ans = -1;
    int INF = 10000000;
    array<int,30> dist[1010];
    for(int i = 0;i < 1010;i++) {
        dist[i].fill(INF);
    }
    dist[s][1] = 0;
    priority_queue<IntegerTriple,vector<IntegerTriple>,myfunction> pq;
    IntegerTriple IT;
    IT.insertvalue(0,1,s);
    pq.push(IT);
    while(!pq.empty()) {
        IntegerTriple top = pq.top();
        pq.pop();
        int d = top.dist, vertices_used = top.hops, u = top.node;
        if(vertices_used > k) {
            continue;
        }
        if(u == t) {
            return d;
        }
        if(d > dist[u][vertices_used]) {
            continue;
        }
        for(auto iter: AdjList[u]) {
            ii p = iter;
            int v = p.first, weight_u_v = p.second;
            if(dist[u][vertices_used]+weight_u_v < dist[v][vertices_used+1]) {
                dist[v][vertices_used+1] = dist[u][vertices_used]+weight_u_v;
                IT.insertvalue(dist[v][vertices_used+1],vertices_used+1,v);
                pq.push(IT);
            }
        }
    }
    return ans;
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

    //PreProcess(); // optional

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