#include<stdio.h>
#include"stdlib.h"
#include"string.h"
typedef struct NhanVien{
	char ma[10],ht[30],phong[10];
	float hsl;
	double luong;
};
void nhap(char tentep[],int &n,NhanVien *&ds)
{
	FILE *f;
	f=fopen(tentep,"r");
	if(f==NULL) puts("loi doc tep");
	else
	{	int i;
		fscanf(f,"%d\n",&n);
		ds=(NhanVien*) malloc(sizeof(NhanVien)*n);
		for(i=0;i<n;i++)
		{
			fgets(ds[i].ma,10,f);
			ds[i].ma[strlen(ds[i].ma)-1]='\0';
			fgets(ds[i].ht,30,f);
			ds[i].ht[strlen(ds[i].ht)-1]='\0';
			fgets(ds[i].phong,10,f);
			ds[i].phong[strlen(ds[i].phong)-1]='\0';
			fscanf(f,"%f\n",&ds[i].hsl);
		}
	}fclose(f);
}
void tinhtuong(double lcb,NhanVien &a)
{
	a.luong= a.hsl*lcb;
}
void sapxep(int n,NhanVien *ds)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(ds[i].luong<ds[j].luong)
			{
				NhanVien t=ds[i];
				ds[i]=ds[j];
				ds[j]=t;
			}
}
void inds(int n,NhanVien *ds)
{
	for(int i=0;i<n;i++)
		printf("%s\t%s\t%s\t%5.2f\t %10.0lf\n",
		ds[i].ma,ds[i].ht,ds[i].phong,ds[i].hsl,ds[i].luong);
}
void cau1(int n,NhanVien*ds)
{
	double lcb;
	printf("nhap luong co ban ");
	scanf("%lf", &lcb);
	for(int j=0;j<n;j++) tinhtuong(lcb,ds[j]);
	sapxep(n,ds);
	inds(n,ds);
}
void LuongTBPhong(int n,NhanVien*ds)
{
	double s[4];
	int d[4];
	puts("TBC cua lan luot cac phong HCTH,TCKT,KT,Baove la ");
	for(int i=0;i<4;i++)
	{	s[i]=0;d[i]=0;
		for(int j=0;j<n;j++)
		{
			if(strcmpi(ds[j].phong,"HCTH")==0){
				s[0]+=ds[j].luong;d[0]++;
			}
			if(strcmpi(ds[j].phong,"TCKT")==0){
				s[1]+=ds[j].luong;d[1]++;
			}
			if(strcmpi(ds[j].phong,"KT")==0){
				s[2]+=ds[j].luong;d[2]++;
			}
			if(strcmpi(ds[j].phong,"BAOVE")==0){
				s[3]+=ds[j].luong;d[3]++;
			}	
		}
		if(d[i])printf("%10.0lf  ",s[i]/d[i]);
		else printf("\tK co nv o phong nay ");
	}
}
void intep(char tentep[],int n,NhanVien *ds)
{
	FILE *f=fopen(tentep,"w");
	cau1(n,ds);
	for(int i=0;i<n;i++)
		fprintf(f,"%s\t%s\t%s\t%5.2f\t %10.0lf\n",
		ds[i].ma,ds[i].ht,ds[i].phong,ds[i].hsl,ds[i].luong);
	fclose(f);
}
int main()
{
	int n;
	NhanVien *ds;
	nhap("bai.txt",n,ds);puts("\n");

	intep("outbai2.txt",n,ds);	puts("\n");
	LuongTBPhong(n,ds);
}
