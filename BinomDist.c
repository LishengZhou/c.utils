// By: Lisheng Zhou

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*Binomial Distribution Function (probability mass function, not cummulative)*/

#include "BinomDist.h"

//factor function
double fact(int x)
{
 double i;
 double f = 1;
 for (i = x; i > 1; i--)
 {
  f = f * i;
 }
 return f;
} // end of factor function

//Binomial distribution
double binomial(short x, short n, float p)
{
 double pmf = (fact(n)/(fact(x)*fact(n-x)))*pow(p,x)*pow((1-p),(n-x));
 return pmf;
} //end of Binomial distribution
