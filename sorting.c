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
    if (argc != 2) {
        fprintf(stderr, "Penggunaan: %s <jumlah_elemen>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Jumlah elemen harus lebih besar dari 0\n");
        return 1;
    }

    float *original = malloc(n * sizeof(float));
    float *temp = malloc(n * sizeof(float));
    if (original == NULL || temp == NULL) {
        printf("Alokasi memori gagal\n");
        free(original); // Note: free(NULL) is safe
        free(temp);
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Generate random float array
    for (int i = 0; i < n; i++) {
        original[i] = (float)rand() / RAND_MAX * 100.0f; // Random float between 0 and 100
    }

    printf("Mengurutkan %d elemen data acak...\n\n", n);

    // Bubble Sort
    memcpy(temp, original, n * sizeof(float));
    clock_t start = clock();
    bubble_sort(temp, n);
    clock_t end = clock();
    printf("Waktu Bubble Sort    : %.6f detik\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Selection Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    selection_sort(temp, n);
    end = clock();
    printf("Waktu Selection Sort : %.6f detik\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Insertion Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    insertion_sort(temp, n);
    end = clock();
    printf("Waktu Insertion Sort : %.6f detik\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    free(original);
    free(temp);
    return 0;
}