#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct MinHeapNode {
    int vertex;
    int distance;
};

// MinHeap structure
struct MinHeap {
    int size;
    int capacity;
    vector<int> pos;
    vector<MinHeapNode> array;
};

// Function to create a MinHeap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = new MinHeap;
    minHeap->pos.resize(capacity);
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array.resize(capacity);
    return minHeap;
}

// Swap function for MinHeap nodes
void swapMinHeapNode(MinHeapNode* a, MinHeapNode* b) {
    MinHeapNode t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index i
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left].distance < minHeap->array[smallest].distance)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right].distance < minHeap->array[smallest].distance)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode smallestNode = minHeap->array[smallest];
        MinHeapNode idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode.vertex] = idx;
        minHeap->pos[idxNode.vertex] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

//  build_heap() function
void build_heap(MinHeap* minHeap, int V) {
    int n = V - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

//  extract_min() function
MinHeapNode extract_min(MinHeap* minHeap) {
    if (minHeap->size == 0) {
        MinHeapNode emptyNode = {-1, INT_MAX};
        return emptyNode;
    }

    MinHeapNode root = minHeap->array[0];
    MinHeapNode lastNode = minHeap->array[minHeap->size - 1];

    minHeap->array[0] = lastNode;

    minHeap->pos[root.vertex] = minHeap->size - 1;
    minHeap->pos[lastNode.vertex] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

//  decrease_key() function
void decrease_key(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i].distance = dist;

    while (i && minHeap->array[i].distance < minHeap->array[(i - 1) / 2].distance) {
        minHeap->pos[minHeap->array[i].vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2].vertex] = i;

        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if vertex is in minHeap
bool isInMinHeap(MinHeap* minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

// Dijkstra’s Algorithm Implementation
void dijkstra(vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        minHeap->array[v].vertex = v;
        minHeap->array[v].distance = dist[v];
        minHeap->pos[v] = v;
    }

    dist[src] = 0;
    minHeap->array[src].distance = 0;
    build_heap(minHeap, V);
    minHeap->size = V;

    while (minHeap->size != 0) {
        MinHeapNode minNode = extract_min(minHeap);
        int u = minNode.vertex;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                graph[u][v] + dist[u] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decrease_key(minHeap, v, dist[v]);
            }
        }
    }

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t" << dist[i] << "\n";
}

// MAIN FUNCTION
int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 9, 6, 0, 0},
        {9, 0, 11, 5, 0},
        {6, 11, 0, 0, 2},
        {0, 5, 0, 0, 3},
        {0, 0, 2, 3, 0}
    };

    int source = 0;
    cout << "Dijkstra's Algorithm using Min-Heap\n";
    dijkstra(graph, source, V);

    return 0;
}
