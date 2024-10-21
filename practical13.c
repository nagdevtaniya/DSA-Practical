#include <stdio.h>
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int choice, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
       printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4) {
            printf("Exit\n");
            break;
        }
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        switch (choice) {
            case 1:
                selection_sort(arr, n);
                printf("Sorted array (Selection Sort): ");
                print_array(arr, n);
                break;
            case 2:
                bubble_sort(arr, n);
                printf("Sorted array (Bubble Sort): ");
                print_array(arr, n);
                break;
            case 3:
                insertion_sort(arr, n);
                printf("Sorted array (Insertion Sort): ");
                print_array(arr, n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
