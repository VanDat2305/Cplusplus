#include <stdio.h>

//1
void docMaTran(FILE *file, double maTran[][100], int *m, int *n) {
    fscanf(file, "%d %d", m, n);
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%lf", &maTran[i][j]);
        }
    }
}

//2
double tinhTrungBinhCacPhanTuDuongHangLe(double maTran[][100], int m, int n) {
    double sum = 0;
    int count = 0;
    for (int i = 1; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
            if (maTran[i][j] > 0) {
                sum += maTran[i][j];
                count++;
            }
        }
    }
    return (count == 0) ? 0 : sum / count;
}

//3
double timPhanTuDuongNhoNhat(double maTran[][100], int m, int n) {
    double min;
    bool found = false;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maTran[i][j] > 0) {
                if (!found || maTran[i][j] < min) {
                    min = maTran[i][j];
                    found = true;
                }
            }
        }
    }
    return found ? min : -1;
}

int main() {
    FILE *file;
    char fileName[100];
    double maTran[100][100];
    int m, n;

//    
//    printf("Nhap ten tep: ");
//    scanf("%s", fileName);
//
//    
//    file = fopen(fileName, "r");
//    if (file == NULL) {
//        printf("Loi khi mo tep dau vao.\n");
//        return 1;
//    }
    while (1) {
        printf("Nhap ten tep: ");
        if (scanf("%99s", fileName) != 1) {
            printf("Loi khi doc ten tep.\n");
            return 1;
        }

       
        if ((file = fopen(fileName, "r")) != NULL) {
           
            fclose(file);
            break;
        } else {
            printf("Tep khong ton tai. Vui long nhap lai.\n");
        }
    }

    docMaTran(file, maTran, &m, &n);
    fclose(file);

    
    double tb = tinhTrungBinhCacPhanTuDuongHangLe(maTran, m, n);
    printf("Trung binh cong cac phan tu duong o hang le: %.2f\n", tb);

    
    double viTriBe = timPhanTuDuongNhoNhat(maTran, m, n);
    if (viTriBe == -1) {
        printf("Khong co phan tu duong trong ma tran.\n");
    } else {
        printf("Phan tu duong nho nhat trong ma tran: %.2f\n", viTriBe);
    }

    return 0;
}

