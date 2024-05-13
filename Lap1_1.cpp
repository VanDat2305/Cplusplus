#include <stdio.h>

//B�i 1. Cho t?p van b?n input.txt ch?a th�ng tin v? hai d�y al, a2, .... an v� bim b2. .... bn.
//T?p c� c?u tr�c nhu sau: D�ng d?u ch?a c�c s? nguy�n n, m l� s? ph�n t? c?a d�y a v� d�y
//b. d�ng th? hai ch?a n s? c?a d�y a, d�ng th? ba ch?a m s? c?a d�y b. H�y vi?t chuong
//tr�nh c� x�y d?ng c�c h�m d? th?c hi?n:
//1. �?c t? t?p hai d�y s? nguy�n, c� c?p ph�t d?ng b? nh?, in c�c d�y s? ra m�n h�nh.
//2. T�nh gi� tr? l?n nh?t c?a d�y a v� gi� tr? l?n nh?t c?a d�y b.
//3. S?p x?p d�y a v� d�y b d?u theo th? t? gi?m d?n, sau d� dua c�c d�y s? d� du?c s?p x?p
//ra m�n h�nh.

// Doc day so tu tep va luu vao mang, tra ve so phan tu
int docDaySo(FILE *file, int daySo[]) {
    int doDai;
    fscanf(file, "%d", &doDai);
    printf("%d\n", doDai);
    for (int i = 0; i < doDai; i++)
        fscanf(file, "%d", &daySo[i]);
    return doDai;
}

// Tim gia tri lon nhat trong day so
int timMax(int daySo[], int doDai) {
    int max = daySo[0];
    for (int i = 1; i < doDai; i++) {
        if (daySo[i] > max)
            max = daySo[i];
    }
    return max;
}

// Sap xep day so theo thu tu giam dan
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

    // Mo tep dau vao
    file = fopen("inputLap11.txt", "r");
    if (file == NULL) {
        printf("Loi khi mo tep dau vao.\n");
        return 1;
    }
    
   


//    // Doc va in day so A
//    doDaiA = docDaySo(file, daySoA);
//    printf("Day so A: ");
//    inDaySo(daySoA, doDaiA);
//
//    // Doc va in day so B
    doDaiB = docDaySo(file, daySoB);
//    printf("Day so B: ");
//    inDaySo(daySoB, doDaiB);
//
//    // Tim va in gia tri lon nhat cua day A
//    int maxA = timMax(daySoA, doDaiA);
//    printf("Gia tri lon nhat cua day A: %d\n", maxA);
//
//    // Tim va in gia tri lon nhat cua day B
//    int maxB = timMax(daySoB, doDaiB);
//    printf("Gia tri lon nhat cua day B: %d\n", maxB);
//
//    // Sap xep ca hai day theo thu tu giam dan
//    sapXepGiamDan(daySoA, doDaiA);
//    sapXepGiamDan(daySoB, doDaiB);
//
//    // In cac day da sap xep ra man hinh
//    printf("Day A da sap xep: ");
//    inDaySo(daySoA, doDaiA);
//    printf("Day B da sap xep: ");
//    inDaySo(daySoB, doDaiB);

    // Dong tep
    fclose(file);

    return 0;
}

