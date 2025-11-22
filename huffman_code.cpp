#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << "\n";
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    unordered_map<char, int> freq;
    char c;
    int f;

    cout << "Enter character and its frequency:\n";
    for (int i = 0; i < n; i++) {
        cin >> c >> f;
        freq[c] = f;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto it : freq) {
        pq.push(new Node(it.first, it.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();  pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}
