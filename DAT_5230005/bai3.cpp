#include <stdio.h>
#include <string.h>

typedef struct {
    char hoTen[100];
    int diem;
    char tenTruong[100];
} SinhVien;


//C�u 2 (5 di?m). Danh s�ch th� sinh tham gia Olympic sinh vi�n du?c luu trong t?p van b?n input.txt,
// trong d� d�ng d?u l� s? thi sinh, tr�n m?i ba d�ng ti?p theo l� th�ng tin c?a m?t th� sinh, g?m: H? t�n, S? di?m, T�n tru?ng
//(Gi? s? ch? c� b?n tru?ng tham gia thi l� A, B, C, D). H�y vi?t c�c h�m:
//1. �?c d? li?u t? t?p tr�n.
//2.Cho bi?t c�c tru?ng n�o c� t?ng s? di?m cao nh?t.
//3.T�m c�c th� sinh d?t di?m cao nh?t.
//Vi?t h�m main() s? d?ng c�c h�m d� x�y d?ng v� ho�n thi?n chuong tr�nh.


// Danh sach thi sinh tham gia Olymic sinh vien duoc luu trong tep van ban input.txt
// trong do dong dau la so thi sinh tren moi ba dong tiep theo la thong tin cua mot thi sinh gom ho te so diem ten truong
// gia su chi co 4 truong tham gia thi la A B C D. Hay viet cac ham 
// 1 doc du lieu tu tep tren 
int readDataFormFile(const char *fileName, SinhVien danhSach[], int *countDataFile){
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Khong the mo tep %s.\n", fileName);
		return 0;
	}
	
	if (fscanf(file, "%d", countDataFile) != 1) {
        printf("Loi khi doc so luong thi sinh.\n");
        fclose(file);
        return 0;
    }

//  3 dong tiep theo la thong tin cua 1 thi sinh
//	for (int i = 0; i < *countDataFile; i++) {
//	    fscanf(file, %[^\n]%*c, danhSach[i].hoTen);
//	    fscanf(file, "%d", &danhSach[i].diem);
//	    fscanf(file, %[^\n]%*c, danhSach[i].tenTruong);
//	    
//	    printf("%-30s %-10d %-20s\n", danhSach[i].hoTen, danhSach[i].diem, danhSach[i].tenTruong);
//    }
//  1 dong la thong itn cua 1 thu sinh gom 3 thong tin
    for (int i = 0; i < *countDataFile; i++) {
        if (fscanf(file, "%s %d %s", danhSach[i].hoTen, &danhSach[i].diem, danhSach[i].tenTruong) != 3) {
            printf("Loi khi doc thong tin sinh vien thu %d.\n", i + 1);
            fclose(file);
            return 0;
        }
    }
	fclose(file);
    return 1;
}

// 2 Cho biet truong nao co tong so diem cao nhat
void schoolTopScore(SinhVien danhSach[], int countDataFile){
    float diemCaoNhat = 0;
    char truongDiemCaoNhat[5][50];
    int soTruongDiemCaoNhat = 0;


}

// 3 tim cac thi sinh dat diem cao nhat

// 4 viet ham xuat thong tin thi sinh 
// Ham xuat du lieu sinh vien ra file output
int writeDataToFile(const char *fileName, SinhVien danhSach[], int countDataFile) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Khong the mo tep %s de ghi du lieu.\n", fileName);
        return 0;
    }

    // Xuat tieu de cac cot
    fprintf(file, "%-30s %-10s %-20s\n", "Ho ten", "Diem", "Ten truong");

    // Xuat thong tin cua tung sinh vien
    for (int i = 0; i < countDataFile; i++) {
        fprintf(file, "%-30s %-10d %-20s\n", danhSach[i].hoTen, danhSach[i].diem, danhSach[i].tenTruong);
    }

    fclose(file);
    return 1;
}

// viet ham main() su dung cac ham da xay dung va hoan thien chuong trinh

int main() {
//	FILE *file; // khai bao mot con tro co ten la file
	const char* fileName = "inputbai3.txt";
	int countDataFile  = 0;
	// khai bao cau truc du lieu
	
	SinhVien dsSinhVien[100];
	;
	if (!readDataFormFile(fileName, dsSinhVien, &countDataFile)) {
        return 1;
    }
    
    // goi ham de xuat du lieu ra
    if (!writeDataToFile("output3.txt", dsSinhVien, countDataFile)) {
        return 1;
    }
	
}
