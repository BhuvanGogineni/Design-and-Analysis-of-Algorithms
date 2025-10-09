#include <iostream>
using namespace std;

#define V 5
#define E 7

struct Edge {
    int src, dest, wt;
};

Edge edges[E] = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 2, 3},
    {1, 3, 8},
    {1, 4, 5},
    {2, 4, 7},
    {3, 4, 9}
};

int parent[V], rankArr[V] = {0};

int findParent(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v]);
}

void unionSets(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) {
        if (rankArr[a] < rankArr[b]) parent[a] = b;
        else if (rankArr[a] > rankArr[b]) parent[b] = a;
        else { parent[b] = a; rankArr[a]++; }
    }
}

void sortEdges() {
    for (int i = 0; i < E - 1; i++)
        for (int j = 0; j < E - i - 1; j++)
            if (edges[j].wt > edges[j + 1].wt)
                swap(edges[j], edges[j + 1]);
}

void KruskalMST() {
    for (int i = 0; i < V; i++) parent[i] = i;

    sortEdges();

    cout << "Edge\tWeight\n";
    int total = 0, count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = findParent(edges[i].src);
        int v = findParent(edges[i].dest);

        if (u != v) {
            cout << edges[i].src << " - " << edges[i].dest << "\t" << edges[i].wt << endl;
            total += edges[i].wt;
            unionSets(u, v);
            count++;
        }
    }
    cout << "Total Weight of MST = " << total << endl;
}

int main() {
    KruskalMST();
    return 0;
}
