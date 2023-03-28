#include <stdio.h>
/*
 * A function called "bits_count" which summarizes and returns the number of bits that are
in even places
 */

int count_bits(unsigned long x);

int  main(){
    unsigned long i = 0;
        printf("\nPlease enter a  number: ");
        scanf("%i",&i);
        printf("\nthe even bits in the number:%i\n is :%d\n",i,count_bits(i));
    }

int count_bits(unsigned long x){

    int count=0;
    int even=0;
    unsigned int mask=1;
    while (mask){/*While loop   mask until mask different from zero */
        if((x&mask)&&(even%2==0)){/*Checks how much the bit is worth and if its a Even number,Then we will count it*/
            count++;
        }
        even++;/*else we will continue to the next Bit*/
        mask=mask<<1;
    }
    return count;/*returns the number of bits that are in even places*/
}
