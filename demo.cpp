#include <iostream>
using namespace std;

// Leftist Heap Node
struct Node {
    int key;
    Node* left;
    Node* right;
    int npl;  // Null Path Length

    Node(int val) {
        key = val;
        left = right = nullptr;
        npl = 0;
    }
};

// Leftist Heap Class
class LeftistHeap {
public:
    Node* root;

    LeftistHeap() : root(nullptr) {}

    // Merge two leftist heaps
    Node* merge(Node* h1, Node* h2) {
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;

        // Ensure that h1 has the smaller root
        if (h1->key > h2->key) {
            swap(h1, h2);
        }

        h1->right = merge(h1->right, h2);

        // Maintain the leftist property
        if (getNPL(h1->left) < getNPL(h1->right)) {
            swap(h1->left, h1->right);
        }

        h1->npl = getNPL(h1->right) + 1;
        return h1;
    }

    // Insert a new element into the heap
    void insert(int key) {
        Node* newNode = new Node(key);
        root = merge(root, newNode);
        cout << "Inserted: " << key << endl;
    }

    // Find the minimum element
    int findMin() {
        if (root == nullptr) {
            cout << "Heap is empty." << endl;
            return -1;
        }
        return root->key;
    }

    // Extract the minimum element
    void extractMin() {
        if (root == nullptr) {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Extracting minimum: " << root->key << endl;
        Node* oldRoot = root;
        root = merge(root->left, root->right);
        delete oldRoot;
    }

    // Merge the current heap with another heap
    void mergeWith(LeftistHeap& otherHeap) {
        root = merge(root, otherHeap.root);
        otherHeap.root = nullptr;  // Clear the merged heap
    }

private:
    // Get the Null Path Length (NPL) of a node
    int getNPL(Node* node) {
        return (node == nullptr) ? -1 : node->npl;
    }
};

int main() {
    LeftistHeap heap1, heap2;

    // Insert elements into heap1
    heap1.insert(10);
    heap1.insert(20);
    heap1.insert(5);

    // Insert elements into heap2
    heap2.insert(15);
    heap2.insert(25);
    heap2.insert(3);

    // Find minimum in heap1
    cout << "Minimum in heap1: " << heap1.findMin() << endl;

    // Extract minimum from heap1
    heap1.extractMin();
    cout << "Minimum in heap1 after extract: " << heap1.findMin() << endl;

    // Merge heap1 and heap2
    cout << "Merging heap1 and heap2..." << endl;
    heap1.mergeWith(heap2);

    // Find minimum after merging
    cout << "Minimum after merge: " << heap1.findMin() << endl;

    // Extract minimum after merging
    heap1.extractMin();
    cout << "Minimum after extract: " << heap1.findMin() << endl;

    return 0;
}
