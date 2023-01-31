#include "monty.h"

/**
 * str_split - Splits a string
 * @str: The string that will be splited
 *
 * Return: On success, it returns the new array
 * of strings. On failure, it returns NULL
 */
char **splitString(char *str, size_t *numOfStrings)
{
    char *piece, **str_arr = NULL, *str_cpy = NULL;
    int i = 0;

    if (str == NULL)
        return (NULL);

    str_cpy = strdup (str);
    piece = strtok(str_cpy, " ");
    while (piece != NULL)
    {
        if ((*piece) == '\n')
        {
            piece = strtok(NULL, " ");
            continue;
        }
        (*numOfStrings)++;
        piece = strtok(NULL, " ");
    }

    str_arr = (char **)malloc(sizeof(char *) * (*numOfStrings));
    piece = strtok(str, " ");
    for (i = 0; piece != NULL; i++)
    {
        if ((*piece) == '\n')
        {
            piece = strtok(NULL, " ");
            continue;
        }
        str_arr[i] = (char *)malloc(sizeof(char) * (strlen(piece) + 1));
        strcpy(str_arr[i], piece);
        piece = strtok(NULL, " ");
    }

    if (str_cpy)
        free (str_cpy);

    return (str_arr);
}
