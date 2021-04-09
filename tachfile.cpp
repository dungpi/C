#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 50

struct TraiCay{
    int soluong;
    int gia;
    char tentraicay [20];
    char mahang [30];
};

void nhaptraicay(TraiCay *traicay);
void xuattraicay(TraiCay *traicay);
void nhaptraicay(TraiCay *traicay, int &soluonghang);
void xuattraicay(TraiCay *traicay, int soluonghang);
void timkiem(TraiCay *traicay, int soluonghang);
int total(TraiCay *traicay, int soluonghang);
void sorttotal (TraiCay *traicay, int soluonghang);
void sortten (TraiCay *traicay, int soluonghang);
void statisticsbyquantity (TraiCay *traicay, int soluonghang);
void statisticsbyname (TraiCay *traicay,int soluonghang);
void erase (TraiCay *traicay, int &soluonghang, char ma[8]);
void outprint (FILE *file,char *path,TraiCay *traicay,int soluonghang);
void menu (TraiCay *traicay, int soluonghang,FILE *file, char ma[10], char *path);

int main(){
    TraiCay *traicay;
    int soluonghang;
    char ma[8];
    FILE *file;
    char *path = "./found.out";
    traicay = (TraiCay*)malloc(sizeof(TraiCay));
    nhaptraicay(traicay,soluonghang);
    menu (traicay,soluonghang,file,ma,path);
    if (traicay != NULL) 
    free(traicay);
    return 0; 
}

void nhaptraicay(TraiCay *traicay){
    fflush(stdin);
    printf("Nhap ten trai cay: ");
    gets(traicay -> tentraicay);
    printf("Nhap ma trai cay: ");
    gets(traicay -> mahang);
    printf("So luong: ");
    scanf("%d", &traicay -> soluong);
    printf("Gia mat hang: ");
    scanf("%d", &traicay -> gia);
}

void nhaptraicay(TraiCay *traicay, int &soluonghang){
    do {
        printf ("Nhap So Luong Trai Cay: ");
        scanf("%d",&soluonghang);
    if (soluonghang <= 0||soluonghang > MAX){
        printf ("Xin vui long nhap lai!!!");
        printf ("\nNhap So Luong Trai Cay: ");
        scanf("%d",&soluonghang);
        }
    }while (soluonghang <= 0||soluonghang > MAX);
        traicay = (TraiCay*)realloc(traicay,(soluonghang)*sizeof(TraiCay));
    for (int i = 0; i < soluonghang; i++){
        printf ("~~~~~~~~~~~~~~~~~~~\n");
        nhaptraicay(&*(traicay + i));
    } 
}

void xuattraicay(TraiCay *traicay){
    printf("\n____________________________________\n");
    printf("|\t Trai Cay: %-16s |\n",traicay->tentraicay);
    printf("|\t Ma: %-22s |\n",traicay->mahang);
    printf("|\t So Luong: %-16d |\n",traicay->soluong);
    printf("------------------------------------");
}

void xuattraicay(TraiCay *traicay, int soluonghang){
    for (int i = 0; i < soluonghang; i++){
        xuattraicay(traicay +  i);
    }
}

void timkiem(TraiCay *traicay, int soluonghang){
    char name [30];
    int count = 0;
    fflush(stdin);
    printf("\nNhap Ma Trai Cay Can Tim: ");
    gets (name);
    for (int i = 0; i < soluonghang; i++){
        if (strcmp(name,(traicay + i)->mahang) == 0 ){
            printf ("\nMa Trai Cay: %-10s||Ten Trai Cay: %-20s||So Luong: %-3d||Gia: %-6d",(traicay+i)->mahang,(traicay+i)->tentraicay,(traicay+i)->soluong,(traicay+i)->gia);
            printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            count ++;
        }
    }
    if (count == 0)
        printf("\nTen Tim Kiem Khong Co Trong Danh Trai Cay");
}

int total(TraiCay *traicay, int soluonghang){
    int sum = 0;
    for(int i = 0; i < soluonghang; i ++){
        sum +=((traicay+i)->soluong);
    }
    return sum;
}

void sorttotal (TraiCay *traicay, int soluonghang){
    TraiCay temp;
    for (int i = 0; i < soluonghang - 1; i++){
        for(int j = i+1; j < soluonghang; j++){
            if ((traicay+i)->soluong > (traicay+j)->soluong){
                temp = *(traicay+i);
                *(traicay+i) = *(traicay+j);
                *(traicay+j) = temp;
            }
        }    
    }
}
void sortten (TraiCay *traicay, int soluonghang){
    TraiCay temp;
    for (int i = 0; i < soluonghang - 1; i++){
        for(int j = i+1; j < soluonghang; j++){
            if (strcmp((traicay+i)->tentraicay,(traicay+j)->tentraicay) > 0){
                temp = *(traicay+i);
                *(traicay+i) = *(traicay+j);
                *(traicay+j) = temp;
            }
        }
    }
}

void statisticsbyquantity (TraiCay *traicay, int soluonghang){
    printf ("\nSo Luong Trai Cay Co Trong Kho La: %d",total(traicay,soluonghang));
    printf ("\nTrong do co :");
    sorttotal(traicay,soluonghang);
    for(int i = 0; i < soluonghang ; i++){
        printf ("\nSo Luong: %-3d||Trai Cay: %-10s||Ma Trai Cay: %-20s||Gia: %-6d",(traicay+i)->soluong,(traicay+i)->tentraicay,(traicay+i)->mahang,(traicay+i)->gia);
    }
}

void statisticsbyname (TraiCay *traicay,int soluonghang){
    sortten (traicay,soluonghang);
    for(int i = 0; i < soluonghang ; i++){
        printf ("\nTrai Cay: %-20s||Ma Trai Cay: %-10s||So Luong: %-3d||Gia: %-6d",(traicay+i)->tentraicay,(traicay+i)->mahang,(traicay+i)->soluong,(traicay+i)->gia);
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
}

void erase (TraiCay *traicay, int &soluonghang, char ma[8]){
    bool check = false;
    printf("\nNhap ma   muon xoa: ");
    fflush(stdin);
    gets (ma);
    // Dich chuyen mang
    for(int i = 0; i < soluonghang ; i++){
        if (strcmp (ma,(traicay+i)->mahang) == 0){
            for (int j = i; j < soluonghang - 1;j++){
                *(traicay+j) = *(traicay+j+1);
                check = true;
            } 
            soluonghang--;
        }
    }
    if (check){
        printf ("\nXoa Thanh Cong!!!");
    }
    else printf ("\nMa Trai Cay Khong Ton Tai Trong Danh Trai Cay!!!");
}

void outprint (FILE *file,char *path,TraiCay *traicay,int soluonghang){
    char *mode = "ab";//NOTE: a:Khi chưa có file sẽ tạo ra file nếu có rr sẽ ghi tiếp theo ,b: là binarynumber(nhị phân)
    //mở file 
    file = fopen (path,mode);
    fprintf (file,"\n============================================================================LIST==============================================================================");
    for (int i = 0; i < soluonghang ; i++){
        fprintf (file,"\nMa Trai Cay: %-4s||Trai Cay: %-25s||So Luong: %-3d||Gia: %-6d",(traicay+i)->mahang,(traicay+i)->tentraicay,(traicay+i)->soluong,(traicay+i)->gia);
        fprintf (file,"\n--------------------------------------------------------------------------------------------------------------------------------------------------------------");
    }
    fclose (file);
}

void menu (TraiCay *traicay, int soluonghang,FILE *file, char ma[10], char *path){
    int choice;
    char c,k;
    do{
        printf("\n===========MENU==========\n");
        printf("1.Xuat Danh Trai Cay Da Nhap\n");
        printf("2.Thong Ke Trai Cay Theo So Luong\n");
        printf("3.Thong Ke Trai Cay Thep Ten Trai Cay (A->Z)\n");
        printf("4.Tim Trai Cay Theo Ten\n");
        printf("5.Xoa Theo Ma Trai Cay\n");
        printf("6.Xuat Ra File Nhi Phan\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1: 
                xuattraicay(traicay,soluonghang);
                break;
            case 2: 
                statisticsbyquantity(traicay,soluonghang);
                break;
            case 3:
                statisticsbyname(traicay,soluonghang);
                break;
            case 4:
                timkiem(traicay,soluonghang);
                break;
            case 5:
                erase(traicay,soluonghang,ma);
                xuattraicay(traicay,soluonghang);
                break;
            case 6: outprint (file,path,traicay,soluonghang);
                break;
            default: printf ("\n Cu Phap Khong Hop Le!!! Vui long nhap lai lua chon: ");
                break;
        }
        printf("\nWanna Exit?? (ESC)");
        k = getch();
        c = k;
    } while (c != 27);
}