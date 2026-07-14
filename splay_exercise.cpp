// ============================================================
//  Splay Function — Fill in the Blank
//  Use each snippet from the bank below to complete the function.
//  Some snippets may be used more than once.
// ============================================================

// ------- CODE SNIPPET BANK (use each as needed) -------------
//
//  1.  !n || n->key == key
//  2.  key < n->key
//  3.  n->left
//  4.  n->right
//  5.  n->left->right
//  6.  n->right->left
//  7.  Splay(n->left->left, key)
//  8.  Splay(n->left->right, key)
//  9.  Splay(n->right->right, key)
//  10. Splay(n->right->left, key)
//  11. RotateRight(n)
//  12. RotateLeft(n)
//  13. RotateLeft(n->left)
//  14. RotateRight(n->right)
//
// ------------------------------------------------------------

template <typename K>
void SplayTree<K>::Splay(Node*& n, const K& key) {

    // Base case: empty node or key is already at root
    if ( ___[1]___ ) return;

    if ( ___[2]___ ) {          // target key is in the LEFT subtree

        if (!___[3]___) return; // key is not in the tree

        if (key < n->left->key) {
            // --- Zig-Zig (left-left): key is left child of left child ---
            ___[7]___;          // recurse: splay key within the left-left grandchild
            ___[11]___;          // rotate grandparent right (first of two rotations)

        } else if (key > n->left->key) {
            // --- Zig-Zag (left-right): key is right child of left child ---
            ___[8]___;          // recurse: splay key within the left-right grandchild
            if (___[5]___) ___[13]___;   // rotate parent left (inner rotation)
        }

        // Zig: final right rotation brings target to current root
        // (also acts as the second rotation for zig-zig and zig-zag)
        if (n->left) ___[I]___;

    } else {                    // target key is in the RIGHT subtree

        if (!___[J]___) return; // key is not in the tree

        if (key > n->right->key) {
            // --- Zig-Zig (right-right): key is right child of right child ---
            ___[K]___;          // recurse: splay key within the right-right grandchild
            ___[L]___;          // rotate grandparent left (first of two rotations)

        } else if (key < n->right->key) {
            // --- Zig-Zag (right-left): key is left child of right child ---
            ___[M]___;          // recurse: splay key within the right-left grandchild
            if (___[N]___) ___[O]___;   // rotate parent right (inner rotation)
        }

        // Zig: final left rotation brings target to current root
        if (n->right) ___[P]___;
    }
}

// ============================================================
//  ANSWER KEY  (highlight/scroll below to reveal)
//
//  [A]  !n || n->key == key
//  [B]  key < n->key
//  [C]  n->left
//  [D]  Splay(n->left->left, key)
//  [E]  RotateRight(n)
//  [F]  Splay(n->left->right, key)
//  [G]  n->left->right
//  [H]  RotateLeft(n->left)
//  [I]  RotateRight(n)
//  [J]  n->right
//  [K]  Splay(n->right->right, key)
//  [L]  RotateLeft(n)
//  [M]  Splay(n->right->left, key)
//  [N]  n->right->left
//  [O]  RotateRight(n->right)
//  [P]  RotateLeft(n)
// ============================================================
