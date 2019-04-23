#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

   if (argc < 3) {
      printf("Usage: %s <Array Size> <find> <?start> \n", argv[0]);
      return 0;
   }

   const int find = atoi(argv[2]);

   const int start = argc == 4 ? atoi(argv[3]) : 0;

   const int array_size = atoi(argv[1]);

   int values[array_size];

   // make ordered list of numbers.
   for (int i = 0; i < array_size; i++) values[i] = i + start;

   // -- the actual program starts here. --

   const int arrLength = sizeof(values) / sizeof(values[0]);

   int lowBound = 0;
   int upBound  = arrLength - 1;

   int iterations = 0;

   while (lowBound <= upBound) {
      iterations += 1;

      const int mid = (lowBound + upBound) / 2;

      if (values[mid] > find) {
         upBound = mid - 1;
      } else if (values[mid] < find) {
         lowBound = mid + 1;
      } else {
         printf("Found at index %d\n", mid);
         printf("Found in %d iterations\n", iterations);

         // end program if number found.
         return 0;
      }

   }

   // display error if number not found.
   printf("Number not found.\n");

   return 0;
}