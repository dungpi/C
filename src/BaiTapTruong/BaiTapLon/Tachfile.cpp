#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct Sach{
    char masach [8];
    char ten[30];
    char theloai[50];
    char tentacgia[30];    
    int namxuatban;
    int soluong;
    int gia;
};
void enter (Sach *sach);
void print (Sach *sach);
void enter (Sach *&sach, int &sotuasach);
void print (Sach *sach, int sotuasach);
void findbyid (Sach *sach, int sotuasach);
void findbyname (Sach *sach, int sotuasach,char name[30]);

int main () {
    Sach *sach;
    int sotuasach;
    enter (sach,sotuasach);
    print (sach,sotuasach);
    findbyname (sach,sotuasach,"2");
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
void print (Sach *sach){
    printf ("\nMa sach: %-10s||Ten Sach: %-20s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %.4d||So Luong: %-3d||Gia: %-6d",sach->masach,sach->ten,sach->theloai,sach->tentacgia,sach->namxuatban,sach->soluong,sach->gia);
}
void enter (Sach *&sach, int &sotuasach){
    do {
    printf ("Nhap So Luong Sach Trong Thu Vien: ");
    scanf("%d",&sotuasach);
        if (sotuasach <= 0||sotuasach > MAX){
            printf ("Xin vui long nhap lai!!!");
            printf ("\nNhap So Luong Sach Trong Thu Vien: ");
            scanf("%d",&sotuasach);
        }
    }while (sotuasach <= 0||sotuasach > MAX);
    sach = (Sach*)malloc(sotuasach*sizeof(Sach));
    for (int i = 0; i < sotuasach ; i++){
        printf ("\n\n--------------------------------");
        printf ("\nNhap thong tin Sach %d\n",i+1);
        enter(&*(sach+i));
    }
}
void print (Sach *sach, int sotuasach){
    printf ("\n=======================================================================LIST=========================================================================");
    for (int i = 0; i < sotuasach ; i++){
        printf ("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
        print(sach+i);
    }
}
void findbyname (Sach *sach, int sotuasach,char name[30]){
    int count = 0;
    fflush(stdin);
    
    for (int i = 0; i < sotuasach ; i++){
        if (strcmp (name,(sach+i)->ten) == 0){
            printf ("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
            printf ("\nMa sach: %-10s||Ten Sach: %-20s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %.4d||So Luong: %-3d||Gia: %-6d",(sach+i)->masach,(sach+i)->ten,(sach+i)->theloai,(sach+i)->tentacgia,(sach+i)->namxuatban,(sach+i)->soluong,(sach+i)->gia);
            printf ("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
            count ++;
        }
    }
    if(count == 0){
        printf("\nKhong co sach do trong kho!");
    }
}
void findbyid (Sach *sach, int sotuasach){
    char ma[8];
    fflush(stdin);
    // printf ()
}