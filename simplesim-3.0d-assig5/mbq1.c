#include <stdio.h>
int main (int argc, char *argv[ ])
{
	/* compiled using -O0 flag in the ssbig-na-sstrix-gcc mbq1.c -O0 -o mbq1*/
  
  int i;

	int Q[10000]; 

	while (i < 10000)
	{
    /* This microbenchmark verifies the next line prefetcher by accessing the array Q
       lineraly. In this benchmark as the array is accessed there will be only compulsory/cold
       misses if increase cache set associtvity.In the Next Line Prefetcher whenever there 
       is a miss on an address the next cache block request is generated if it is not already 
       in the list. L1 Cache used with this benchmark is 16 way with 64 sets and 64 bytes block 
       size with lru replacement policy.The associtivity is increased so there are no conflict 
       misses only the initial compulsory/cold misses.
    */
	  Q[i] = i;
	  i++;
	}

  return 0;
}

