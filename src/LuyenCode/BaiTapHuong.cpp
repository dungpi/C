#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Diem{
    float toan; 
    float ly; 
    float hoa;
    float dtb; 
};
struct Sinhvien{
    char ten[30];
    int tuoi;
    char gioitinh[10];
    Diem *diem; 
};
void nhapdiem(Diem *diem);
void xuatdiem(Diem *diem);
void nhapsv(Sinhvien *sinhvien);
void xuatsv(Sinhvien *sinhvien);
void nhapds(Sinhvien *sinhvien, int &sosinhvien);
void xuatds(Sinhvien *sinhvien, int sosinhvien);
int main(){ 
    Sinhvien *sinhvien;
    Diem *diem;
    int sosinhvien;
    sinhvien = (Sinhvien*)malloc(sizeof(Sinhvien));
    diem = (Diem*)malloc(sizeof(Diem));
    nhapds(sinhvien,sosinhvien);
    xuatds(sinhvien,sosinhvien);
}
void nhapdiem(Diem *diem){ 
    printf("Nhap diem toan: ");
    scanf("%f",&diem->toan);
    printf("Nhap diem hoa: ");
    scanf("%f",&diem->hoa);
    printf("Nhap diem ly: ");
    scanf("%f",&diem->ly);
}
void xuatdiem(Diem *diem){
    printf("Toan: %.2f ||Ly: %.2f ||Hoa: %.2f", diem->toan,diem->ly,diem->hoa);
}
void nhapsv(Sinhvien *sinhvien){
    fflush(stdin);
    printf("Nhap ho va ten: ");
    gets(sinhvien->ten);
    printf("Nhap tuoi: ");
    scanf("%d",&sinhvien->tuoi);
    fflush(stdin);
    printf("Nhap gioi tinh: ");
    gets(sinhvien->gioitinh);
    sinhvien->diem = (Diem *)malloc(sizeof(Diem));
    nhapdiem(sinhvien->diem);
}
void xuatsv(Sinhvien *sinhvien){
    printf("Ho va ten:%s ||Tuoi:%d ||Gioi tinh: %s\n", sinhvien->ten,sinhvien->tuoi,sinhvien->gioitinh);
    xuatdiem(sinhvien->diem);
}
void nhapds(Sinhvien *sinhvien, int &sosinhvien){
    printf("Nhap so sinh vien: ");
    scanf("%d", &sosinhvien);
    for(int i=0;i<sosinhvien;i++){ 
        printf("\nSinh vien thu %d: \n",i+1);
        nhapsv(&*(sinhvien+i));
    } 
}
void xuatds(Sinhvien *sinhvien, int sosinhvien){
    printf("----------Thong tin da nhap--------\n");
    for(int i=0;i<sosinhvien;i++){
        printf("\n\nSinh vien thu %d: \n",i+1);
        xuatsv(sinhvien+i);
    }
}
