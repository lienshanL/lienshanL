    # include <stdio.h>

   # include <stdlib.h>
   

   int main ()

   {

       int num_int;

       double num_double;

       char str_int[30] = "435";         //��Ҫ��ת��Ϊ���͵��ַ���

       char str_double[30] = "436.55";  //��Ҫ��ת��Ϊ�����͵��ַ���

 

      num_int = atoi(str_int);          //ת��Ϊ����ֵ

      num_double = atof(str_double);  //ת��Ϊ������ֵ

 
       printf("num_int: %d\n", num_int);

       printf("num_double: %lf\n", num_double);

 

       return 0;

   }
