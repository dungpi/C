
#include <stdio.h>
int main(){
    char arr[10] = {'G', 'I', 'A','O','T', 'H','O','N','G'};
    char *p;
    p = (char *)(arr+3)[2];
    printf("%c", p);
}