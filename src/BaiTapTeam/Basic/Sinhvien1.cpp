// - nhập xuất 1 struct Sinh viên: mã, tên, năm sinh, điểm toán, lý, hóa (done)
// - nhập 1 danh sách n sinh viên (done)
// - kiểm tra sinh viên có mã được nhập vào từ bàn phím(done)
// - đếm số lượng sinh viên có tên "Nam" trong danh sách(done)
// - đếm số lượng sinh viên có điểm trung bình >8 (done)
// - liệt kê danh sách sinh viên có điểm trung bình >8 (done)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void findbyid (SinhVien *sinhvien, int sosinhvien);
void amount(SinhVien *sinhvien, int sosinhvien);
float dtb (float a, float b,float c);
void count(SinhVien *sinhvien, int sosinhvien);
int main (){
    SinhVien *sinhvien;
    int sosinhvien;
    sinhvien = (SinhVien*)malloc(sizeof(SinhVien));
    enter (sinhvien,sosinhvien);
    count (sinhvien,sosinhvien);
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
    printf ("\n======================================List=========================================");
    for (int i = 0; i < sosinhvien; i ++){
        print (sinhvien+i);
        printf ("\n-----------------------------------------------------------------------------------");
    }
}
void findbyid (SinhVien *sinhvien, int sosinhvien){
    char id[8];
    int count = 0;
    fflush(stdin);
    printf ("Nhap Ma Can Tim: ");
    gets (id);
    for(int i = 0; i < sosinhvien ; i++){
        if (strcmp(id,(sinhvien+i)->ma) == 0){
            print (sinhvien+i);
            count ++;
        }
    }
    if (count == 0){
        printf ("\nMa Khong Co Trong Danh Sach!!!");
    }
}
void amount(SinhVien *sinhvien, int sosinhvien){
    int count = 0;
    for(int i = 0; i < sosinhvien ; i++){
        if (strcmp("Nam",(sinhvien+i)->ten) == 0){
            count ++;
        }
    }
    if (count == 0){
        printf ("\nKhong Co Sinh Vien Ten Nam Trong Danh Sach!");
    }
    else {
        printf ("\nCo %d Sinh Vien Ten Nam Trong Danh",count);
    }
}
float dtb (float a,float b,float c){
    float dTB = 0;
        dTB = (a+b+c)/3;
    return dTB;
}
void count(SinhVien *sinhvien, int sosinhvien){
    int count = 0;
    for(int i = 0; i < sosinhvien; i++){
        if (dtb((sinhvien+i)->diem->toan,(sinhvien+i)->diem->ly,(sinhvien+i)->diem->hoa) > 8){
            count ++;
            print (sinhvien+i);
            printf ("\n-----------------------------------------------------------------------------------");

        }
    }
    if (count == 0){
        printf ("\nKhong Co Sinh Vien Co Diem Tren 8");
    }
    else {
        printf ("\nVay Co %d Sinh Vien Co Diem Tren 8",count);
    }
}