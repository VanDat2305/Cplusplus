// xay dung ham thuc hien cac cong viec sau:
// - nhap vao mot day so nguyen co n phan tu
// - In day so ra man hinh
// - Dem cac phan tu co gia tri lon hon x coi x nhap tu ban phim
// - Tinh tong cac phan tu co gia tri am trong day 
// - Kiem tra xem day co phai la day tang dan hay khong

#include<iostream>
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

// - Dem cac phan tu co gia tri lon hon x coi x nhap tu ban phim
int dem(int x, int n, int a[])
{
	int d=0;
	for (int i = 0; i<n; i++){
		if(a[i]>x)d++;
	}
	return d;
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

////ham tinh tong gia tri am trong mang
//int sum_array_elements( int array[], int n ) {
//   if (n < 0) {
//     return 0;
//   	} else{
//   		if(array[n]<0){
//   			return array[n] + sum_array_elements(array, n-1);
//		}else {
//			return sum_array_elements(array, n-1);
//		}
//     
//	}
//}
////Kiem tra xem day co phai la day tang dan hay khong
//
//bool isIncrease(int array[], int n) {
//	int i;
//
//   for (i = 1; i < (n-1); i++)
//  
//      if (array[i] >= array[i+1]){
//      	return false;
//	  }
//         
//   return true;
//}


int main()
{
	int array[100], n, x;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    cout << "Nhap phan tu:\n";
   	input_array(array, n);
   	show_array(array, n);
   	
   	cout << "gia tri lon nhat trong mang:"<< largest(array, n)<< endl;
   	
//   	cout << "tong gia tri am:"<< sum_array_elements(array, n)<<endl;
//   	
//   	if(isIncrease(array, n)) {
//   		cout << "chuoi tang dan\n";
//	   } else {
//	   	cout << "chuoi khong tang dan\n";
//	   }
//   	
//   	cout << "Nhap so nguyen duong x: ";
//    cin >> x;
//    int d = dem(x, n, array);
//    cout <<"\n so ptu lon hon x la:" <<d;
//   	
   	
}
