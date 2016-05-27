// By: Lisheng Zhou

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mapping_func.h"

// This function will convert a number into a multi-locus genotype array (coded by 0, 1, 2 for each locus) according to the number of loci
// base 10 (number) to base 3 (vector)
// Genotype code:
// 0 - homozygous with 2 common alleles
// 1 - heterozygous with 1 common allele and 1 rare allele
// 2 - homozygous with 2 rare alleles

void map_in(int InNum, int NumLocus, int GenomArray[]){
        // InNum - number you want to convert
        // NumLocus - number of loci
        // GenomArray[] - output array of the multi-locus genotype

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

// This function will convert a multi-locus genotype array (coded by 0, 1, 2 for each locus) into a number according to the number of loci
// base 3 (vector) to base 10 (number)
int map_out(int GenomArray[], int NumLocus){
        int sum = 0;
        for (int i = 0; i < NumLocus; i++){
                sum += GenomArray[i] * (int)pow(3,i);
        }
        return sum;
}

// Example
//int main(){
//      int OutNum;
//      int n = 3;
//      int *p;
//      p = (int*)malloc(sizeof(int)*n);
//      p[0] = 3;
//      p[1] = 3;
//      p[2] = 3;
//      OutNum = map_out(p, n);
//      printf("%i\n", OutNum);
//      free(p);
//      return 0;
//}

