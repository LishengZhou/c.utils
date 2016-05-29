// Created by: Lisheng

// This function will create nested loops with number of levels defined by the user

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "nested_loop.h"


void nestedLoop ( int cvrg, int level, int* array )
{
	if ( level == 0 )
	{
		for ( int i = 0; i <= cvrg; i++ )
		{
			array[level] = i;

		}
	} else {
		for ( int prev_i = 0; prev_i <= cvrg; prev_i++ )
		{
			array[level] = prev_i;
			nestedLoop( cvrg, level-1, array );
		}
	}
}
