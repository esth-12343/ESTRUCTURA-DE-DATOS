#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "b_tree.h"

int main() {
    printf("Ingrese el número máximo de llaves: ");
    scanf("%d", &MAX_KEYS);

    if (MAX_KEYS < 2) {
        printf("El número máximo de llaves debe ser al menos 2.\n");
        return 1;
    }

    struct BTreeNode *root = NULL;

    clock_t start_load = clock();
    loadNumbersFromFile(&root, "random_numbers_1000000.csv");
    clock_t end_load = clock();
    double load_time = (double)(end_load - start_load) / CLOCKS_PER_SEC;
    printf("Tiempo de carga de datos: %.5lf segundos\n", load_time);

    double search_key;
    printf("Ingrese el número que desea buscar: ");
    scanf("%lf", &search_key);

    clock_t start_search = clock();
    struct SearchResult result = search(root, search_key);
    clock_t end_search = clock();
    double search_time = (double)(end_search - start_search) / CLOCKS_PER_SEC;
    printf("Tiempo de búsqueda: %.5lf segundos\n", search_time);

    if (result.node != NULL) {
        printf("El número %.5lf se encuentra en el árbol B.\n", search_key);
        printf("Nodo: ");
        for (int i = 0; i < result.node->num_keys; i++) {
            printf("%.5lf ", result.node->keys[i]);
        }
        printf("\nNúmero de llave en que está ubicado ese valor: %d\n", result.index + 1);
    } else {
        printf("El número %.5lf no se encuentra en el árbol B.\n", search_key);
    }

    return 0;
}
