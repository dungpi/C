//Nhập một dãy só nguyên gồm n phần tử 
//Xuất dãy số nguyên đó ra màn hình 
//Tính tổng dãu số nguyên 
//Tìm phần tử âm lớn thứ 2 trong dãy
//Kiểm tra trong dãy có bao nhiêu số nguyên tố 
//Dùng con trỏ
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 50
void enter (int *array,int &n);
void print (int *array, int n);
void tong (int *array,int n);
int NguyenAmMax2(int *array,int n);
void menu (int *array,int n);
int main (){
    int *array,n;
    array = (int *) malloc(sizeof(int));
    do {
        printf ("Nhap n so nguyen: ");
        scanf ("%d",&n);
        if (n <= 0||n > MAX){
            printf ("Nhap lai n: ");
            scanf ("%d",&n);
        }
    }while(n <= 0 || n > MAX);
    enter(array,n);
    printf ("Phan tu am lon thu 2 trong day la: %d",NguyenAmMax2(array,n));
    return 0;
}
void enter (int *array,int &n){
    printf ("====Nhap cac phan tu====\n");
    for (int i = 0;i < n;i++){
        printf("a[%d] = ",i);
        scanf("%d",&*(array+i));
    }
}
void print (int *array, int n){
    printf("===Cac Phan Tu Da Nhap===");
    for (int i = 0;i < n;i++){
         printf("%d\t",i,*(array+i));
    }
}
void tong (int *array,int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
            sum += *(array+i);
    }
        printf("Mang co tong gia tri la: %d",sum);
}
int NguyenAmMax2(int *array,int n) {
    int max = 0;
    for (int i = 0;i < n,i++){
        if (*(array+i) < 0){
            max = *(array+i);
        }
        return max;
    }
    for(i=0; i<n; i++) {
        if(a[i]<0 && a[i]>max){
            max = *(array+1);
        }
    }
     return max;
}
void menu (int *array,int n){
    int choise ;
    char k,c ;
    do{
        printf("\n===========MENU==========\n");
        printf("0.Xuat gia tri da nhap\n");
        printf("1.Gia tri lon nhat\n");
        printf("2.Gia tri nho nhat\n");
        printf("3.Tinh tong so chan\n");
        printf("4.Top n phan tu\n");
        printf("Your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 0: print(array,n);
                break;
            case 1:findMax(array,n);
                break;
            case 2:findMin(array,n);
                break;
            case 3:tongChan(array,n);
                break;
            case 4:sapXepGiam(array,n);
                    printtop(array,n);
                break;
        }
        printf("\nDo you want to exit ?(esc)");
        k = getch();
        c = k;
    }while(c != 27);
}