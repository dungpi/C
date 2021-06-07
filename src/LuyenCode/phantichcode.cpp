#include <stdio.h>
int main(){
    int a = 3;
    int z = 3;
    int s = 1;
    int b = ++a + a++ + --a;
        // 4 +4+1 +5-1
    int c = ++z + z++ + z++; 
        //  4 +4+1+5
    // int d = ++s + ++s + ++s + s++;
        //     2 + 3+4+1+4
    //     ++s;
    //    printf ("%d ",s); 
    //     ++s;
    //            printf ("%d ",s); 

    //     ++s;
    //            printf ("%d ",s); 

    //     s++;
    //    printf ("%d \n",s); 

    int d = ++s + ++s + ++s;// + s++;
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d", d);
}