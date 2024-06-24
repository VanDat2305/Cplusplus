#include<stdio.h>
#include<string.h>


typedef struct {
	char MNV[50];
	char HT[100];
	float LUONG;
	char PHONG[100];
} NhanVien;

typedef struct {
	char PHONG[100];
	float totalSalary;
	int employeeCount;
} PhongBan;

// 1. Doc file
int readDataFormFile(const char *fileName, NhanVien dsNhanVien[], int *countDataFile){
	FILE *file = fopen(fileName, "r");
	if(file == NULL) {
		printf("Khong the mo file : %s", fileName);
		return 0;
	}
	
	if (fscanf(file, "%d", countDataFile) != 1){
		printf("%d", countDataFile);
		printf("Loi doc so luong du lieu");
		fclose(file);
		return 0;
	}
	// cách 1 moi thong tin 1 dong
	// for(int i = 1; i < (*countDataFile+1); i++){

	// 	fscanf(file, " %[^\n]%*c", dsNhanVien[i].MNV);
	// 	fscanf(file," %[^\n]%*c", dsNhanVien[i].HT);
	// 	fscanf(file, "%f%*c", &dsNhanVien[i].LUONG);
	// 	fscanf(file," %[^\n]%*c", dsNhanVien[i].PHONG);

	// 	printf("%-10s %-20s %-10.0f %-10s \n", dsNhanVien[i].MNV, dsNhanVien[i].HT, dsNhanVien[i].LUONG, dsNhanVien[i].PHONG);
	// }
	//  cách 2 1 dong la thong tin cua 1 nhan vien gom 4 thong tin
    for (int i = 0; i < (*countDataFile); i++) {
        if (fscanf(file, "%s %s %f %s", dsNhanVien[i].MNV, dsNhanVien[i].HT, &dsNhanVien[i].LUONG, dsNhanVien[i].PHONG) != 4) {
            printf("Loi khi doc thong tin nhan vien thu %d.\n", i + 1);
            fclose(file);
            return 0;
        }
		// printf("%-10s %-20s %-10.0f %-10s \n", dsNhanVien[i].MNV, dsNhanVien[i].HT, dsNhanVien[i].LUONG, dsNhanVien[i].PHONG);
    }
	fclose(file);
    return 1;
}

// 2. Tinh luong trung binh cua tung phong va cho viet phong nao có luong trung binh thap nhat
char* phongBanLuongTrungBinhThapNhat(NhanVien dsNhanVien[], int countDataFile, char* textPhongBan){
	PhongBan PhongBan[100];
	int numPhong;
	for (int i = 0; i < countDataFile; i++) {
		int found = 0;
		for(int j = 0; j < numPhong; j++) {
			if(strcmp(dsNhanVien[i].PHONG, PhongBan[j].PHONG) == 0){
				PhongBan[j].totalSalary += dsNhanVien[i].LUONG;
				PhongBan[j].employeeCount++;
				found = 1;
				break;
			}
		}
		if (!found){
			strcpy(PhongBan[numPhong].PHONG, dsNhanVien[i].PHONG);
			PhongBan[numPhong].totalSalary = dsNhanVien[i].LUONG;
			PhongBan[numPhong].employeeCount = 1;
			numPhong++;
		}
	}
    for (int i = 0; i < numPhong; i++) {
        float avgSalary = PhongBan[i].totalSalary / PhongBan[i].employeeCount;
        printf("Phong %s: %.2f\n", PhongBan[i].PHONG, avgSalary);
    }
	float minAvgSalary = PhongBan[0].totalSalary / PhongBan[0].employeeCount;
	int minIndex = 0;
	for (int i = 1; i < numPhong; i++) {
		float avgSalary = PhongBan[i].totalSalary / PhongBan[i].employeeCount;
		if (avgSalary < minAvgSalary) {
			minAvgSalary = avgSalary;
			minIndex = i;
		}
	}
	strcpy(textPhongBan, PhongBan[minIndex].PHONG);

}

// 3. In danh sach nhan vien co luong giam dan
void sapXepDanhSachNhanVienGiamDanTheoLuong(NhanVien dsNhanVien[], int countDataFile){
	int i,j;
	NhanVien temp; 

	for (i = 0; i < countDataFile - 1; i++) {
        for (j = 0; j < countDataFile - i - 1; j++) {
            if (dsNhanVien[j].LUONG < dsNhanVien[j + 1].LUONG) {
                temp = dsNhanVien[j];
                dsNhanVien[j] = dsNhanVien[j + 1];
                dsNhanVien[j + 1] = temp;
            }
        }
    }
}
// 4. luu kq vao tep txt
int writeDataToFile(const char *fileName, NhanVien dsNhanVien[], int *countDataFile , char* textPhongBan){

	FILE *file = fopen(fileName, "w");
	if(file == NULL) {
		printf("Khong the mo file : %s", fileName);
		return 0;
	}
	fprintf(file, "Phong ban co luong trung binh thap nhat : %s \n", textPhongBan);
	// in danh sach nhan vien 
	fprintf(file, "%-15s %-20s %-10s %-10s \n", "Ma nhan vien", "Ho ten", "Luong", "Phong ban");
	for (int i = 0; i< *countDataFile; i++){
		fprintf(file, "%-15s %-20s %-10.0f %-10s \n", dsNhanVien[i].MNV, dsNhanVien[i].HT, dsNhanVien[i].LUONG, dsNhanVien[i].PHONG);
	}

	return 1;
}

int main(){

	const char *fileName = "input_021.txt";
	char textPhongBan[100];
	// char fileName[100];
	// printf("Nhap ten file: \n");
	// scanf("%s", fileName);

	// printf("ten file nhap vao : %s \n", fileName);

	int countDataFile = 0;
	NhanVien dsNhanVien[100];
	if(!readDataFormFile(fileName, dsNhanVien, &countDataFile)){
		return 1;
	};

	phongBanLuongTrungBinhThapNhat(dsNhanVien, countDataFile, textPhongBan);
	printf("%s", textPhongBan);
	sapXepDanhSachNhanVienGiamDanTheoLuong(dsNhanVien, countDataFile);
	if(!writeDataToFile("kq.txt", dsNhanVien, &countDataFile, textPhongBan)){
		return 1;
	}

	return 1;
}
