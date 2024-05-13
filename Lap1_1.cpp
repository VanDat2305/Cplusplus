#include <stdio.h>

//Bài 1. Cho t?p van b?n input.txt ch?a thông tin v? hai dãy al, a2, .... an và bim b2. .... bn.
//T?p có c?u trúc nhu sau: Dòng d?u ch?a các s? nguyên n, m là s? phân t? c?a dãy a và dãy
//b. dòng th? hai ch?a n s? c?a dãy a, dòng th? ba ch?a m s? c?a dãy b. Hãy vi?t chuong
//trình có xây d?ng các hàm d? th?c hi?n:
//1. Ð?c t? t?p hai dãy s? nguyên, có c?p phát d?ng b? nh?, in các dãy s? ra màn hình.
//2. Tính giá tr? l?n nh?t c?a dãy a và giá tr? l?n nh?t c?a dãy b.
//3. S?p x?p dãy a và dãy b d?u theo th? t? gi?m d?n, sau dó dua các dãy s? dã du?c s?p x?p
//ra màn hình.

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

