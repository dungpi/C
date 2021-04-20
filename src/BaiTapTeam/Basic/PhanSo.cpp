#include<stdio.h>
#include<stdlib.h>
struct PHANSO{
	int TS;
	int MS;
};
void NhapPS (PHANSO *&x);
void XuatPS (PHANSO *x);
void rutgon(PHANSO *&x);
float TongPS(PHANSO *x1, PHANSO *x2);
float HieuPS(PHANSO *x1, PHANSO *x2);
float TichPS(PHANSO *x1, PHANSO *x2);
float ThuongPS(PHANSO *x1, PHANSO *x2);
int main() { 
	PHANSO *ps1, *ps2;
	ps1 = (PHANSO *)malloc(sizeof(PHANSO));
	ps2 = (PHANSO *)malloc(sizeof(PHANSO));
	printf("Nhap Phan So 1 ");
	NhapPS(ps1);
	printf("Nhap Phan So 2 ");
	NhapPS(ps2);
	printf("Phan so 1 la: "); XuatPS(ps1);
	printf("\nPhan so 2 la: "); XuatPS(ps2);
	rutgon (ps1);
	rutgon (ps2);
	printf ("\n\nPhan so sau rut gon ");
	printf("\nPhan so 1 la: "); XuatPS(ps1);
	printf("\nPhan so 2 la: "); XuatPS(ps2);
	printf("\n\nTong 2 phan so la: %.2f",TongPS(ps1, ps2));
	printf("\nHieu 2 phan so la: %.2f",HieuPS(ps1, ps2));
	printf("\nTich 2 phan so la: %.2f",TichPS(ps1, ps2));
	printf("\nThuong 2 phan so la: %.2f",ThuongPS(ps1, ps2));
	return 0;
} 
void NhapPS (PHANSO *&x){
	printf ("\nNhap Tu So: ");
	scanf("%d", &x->TS);
	do{
		printf ("Nhap Mau So: ");
		scanf("%d", &x->MS);
		if(x->MS==0)
			printf ("Nhap sai, yeu cau nhap lai mau so: ");
	}while(x->MS==0);
}
void XuatPS (PHANSO *x){
	printf ("%d/%d ",x->TS,x->MS);
}
float TongPS(PHANSO *x1, PHANSO *x2){
	int Tu, Mau;
	Tu = x1->TS*x2->MS + x1->MS*x2->TS;
	Mau = x1->MS*x2->MS;
	return (float)Tu/Mau;
}
float HieuPS(PHANSO *x1, PHANSO *x2){
	int Tu, Mau;
	Tu = x1->TS*x2->MS - x1->MS*x2->TS;
	Mau = x1->MS*x2->MS;
	return (float)Tu/Mau;
}
float TichPS(PHANSO *x1, PHANSO *x2){
	int Tu, Mau;
	Tu = x1->TS * x2->TS;
	Mau = x1->MS * x2->MS;
	return (float)Tu/Mau;
}
float ThuongPS(PHANSO *x1, PHANSO *x2){
	int Tu, Mau;
	Tu = x1->TS * x2->MS;
	Mau = x1->MS * x2->TS;
	return (float)Tu/Mau;
}
void rutgon(PHANSO *&x){
	int a= x->TS,b=x->MS;
	if(a==0) return;
	while(a!=b)
	if(a>b) a-=b;
	else b-=a;
	x->TS/=a;
	x->MS/=a;
}
