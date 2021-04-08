#include<stdio.h>
void outfile (FILE *file,char *path ,int a);
int main (){
    FILE *file;
    char *path = "./output/test.out";
    int a;
    printf ("Nhap a");
    scanf("%d",&a);
    outfile (file,path,a);
    return 0;
}
void outfile (FILE *file,char *path ,int a){
    char *mode = "ab";
    file = fopen(path,mode);
    fprintf (file, "\nhhhhh %d",a);
    fclose(file);
}