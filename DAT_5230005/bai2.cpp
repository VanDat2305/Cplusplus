#include <stdio.h>

typedef struct {
    char hoTen[100];
    char queQuan[100];
    char hocLuc;
} SinhVien;

//y1
int docDanhSachSinhVien(FILE *file, SinhVien dsSinhVien[]) {
    int soSV;
    fscanf(file, "%d", &soSV);
    for (int i = 0; i < soSV; i++) {
        fscanf(file, " %[^\n]%*c", dsSinhVien[i].hoTen);
        fscanf(file, " %[^\n]%*c", dsSinhVien[i].queQuan);
        fscanf(file, " %c%*c", &dsSinhVien[i].hocLuc);
    }
    return soSV;
}

//y2
void xuatDanhSachSinhVien(SinhVien dsSinhVien[], int soSV) {
    for (int i = 0; i < soSV; i++) {
        printf("Sinh Vien %d:\n", i + 1);
        printf("  Ho ten: %s\n", dsSinhVien[i].hoTen);
        printf("  Que quan: %s\n", dsSinhVien[i].queQuan);
        printf("  Hoc luc: %c\n", dsSinhVien[i].hocLuc);
    }
}
//y3
void timSinhVienTheoTen(SinhVien dsSinhVien[], int soSV, const char *ten) {
    int found = 0;
    for (int i = 0; i < soSV; i++) {
	        SinhVien temp = dsSinhVien[i];
	        if(dsSinhVien[i].hoTen == ten){
	         printf("\nThong tin Sinh vien:\n");
	            printf("%-10s %-30s %-10s\n", dsSinhVien[i].hoTen, dsSinhVien[i].queQuan, dsSinhVien[i].hocLuc);
	   }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ten: %s\n", ten);
    }
}
//y4
int demSinhVienHocLucA(SinhVien dsSinhVien[], int soSV) {
    int count = 0;
    for (int i = 0; i < soSV; i++) {
        if (dsSinhVien[i].hocLuc == 'A') {
            count++;
        }
    }
    return count;
}
//
void inSinhVienTheoHocLuc(SinhVien dsSinhVien[], int soSV, char hocLuc) {
    int found = 0;
    for (int i = 0; i < soSV; i++) {
        if (dsSinhVien[i].hocLuc == hocLuc) {
            printf("Thong tin sinh vien:\n");
            printf("  Ho ten: %s\n", dsSinhVien[i].hoTen);
            printf("  Que quan: %s\n", dsSinhVien[i].queQuan);
            printf("  Hoc luc: %c\n", dsSinhVien[i].hocLuc);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi hoc luc: %c\n", hocLuc);
    }
}

int main() {
    FILE *file;
    char fileName[100];
    SinhVien dsSinhVien[100];
    int soSV;
    
    printf("Nhap ten tep: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Loi khi mo tep dau vao.\n");
        return 1;
    }

    soSV = docDanhSachSinhVien(file, dsSinhVien);
    fclose(file);
    
    printf("Danh sach sinh vien:\n");
    xuatDanhSachSinhVien(dsSinhVien, soSV);
    
    char ten[100];
    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]%*c", ten);
    timSinhVienTheoTen(dsSinhVien, soSV, ten);

    int countA = demSinhVienHocLucA(dsSinhVien, soSV);
    printf("So sinh vien dat hoc luc A: %d\n", countA);
    
    char hocLuc;
    printf("Nhap hoc luc can tim: ");
    scanf(" %c", &hocLuc);
    inSinhVienTheoHocLuc(dsSinhVien, soSV, hocLuc);
    
}
