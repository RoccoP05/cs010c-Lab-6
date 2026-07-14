# Lab 6 — Splay Tree

A templated `SplayTree<K>` with `Insert`, `Contains`, and in-order `Print`, using rotations (`RotateLeft`/`RotateRight`) and a recursive `Splay` operation to move accessed keys to the root.

## Files

- `splaytree.h` — the splay tree implementation.
- `main.cc` — driver that inserts keys and exercises `Contains`.
- `splay_exercise.cpp` — fill-in-the-blank exercise reconstructing the `Splay` function from a snippet bank.

## Build & run

```
g++ -std=c++17 -Wall -Wextra main.cc -o splaytree_out
./splaytree_out
```
