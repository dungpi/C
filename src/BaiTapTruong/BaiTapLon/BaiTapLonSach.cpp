#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
/* Thêm các tính năng như: 
    1.Đếm số sách trong kho(thống kê)(DONE)
    2.tìm kiếm theo tên sách (DONE)
    3.Thống kê sách theo năm xuất bản (DONE)
    4.Xóa sách (DONE)
    5.Xuất ra file nhị phân (DONE)
    6.Menu (DONE)
*/
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
void enter (Sach *sach, int &sotuasach);
void print (Sach *sach);
void print (Sach *sach, int sotuasach);
void findbyname (Sach *sach, int sotuasach);
int total (Sach *sach, int sotuasach);//tổng số sách trong kho 
void sortbynumber (Sach *sach, int sotuasach);// sắp xếp 
void sortbyyear (Sach *sach, int sotuasach);
void sortbyname (Sach *sach, int sotuasach);
void statisticsbyquantity (Sach *sach, int sotuasach);//thống kê
void statisticsbyyear (Sach *sach,int sotuasach);
void statisticsbyname (Sach *sach,int sotuasach);
void erase (Sach *sach, int &sotuasach, char ma[8]);
void outprint (FILE *file,char *path,Sach *sach,int sotuasach);
void menu (Sach *sach, int sotuasach,char ma[8],FILE *file, char *path);
int main (){
    Sach *sach;
    FILE *file;
    int sotuasach;
    char ma[8];   
    char *path = "./src/BaiTapTruong/outfile/print.out";
    sach = (Sach *)malloc(sizeof(Sach));
    enter (sach,sotuasach);
    menu (sach,sotuasach,ma,file,path);
    if(sach != NULL)
    free (sach);
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
    do {
    printf ("Nhap So Luong Sach Trong Thu Vien: ");
    scanf("%d",&sotuasach);
        if (sotuasach <= 0||sotuasach > MAX){
            printf ("Xin vui long nhap lai!!!");
            printf ("\nNhap So Luong Sach Trong Thu Vien: ");
            scanf("%d",&sotuasach);
        }
    }while (sotuasach <= 0||sotuasach > MAX);
    sach = (Sach*)realloc(sach,(sotuasach)*sizeof(Sach));
    for (int i = 0; i < sotuasach ; i++){
        printf ("\n\n--------------------------------");
        printf ("\nNhap thong tin Sach %d\n",i+1);
        enter(&*(sach+i));
    }
}
void print (Sach *sach){
    printf ("\nMa sach: %-10s||Ten Sach: %-20s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %.4d||So Luong: %-3d||Gia: %-6d",sach->masach,sach->ten,sach->theloai,sach->tentacgia,sach->namxuatban,sach->soluong,sach->gia);
}
void print (Sach *sach, int sotuasach){
    printf ("\n=======================================================================LIST=========================================================================");
    for (int i = 0; i < sotuasach ; i++){
        print(sach+i);
        printf ("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
void findbyname (Sach *sach, int sotuasach){
    char name [30];
    int count = 0;
    fflush(stdin);
    printf ("\nNhap Ten Sach Can Tim: ");
    gets (name);
    for (int i = 0; i < sotuasach ; i++){
        if (strcmp (name,(sach+i)->ten) == 0){
            printf ("\nMa sach: %-10s||Ten Sach: %-20s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %.4d||So Luong: %-3d||Gia: %-6d",(sach+i)->masach,(sach+i)->ten,(sach+i)->theloai,(sach+i)->tentacgia,(sach+i)->namxuatban,(sach+i)->soluong,(sach+i)->gia);
            printf ("\n----------------------------------------------------------------------------------------------------------------------------------------------------");
            count ++;
        }
    }
    if(count == 0){
        printf("\nKhong co sach do trong kho!");
    }
}
int total (Sach *sach, int sotuasach){
    int sum = 0;
    for(int i = 0; i < sotuasach;i ++){
        sum +=((sach+i)->soluong);
    }
    return sum;
}
void sortbynumber (Sach *sach, int sotuasach){
    Sach temp ;
    for (int i = 0; i < sotuasach-1; i++){
        for(int j = i+1; j < sotuasach; j++){
            if ((sach+i)->soluong > (sach+j)->soluong){
                temp = *(sach+i);
                *(sach+i) = *(sach+j);
                *(sach+j) = temp;
            }
        }
    }
}
void sortbyyear (Sach *sach, int sotuasach){
    Sach temp ;
    for (int i = 0; i < sotuasach-1; i++){
        for(int j = i+1; j < sotuasach; j++){
            if ((sach+i)->namxuatban > (sach+j)->namxuatban){
                temp = *(sach+i);
                *(sach+i) = *(sach+j);
                *(sach+j) = temp;
            }
        }
    }
}
void sortbyname (Sach *sach, int sotuasach){
    Sach temp;
    for (int i = 0; i < sotuasach-1; i++){
        for(int j = i+1; j < sotuasach; j++){
            if (strcmp((sach+i)->ten,(sach+j)->ten) > 0){
                temp = *(sach+i);
                *(sach+i) = *(sach+j);
                *(sach+j) = temp;
            }
        }
    }
}
void statisticsbyquantity (Sach *sach, int sotuasach){
    printf ("\nSo luong sach co trong kho la: %d",total(sach,sotuasach));
    printf ("\nTrong do co :");
    sortbynumber (sach,sotuasach);
    for(int i = 0; i < sotuasach ; i++){
        printf ("\nSo luong %-3d sach: %-20s ||Ma sach: %-10s||The loai: %-15s||Tac gia: %-10s||Nam xuat ban: %.4d||Gia: %-6d",(sach+i)->soluong,(sach+i)->ten,(sach+i)->masach,(sach+i)->theloai,(sach+i)->tentacgia,(sach+i)->namxuatban,(sach+i)->gia);
        printf ("\n-----------------------------------------------------------------------------------------------------------------------------------------------");
    }
}void statisticsbyyear (Sach *sach,int sotuasach){
    sortbyyear (sach,sotuasach);
    for(int i = 0; i < sotuasach ; i++){
        printf ("\nNam %.4d sach: %-24s ||Ma sach: %-10s||The loai: %-15s||Tac Gia: %-10s||So luong: %-8d||Gia: %-6d",(sach+i)->namxuatban,(sach+i)->ten,(sach+i)->masach,(sach+i)->theloai,(sach+i)->tentacgia,(sach+i)->soluong,(sach+i)->gia);
        printf ("\n-----------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
void statisticsbyname (Sach *sach,int sotuasach){
    sortbyname (sach,sotuasach);
    for(int i = 0; i < sotuasach ; i++){
        printf ("\nSach: %-19s||So Luong: %-3d||Ma sach: %-10s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %.4d||Gia: %-6d",(sach+i)->ten,(sach+i)->soluong,(sach+i)->masach,(sach+i)->theloai,(sach+i)->tentacgia,(sach+i)->namxuatban,(sach+i)->gia);
        printf ("\n-----------------------------------------------------------------------------------------------------------------------------------------------");
    }
}
void erase (Sach *sach, int &sotuasach, char ma[8]){
    bool check = false;
    printf("\nNhap ma sach muon xoa: ");
    fflush(stdin);
    gets (ma);
    // Dich chuyen mang
    for(int i = 0; i < sotuasach ; i++){
        if (strcmp (ma,(sach+i)->masach) == 0){
            for (int j = i; j < sotuasach - 1;j++){
                *(sach+j) = *(sach+j+1);
                check = true;
            } 
            sotuasach--;
        }
    }
    if (check){
        printf ("\nXoa sach thanh cong!!!");
    }
    else printf ("\nMa sach khong ton tai!!!");
}
void menu (Sach *sach, int sotuasach,char ma[8],FILE *file, char *path){
    int choise ;
    char k,c ;
    do{
        printf("\n===========MENU==========\n");
        printf("1.Xuat Danh Sach Da Nhap\n");
        printf("2.Thong Ke Sach Theo So Luong\n");
        printf("3.Thong Ke Sach Theo Nam Xuat Ban\n");
        printf("4.Thong Ke Sach Thep Ten Sach (A->Z)\n");
        printf("5.Tim Sach Theo Ten Sach\n");
        printf("6.Xoa Theo Ma Sach\n");
        printf("7.Xuat ra file nhi phan\n");
        printf("Your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1: print(sach,sotuasach);
                break;
            case 2:statisticsbyquantity(sach,sotuasach);
                break;
            case 3:statisticsbyyear(sach,sotuasach);
                break;
            case 4:statisticsbyname(sach,sotuasach);
                break;
            case 5:findbyname(sach,sotuasach);
                break;
            case 6:erase(sach,sotuasach,ma);
                   print (sach,sotuasach);
                break;
            case 7: outprint (file,path,sach,sotuasach);
                break;
            default: printf ("\nKhong Hop Le!!! Vui long nhap lai lua chon: ");
                break;
        }
        printf("\nDo you want to exit ?(esc)");
        k = getch();
        c = k;
    }while(c != 27);
}
void outprint (FILE *file,char *path,Sach *sach,int sotuasach){
    char *mode = "ab";//NOTE: a:Khi chưa có file sẽ tạo ra file nếu có rr sẽ ghi tiếp theo ,b: là binarynumber(nhị phân)
    //mở file 
    file = fopen (path,mode);
    fprintf (file,"\n=======================================================================LIST=========================================================================");
    for (int i = 0; i < sotuasach ; i++){
        fprintf (file,"\nMa sach: %-10s||Ten Sach: %-20s||The Loai: %-15s||Tac Gia: %-10s||Nam Xuat Ban: %.4d||So Luong: %-3d||Gia: %-6d",(sach+i)->masach,(sach+i)->ten,(sach+i)->theloai,(sach+i)->tentacgia,(sach+i)->namxuatban,(sach+i)->soluong,(sach+i)->gia);
        fprintf (file,"\n----------------------------------------------------------------------------------------------------------------------------------------------------");
    }
    fclose (file);
}