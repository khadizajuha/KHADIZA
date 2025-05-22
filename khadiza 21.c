#include <stdio.h>

#define SIZE 100

int arr[SIZE];
int n = 0; // Current size of the array

void insert() {
    int count, value;
    printf("How many values do you want to insert? ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        if (n >= SIZE) {
            printf("Array is full!\n");
            return;
        }
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        arr[n++] = value;
    }
}

void update() {
    int index, value;
    printf("Enter index to update: ");
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        printf("Enter new value: ");
        scanf("%d", &value);
        arr[index] = value;
    } else {
        printf("Invalid index!\n");
    }
}

void delete() {
    int value, found = 0;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1]; // Shift left
            }
            n--;
            printf("Value deleted.\n");
            break;
        }
    }
    if (!found)
        printf("Value not found!\n");
}

void display() {
    printf("Current Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int order) {
    // order = 1 for ascending, 0 for descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((order && arr[i] > arr[j]) || (!order && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf(order ? "Sorted in Ascending order.\n" : "Sorted in Descending order.\n");
}

void search() {
    int value, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Value found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Value not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n2. Update\n3. Delete\n4. Display\n5. Sort\n6. Search\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: update(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: {
                int order;
                printf("1 for Ascending, 0 for Descending: ");
                scanf("%d", &order);
                sort(order);
                break;
            }
            case 6: search(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
