/* c PROGRAME TO FIND SIZE OF UNION
   -- demonstrates that the size of union is equivalent to its largest size member
   date: 20-feb,2020  author: MD SHAKIL ANSARI*/ 


#include <stdio.h>
union union1{
    short s1;
    short s2;
    char c1;

};
union union2{
    short s1;
    char c1;
    short s2;
    
};

int main()
{
    union union1 var1;
    union union2 var2;
    printf("\n the size of first union is :%d",(int)sizeof(var1));
    printf("\n the size of second union is :%d",(int)sizeof(var2));

    return 0;
}
