#include <stdio.h>
#include <string.h>

void deleteFirstOccurrence(char *str, char charToDelete) {
    int i, j;
    int len = strlen(str);
    int found = 0; // Flag to indicate if the character was found

    for (i = 0; i < len; i++) {
        if (str[i] == charToDelete) {
            // If found, shift all characters from this point one step left
            for (j = i; j < len; j++) {
                str[j] = str[j+1];
            }
            found = 1;
            break; // Exit the loop after deleting the first occurrence
        }
    }

    if (!found) {
        printf("Character '%c' not found in the string.\n", charToDelete);
    }
}

int main() {
    char str[] = "hello world, hello universe";
    char charToDelete = 'l';

    printf("Original string: %s\n", str);

    deleteFirstOccurrence(str, charToDelete);

    printf("String after deleting first '%c': %s\n", charToDelete, str);

    return 0;
}
