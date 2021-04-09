#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 50

/* Danh sách cần làm:
1. Thống kê danh sách (Done)
2. Tìm kiếm theo mã thức ăn. (Done)
3. Thêm bớt trái cây
4. Thanh toán
5. Xuất nhị phân
6. Menu     */

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
int totalcost(TraiCay *traicay, int soluonghang);// Tổng giá tiền
int total(TraiCay *traicay, int soluonghang); //Tổng số lượng
void sorttotal (TraiCay *traicay, int soluonghang); //Sắp xếp
void sortten (TraiCay *traicay, int soluonghang);
void sortID (TraiCay *traicay, int soluonghang);
void statisticsbyquantity (TraiCay *traicay, int soluonghang);
void statisticsbyID (TraiCay *traicay,int soluonghang);
void statisticsbyname (TraiCay *traicay,int soluonghang);
void erase (TraiCay *traicay, int &soluonghang, char ma[8]);
void menu (TraiCay *traicay, int soluonghang,char ma[8],FILE *file, char *path);
void outprint (FILE *file,char *path,TraiCay *traicay,int soluonghang);


int main(){
    TraiCay *traicay;
    FILE *file;
    int soluonghang;
    char ma[10];   
    char *path = "./src/BaiTapLon/print.out";
    traicay = (TraiCay *)malloc(sizeof(TraiCay));
    nhaptraicay (traicay,soluonghang);
    menu (traicay,soluonghang,ma,file,path);
    if(traicay != NULL)
    free (traicay);
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
    printf("|\t Trai Cay: %-15s |\n",traicay->tentraicay);
    printf("|\t Ma: %-22s |\n",traicay->mahang);
    printf("|\t So Luong: %-16d |\n",traicay->soluong);
    printf("------------------------------------");
}

void xuattraicay(TraiCay *traicay, int soluonghang){
    for (int i = 0; i < soluonghang; i++){
        xuattraicay(traicay + i);
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
}

int total(TraiCay *traicay, int soluonghang){
    int sum = 0;
    for(int i = 0; i < soluonghang; i ++){
        sum +=((traicay+i)->soluong);
    }
    return sum;
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

void sorttotal (TraiCay *traicay, int soluonghang){
    TraiCay temp;
    for (int i = 0; i < soluonghang - 1; i++){
        for(int j = i+1; j < soluonghang; j++){
        if ((traicay+i)->soluong > (traicay+j)->soluong)
            temp = *(traicay+i);
            *(traicay+i) = *(traicay+j);
            *(traicay+j) = temp;
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

void sortID (TraiCay *traicay, int soluonghang){
    TraiCay temp ;
    for (int i = 0; i < soluonghang-1; i++){
        for(int j = i+1; j < soluonghang; j++){
            if ((traicay+i)->mahang > (traicay+j)->mahang){
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
    sorttotal (traicay,soluonghang);
    for(int i = 0; i < soluonghang ; i++){
        printf ("\nSo Luong: %-3d||Trai Cay: %-20s||Ma Trai Cay: %-10s||Gia: %-6d",(traicay+i)->soluong,(traicay+i)->tentraicay,(traicay+i)->mahang,(traicay+i)->gia);
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
}
void statisticsbyID (TraiCay *traicay,int soluonghang){
    sortID (traicay,soluonghang);
    for(int i = 0; i < soluonghang ; i++){
        printf ("\nMa Trai Cay: %-10d||Trai Cay: %-20s||So Luong: %-3d||Gia: %-6d",(traicay+i)->mahang,(traicay+i)->tentraicay,(traicay+i)->soluong,(traicay+i)->gia);
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
}
void statisticsbyname (TraiCay *traicay,int soluonghang){
    sortten (traicay,soluonghang);
    for(int i = 0; i < soluonghang ; i++){
        printf ("\nTrai Cay: %-20d||Ma Trai Cay: %-10s||So Luong: %-3d||Gia: %-6d",(traicay+i)->tentraicay,(traicay+i)->mahang,(traicay+i)->soluong,(traicay+i)->gia);
        printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
}

void erase (TraiCay *traicay, int &soluonghang, char ma[8]){
    bool check = false;
    printf("\nNhap ma traicay muon xoa: ");
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

void menu (TraiCay *traicay, int soluonghang,char ma[10],FILE *file, char *path){
    int choice ;
    char k,c ;
    do{
        printf("\n===========MENU==========\n");
        printf("1.Xuat Danh Trai Cay Da Nhap\n");
        printf("2.Thong Ke Trai Cay Theo So Luong\n");
        printf("3.Thong Ke Trai Cay Theo Ma Trai Cay (A->Z)\n");
        printf("4.Thong Ke Trai Cay Thep Ten Trai Cay (A->Z)\n");
        printf("5.Tim Trai Cay Theo Ten\n");
        printf("6.Xoa Theo Ma Trai Cay\n");
        printf("7.Xuat Ra File Nhi Phan\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1: xuattraicay(traicay,soluonghang);
                break;
            case 2: statisticsbyquantity(traicay,soluonghang);
                break;
            case 3: statisticsbyID(traicay,soluonghang);
                break;
            case 4: statisticsbyname(traicay,soluonghang);
                break;
            case 5 :timkiem(traicay,soluonghang);
                break;
            case 6:erase(traicay,soluonghang,ma);
                   xuattraicay(traicay,soluonghang);
                break;
            case 7: outprint (file,path,traicay,soluonghang);
                break;
            default: printf ("\n Cu Phap Khong Hop Le!!! Vui long nhap lai lua chon: ");
                break;
        }
        printf("\nWanna Exit?(esc)");
        k = getch();
        c = k;
    }while(c != 27);
}
void outprint (FILE *file,char *path,TraiCay *traicay,int soluonghang){
    char *mode = "ab";
    file = fopen (path,mode);
    fprintf (file,"\n=======================================================================LIST=========================================================================");
    for (int i = 0; i < soluonghang ; i++){
        fprintf (file,"\nMa Trai Cay: %-4s||Ten Trai Cay: %-20s||So Luong: %-3d||Gia: %-6d",(traicay+i)->mahang,(traicay+i)->tentraicay,(traicay+i)->soluong,(traicay+i)->gia);
        fprintf (file,"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~--------------------");
    }
    fclose (file);
}