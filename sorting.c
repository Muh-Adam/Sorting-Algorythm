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

    // Seed random number generator
    srand(time(NULL));

    // Generate random float array
    for (int i = 0; i < n; i++) {
        original[i] = (float)rand() / RAND_MAX * 100.0f; // Random float between 0 and 100
    }

    printf("Data awal (acak):\n");
    print_array(original, n);

    // Bubble Sort
    memcpy(temp, original, n * sizeof(float));
    clock_t start = clock();
    bubble_sort(temp, n);
    clock_t end = clock();
    double bubble_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Setelah Bubble Sort:\n");
    print_array(temp, n);
    printf("Waktu Bubble Sort: %.6f detik\n", bubble_time);

    // Selection Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    selection_sort(temp, n);
    end = clock();
    double selection_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Setelah Selection Sort:\n");
    print_array(temp, n);
    printf("Waktu Selection Sort: %.6f detik\n", selection_time);

    // Insertion Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    insertion_sort(temp, n);
    end = clock();
    double insertion_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Setelah Insertion Sort:\n");
    print_array(temp, n);
    printf("Waktu Insertion Sort: %.6f detik\n", insertion_time);

    // Perbandingan waktu
    printf("\nPerbandingan Waktu Eksekusi:\n");
    printf("Bubble Sort: %.6f detik\n", bubble_time);
    printf("Selection Sort: %.6f detik\n", selection_time);
    printf("Insertion Sort: %.6f detik\n", insertion_time);

    // Analisis
    printf("\nAnalisis:\n");
    printf("Ketiga algoritma sorting ini memiliki kompleksitas waktu rata-rata O(n^2), sehingga untuk array besar, waktu eksekusi akan meningkat signifikan.\n");
    printf("Bubble Sort biasanya paling lambat karena melakukan banyak pertukaran elemen.\n");
    printf("Selection Sort sedikit lebih efisien karena hanya melakukan satu pertukaran per iterasi luar.\n");
    printf("Insertion Sort bisa lebih cepat untuk array yang hampir terurut, karena hanya memindahkan elemen yang diperlukan.\n");
    printf("Dalam kasus ini, dengan data acak, Insertion Sort mungkin menunjukkan performa yang lebih baik dibandingkan Bubble Sort.\n");

    free(original);
    free(temp);
    return 0;
}