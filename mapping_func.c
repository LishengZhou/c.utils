// By: Lisheng Zhou

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mapping_func.h"

// from number to vector

void map_in(int InNum, int NumLocus, int GenomArray[]){


        int remain = 0;
        int TempIn = InNum;
        int TempGeno = 0;

        for (int i = 0; i < NumLocus-1; i++){
                if ( i != NumLocus-1){

                        remain = TempIn % (int)pow(3, (NumLocus-1-i));
                        TempGeno = (TempIn - remain)/(int)pow(3,(NumLocus-1-i));
                        TempIn = remain;
                }else{
                        TempGeno=remain;
                }
                        GenomArray[i] = TempGeno;
        }
}

int map_out(int GenomArray[], int NumLocus){
        int sum = 0;
        for (int i = 0; i < NumLocus; i++){
                sum += GenomArray[i] * (int)pow(3,i);
        }
        return sum;
}
