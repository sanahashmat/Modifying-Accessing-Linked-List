#include <stdio.h>

int main() {
    // Example array (list) of integers
    int numbers[] = {34, 12, 56, 78, 23, 90, 45, 11};
    // Calculate the number of elements in the array
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Initialize max and min with the first element of the array
    int max = numbers[0];
    int min = numbers[0];

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is greater than the current maximum
        if (numbers[i] > max) {
            max = numbers[i];
        }

        // Check if the current element is smaller than the current minimum
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // Print the results
    printf("The elements in the list are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Maximum element in the list: %d\n", max);
    printf("Minimum element in the list: %d\n", min);

    return 0;
}
