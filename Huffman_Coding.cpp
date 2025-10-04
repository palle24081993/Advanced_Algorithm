#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int f;
    Node *l, *r;
    Node(char c, int freq) : ch(c), f(freq), l(nullptr), r(nullptr) {}
};

struct Cmp {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

void preorder(Node* root, string s) {
    if (!root) return;
    if (!root->l && !root->r) cout << s << " ";
    preorder(root->l, s + "0");
    preorder(root->r, s + "1");
}

void huffman(const vector<char>& c, const vector<int>& f) {
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (size_t i = 0; i < c.size(); i++) pq.push(new Node(c[i], f[i]));

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        Node* p = new Node('\0', a->f + b->f);
        p->l = a; p->r = b;
        pq.push(p);
    }
    preorder(pq.top(), "");
    cout << endl;
}

int main() {
    string s = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    vector<char> c(s.begin(), s.end());

    huffman(c, f);
    return 0;
}
