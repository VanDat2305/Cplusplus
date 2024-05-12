// Xác dinh ham co gia tri tra ve return
// các tham so dau vao cua ham 
// ten ham 
// thuc hien nhiem vu cua ham

#include<iostream>
using namespace std;
int tong(int a, int b){
	return a+b;
}
// viet ham kiem tra 1 so nguyen duong n co phai la so nguyen to hay khong
// xay dung ham main de kiem tra 

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
// 2. viet ham so sanh 2 so nguyen a va b

int soSanh(int a, int b)
{
	return a - b;
}
// 3. viet ham tinh trung binh cong cac so le nho hon n voi n nhap tu ban phim 
float trungBinh(int n)
{
	for (int i = 1, i < n, i++)
	{
		if 
	}
}

int main()
{
//	int a = 4, b = 7;
//	int s = tong (a, 7);
//	cout << "\n tông la: "<<s;
	int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    bool flag = is_prime(n);
    if (flag) {
        cout << n << " la so nguyen to." << endl;
    } else {
        cout << n << " khong la so nguyen to." << endl;
    }
    return 0;
}








