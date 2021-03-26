#include <stdio.h>
#include <stdlib.h>
struct DateTime{
    int day;
    int month;
    int year;
};
struct Tacgia{
    // char matacgia[30];
    char tentacgia[30];
    DateTime *ngaysinh;   
    
};
struct Nhaxuatban{
    // char manhaxuatban [30];
    char tennhaxuatban [30];
    DateTime *namxuatban;
};
struct Sach{
    char masach [30];
    char ten[30];
    char theloai[50];
    Tacgia *tacgia;
    Nhaxuatban *nhaxuatban;
    int soluong;
    float gia;
};
struct Nguoimuon{
    char manguoimuon[30];
    Sach *sach;
};
void enter (DateTime *time );
void enter (Nhaxuatban *nhaxuatban);
void enter (Tacgia *tacgia);
void enter (Sach *sach);
void enter (Sach *sach, int &sotuasach);
void enter (Nguoimuon *nguoimuon);
void print (DateTime *time);
void print (Nhaxuatban *nhaxuatban);
void print (Tacgia *tacgia);
bool validDay(DateTime *time);
bool leapYear(DateTime *time);
int main (){
    Sach *sach;
    int sotuasach;
    sach = (Sach *)malloc(sizeof(Sach));
    enter (sach,sotuasach);
    return 0;
}
void enter (DateTime *time ){
    do{
    printf ("Nhap Ngay: ");
    scanf ("%d",&time -> day);
    printf ("Nhap Thang: ");
    scanf ("%d",&time -> month);
    printf ("Nhap Nam: ");
    scanf ("%d",&time -> year);
    }while(!validDay(time));
}
bool validDay(DateTime *time){ //kiểm tra ngày tháng
    bool validDay = true;
    if (time->month < 0 || time->month > 12){
        validDay = false;
    }
    else{
        switch (time->month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (time->day < 1 || time->day > 31){
                validDay = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (time->day < 1 || time->day > 30){
                validDay = false;
            }
            break;
        case 2:
            if (leapYear(time) && (time->day < 1 || time->day > 29)){
                validDay = false;
            }
            break;
        }
    }
    return validDay;
}
bool leapYear(DateTime *time){
    return time->year % 4 == 0;
}
void print (DateTime *time){
    printf("%.2d/%.2d/%.4d",time->day,time->month,time->year);
}
void enter(Nhaxuatban *nhaxuatban){
    fflush(stdin);
    // printf("Nhap ma nha xuat ban:");
    // gets(nhaxuatban->manhaxuatban);
    printf("Nhap ten nha xuat ban:");
    gets(nhaxuatban->tennhaxuatban);
    nhaxuatban->namxuatban = (DateTime*)(malloc(sizeof(DateTime)));
    enter(nhaxuatban->namxuatban);
}
void print(Nhaxuatban *nhaxuatban){
    printf("Thong tin nha xuat ban: %s %s\n",nhaxuatban->manhaxuatban,nhaxuatban->tennhaxuatban);
    printf("Xuat Ban Nam: ");
    print (nhaxuatban->namxuatban);
}
void enter (Tacgia *tacgia){
    fflush(stdin);
    printf("Nhap Ten Tac Gia: ");
    gets (tacgia->tentacgia);
    // printf("Nhap Ma Tac Gia: ");
    // gets (tacgia->matacgia);
    tacgia->ngaysinh = (DateTime*)(malloc(sizeof(DateTime))); 
    enter (tacgia->ngaysinh);
}
void print (Tacgia *tacgia){
    printf ("\n-----------Tac Gia-------------");
    printf ("\nTac Gia: %s",tacgia->tentacgia);
    // printf ("\nMa Tac Gia: %s",tacgia->matacgia);
    printf ("\nNam Sinh Tac Gia: ");
    print(tacgia->ngaysinh);
    printf ("\n-------------------------------");
}
void enter (Sach *sach){
    fflush(stdin);
    printf ("Nhap Ma Sach: ");
    gets(sach->masach);
    printf ("Nhap Ten Sach: ");
    gets(sach->ten);
    printf ("Nhap The Loai Sach: ");
    gets(sach->theloai);
    sach->tacgia = (Tacgia*)(malloc(sizeof(Tacgia)));
    enter(sach->tacgia);
    sach->nhaxuatban = (Nhaxuatban*)(malloc(sizeof(Nhaxuatban)));
    enter(sach->nhaxuatban);
    printf ("Nhap So Luong Sach: ");
    scanf("%d",&sach->soluong);
    printf ("Nhap Gia Sach: ");
    scanf("%f",&sach->gia);
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