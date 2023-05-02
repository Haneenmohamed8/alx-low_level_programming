#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: a pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *new_dog;
    char *name_copy, *owner_copy;
    int name_len, owner_len;

    /* Calculate length of name and owner strings */
    for (name_len = 0; name[name_len]; name_len++)
        ;
    for (owner_len = 0; owner[owner_len]; owner_len++)
        ;

    /* Allocate memory for new dog and copied strings */
    new_dog = malloc(sizeof(dog_t));
    if (new_dog == NULL)
        return (NULL);
    name_copy = malloc(sizeof(char) * (name_len + 1));
    if (name_copy == NULL) {
        free(new_dog);
        return (NULL);
    }
    owner_copy = malloc(sizeof(char) * (owner_len + 1));
    if (owner_copy == NULL) {
        free(new_dog);
        free(name_copy);
        return (NULL);
    }

    /* Copy name and owner strings */
    for (int i = 0; i <= name_len; i++)
        name_copy[i] = name[i];
    for (int i = 0; i <= owner_len; i++)
        owner_copy[i] = owner[i];

    /* Initialize new dog */
    new_dog->name = name_copy;
    new_dog->age = age;
    new_dog->owner = owner_copy;

    return (new_dog);
}
