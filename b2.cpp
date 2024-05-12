#include <iostream>
using namespace std;
// ham nhap phan tu trong ma
void input_array(int array[], int length){
    for (short i = 0; i < length; i++) cin >> array[i];
}
// ham in phan tu trong mang
void show_array(int array[], int length){
    for(short i = 0; i < length; i++)  cout << array[i] <<' ';   
    cout << endl;
}
//ham tinh tong trong mang
int sum_array_elements( int array[], int n ) {
   if (n < 0) {
     return 0;
   } else{
     return array[n] + sum_array_elements(array, n-1);
    }
}

// ham tim gia tri lon nhat 
int largest(int array[], int n)
{
   int i;
   
   int max = array[0];
   for (i = 1; i < n; i++)
      if (array[i] > max)
         max = array[i];
   return max;
}

int search(int array[], int n, int x)
{
   int i;
   int max = array[0];
   for (i = 1; i < n; i++)
      if (array[i] == x)
         return true;
   return false;
}

int main() {
	int array[100], count, n, x, a, b, i, j, pt;
	   cout << "Nhap so phan tu: ";
	   cin >>  n;
	
	cout << "Nhap phan tu:\n";
   	input_array(array, n);
   	
   	cout << "tong cac phan tu trong mang:"<< sum_array_elements(array, n) << endl;
   	
   	cout << "gia tri lon nhat trong mang:"<< largest(array, n)<< endl;
   	
   	cout << "Nhap x: ";
   	cin >>  x;
   	if (search(array, n, x)) {
   		cout << "x ton tai trong mang"<< endl;
	} else {
		cout << "x khong ton tai trong mang"<< endl;
	}
   	
   	
   	cout << "Nhap vao a:";
   	cin >> a;
   	cout << "Nhap vao b:";
   	cin >> b;
   	if (a>b) {
   		i = b;
   		j = a;
   		pt = b - a;
	} else {
		i = a;
   		j = b;
   		pt = b - a;
	}
	int sum = 0;
	float tb;
	
   	for (i; i < j; i++) {
   		sum = sum + i;
	}
	tb =  sum/pt;
	cout << "Trung binh a b " << tb << endl;
   	
	return 0;
}
