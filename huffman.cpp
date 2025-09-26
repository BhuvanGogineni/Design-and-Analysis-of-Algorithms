#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare function for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = code;
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

int main() {
    // Frequencies given in the problem (in hundreds)
    map<char, int> freq = {
        {'a', 20}, {'c', 11}, {'d', 2}, {'e', 10},
        {'o', 15}, {'m', 8}, {'s', 10}, {'t', 22}, {'u', 2}
    };

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it : freq) pq.push(new Node(it.first, it.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node* root = pq.top();
    map<char, string> codes;
    generateCodes(root, "", codes);

    cout << "Letter\tHuffman Code\n";
    for (auto it : codes) cout << it.first << "\t" << it.second << endl;

    return 0;
}
