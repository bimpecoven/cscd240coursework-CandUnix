#include "lab21.h"


int main(void)
{
   int choice, num, fromBase, toBase;
   char * converted = NULL, *fromBaseValues = NULL, *toBaseValues = NULL, *diffBaseNum = NULL;
   
   char to[] = {'t', 'o', '\0'};
   char from[] = {'f', 'r', 'o', 'm', '\0'};
   
   char bin[] = {'0', '1', '\0'};
   char oct[] = {'0', '1', '2', '3', '4', '5', '6', '7', '\0'};
   char dec[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
   char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '\0'};
   
   do
   {
         choice = menu();
         
         switch(choice)
         {
            case 1:  num = readNumber(10);
                     converted = convert(num, 10, dec, 2, bin);
                     printResults(num, 10, 2, converted);
                     break;
                     
            case 2:  num = readNumber(10);
                     converted = convert(num, 10, dec, 8, oct);
                     printResults(num, 10, 8, converted);
                     break;
         
            case 3:  num = readNumber(10);
                     converted = convert(num, 10, dec, 16, hex);
                     printResults(num, 10, 16, converted);
                     break;        
                     
            case 4:  fromBase = readBase(from);       
                     fromBaseValues = readBaseValues(from, fromBase);
                     
                     toBase = readBase(to);
                     toBaseValues = readBaseValues(to, toBase); 
                     
                     diffBaseNum = readDiffBaseNumber(fromBase);                     
                     converted = convertDiffBase(diffBaseNum, fromBase, fromBaseValues, toBase, toBaseValues);
                     printDiffBaseResults(diffBaseNum, fromBase, toBase, converted);
                                          
                     free(diffBaseNum);
                     diffBaseNum = NULL;
                     
                     free(fromBaseValues);
                     fromBaseValues = NULL;
                     
                     free(toBaseValues);
                     toBaseValues = NULL;
                     break;
                    
                    
           default:  printf("Thanks for using my silly base converter\n");      
         }// end switch
         
         free(converted);
         converted = NULL;
    
         
      }while(choice != 5);
      
      return 0;
}// end main