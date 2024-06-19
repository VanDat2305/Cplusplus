#include <stdio.h>

// 1. doc ma tan
void docMaTran(FILE *file, int maTran[][100], int *cap) {
    fscanf(file, "%d", cap);
    for (int i = 0; i < *cap; i++) {
        for (int j = 0; j < *cap; j++) {
            fscanf(file, "%d", &maTran[i][j]);
        }
    }
}
// 2. tinh trung binh
double tinhTrungBinhDuoiDuongCheoPhu(int maTran[][100], int cap) {
    int sum = 0, count = 0;
    for (int i = 1; i < cap; i++) {
        for (int j = 0; j < cap - i; j++) {
            sum += maTran[i][j];
            count++;
        }
    }
    return (count == 0) ? 0 : (double)sum / count;
}

//// 3 
int kiemTraMaTranTamGiacTren(int maTran[][100], int cap) {
    for (int i = 1; i < cap; i++) {
        for (int j = 0; j < i; j++) {
            if (maTran[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}
/// 5
int hangCoTongLonNhat(int maTran[][100], int cap) {
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < cap; i++) {
        int sum = 0;
        for (int j = 0; j < cap; j++) {
            sum += maTran[i][j];
        }
        if (i == 0 || sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    return maxRow;
}
// 4
int kiemTraDoiXung(int maTran[][100], int cap) {
    for (int i = 0; i < cap; i++) {
        for (int j = 0; j < cap; j++) {
            if (maTran[i][j] != maTran[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}


int main() {
	FILE *file;
	char fileName[100];
	
	int maTran[100][100], cap;
	
	
	printf("Nhap ten tep: ");
    scanf("%s", fileName);
    // y1
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Loi khi mo tep dau vao.\n");
        return 1;
    }
    
    docMaTran(file, maTran, &cap);
    fclose(file);
    
    //y2
    
    double tb = tinhTrungBinhDuoiDuongCheoPhu(maTran, cap);
    printf("Trung binh cong cac phan tu: %.2f\n", tb);

	// y3
    if (kiemTraMaTranTamGiacTren(maTran, cap)) {
        printf("Ma tran la ma tran tam giac tren.\n");
    } else {
        printf("Ma tran khong phai la ma tran tam giac tren.\n");
    }

	//y4
	if (kiemTraDoiXung(maTran, cap)) {
        printf("Ma tran doi xung.\n");
    } else {
        printf("Ma tran khong doi xung.\n");
    }
    //y5
    int maxRow = hangCoTongLonNhat(maTran, cap);
    printf("Hang co tong lon nhat la hang %d\n", maxRow + 1);
    
	
}
