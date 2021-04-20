// 1. Số Phức
// - nhập, xuất số phức (done)
// - viết hàm tính tổng, hiệu, tích, thương, module số phức
// - viết hàm so sánh 2 số phức trả về một giá trị enum
#include <stdio.h>
#include <math.h>
struct SoPhuc{
    int thuc;
    int ao;
};
void enter (SoPhuc *sophuc);
void enter (SoPhuc *sophuc,int &n);
void in1sophuc (SoPhuc *sophuc);
void print (SoPhuc *sophuc,int n);
void plus (SoPhuc *sophuc,int n);
void subtraction (SoPhuc *sophuc,int n);
SoPhuc* TinhTich2SoPhuc (SoPhuc *sophuc);
float Modulus(SoPhuc *sophuc);
int main (){
    SoPhuc *sophuc;
    int n;
    enter (sophuc,n);
    print (sophuc,n);
    plus (sophuc,n);
    subtraction (sophuc,n);
    printf ("\nModulus cua so phuc: %.2f",Modulus(sophuc));
    printf ("\nTich Hai So Phuc: ");
    sophuc = (SoPhuc*)malloc(sizeof(SoPhuc));
    in1sophuc (TinhTich2SoPhuc(sophuc));
    return 0;
}
void enter (SoPhuc *sophuc){
    printf ("Nhap Phan Thuc: ");
    scanf ("%d",&sophuc->thuc);
    printf ("Nhap Phan Ao: ");
    scanf ("%d",&sophuc->ao);
}
void enter (SoPhuc *sophuc,int &n){
    printf ("Ban Muon Nhap Bao Nhieu So Phuc: ");
    scanf ("%d",&n);
    for(int i = 0; i < n ; i++){
        printf ("\t\tNhap So Phuc %d \n",i+1);
        enter (sophuc+i);
    }
}
void in1sophuc (SoPhuc *sophuc){
    if (sophuc->thuc != 0) 
        printf("%d",sophuc->thuc);
    if (sophuc->ao != 0){
        if (sophuc->ao == -1) 
            printf (" - i");
        else if (sophuc->ao == 1){
            if (sophuc->thuc == 0) 
            printf ("i");
            else printf (" + i");
        }
        else{
        if (sophuc->thuc != 0 && sophuc->ao > 0)
            printf (" + %di",sophuc->ao);
        else
            printf("%di",sophuc->ao);
        }
    }
    if (sophuc->thuc==0 & sophuc->ao==0)
        printf("0");
}
void print (SoPhuc *sophuc,int n){
    for(int i = 0; i < n; i++){
        printf ("\nSo Phuc %d :",i+1);
        in1sophuc (sophuc+i);
    }
}
float Modulus(SoPhuc *sophuc){
   return sqrt(sophuc->thuc*sophuc->thuc+sophuc->ao*sophuc->ao);
}
void plus (SoPhuc *sophuc,int n){
    int sumthuc = 0;
    int sumao = 0;
    for(int i = 0; i < n; i++){
        sumthuc += (sophuc+i)->thuc;
        sumao += (sophuc+i)->ao;
    }
    printf ("\nSo Phuc Sau Cong: ");
    if (sumthuc != 0) 
        printf("%d",sumthuc);
    if (sumao != 0){
        if (sumao == -1) 
            printf (" - i");
        else if (sumao == 1){
            if (sumthuc == 0) 
            printf ("i");
            else printf (" + i");
        }
        else{
        if (sumthuc != 0 && sumao > 0)
            printf (" +%di",sumao);
        else
            printf("%di",sumao);
        }
    }
    if (sumthuc==0 & sumao==0)
        printf("0");
}
void subtraction (SoPhuc *sophuc,int n){
    int minusthuc = sophuc->thuc;
    int minusao = sophuc->ao;
    for(int i = 1; i < n; i++){
        minusthuc -= (sophuc+i)->thuc;
        minusao -= (sophuc+i)->ao;
    }
    printf ("\nSo Phuc Sau Tru: ");
    if (minusthuc != 0) 
        printf("%d",minusthuc);
    if (minusao != 0){
        if (minusao == -1) 
            printf (" - i");
        else if (minusao == 1){
            if (minusthuc == 0) 
            printf ("i");
            else printf (" + i");
        }
        else{
        if (minusthuc != 0 && minusao > 0)
            printf (" +%di",minusao);
        else
            printf(" %di",minusao);
        }
    }
    if (minusthuc==0 & minusao==0)
        printf("0");
}
SoPhuc TinhTich2SoPhuc(SoPhuc *a, SoPhuc *b)
{
    SoPhuc *c;
    c->thuc = a->thuc * b->thuc - a->ao * b->ao;
    c->ao = a->thuc * b->ao + a->ao * b->thuc;
    return *c;
}
SoPhuc* TinhTich2SoPhuc(SoPhuc *sophuc){
    SoPhuc *c;
    c = (SoPhuc*)malloc(sizeof(SoPhuc));
        c->thuc = (sophuc+0)->thuc * (sophuc+1)->thuc - (sophuc+0)->ao * (sophuc+1)->ao;
        c->ao = (sophuc+0)->thuc * (sophuc+1)->ao + (sophuc+0)->ao * (sophuc+1)->thuc;
    return *c;
}