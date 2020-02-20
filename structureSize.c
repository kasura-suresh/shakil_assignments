/* C programme to find size of a structrure
   date: 20-feb,2020 author: MD SHAKIL ANSARI*/

#include <stdio.h>
struct structure1{
    short s1;
    short s2;
    char c1;

};
struct structure2{
    short s1;
    char c1;
    short s2;
    
};

int main()
{
    struct structure1 var1;
    struct structure2 var2;
    printf("\n the size of first structure is :%d",(int)sizeof(var1));
    printf("\n the size of second structure is :%d",(int)sizeof(var2));

    return 0;
}
