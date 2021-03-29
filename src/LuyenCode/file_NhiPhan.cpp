//Nhập xuất mảng bằng file nhị phân 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#define MAX 30
void enter (int *hi,int size);
void print (int *hi,int size);
void exportInputValue(FILE *file, char *path, const int *hi, const int size);

int main (){
    int *hi,size;
    FILE *file;
        char *path = "E:\C\src\LuyenCode\file.txt";
    hi = (int *)malloc(sizeof(int)*size); 
    do {
        printf ("Nhap size: ");
        scanf("%d",&size);
        if (size < 0 || size > MAX){
            printf ("Vui long nhap lai size: ");
            scanf("%d",&size);
        }
    }while (size < 0 || size > MAX);
    enter (hi,size);
    print (hi,size);
    exportInputValue(file,path,hi,size);
    return 0;
}

void exportInputValue(FILE *file, char *path, const int *hi, const int size){
    // chuỗi về sau mình sử dụng *path thay vì path
    char *mode = "a";// chế độ append: file mở ra chỉ để ghi. Nếu chưa có file nó sẽ tự tạo
    // file: mở --> làm gì đó --> đóng file
    file = fopen(path,mode);// mở file có đường dẫn là path ra để ghi file
    fprintf(file,print(hi,size));//viết vào file có đường dẫn là path
    
    fclose(file);
}
void enter (int *hi,int size){
    int temp;
    printf ("Nhap cac phan tu:\n");
    for (int index = 0;index < size;index++){
        printf ("\thi %d: ",index);
        scanf("%d",&temp);
        *(hi+index) = temp;
    }
}
void print (int *hi,int size){
    printf ("===Cac Phan Tu Vua Nhap===\n");
    for (int index = 0; index < size;index++){
        printf ("\t%d",*(hi+index));
    }
}