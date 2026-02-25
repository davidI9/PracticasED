# Estructuras de datos lineales

_© F.J. Madrid Cuevas <fjmadrid@uco.es>. Estructura de Datos. Grado de Ingeniería Informática. Universidad de Córdoba. España_

## Objetivos

- Aprender a implementar el TAD CDArray.
- Aprender a implementar el TAD List usando una lista de nodos doblemente enlazados.
- Aprender a implementar el TAD ListIterator.
- Aprender a implementar algoritmos basados en listas: fold, unfold, find, sort, merge.
- Aprender a implementar el TAD Stack usando una lista.
- Aprender a implementar el TAD Queue usando un array dinámico circular.

## Descripción

En esta práctica tienes que implementar varias estructuras de datos lineales. Hay dos estructuras básicas: el array dinámico circular (CDArray)y la lista (List).

Con la lista podrás implementar después la pila (Stack) y con el el array dinámico circular podrás implementar la cola (Queue).

Para implementar la lista, vamos a utilizar un diseño de cadena de nodos doblemente enlazados (ListNode), aunque en la primera semana de la práctica se puede simplificar a una lista simple de nodos enlazados usando sólo un enlace al siguiente nodo.

Para editar la lista utilizaremos iteradores por lo que deberás implementar el TAD ListIterator.

Por último, se propone implementar varios algoritmos aplicados a las listas como son: Plegado/Desplegado (fold/unfold), localizar (find), traspasar nodos (splice), combinar listas ordenadas (merge) y ordenar la lista (mergeSort).

Se recomienda la siguiente forma de realizar la práctica:

- **Primera semana**: implementar los tipos CDArray, Queue, los tipos ListNode y List pero sólo las interfaces para implementar la interfaz de lista simple (crear, front(), push_front(), pop_front()) y el tipo Stack.
- **Segunda semana**: implementar los tipos ListNode completo (doble enlazado), ListIterator, operaciones de edición de Lista (usando iteradores), los algoritmos de lista (splice, merge y sort) y el TAD Stack.

## Evaluación

Puedes ver los tests a pasar y su peso en la evaluación en el fichero `TESTS.json`.

## Fechas de entrega

Ver fichero `DATES.json`.

**Importante**: Independientemente del grupo GM al que asistas, tienes que realizar la entrega con fecha tope según el grupo que tienes asignado en moodle.
