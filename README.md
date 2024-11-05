# ESTRUCTURA DE DATOS
# Proyecto de Árbol B en C

Este proyecto implementa un **Árbol B** en el lenguaje C para gestionar y buscar datos de manera eficiente. Los Árboles B son estructuras de datos autoequilibradas que optimizan la búsqueda y la inserción, manteniendo los datos organizados y accesibles.

## Archivos del Proyecto

### `b_tree.h`
Define las estructuras y las declaraciones de funciones del Árbol B.

- **Estructura `BTreeNode`**: Representa los nodos del Árbol B, incluyendo las claves y los punteros a los nodos hijos.
- **Estructura `SearchResult`**: Contiene el resultado de una búsqueda, indicando si una clave se encontró y en qué posición.
- **Constante `MAX_KEYS`**: Establece el número máximo de claves en un nodo. Puede ajustarse para pruebas.
- **Prototipos de Funciones**: Declaraciones de funciones principales, incluyendo `createNode`, `insert`, `splitChild`, `insertNonFull`, `insertKey` y `search`.

### `b_tree.c`
Implementa las funciones para manipular el Árbol B.

- **`createNode`**: Crea un nuevo nodo vacío para el Árbol B.
- **`insert`**: Inserta una clave en el Árbol B y divide nodos cuando es necesario para mantener el equilibrio.
- **`splitChild`**: Divide un nodo lleno y sube la clave media al nodo padre.
- **`insertNonFull`**: Inserta una clave en un nodo no lleno, buscando el lugar correcto.
- **`insertKey`**: Inserta una clave en un nodo hoja.
- **`search`**: Realiza una búsqueda en el Árbol B y devuelve la posición de la clave, si se encuentra.

### `main.c`
Archivo principal que ejecuta el programa y gestiona la carga de datos y la búsqueda.

- **`loadNumbersFromFile`**: Lee un archivo CSV (`random_numbers_1000000.csv`), ignora el encabezado y carga los números en el Árbol B.
- **Función `main`**:
  - Carga datos desde un archivo CSV y mide el tiempo de inserción.
  - Permite al usuario ingresar un número para buscar y mide el tiempo de búsqueda.
  - Muestra si el número se encuentra en el Árbol B y su posición dentro del nodo.

