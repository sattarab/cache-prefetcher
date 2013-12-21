#include <stdio.h>
int main (int argc, char *argv[ ])
{
	/* compiled using -O0 flag in the ssbig-na-sstrix-gcc mbq2.c -O0 -o mbq2*/
  

  int i, j, k;
  int a[100][100], b[100][100], c[100][100];

  /*   This microbenchmark verifies the stride prefetcher by accessing the addresses in a constant stride. 
       So for this benchmark as the addresses are accessed in a constant stride there will be only 
       compulsory/cold misses if we increase the cache associtivity and number of RPT enteries to 
       decrease conflict misses. In Stride prefetcher the entries that have constant stride are prefetched 
       i.e. address + stride if not already in the cache. L1 Cache used with this benchmark is 16 way with 
       64 sets and 64 bytes block size with lru replacement policy. The num of lines used for the RPT table are 32.
       The associtivity and num of RPT lines are increased to decrease the conflict misses to almost 0 
       to verify the stride prefetcher implementation as the miss rate should be almost 0 as there would be only 
       cold misses.
  */

  /* Initialize the array */
  for (i = 0; i < 100; i++)
  {
    for (j = 0; j < 100; j++)
    {
      c[i][j] = 0;
      a[i][j] = 1;
      b[i][j] = 2;
    }
  }
  
  /* do the computation */
  for (i = 0; i < 100; i++)
  {
    for (j = 0; j < 100; j++)
    {
      for (k = 0; k < 100; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return 0;
}
