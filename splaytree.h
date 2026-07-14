#ifndef SPLAYTREE_H_
#define SPLAYTREE_H_
#include <iostream>
template <typename K>
class SplayTree {
    private:
        // TODO: define internal data structure
        // helper methods
        struct Node{
            K key;
            Node* left = nullptr;
            Node* right  = nullptr;
        };
        Node* root = nullptr;
        void InorderRecur(Node* n, int level);
        void InsertHelper(Node*& n, const K& key);
        //Rotates key to the right
        void RotateRight(Node*& n);
        //Rotates key to the left
        void RotateLeft(Node*& n);
        void Splay(Node*& n, const K& key);
        void DestroyTree(Node* n);
        Node* CopyTree(Node* n);

    public:
        // public API
        SplayTree() = default;
        ~SplayTree();
        SplayTree(const SplayTree& other);
        SplayTree& operator=(const SplayTree& other);
        bool Contains(const K &key);
        void Insert(const K &key);
        void Print();
};

// TODO: Implement the Contains method
template <typename K>
bool SplayTree<K>::Contains(const K &key) {
    Splay(root, key);  // Splay accessed key to root
    return root && root->key == key;
}
// TODO: Implement the Insert method (public version)
template <typename K>
void SplayTree<K>::Insert(const K& key) {
  InsertHelper(root, key);  // Call recursive helper
  Splay(root, key);         // Splay inserted key to root
}

template <typename K>
void SplayTree<K>::InsertHelper(Node*& n, const K& key) {
  if (!n) {
    // Base case: reached null, insert here
    n = new Node{key};
  } else if (key < n->key) {
    // Recursive case: insert in left subtree
    InsertHelper(n->left, key);
  } else if (key > n->key) {
    // Recursive case: insert in right subtree
    InsertHelper(n->right, key);
  } else {
    // Key already exists
    std::cerr << "Key " << key << " already inserted!\n";
  }
}
// TODO: Implement the Print method
// This should print an in-order traversal of the tree
// in this format: "key1 (level), key2 (level), ..."
// You may use this code: std::cout << key << " (" << level << "), ";
template <typename K>
void SplayTree<K>::Print() {
    InorderRecur(root, 0);
}

template <typename K>
void SplayTree<K>::InorderRecur(Node* n, int level) {
    if (!n) return;  // Base case: null node

    InorderRecur(n->left, level + 1);   // Recurse left first
    std::cout << n->key << " (" << level << "), ";   // Process current node
    InorderRecur(n->right, level + 1);  // Recurse right last
}

// TODO: Q2.1 What are the different **splay rotation cases** that must be
//considered?
// Your answer: Single left, single right, right left, left right

// TODO: Q2.2 Implement RotateLeft and RotateRight
template <typename K>
void SplayTree<K>::RotateRight(Node*& n){
    Node* chd = n->left;
    n->left = chd->right;
    chd->right = n;
    n = chd;
}

template <typename K>
void SplayTree<K>::RotateLeft(Node*& n){
    Node* chd = n->right;
    n->right = chd->left;
    chd->left = n;
    n = chd;
}
template <typename K>
SplayTree<K>::~SplayTree() {
    DestroyTree(root);
}

template <typename K>
SplayTree<K>::SplayTree(const SplayTree& other) : root(CopyTree(other.root)) {}

template <typename K>
SplayTree<K>& SplayTree<K>::operator=(const SplayTree& other) {
    if (this != &other) {
        DestroyTree(root);
        root = CopyTree(other.root);
    }
    return *this;
}

template <typename K>
void SplayTree<K>::DestroyTree(Node* n) {
    if (!n) return;
    DestroyTree(n->left);
    DestroyTree(n->right);
    delete n;
}

template <typename K>
typename SplayTree<K>::Node* SplayTree<K>::CopyTree(Node* n) {
    if (!n) return nullptr;
    Node* newNode = new Node{n->key};
    newNode->left = CopyTree(n->left);
    newNode->right = CopyTree(n->right);
    return newNode;
}

// TODO: Q2.3 Implement Splay
template <typename K>
void SplayTree<K>::Splay(Node*& n, const K& key) {
    if (!n || n->key == key) return;

    if (key < n->key) {
        if (!n->left) return;  // key not in tree

        if (key < n->left->key) {
            // Zig-Zig (left-left): splay to grandchild, then two right rotations
            Splay(n->left->left, key);
            RotateRight(n);
        } else if (key > n->left->key) {
            // Zig-Zag (left-right): splay to grandchild, rotate left then right
            Splay(n->left->right, key);
            if (n->left->right) RotateLeft(n->left);
        }
        // Zig: final right rotation (also serves as second rotation for zig-zig/zig-zag)
        if (n->left) RotateRight(n);

    } else {
        if (!n->right) return;  // key not in tree

        if (key > n->right->key) {
            // Zig-Zig (right-right): splay to grandchild, then two left rotations
            Splay(n->right->right, key);
            RotateLeft(n);
        } else if (key < n->right->key) {
            // Zig-Zag (right-left): splay to grandchild, rotate right then left
            Splay(n->right->left, key);
            if (n->right->left) RotateRight(n->right);
        }
        // Zig: final left rotation (also serves as second rotation for zig-zig/zig-zag)
        if (n->right) RotateLeft(n);
    }
}

#endif // SPLAYTREE_H_