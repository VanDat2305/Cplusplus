#include <stdio.h>
#include <string.h>


// khai bao cau truc thi sinh
struct ThiSinh {
    char ten[1000];
    float diem;
    char truong[5];
};

// ham doc du lieu thi sinh tu tep
void docThiSinh(FILE *file, struct ThiSinh thisinh[], int *soThiSinh) {
    fscanf(file, "%d", soThiSinh);
    for (int i = 0; i < *soThiSinh; i++) {
        fscanf(file, " %[^\n] %f %s", thisinh[i].ten, &thisinh[i].diem, thisinh[i].truong);
    }
}

// Truong có so diem cao nhat
void timTruongCoDiemCaoNhat(struct ThiSinh thisinh[], int soThiSinh) {
    float diemCaoNhat = 0;
    char truongDiemCaoNhat[5][50];
    int soTruongDiemCaoNhat = 0;

    // tinh tong diem cao nhat
    for (int i = 0; i < soThiSinh; i++) {
        float tongDiem = 0;
        for (int j = 0; j < soThiSinh; j++) {
            if (strcmp(thisinh[i].truong, thisinh[j].truong) == 0) {
                tongDiem += thisinh[j].diem;
            }
        }
        if (tongDiem > diemCaoNhat) {
            diemCaoNhat = tongDiem;
        }
    }

    // tim truong diem cao nhat
    for (int i = 0; i < soThiSinh; i++) {
        float tongDiem = 0;
        for (int j = 0; j < soThiSinh; j++) {
            if (strcmp(thisinh[i].truong, thisinh[j].truong) == 0) {
                tongDiem += thisinh[j].diem;
            }
        }
        if (tongDiem == diemCaoNhat) {
            strcpy(truongDiemCaoNhat[soTruongDiemCaoNhat], thisinh[i].truong);
            soTruongDiemCaoNhat++;
        }
    }

    // In ra cac truong co diem cao nhat
    printf("Cac truong co diem cao nhat la: ");
    for (int i = 0; i < soTruongDiemCaoNhat; i++) {
        printf("%s ", truongDiemCaoNhat[i]);
    }
    printf("\n");
}

// tim thi sinh co diem cao nhat
void timThiSinhCoDiemCaoNhat(struct ThiSinh thisinh[], int soThiSinh) {
    float diemCaoNhat = 0;
    printf("Cac thi sinh dat diem cao nhat la:\n");
    for (int i = 0; i < soThiSinh; i++) {
        if (thisinh[i].diem > diemCaoNhat) {
            diemCaoNhat = thisinh[i].diem;
        }
    }
    for (int i = 0; i < soThiSinh; i++) {
        if (thisinh[i].diem == diemCaoNhat) {
            printf("%s (%s) - %.2f diem\n", thisinh[i].ten, thisinh[i].truong, thisinh[i].diem);
        }
    }
}

int main() {
    FILE *tep;
    char tenTep[100];
    struct ThiSinh thisinh[100];
    int soThiSinh;

    printf("Nhap ten tep: ");
    scanf("%s", tenTep);

    tep = fopen(tenTep, "r");
    if (tep == NULL) {
        printf("Loi khi mo tep dau vao.\n");
        return 1;
    }

    docThiSinh(tep, thisinh, &soThiSinh);
    fclose(tep);

    timTruongCoDiemCaoNhat(thisinh, soThiSinh);
    timThiSinhCoDiemCaoNhat(thisinh, soThiSinh);

    return 0;
}

