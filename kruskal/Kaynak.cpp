#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 9563258;
// for create an infinity number
vector<int> parent(N);
vector<int> sz(N);

void make_Set(int V) {
    parent[V] = V;
    sz[V] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void merge_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    for (int i = 0; i < N; i++)
        make_Set(i);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        // u v and w stands for edges nodes and costs 
        cin >> u >> v >> w;
        edges.push_back({ w, u, v });
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    for (auto i : edges) {
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);

        if (x == y) {
            continue;
        }
        else {
            cout << u << " " << v << "\n";
            cost += w;
            merge_sets(u, v);
        }
    }

    cout << cost;
    /* its a simple code that you first insert values for edges and nodes number and their weights, links , names
    after that code create an mst and calculate total cost.*/
    return 0;
}
