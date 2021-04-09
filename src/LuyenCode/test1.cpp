#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 1 nhap xuat trai cay
 2. Tim kiem trai cay
*/
struct TraiCay{
    char Ten[30];
    char MaHang[20];
    int SoLuong;
    int Gia;
};
void Nhap(TraiCay *traicay);
void Xuat (TraiCay *traicay);
void Nhap(TraiCay *traicay,int &n);
void Xuat(TraiCay *traicay,int n);
void TimKiemMa(TraiCay *traicay,int n);
int main(){
    int n;
    TraiCay *traicay;
    traicay = (TraiCay*)malloc((sizeof(TraiCay)));
    Nhap(traicay,n);
    TimKiemMa(traicay,n);
    return 0 ;
}
void Nhap(TraiCay *traicay){
    fflush(stdin);
    printf("nhap Ten Trai Cay: ");
    gets(traicay->Ten);
    printf("nhap Ma Hang: ");
    gets(traicay->MaHang);
    fflush(stdin);
    printf("Nhap so luong: ");
    scanf("%d",&traicay->SoLuong);
    printf("Nhap gia: ");
    scanf("%d",&traicay->Gia);
}
void Xuat (TraiCay *traicay){
    printf("Ten trai cay: %s\n",traicay->Ten);
    printf("Ma hang: %s\n",traicay->MaHang);
    printf("So Luong: %d\n",traicay->SoLuong);
    printf("Gia: %d\n",traicay->Gia);
}
void Nhap(TraiCay *traicay,int &n){
    printf("nhap Gio trai cay: ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        Nhap(traicay + i);
    }
}
void Xuat(TraiCay *traicay,int n){
    for(int i = 0 ; i < n ; i++){
        Xuat(traicay + i);
    }
}
void TimKiemMa(TraiCay *traicay,int n){
    char name[30];
    int count = 0;
    printf("Nhap Ma can tim kiem: ");
    fflush(stdin);
    gets(name);
    for(int i = 0 ; i < n; i++){
    if(strcmp(name,(traicay +i)->MaHang)==0){
        Xuat(traicay+i);
        count ++;
        }
    }
}