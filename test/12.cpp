    # include <stdio.h>

   # include <stdlib.h>
   

   int main ()

   {

       int num_int;

       double num_double;

       char str_int[30] = "435";         //将要被转换为整型的字符串

       char str_double[30] = "436.55";  //将要被转换为浮点型的字符串

 

      num_int = atoi(str_int);          //转换为整型值

      num_double = atof(str_double);  //转换为浮点型值

 
       printf("num_int: %d\n", num_int);

       printf("num_double: %lf\n", num_double);

 

       return 0;

   }
