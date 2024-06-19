#include <stdio.h>
#include <string.h>

typedef struct {
    char hoTen[100];
    int diem;
    char tenTruong[100];
} SinhVien;


//Câu 2 (5 di?m). Danh sách thí sinh tham gia Olympic sinh viên du?c luu trong t?p van b?n input.txt,
// trong dó dòng d?u là s? thi sinh, trên m?i ba dòng ti?p theo là thông tin c?a m?t thí sinh, g?m: H? tên, S? di?m, Tên tru?ng
//(Gi? s? ch? có b?n tru?ng tham gia thi là A, B, C, D). Hãy vi?t các hàm:
//1. Ð?c d? li?u t? t?p trên.
//2.Cho bi?t các tru?ng nào có t?ng s? di?m cao nh?t.
//3.Tìm các thí sinh d?t di?m cao nh?t.
//Vi?t hàm main() s? d?ng các hàm dã xây d?ng và hoàn thi?n chuong trình.


// Danh sách thi sinh tham gia Olymic sinh vien duoc luu trong tep van ban input.txt
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
//	    fscanf(file, "%s", danhSach[i].hoTen);
//	    fscanf(file, "%d", &danhSach[i].diem);
//	    fscanf(file, "%s", danhSach[i].tenTruong);
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
//    printf("%-30s %-10s %-20s\n", "Ho ten", "Diem", "Ten truong");
//    for (int i = 0; i < *countDataFile; i++) {
//        printf("%-30s %-10d %-20s\n", danhSach[i].hoTen, danhSach[i].diem, danhSach[i].tenTruong);
//    }

	
	fclose(file);
    return 1;
	
}

// 2 Cho vie truong nao có tong so diem cao nhat
// 3 tim cac thi sinh dat diem cao nhat

// 4 viet ham xuat thong tin thi sinh 
// Hàm xu?t d? li?u sinh viên ra file output
int writeDataToFile(const char *fileName, SinhVien danhSach[], int countDataFile) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Khong the mo tep %s de ghi du lieu.\n", fileName);
        return 0;
    }

    // Xu?t tiêu d? các c?t
    fprintf(file, "%-30s %-10s %-20s\n", "Ho ten", "Diem", "Ten truong");

    // Xu?t thông tin c?a t?ng sinh viên
    for (int i = 0; i < countDataFile; i++) {
        fprintf(file, "%-30s %-10d %-20s\n", danhSach[i].hoTen, danhSach[i].diem, danhSach[i].tenTruong);
    }

    fclose(file);
    return 1;
}

// viet ham main() su dung cac ham da xay dung va hoan thien chuong trinh

int main() {
//	FILE *file; // khai bao mot con tro có ten la file
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
