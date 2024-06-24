#include <stdio.h>

// doc day so tu file
void docDaySo(FILE *file, int daySo[], int doDai) {
    for (int i = 0; i < doDai; i++) {
        fscanf(file, "%d", &daySo[i]);
    }
}

// tim gia tri lon nhat trong day
int timMax(int daySo[], int doDai) {
    int max = daySo[0];
    for (int i = 1; i < doDai; i++) {
        if (daySo[i] > max)
            max = daySo[i];
    }
    return max;
}

// Sap xep day giam dan
void sapXepGiamDan(int daySo[], int doDai) {
    for (int i = 0; i < doDai - 1; i++) {
        for (int j = i + 1; j < doDai; j++) {
            if (daySo[i] < daySo[j]) {
                int temp = daySo[i];
                daySo[i] = daySo[j];
                daySo[j] = temp;
            }
        }
    }
}

// In day so ra man hinh
void inDaySo(int daySo[], int doDai) {
    for (int i = 0; i < doDai; i++) {
        printf("%d ", daySo[i]);
    }
    printf("\n");
}


int main() {
    FILE *file;
    int daySoA[100], daySoB[100];
    int doDaiA, doDaiB;

    // mo tep
    file = fopen("input_01.txt", "r");
    if (file == NULL) {
        printf("khong mo duoc file.\n");
        return 1;
    }

    // Doc do dai day A va day B
    fscanf(file, "%d %d", &doDaiA, &doDaiB);

    // doc in day A
    docDaySo(file, daySoA, doDaiA);
    printf("Day so A: ");
    inDaySo(daySoA, doDaiA);

    // Doc day so B
    docDaySo(file, daySoB, doDaiB);
    printf("Day so B: ");
    inDaySo(daySoB, doDaiB);

    // Dong tep
    fclose(file);

    // Tim va in ra gia tri lon nhat cua day A va B
    int maxA = timMax(daySoA, doDaiA);
    int maxB = timMax(daySoB, doDaiB);
    printf("gia tri lon nhat trong day so A: %d\n", maxA);
    printf("gia tri lon nhat trong day so B: %d\n", maxB);

    // Sap xep va in day so A va B theo thu tu giam dan
    sapXepGiamDan(daySoA, doDaiA);
    sapXepGiamDan(daySoB, doDaiB);
    printf("Day so A sau khi sap xep giam dan : ");
    inDaySo(daySoA, doDaiA);
    printf("Day so B sau khi sap xep giam dan : ");
    inDaySo(daySoB, doDaiB);

    return 0;
}
