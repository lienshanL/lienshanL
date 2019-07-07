#include <stdio.h> 
 
int main()
{ 
FILE *stream;
       int ret,i=0;
   char s[100][81];
   char str[100][81];
 
   if( (stream=fopen( "test.txt", "r" )) ==NULL  )
      printf( "The file fscanf.out was not opened\n" );
   else
   {
       while((ret=fscanf( stream, "%s", s[i]) != EOF))
       {
           i++;
       }
       for(int j=0;j<i;j++){
	
        printf( "%s", s[j] );
		}
 
      fclose( stream );
   } 
   return 0;
}
