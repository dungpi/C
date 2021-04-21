#include<stdio.h>
#include<math.h>
void input(int &a,int &b);
int sub (int a,int b);
int mul (int a,int b);
int add (int a,int b);
int residue (int a,int b);
int division (int a,int b);
void menu (int a,int b);
long dec2bin (int n);
int menu (){
    int a,b;
    input(a,b);
    menu (a,b);
    return 0;
}
void input(int &a,int &b){
    printf("enter a:");
    scanf("%d",&a);
    printf("enter b:");
    scanf("%d",&b);
}
int add (int a,int b){
    return a+b;
}
int sub (int a,int b){
    return a-b;
}
int mul (int a,int b){
    return a*b;
}
int residue (int a,int b){
    return a%b;
}
int division (int a,int b){
    return a/b;
}
void menu (int a,int b){
    int choise ;
    do {
        printf("\n===Thuc hien phep tinh bit===\n");
        printf("1. Phep cong\n");
        printf("2. Phep tru\n");
        printf("3. Phep nhan\n");
        printf("4. Phep chia lay du\n");
        printf("5. Phep chia lay nguyen\n");
        printf("Your choise:");
        scanf("%d",&choise);
        switch (choise){
            case 1: printf ("%d",add(a,b));
                    printf ("Binarynumber: %d",dec2bin(add(a,b)));
                break;
            case 2: printf ("%d",sub(a,b));
                    printf ("Binarynumber: %d",dec2bin(sub(a,b)));
                break;
            case 3: printf ("%d",mul(a,b));
                    printf ("Binarynumber: %d",dec2bin(mul(a,b)));
                break;
            case 4: printf ("%d",residue(a,b));
                    printf ("Binarynumber: %d",dec2bin(residue(a,b)));
                break;
            case 5: printf ("%d",division(a,b));
                    printf ("Binarynumber: %d",dec2bin(division(a,b)));
                break;
            default: printf ("enter again!\n");
                break;
        }
        printf ("\nDo you want to exit?(press 0)");
        scanf("%d",&choise);
    }while(choise);
}
long dec2bin (int n){
    long long binarynumber = 0;
    int p = 0;
    while (n > 0){
        binarynumber += n % 2 * pow(10,p);
        p++;
        n /= 2;
    }
    return binarynumber;
}
