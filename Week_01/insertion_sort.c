/*
 * Insertion sort
 */

#include <assert.h> /* assert */
#include "insertion_sort_array.h"

void swap(int a, int b, int* x, int n)
{
  /* pre-condition */
  /* a and b are within bounds of x array */
  assert (0 <= a && a < n &&
          0 <= b && b < n);

  /* post-condition */
  int t; /* temporary variable for swapping */
  t = x[a];
  x[a] = x[b];
  x[b] = t;
}

void isort(int n, int* x)
{
   int i;  /* counter variable */
   int j;  /* counter variable */

   /* pre-condition */
   assert (0 <= n);

   /* post-condition: x[0..n] is sorted */
   for(i = 1; i < n; i = i + 1)
   {
     /* invariant: x[0..i-1] is sorted */
     j = i;
       /* insert next element j into
        * ordered position
        */
     for(; j > 0; j = j - 1)
     {
       if(x[j] > x[j-1])
         break; /* jth element is in correct position */
       else
         swap(j, j-1, x, n);
     }
   }
}
