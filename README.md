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

# TABLA COMPARATIVA 
Se realiza una comparación en relación al numero de llaves y al tiempo que conlleva en encontrar un valor en el árbol B.

![Tabla comparativa](https://github.com/esth-12343/ESTRUCTURA-DE-DATOS/blob/main/images/TABLA-COMPARATIVA.png)

A medida que se incrementa el número de llaves por nodo en el B-tree (3, 5, 7, 9), el tiempo de búsqueda disminuye. Esto ocurre porque tener más llaves por nodo hace que el árbol sea más "plano", reduciendo la cantidad de niveles que se deben recorrer para encontrar un valor.

**Reducción del Tiempo de Búsqueda:

Pasar de 3 a 9 llaves reduce el tiempo de búsqueda de 2.649 a 1.963 segundos.
La mejora es mayor al principio, pero disminuye conforme aumentan las llaves por nodo (beneficios decrecientes).

**Balance entre Velocidad y Tamaño: Aunque más llaves por nodo mejoran la velocidad de búsqueda, también aumentan el tamaño de cada nodo, lo cual podría requerir más memoria o espacio en disco. Es importante balancear el número de llaves por nodo para optimizar rendimiento sin exceder los recursos disponibles.

En resumen, más llaves por nodo en un B-tree tienden a mejorar el tiempo de búsqueda, pero hay un límite práctico donde los beneficios disminuyen.