#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

int MAX_KEYS;

struct BTreeNode *createNode() {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        printf("La asignación de memoria falló.\n");
        exit(1);
    }
    newNode->keys = (double *)malloc(MAX_KEYS * sizeof(double));
    newNode->children = (struct BTreeNode **)malloc((MAX_KEYS + 1) * sizeof(struct BTreeNode *));
    if (newNode->keys == NULL || newNode->children == NULL) {
        printf("La asignación de memoria falló.\n");
        free(newNode);
        exit(1);
    }
    newNode->num_keys = 0;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insert(struct BTreeNode **root, double key) {
    if (*root == NULL) {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
    } else {
        if ((*root)->num_keys == MAX_KEYS) {
            struct BTreeNode *newRoot = createNode();
            newRoot->children[0] = *root;
            splitChild(newRoot, 0);
            *root = newRoot;
        }
        insertNonFull(*root, key);
    }
}

void splitChild(struct BTreeNode *parent, int index) {
    struct BTreeNode *child = parent->children[index];
    struct BTreeNode *newChild = createNode();
    newChild->num_keys = MAX_KEYS / 2;

    for (int i = 0; i < MAX_KEYS / 2; i++) {
        newChild->keys[i] = child->keys[i + MAX_KEYS / 2 + 1];
    }

    if (child->children[0] != NULL) {
        for (int i = 0; i < MAX_KEYS / 2 + 1; i++) {
            newChild->children[i] = child->children[i + MAX_KEYS / 2 + 1];
        }
    }

    child->num_keys = MAX_KEYS / 2;

    for (int i = parent->num_keys; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newChild;

    for (int i = parent->num_keys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = child->keys[MAX_KEYS / 2];
    parent->num_keys++;
}

void insertNonFull(struct BTreeNode *node, double key) {
    int i = node->num_keys - 1;

    if (node->children[0] == NULL) {
        insertKey(node, key);
    } else {
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;
        if (node->children[i]->num_keys == MAX_KEYS) {
            splitChild(node, i);
            if (node->keys[i] < key) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

void insertKey(struct BTreeNode *node, double key) {
    int i = node->num_keys - 1;

    while (i >= 0 && node->keys[i] > key) {
        node->keys[i + 1] = node->keys[i];
        i--;
    }
    node->keys[i + 1] = key;
    node->num_keys++;
}

struct SearchResult search(struct BTreeNode *node, double key) {
    int i = 0;
    while (i < node->num_keys && key > node->keys[i]) {
        i++;
    }

    struct SearchResult result = {NULL, -1};

    if (i < node->num_keys && key == node->keys[i]) {
        result.node = node;
        result.index = i;
        return result;
    }

    if (node->children[0] == NULL) {
        return result;
    }

    return search(node->children[i], key);
}

void loadNumbersFromFile(struct BTreeNode **root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    char buffer[1024];
    fgets(buffer, sizeof(buffer), file); // Ignora la primera línea (encabezado)

    double key;
    while (fscanf(file, "%*d,%lf", &key) == 1) {
        insert(root, key);
    }

    fclose(file);
}
