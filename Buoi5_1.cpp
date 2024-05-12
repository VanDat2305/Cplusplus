#include<stdio.h>
void nhap (int n , int a[],	FILE *f){
		for(int i=0;i<n;i++)
		fscanf(f, "%d", &a[i]);
	
} 
void xuat( int n, int a[]){
	for(int i=0;i<n;i++)
		printf("%d" , a[i]);
}

// dem cac phan tu am 
int demAm(int n, int a[]){
	int d = 0 ;
	for(int i=0;i<n;i++)
		if(a[i]<0)
		 d++;
	return d;
	
}



// tim gia tri lon nhat in ra tep output.txt
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
// dem va in ra tep output cac bo 3 so lien tiep lap thanh cac so cong
// ( khong xet thu tu) 4 6 8 => 4 8 6
//int hnt(int array[], int n, FILE *f) {
//	for (int i = 2; i < n; i++) {
//		float avg = (array[i] + array[i - 1] + array[i - 2])/3;
//		if (array[i] == avg || array[i - 1] == avg || array[i - 2] == avg){
//		
//			fprintf(f, "/n 3 so lien tiep thanh cap so cong la: %d %d %d", array[i] , array[i - 1] , array[i - 2]);
//		}
//	}
//}
void boBaSo(int n, int a[], FILE *f){
	int d = 0;
	for(int i=0; i<n-2; i++){
		int so1 = a[i];
		int so2 = a[i+1];
		int so3 = a[i+2];
		if(so1+so2 == 2*so3 || so1*so3==2*so2 || so2*so3==2*so1){
			fprintf(f, "\n%d %d %d", so1, so2, so3);
			d++;
		}
	}
	fprintf(f, "\nSo cac cap la: %d", d);
}

int main(){
	
	FILE *f, *fo;
	int n;
	int a[100];
	//mo file 
	f = fopen("input.txt", "rt");
	fo = fopen("output.txt", "wt");
	fscanf(f, "%d", &n);
	nhap(n , a, f);
	xuat (n, a);
//	hnt(a, n, fo);
	boBaSo(n, a, f);
	fprintf(fo, "\ncac phan tu am la: %d", demAm(n, a));
	fprintf(fo, "\nGia tri on nhat la: %d", largest(a, n));
	
}
