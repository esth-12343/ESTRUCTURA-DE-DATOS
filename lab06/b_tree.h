#ifndef B_TREE_H
#define B_TREE_H

extern int MAX_KEYS;

struct BTreeNode {
    double *keys;
    int num_keys;
    struct BTreeNode **children;
};

struct SearchResult {
    struct BTreeNode *node;
    int index;
};

struct BTreeNode *createNode();
void insert(struct BTreeNode **root, double key);
void splitChild(struct BTreeNode *parent, int index);
void insertNonFull(struct BTreeNode *node, double key);
void insertKey(struct BTreeNode *node, double key);
struct SearchResult search(struct BTreeNode *node, double key);
void loadNumbersFromFile(struct BTreeNode **root, const char *filename);

#endif // B_TREE_H
