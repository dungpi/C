// Bài 2
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define Max 50
struct Sach {
    char ten[30];
    char tacgia[30];
    int namxuatban;
};
void enter (Sach *sach);
void enter (Sach *sach, int &n);
void print (Sach *sach);
void print (Sach *sach, int n);
int demTG (Sach *sach,int n);
void thongke (Sach *sach,int n);
void sortbyyear (Sach *sach, int n);
void menu (Sach *sach,int n);
int main (){
    Sach *sach;
    int n;
    sach = (Sach*)malloc(sizeof(Sach));
    enter (sach,n);
    menu (sach,n);
    if (sach != NULL)
    free (sach);
    return 0;
}
void enter (Sach *sach){
    fflush(stdin);
    printf ("Nhap Ten Sach: ");
    gets(sach->ten);
    printf ("Nhap Ten Tac Gia: ");
    gets(sach->tacgia);
    printf ("Nhap Nam Xuat Ban: ");
    scanf("%d",&sach->namxuatban);
}
void enter (Sach *sach, int &n){
    printf ("Nhap So Luong Sach: ");
    scanf("%d",&n);
    sach = (Sach*)realloc(sach,n*sizeof(Sach));
    for (int i = 0;i < n; i++){
    printf ("Quyen Sach %d \n",i+1);
    enter (sach+i);
    }
}
void print (Sach *sach){
    printf ("\n  %-10s:  %-10s:  %.4d",sach->ten,sach->tacgia,sach->namxuatban);
}
void print (Sach *sach, int n){
    printf ("  %-10s:  %-10s:  %-15s","Ten Sach","Tac Gia","Nam Xuat Ban");
    for(int i = 0; i < n; i++){
        print (sach+i);
    }
}
int demTG (Sach *sach,int n){
    char TG[30];
    int count = 0;
    fflush(stdin);
    printf ("\nNhap Ten Tac Gia: ");
    gets (TG);
    for (int i = 0; i < n; i++){
        if(strcmp(TG,(sach+i)->tacgia) == 0)
        count ++;
    }
    return count;
}
void sortbyyear (Sach *sach, int n){
    Sach temp ;
    for (int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if ((sach+i)->namxuatban > (sach+j)->namxuatban){
                temp = *(sach+i);
                *(sach+i) = *(sach+j);
                *(sach+j) = temp;
            }
        }
    }
}
void thongke (Sach *sach,int n){
    sortbyyear (sach,n);
    int count = 0;
    printf ("\n\nThong tin sach nam %.4d: ",sach->namxuatban);
    for (int i = 0; i < n; i++){
        print (sach+i);
        count ++;
        if ((sach+i+1)->namxuatban != (sach+i)->namxuatban){
            printf ("\nNam %.4d co %d quyen sach",(sach+i)->namxuatban,count);
            count = 0;
            if (i < n-1)
            printf ("\n\nThong tin sach nam %.4d: ",(sach+i+1)->namxuatban);
        }
    }
}
void menu (Sach *sach,int n){
    int choice;
    char k,c;
    do {
        printf ("\n1.Xuat Thong Tin Sach");
        printf ("\n2.Dem So Sach Cua Tac Gia Nhap Tu Ban Phim");
        printf ("\n3.Thong Ke Sach Theo Nam Xuat Ban");
        printf ("\nLua Chon: ");
        scanf ("%d",&choice);
        switch (choice){
            case 1: print (sach,n);
                break;
            case 2: printf ("\nCo %d cuon sach",demTG(sach,n));
                break;
            case 3: thongke (sach,n);
                break;
            default: printf ("\nVui long nhap lai lua chon: ");
                break;
        }
        printf ("\nBan muon thoat? (esc)");
        k = getch();
        c = k;
    }while (c!= 27);
}