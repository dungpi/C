#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct DateTime{
    int ngay;
    int thang;
    int nam;
};
typedef struct Tacgia{
    char matacgia[30];
    char tentacgia[30];
    DateTime *ngaysinh;
};
typedef struct Nhaxuatban{
    char manhaxuatban[30];
    char tennhaxuatban[30];
};
typedef struct Sach{
    char masach[30];
    char ten[30];
    Tacgia *tacgia;
    Nhaxuatban *nhaxuatban;
    int soluong;
    float gia;
};
typedef struct NguoiMuon{
    char manguoimuon[30];
    Sach *sach;  
};
// nhap xuat
void nhap(DateTime *time);
void nhap(Nhaxuatban *nhaxuatban);
void nhap(Tacgia *tacgia);
void nhap(Sach *sach);
void nhap(NguoiMuon *nguoiMuon);
void xuat(DateTime *time);
void xuat(Nhaxuatban *nhaxuatban);
void xuat(Tacgia *tacgia);
void xuat(Sach *sach);
void xuat(NguoiMuon *nguoiMuon);
void xuat(Sach *khosach, int sotuasach);
// so sanh 2 cuon sach
bool equal(Sach *sach, Sach *other);
void themVaoKho(Sach *&khosach, int &sotuasach, Sach *sach, int socuon);
void  xuatKho(Sach *&khosach, int &sotuasach, Sach *sach, int socuon);
int main(){
    NguoiMuon *nguoimuon;
    Sach *sach,*khosach;
    int sotuasach = 0;
    // thêm sách
    khosach = (Sach*)malloc(0);
    sach = (Sach*)malloc(sizeof(Sach));
    nhap(sach);
    themVaoKho(khosach,sotuasach,sach,13);
    xuatKho(khosach,sotuasach,sach,14);
    xuat(khosach,sotuasach);
    return 0;
}
void nhap(DateTime *time){
    printf("ngày:");
    scanf("%d",&time->ngay);
    printf("tháng:");
    scanf("%d",&time->thang);
    printf("năm: ");
    scanf("%d",&time->nam);
}
void xuat(DateTime *time){
    printf("%d/%d/%d",time->ngay,time->thang,time->nam);
}
void nhap(Nhaxuatban *nhaxuatban){
    printf("ma nha xuat ban:");
    gets(nhaxuatban->manhaxuatban);
    printf("ten nha xuat ban:");
    gets(nhaxuatban->tennhaxuatban);
}
void xuat(Nhaxuatban *nhaxuatban){
    printf("%s %s",nhaxuatban->manhaxuatban,nhaxuatban->tennhaxuatban);
}
void nhap(Tacgia *tacgia){
    printf("Ma tac gia: ");
    gets(tacgia->matacgia);
    printf ("Ten tac gia: ");
    gets(tacgia->tentacgia);
    tacgia->ngaysinh = (DateTime*)(malloc(sizeof(DateTime)));
    nhap(tacgia->ngaysinh);
    fflush(stdin);
}
void xuat(Tacgia *tacgia){
    printf("%s %s ",tacgia->matacgia,tacgia->tentacgia);
    xuat(tacgia->ngaysinh);
}
void nhap(Sach *sach){
    printf("ma sach: ");
    gets(sach->masach);
    printf("ten sach: ");
    gets(sach->ten);
    printf("Tac gia: ");
    sach->tacgia=(Tacgia *)malloc(sizeof(Tacgia));
    nhap(sach->tacgia);
    printf("Nha xuat ban: ");
    sach->nhaxuatban=(Nhaxuatban *)malloc(sizeof(Nhaxuatban));
    nhap(sach->nhaxuatban);
    printf("Gia:");
    scanf("%f",&sach->gia);
    fflush(stdin);
    sach->soluong=0;
}
void xuat(Sach *sach){
    printf("%s %s ",sach->masach,sach->ten);
    xuat(sach->tacgia);
    xuat(sach->nhaxuatban); 
    printf(" %d",sach->soluong);  
}
void nhap(NguoiMuon *nguoiMuon){
    printf("ma nguoi muon: ");
    gets(nguoiMuon->manguoimuon);
    printf("sach: ");
    nguoiMuon->sach=(Sach *)malloc(sizeof(Sach));
    nhap(nguoiMuon->sach);
}
void xuat(NguoiMuon *nguoiMuon){
    printf("%s", nguoiMuon->manguoimuon);
    xuat(nguoiMuon->sach);
}
bool equal(Sach *sach, Sach *other){
    return sach->masach == other->masach;
}
void themVaoKho(Sach *&khosach, int &sotuasach,Sach *sach, int socuon){
    bool cotrongkho = false;
    for(int index = 0; index <sotuasach;index++){//NOTE: kiểm tra nếu có trong kho thì tăng số lượng
        if(equal(sach,&*(khosach+index))){
            khosach[index].soluong += socuon;
            cotrongkho = true;
            break;
        }
    }
    if(!cotrongkho){//NOTE: không có trong kho thì thêm vào kho
        sotuasach++;
        khosach = (Sach*)realloc(khosach,sotuasach*sizeof(Sach));
        *(khosach+sotuasach-1) = *sach;
        khosach[sotuasach-1].soluong = socuon;
    }
}
void xuat(Sach *khosach, int sotuasach){
    if(sotuasach == 0){
        printf("\nThong bao:Khong co sach trong kho!");
    }
    for(int index = 0; index < sotuasach;index++){
        xuat(&khosach[index]);
    }
}
void  xuatKho(Sach *&khosach, int &sotuasach, Sach *sach, int socuon){
    bool cotrongkho = false;
    for(int index = 0; index < sotuasach;index++){
        if(strcmp(khosach[index].masach,sach->masach)==0){// có sách
            if(khosach[index].soluong>socuon){
                khosach[index].soluong-=socuon;
            }
            else{
               sotuasach--;
               for(int next = index; next<sotuasach; next++){
                   khosach[next] = khosach[next+1];
               }
               khosach = (Sach*) realloc(khosach,sotuasach*sizeof(Sach));
            }
        }
        cotrongkho = true;
        break;
    }
    if(!cotrongkho){
        printf("khong co sach de xuat!");
    }
}