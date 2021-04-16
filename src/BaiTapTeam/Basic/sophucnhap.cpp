#include <stdio.h>
//532 Khai báo biểu diễn thông tin số phức
struct SoPhuc
{
    int iThuc;
    int iAo;
};
//533 Nhập số phức
void NhapSoPhuc(SoPhuc &a)
{
    printf("Nhap phan thuc: ");
    scanf("%d", &a.iThuc);
    printf("Nhap phan ao: ");
    scanf("%d", &a.iAo);
}
//534 Xuất số phức
void XuatSoPhuc(SoPhuc a)
{
    printf("%d+%di", a.iThuc,a.iAo);
}
//535 Tính tổng 2 số phức
SoPhuc TinhTong2SoPhuc(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.iThuc = a.iThuc + b.iThuc;
    c.iAo = a.iAo + b.iAo;
    return c;
}
//536 Tính hiệu 2 số phức
SoPhuc TinhHieu2SoPhuc(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.iThuc = a.iThuc - b.iThuc;
    c.iAo = a.iAo - b.iAo;
    return c;
}
//537 Tính tích 2 số phức
SoPhuc TinhTich2SoPhuc(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.iThuc = a.iThuc * b.iThuc - a.iAo * b.iAo;
    c.iAo = a.iThuc * b.iAo + a.iAo * b.iThuc;
    return c;
}
//538 Tính thương 2 số phức
SoPhuc TinhThuong2SoPhuc(SoPhuc a, SoPhuc b)
{
    SoPhuc c;
    c.iThuc = (a.iThuc * b.iThuc + a.iAo * b.iAo)/(b.iThuc*b.iThuc + b.iAo*b.iAo);    
    c.iAo = (b.iThuc * a.iAo - b.iAo * a.iThuc)/(b.iThuc*b.iThuc + b.iAo*b.iAo);
    return c;
}
//539 Tính lũy thừa bậc n số phức
SoPhuc LuyThuaBacN(SoPhuc a, int n)
{
    while (n!=0)
    {
        a = TinhTich2SoPhuc(a,a);
        n--;
    }
    return a;
}
int main(){
    SoPhuc a;
    SoPhuc b;
    a.iThuc = 2;
    a.iAo = 5;
    b.iThuc = 1;
    b.iAo = 3;
    return 0;
} 