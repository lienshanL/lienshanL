# include <stdio.h>
#include<string.h>
 # include <stdlib.h>
 #include<math.h>
  double str_doubtrans(char str);
int main(){
	double num;
	char str;
	strcpy(str,'0.1248');
    num=str_doubtrans(char str);
    printf("%le",num);
	return 0;
}  

  double str_doubtrans(char str)

   {

       double num_double;

      num_double= strtod(str);  //ת��Ϊ������ֵ

       return  num_double ;

   }
