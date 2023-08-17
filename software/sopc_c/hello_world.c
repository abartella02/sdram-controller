
#include "system.h"
#include <stdio.h>

#define BASE SDRAM_CONTROLLER_0_BASE

#define MAXNUM_WORDS   SDRAM_CONTROLLER_0_SPAN/2
			//For the SDRAM on DE1-SoC, the size is 64MB=67108864 Byte (SDRAM_SPAN)

int main()
{

  int i;
  int char_err_num=0, short_err_num=0, int_err_num=0;

   char * char_ptr;

   char aChar;

   short *short_ptr;
   short aShort;

   int *int_ptr;
   int aInt;

   int charsize, shortsize, intsize;

   charsize=sizeof(aChar);
   shortsize=sizeof(aShort);
   intsize=sizeof(aInt);
   printf("the sizeof char, short, int are: %d, %d, %d\n", charsize, shortsize, intsize);

       //----------------TEST CHAR-----------------------------------

      printf("\n writing chars.....\n");
      for (i=0; i<5; i++) {
               *(char*)(BASE+i)=i%128; // to be safe, use 128 rather than 256
               printf("The written character is %d\n",i%128 );
      }

      printf("\n testing chars.....\n");
      for (i=0; i<5; i++) {
    	  printf("The read character is %d\n", (* (char*)(BASE+i)));
          if (* (char*)(BASE+i)!=i%128){  // or .....(char)i,   if not i%128
                   char_err_num++;
               }

      }
           printf("Testing  Char: the total numbers of error is : %i\n" ,char_err_num);




       //----------------TEST SHORT-----------------------------------

           printf(" \n writing short......\n");
           for (i=0; i<5; i++) {
           //for (i=0; i<32767; i++) {
               *(short*)(BASE+i*2)=i*i; // short, uses two bytes
               printf("The written character is %d\n",i*i);

           }


           printf(" \n testing short......\n");
           for (i=0; i<5; i++) {
					   if (* (short*)(BASE+i*2)!=(i*i)){
							short_err_num++;
							}
					   printf("The read character is %d\n", (* (short*)(BASE+2*i)));

				   }

//
//
//

            printf("Testing Short: the total numbers of error is : %i\n" ,short_err_num);

       //----------------TEST INT    -----------------------------------
           printf(" \n writing integer......\n");

           for (i=0; i<5; i++) {
               *(int*)(BASE+i*4)=i*i*i; // int, use 4 bytes
               printf("The written character is %d\n",i*i*i);

           }


           printf(" \n testing integer......\n");
           for (i=0; i<5; i++) {
           				   if (* (int*)(BASE+4*i)!=i*i*i){
           						int_err_num++;
           					}
           			   printf("The read character is %d\n", (* (int*)(BASE+4*i)));

           		   }
           printf("Testing Int: the total numbers of error is : %i\n" ,int_err_num);
//
//

  return 0;
}
