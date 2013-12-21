#include <stdio.h>
int main (int argc, char *argv[ ])
{
	/* compiled using -O0 flag in the ssbig-na-sstrix-gcc mbq6.c -O0 -o mbq6*/
  

  int i, j, k;
  int a[100][100], b[100][100], c[100][100], d[100][100];

  /*   This microbenchmark verifies the open ended prefetcher by accessing the addresses in a common delta pattern. 
       So for this benchmark as the addresses are accessed in a two different constant delta pattern there will 
       be only compulsory/cold misses.In the open ended prefetcher the most common delta for that PC is selected 
       so the address fetched into the cache is address + common_delta(if not already in the cache). The delta table 
       for each enrty in the history tabe is a fifo table with the history table being the direct mapped table. 
       The L1 Cache used with this benchmark is 16 way with 64 sets and 64 bytes block size with lru replacement 
       policy. The associtivity is increased to decrease the conflict misses to almost 0 to verify the open ended 
       prefetcher implementation.
  */

  /* Initialize the array */
  for (i = 0; i < 100; i++)
  {
    for (j = 0; j < 100; j++)
    {
      c[i][j] = 0;
      a[i][j] = 1;
      b[i][j] = 2;
      d[i][j] = 10;
    }
  }
  
  /* do the computation */
  for (i = 0; i < 25; i++)
  {
    for (j = 0; j < 25; j++)
    {
      for (k = 0; k < 25; k++)
      {
        /* this benchmark should have a dl1 miss rate of about 0.000 for open ended prefetcher
            but will have a worse dl1 miss rate for dl2 although there would be constant strides here*/ 
        if (i % 4 == 0) 
        {
           c[i*4][j] += (a[i*4][k] * b[k*4][j]) + d[i*4][j]; /* constant delta 2 */
        }
        else
        {
           c[i][j] += (a[i][k] * b[k][j]) + d[i][j];/* constant delta 1*/
        }
      }
    }
  }

  return 0;
}
