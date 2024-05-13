#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void ghiDaySoVaoTep(const char *tenTep, int arrays[][MAX_COLS], int numArrays, int arrayLengths[]) {
    FILE *tep = fopen(tenTep, "w"); // M? t?p tin d? ghi (ho?c t?o n?u nó không t?n t?i)
    if (tep == NULL) {
        printf("Khong the mo tep.\n");
        return;
    }

    // Ghi s? lu?ng dãy s? vào t?p tin
    fprintf(tep, "%d\n", numArrays);

    // Ghi s? lu?ng ph?n t? c?a t?ng dãy s? và các ph?n t? vào t?p tin
    for (int i = 0; i < numArrays; i++) {
        fprintf(tep, "%d ", arrayLengths[i]); // Ghi s? lu?ng ph?n t? c?a dãy s?
        for (int j = 0; j < arrayLengths[i]; j++) {
            fprintf(tep, "%d ", arrays[i][j]); // Ghi các ph?n t? c?a dãy s?
        }
        fprintf(tep, "\n");
    }

    fclose(tep); // Ðóng t?p tin sau khi ghi
}

int main() {
    int numArrays;
    printf("Nhap so luong day so: ");
    scanf("%d", &numArrays);

    int arrayLengths[MAX_ROWS];
    int arrays[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < numArrays; i++) {
        printf("Nhap so luong phan tu cua day so thu %d: ", i + 1);
        scanf("%d", &arrayLengths[i]);
        
        printf("Nhap cac phan tu cua day so thu %d: ", i + 1);
        for (int j = 0; j < arrayLengths[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    ghiDaySoVaoTep("outputtest2.txt", arrays, numArrays, arrayLengths);

    printf("Da ghi du lieu vao tep output.txt.\n");

    return 0;
}

