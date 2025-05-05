#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Fonction auxiliaire pour afficher le tableau.
 * @array: Pointeur vers le premier élément du tableau à afficher.
 * @left: Indice gauche du sous-tableau à afficher.
 * @right: Indice droit du sous-tableau à afficher.
 */
void print_array(int *array, int left, int right)
{
    int i;

    printf("Searching in array: ");
    for (i = left; i < right; i++)
        printf("%d, ", array[i]);
    printf("%d\n", array[right]);
}

/**
 * advanced_binary_recursive
 * @array: Pointeur vers le premier élément du tableau à chercher.
 * @left: Indice gauche du sous-tableau actuel.
 * @right: Indice droit du sous-tableau actuel.
 * @value: La valeur à chercher.
 *
 * Return: L'indice de la première occurrence de la valeur,ou -1 si non trouvée
 */
int advanced_binary_recursive(int *array, int left, int right, int value)
{
    int mid;

    if (right >= left)
    {
        mid = left + (right - left) / 2;
        print_array(array, left, right);

        if (array[mid] == value)
        {
            if (mid == left || array[mid - 1] != value)
                return (mid);
            return (advanced_binary_recursive(array, left, mid - 1, value));
        }

        if (array[mid] < value)
            return (advanced_binary_recursive(array, mid + 1, right, value));
        return (advanced_binary_recursive(array, left, mid - 1, value));
    }

    return (-1);
}

/**
 * advanced_binary - Fonction qui initie la recherche binaire.
 * @array: Pointeur vers le premier élément du tableau à chercher.
 * @size: Le nombre d'éléments dans le tableau.
 * @value: La valeur à chercher.
 *
 * Return: L'indice de la première occurrence de la valeur
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);  // Si le tableau est NULL, on retourne -1
    return (advanced_binary_recursive(array, 0, size - 1, value));
}
