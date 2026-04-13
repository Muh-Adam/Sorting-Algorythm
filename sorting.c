#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubble_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                float swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

void selection_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        float swap = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = swap;
    }
}

void insertion_sort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print_array(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Penggunaan: %s <ukuran_problem>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Ukuran problem harus lebih besar dari 0\n");
        return 1;
    }

    float *original = malloc(n * sizeof(float));
    float *temp = malloc(n * sizeof(float));
    if (original == NULL || temp == NULL) {
        printf("Alokasi memori gagal\n");
        free(original);
        free(temp);
        return 1;
    }

    printf("Masukkan %d elemen array:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%f", &original[i]) != 1) {
            printf("Input tidak valid pada elemen ke-%d\n", i + 1);
            free(original);
            free(temp);
            return 1;
        }
    }

    printf("Data awal:\n");
    print_array(original, n);

    memcpy(temp, original, n * sizeof(float));
    bubble_sort(temp, n);
    printf("Setelah Bubble Sort:\n");
    print_array(temp, n);

    memcpy(temp, original, n * sizeof(float));
    selection_sort(temp, n);
    printf("Setelah Selection Sort:\n");
    print_array(temp, n);

    memcpy(temp, original, n * sizeof(float));
    insertion_sort(temp, n);
    printf("Setelah Insertion Sort:\n");
    print_array(temp, n);

    free(original);
    free(temp);
    return 0;
}