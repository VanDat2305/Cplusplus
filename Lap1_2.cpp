#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
//Bài 2. Nh?p danh sách n nhân viên c?a I công ty t? t?p input.txt. M?i nhân viên là m?t c?u
//trúc du?c luu tr? trên 3 dòng c?a t?p g?m các tru?ng : MNV (mã nhân viên), HT (H? tên
//NV), LUONG (Luong ), PHONG (phòng ban). Gi? s? công ty có 3 phòng A, B, C, Dòng
//d?u c?a t?p là s? nguyên luu tr? s? lu?ng nhân viên
//1. T?nh luong trung bình c?a t?ng phòng và cho bi?t phòng nào có luong trung bình th?p
//nh?t
//2. In danh sách nhân viên ra mà hình theo th? t? gi?m cân c?a luong
//3. k?t quái luu vào t?p kq.txt bao g?m c? các thông tin v? n nhân viên.
typedef struct {
    char MNV[10];
    char HT[50];
    float LUONG;
    char PHONG[2];
} NhanVien;

int docDanhSach(FILE *file, NhanVien danhSach[]) {
    int n;
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", danhSach[i].MNV);
        fscanf(file, "%s", danhSach[i].HT);
        fscanf(file, "%f", &danhSach[i].LUONG);
        fscanf(file, "%s", danhSach[i].PHONG);
    }
    return n;
}

void tinhLuongTrungBinh(NhanVien danhSach[], int n, float luongTrungBinh[]) {
    int dem[MAX_SIZE] = {0};
    float tongLuong[MAX_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        if (strcmp(danhSach[i].PHONG, "A") == 0) {
            tongLuong[0] += danhSach[i].LUONG;
            dem[0]++;
        } else if (strcmp(danhSach[i].PHONG, "B") == 0) {
            tongLuong[1] += danhSach[i].LUONG;
            dem[1]++;
        } else if (strcmp(danhSach[i].PHONG, "C") == 0) {
            tongLuong[2] += danhSach[i].LUONG;
            dem[2]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (dem[i] != 0) {
            luongTrungBinh[i] = tongLuong[i] / dem[i];
        } else {
            luongTrungBinh[i] = 0;
        }
    }
}

void inDanhSachTheoLuong(NhanVien danhSach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSach[i].LUONG < danhSach[j].LUONG) {
                NhanVien temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }

    printf("\nDanh sach nhan vien theo thu tu giam dan cua luong:\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-30s %-10.2f %-5s\n", danhSach[i].MNV, danhSach[i].HT, danhSach[i].LUONG, danhSach[i].PHONG);
    }
}

void ghiKetQua(FILE *file, NhanVien danhSach[], int n) {
    fprintf(file, "Danh sach nhan vien:\n");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %.2f %s\n", danhSach[i].MNV, danhSach[i].HT, danhSach[i].LUONG, danhSach[i].PHONG);
    }
}

int main() {
    FILE *file, *fileKQ;
    NhanVien danhSach[MAX_SIZE];
    float luongTrungBinh[3] = {0};
    int n;

    file = fopen("inputLap12.txt", "r");
    if (file == NULL) {
        printf("Loi khi mo tep dau vao.\n");
        return 1;
    }

    n = docDanhSach(file, danhSach);

    tinhLuongTrungBinh(danhSach, n, luongTrungBinh);

    printf("Tinh luong trung binh cua tung phong:\n");
    float luongTrungBinhThapNhat = luongTrungBinh[0];
    char phongLuongThapNhat = 'A';
    for (int i = 0; i < 3; i++) {
        printf("Phong %c: %.2f\n", 'A' + i, luongTrungBinh[i]);
        if (luongTrungBinh[i] < luongTrungBinhThapNhat) {
            luongTrungBinhThapNhat = luongTrungBinh[i];
            phongLuongThapNhat = 'A' + i;
        }
    }
    printf("Phong co luong trung binh thap nhat: Phong %c\n", phongLuongThapNhat);

    inDanhSachTheoLuong(danhSach, n);

    fileKQ = fopen("kq.txt", "w");
    if (fileKQ == NULL) {
        printf("Loi khi mo tep ket qua.\n");
        fclose(file);
        return 1;
    }

    ghiKetQua(fileKQ, danhSach, n);

    fclose(file);
    fclose(fileKQ);

    return 0;
}

