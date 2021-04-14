// - nhập xuất 1 struct Sinh viên: mã, tên, năm sinh, điểm toán, lý, hóa (done)
// - nhập 1 danh sách n sinh viên (done)
// - kiểm tra sinh viên có mã được nhập vào từ bàn phím
// - đếm số lượng sinh viên có tên "Nam" trong danh sách
// - đếm số lượng sinh viên có điểm trung bình >8
// - liệt kê danh sách sinh viên có điểm trung bình >8
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct Diem{
    float toan;
    float ly;
    float hoa;
};
struct SinhVien {
    char ten[30];
    char ma[8];
    int namsinh;
    Diem *diem;
};
void enter (Diem *diem);
void print (Diem *diem);
void enter (SinhVien *sinhvien);
void print (SinhVien *sinhvien);
void enter (SinhVien *sinhvien, int &sosinhvien);
void print (SinhVien *sinhvien, int sosinhvien);
int main (){
    SinhVien *sinhvien;
    Diem *diem;
    int sosinhvien;
    sinhvien = (SinhVien*)malloc(sizeof(SinhVien));
    diem = (Diem*)malloc(sizeof(Diem));
    enter (sinhvien,sosinhvien);
    print (sinhvien,sosinhvien);
    if(sinhvien != NULL)
    free (sinhvien);
    return 0;
}
void enter (Diem *diem){
    do{
    do {
    printf ("Nhap Diem Toan: ");
    scanf ("%f",&diem->toan);
        if (diem->toan < 0||diem->toan > 10){
            printf ("Nhap Lai Diem Toan: ");
            scanf ("%f",&diem->toan);
        }
    }while(diem->toan < 0 || diem->toan > 10);
    do {
    printf ("Nhap Diem Ly: ");
    scanf ("%f",&diem->ly);
        if (diem->ly < 0||diem->ly > 10){
            printf ("Nhap Lai Diem Ly: ");
            scanf ("%f",&diem->ly);
        }
    }while(diem->ly < 0 || diem->ly > 10);
    do{
    printf ("Nhap Diem Hoa: ");
    scanf ("%f",&diem->hoa);
        if (diem->hoa < 0||diem->hoa > 10){
            printf ("Nhap Lai Diem Hoa: ");
            scanf ("%f",&diem->hoa);
        }
    }while(diem->hoa < 0 || diem->hoa > 10);
    }while(diem->toan < 0 || diem->toan > 10 & diem->ly < 0 || diem->ly > 10 & diem->hoa < 0 || diem->hoa > 10);
}
void enter (SinhVien *sinhvien){
    fflush(stdin);
    printf ("\nNhap Ma Sinh Vien: ");
    gets (sinhvien->ma);
    printf ("Nhap Ten Sinh vien: ");
    gets (sinhvien->ten);
    sinhvien->diem = (Diem*)malloc(sizeof(Diem));
    enter (sinhvien->diem);
}
void enter (SinhVien *sinhvien, int &sosinhvien){
    do{
    printf ("\nNhap So Sinh Vien: ");
    scanf ("%d",&sosinhvien);
        if (sosinhvien <= 0||sosinhvien > MAX){
            printf ("Nhap Lai So Sinh Vien: ");
            scanf ("%d",&sosinhvien);
        }
    }while (sosinhvien <= 0||sosinhvien > MAX);
    sinhvien = (SinhVien*)realloc(sinhvien,(sosinhvien)*sizeof(SinhVien));
    printf ("============================ENTER============================");
    for(int i = 0 ; i < sosinhvien ; i++){
        printf ("\n\t\tNhap Thong Tin Sinh Vien %d ",i+1);
        enter (sinhvien+i);
    }
}
void print (Diem *diem){
    printf ("||Toan: %.2f ||Ly: %.2f ||Hoa: %.2f",diem->toan,diem->ly,diem->hoa);
}
void print (SinhVien *sinhvien){
    printf ("\nMSSV: %-8s||Ten: %-25s",sinhvien->ma,sinhvien->ten);
    print (sinhvien->diem);
}
void print (SinhVien *sinhvien, int sosinhvien){
    printf ("\n=======================================List=========================================");
    for (int i = 0; i < sosinhvien; i ++){
        print (sinhvien+i);
        printf ("\n-----------------------------------------------------------------------------------");
    }
}