#include <stdio.h>

// Fungsi Shell Sort
void shellSort(int arr[], int n) {
    // Start dengan gap besar (n/2), lalu bagi 2 setiap iterasi sampai gap = 0
    for (int gap = n/2; gap > 0; gap /= 2) {
        
        // Lakukan gapped insertion sort untuk gap ini.
        // Elemen arr[0..gap-1] sudah dalam urutan gap-nya
        // Terus tambahkan satu elemen lagi sampai seluruh array tergap-sorted
        for (int i = gap; i < n; i++) {
            
            // Simpan nilai arr[i] agar tidak tertimpa saat menggeser
            int temp = arr[i];
            
            // Geser elemen-elemen arr[0..i-1] yang sudah terurut gap
            // ke kanan sampai menemukan lokasi yang pas untuk temp
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // Geser angka besar ke kanan
            }
            
            // Masukkan temp ke posisi yang tepat
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    // Menghitung jumlah elemen array secara dinamis
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum sorting: \n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    shellSort(arr, n);

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}