#include<stdio.h>
int main(){
	FILE *f;
	int n;
	int a[100];
	// mo file
	f = fopen('input.txt', "rt");
	fscanf(f, "%d", &n);
	for(int i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
		
}
