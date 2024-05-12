#include <stdio.h>

// Function to read integers from file
void nhap(int n, int a[], FILE *f) {
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &a[i]);
}

// Function to print integers to console
void xuat(int n, int a[]) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Function to count negative elements
int demAm(int n, int a[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            count++;
    }
    return count;
}

// Function to find the largest element
int largest(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Function to find and print triplets forming arithmetic sequences
void boBaSo(int n, int a[], FILE *f) {
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        int so1 = a[i];
        int so2 = a[i + 1];
        int so3 = a[i + 2];
        if (so1 + so2 == 2 * so3 || so1 * so3 == 2 * so2 || so2 * so3 == 2 * so1) {
            fprintf(f, "%d %d %d\n", so1, so2, so3);
            count++;
        }
    }
    fprintf(f, "Number of triplets: %d\n", count);
}

int main() {
    FILE *f, *fo;
    int n;
    int a[100];

    // Open input file
    f = fopen("input.txt", "rt");
    if (f == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    fo = fopen("output.txt", "wt");
    if (fo == NULL) {
        printf("Error opening output file.\n");
        fclose(f);
        return 1;
    }

    // Read number of elements
    fscanf(f, "%d", &n);

    // Read integers from file
    nhap(n, a, f);

    // Print integers
    xuat(n, a);

    // Find and print triplets forming arithmetic sequences
    boBaSo(n, a, fo);

    // Print number of negative elements
    fprintf(fo, "Number of negative elements: %d\n", demAm(n, a));

    // Print largest element
    fprintf(fo, "Largest element: %d\n", largest(a, n));

    // Close files
    fclose(f);
    fclose(fo);

    return 0;
}

