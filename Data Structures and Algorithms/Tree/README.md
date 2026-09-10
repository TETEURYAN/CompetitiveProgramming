# Tree Data Structures

This directory contains implementations and exercises related to **tree data structures**, with a focus on binary trees, binary search trees, K-ary trees, and segment trees.

Trees are hierarchical data structures composed of **nodes** connected by edges. Unlike linear structures such as arrays and linked lists, trees represent relationships in a hierarchical manner and are widely used in searching, indexing, hierarchical representations, and range-query algorithms.

---

## Binary Tree

A **Binary Tree** is a tree data structure in which each node can have at most two children: a **left child** and a **right child**.

A basic implementation in C can be represented as:

```c
typedef struct tree {
    int info;
    struct tree *right, *left;
} tree;
```

Each node contains:

* `info`: the value stored in the node;
* `left`: pointer to the left child;
* `right`: pointer to the right child.

A binary tree does **not necessarily maintain an ordering relationship** between the values stored in its nodes.

---

## Binary Search Tree

A **Binary Search Tree (BST)** is a specialized binary tree that maintains an ordering property:

* values smaller than the current node are stored in the left subtree;
* values greater than the current node are stored in the right subtree.

This property allows search, insertion, and other operations to be performed efficiently when the tree remains reasonably balanced.

---

## K-ary Tree

A **K-ary Tree** generalizes the concept of a binary tree by allowing a node to have up to **K children**.

The implementation used in this directory represents the children using a **first-child / next-sibling** representation:

```c
typedef struct kary
{
    int num;
    struct kary *firstChild;
    struct kary *nextBro;
} kary;
```

The structure contains:

* `num`: the value stored in the node;
* `firstChild`: pointer to the node's first child;
* `nextBro`: pointer to the node's next sibling.

This representation makes it possible to represent trees with an arbitrary number of children without storing a fixed-size array of child pointers in every node.

---

## Segment Tree

A **Segment Tree** is a tree-based data structure designed primarily for efficiently answering queries over intervals of an array.

Typical applications include range operations such as:

* range sum;
* range minimum or maximum;
* range updates;
* other associative operations.

This directory contains both a basic implementation and an implementation using **lazy propagation**.

Lazy propagation allows updates affecting an entire range to be postponed and propagated only when necessary, improving the efficiency of multiple range-update and range-query operations.

---

## Implementations

| Implementation                                                                                                                                                                                                               | Description                                                                    |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| [Basic Segment Tree.cpp](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/Basic%20Segment%20Tree.cpp)                                                                 | Basic Segment Tree implementation.                                             |
| [Basic binary search tree implementation.c](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/Basic%20binary%20search%20tree%20implementation.c)                       | Basic Binary Search Tree implementation.                                       |
| [Count nodes of K-ary trees.c](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/Count%20nodes%20of%20K-ary%20trees.c)                                                 | Counts the nodes in a K-ary tree.                                              |
| [Count numbers of nodes in a Binary Search Tree.c](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/Count%20numbers%20of%20nodes%20in%20a%20Binary%20Search%20Tree.c) | Counts the nodes in a Binary Search Tree.                                      |
| [K-ary tree implementation.c](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/K-ary%20tree%20implementation.c)                                                       | K-ary Tree implementation using the first-child / next-sibling representation. |
| [Second basic implementation of Binary Tree.c](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/Second%20basic%20implementation%20of%20Binary%20Tree.c)               | Alternative basic implementation of a Binary Tree.                             |
| [Union K-ary trees.c](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/Union%20K-ary%20trees.c)                                                                       | Implementation involving the union of K-ary trees.                             |
| [segtree-lazy.cpp](https://github.com/TETEURYAN/CompetitiveProgramming/blob/main/Data%20Structures%20and%20Algorithms/Tree/segtree-lazy.cpp)                                                                                 | Segment Tree implementation with lazy propagation.                             |



The implementations in this directory are intended for **study, practice, and competitive programming**, providing concrete examples of how different tree structures can be represented and manipulated using C and C++.

The examples progress from basic tree representations to more specialized structures such as **Binary Search Trees** and **Segment Trees with lazy propagation**.
