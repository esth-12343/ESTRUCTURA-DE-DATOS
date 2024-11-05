#ifndef B_TREE_H
#define B_TREE_H

#define MAX_KEYS 2 // Cambiar entre 2 y 3 para las pruebas

struct BTreeNode {
    double keys[MAX_KEYS];
    int num_keys;
    struct BTreeNode *children[MAX_KEYS + 1];
};

// Estructura para almacenar el resultado de la búsqueda
struct SearchResult {
    struct BTreeNode *node;
    int index;
};

// Prototipos de funciones
struct BTreeNode *createNode();
void insert(struct BTreeNode **root, double key);
void splitChild(struct BTreeNode *parent, int index);
void insertNonFull(struct BTreeNode *node, double key);
void insertKey(struct BTreeNode *node, double key);
struct SearchResult search(struct BTreeNode *node, double key);

#endif // B_TREE_H
