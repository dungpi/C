#include <stdio.h>
#include <stdlib.h>

struct Sach{
    char masach [30];
    char ten[30];
    char theloai[50];
    char tentacgia[30];    
    int namxuatban;
    int soluong;
    int gia;
};
struct Nguoimuon{
    char manguoimuon[30];
    Sach *sach;
};
void enter (Sach *sach);
void enter (Sach *sach, int &sotuasach);
void enter (Nguoimuon *nguoimuon);
void print (Sach *sach);
void print (Sach *sach, int sotuasach);

int main (){
    Sach *sach;
    int sotuasach;
    sach = (Sach *)malloc(sizeof(Sach));
    enter (sach,sotuasach);
    print (sach,sotuasach);
    return 0;
}
void enter (Sach *sach){
    fflush(stdin);
    printf ("Nhap Ma Sach: ");
    gets(sach->masach);
    printf ("Nhap Ten Sach: ");
    gets(sach->ten);
    printf ("Nhap The Loai Sach: ");
    gets(sach->theloai);
    printf ("Nhap Ten Tac Gia: ");
    gets(sach->tentacgia);
    printf ("Nhap Nam Xuat Ban: ");
    scanf("%d",&sach->namxuatban);
    printf ("Nhap So Luong Sach: ");
    scanf("%d",&sach->soluong);
    printf ("Nhap Gia Sach: ");
    scanf("%d",&sach->gia);
}
void enter (Sach *sach, int &sotuasach){
    printf ("Nhap So Luong Sach Trong Thu Vien: ");
    scanf("%d",&sotuasach);
    sach = (Sach*)realloc(sach,(sotuasach)*sizeof(Sach));
    for (int i = 0; i < sotuasach ; i++){
        printf ("\n\n--------------------------------");
        printf ("\nNhap thong tin Sach %d\n",i+1);
        enter(&*(sach+i));
    }
}void enter (Nguoimuon *nguoimuon){
    printf ("Nhap Ma Nguoi Muon: ");
    gets(nguoimuon->manguoimuon);
}
void print (Sach *sach){
    printf ("Ma sach: %-10s||Ten Sach: %-20s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %-4d||So Luong: %-4d||Gia: %-6d",sach->masach,sach->ten,sach->theloai,sach->tentacgia,sach->namxuatban,sach->soluong,sach->gia);
}
void print (Sach *sach, int sotuasach){
    printf ("\n=====================================================================LIST=========================================================================");
    for (int i = 0; i < sotuasach ; i++){
        printf ("\n\n--------------------------------------------------------------------------------------------------------------------------------------------------");
        printf ("\n\t\t\t\t\t\t\t\tThong tin Sach %d \n\n",i+1);
        print(sach+i);
    }
}