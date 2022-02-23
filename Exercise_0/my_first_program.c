/* my first program in C */

#include <stdio.h>

int main() {
   int number;
 
   printf("Enter an integer:  >> ");
   scanf("%d", &number);

   printf("Your input was %d.\n", number);

   if (number > 0 && number % 2 == 0) {
      printf("Your input was valid.\n");
   } else {
      printf("Your input was not valid.\n");
   }

   return 0;
}
