#include <stdlib.h>
#include <stdio.h>

int main()
{
   int *daffodil = (int *) calloc(1, sizeof(int));
   
   if (daffodil == NULL)
   {
      printf("daffodil died\n");
      exit(-1);
   }// end if
   
   *daffodil = 170;
   
   int *tulip = daffodil;
   int *carnation = (int *) calloc(1, sizeof(int));
   
   if (carnation == NULL)
   {
      printf("caranation died\n");
      exit(-1);
   }// end if
 
   *carnation = 995;
   
   int *lily = (int *)*tulip;
   
   int crocus = 953;
   
   int *zinnia = &crocus;
   
   printf("Registering daffodil: %d.\n", *daffodil);
   printf("Registering tulip: %d.\n", *tulip);
   printf("Registering carnation: %p.\n", carnation);
   printf("Registering lily: %d.\n", *lily);
   printf("Registering crocus: %d.\n", crocus);
   printf("Registering zinnia: %d.\n", *zinnia);
   
   carnation = NULL;
   
   free(daffodil);
   free(tulip);
   free(carnation);
   free(lily);
   free(zinnia);
   
   return 0;
   
 }// end main