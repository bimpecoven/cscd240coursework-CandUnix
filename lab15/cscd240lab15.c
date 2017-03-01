#include "fileUtil.h"
#include "lab15.h"

int main(int argc, char **argv)
{
   int choice, type;
   FILE * fin = NULL;
   char ** sentence = NULL, **allWords = NULL;

   int articleTotal = 0, nounTotal = 0, verbTotal = 0, prepTotal = 0;
   char ** articles = NULL, **nouns = NULL, **verbs = NULL, **preps = NULL;


   // start of code -- filling the arrays
   fin = openInputFile_Args(argc, argv);

   articleTotal = readTotal(fin);
   articles = createAndFillArray(fin, articleTotal);

   nounTotal  = readTotal(fin);
   nouns = createAndFillArray(fin, nounTotal);

   verbTotal = readTotal(fin);
   verbs = createAndFillArray(fin, verbTotal);

   prepTotal = readTotal(fin);
   preps = createAndFillArray(fin, prepTotal);

   fclose(fin);

   // user making a choice
   do
   {
      choice = menu();

      switch(choice)
      {
         case 1: sentence = generateSentence(articleTotal, articles, nounTotal, nouns, verbTotal, verbs, prepTotal, preps);
                 display(sentence, 5);
                 sentence = clean(5, sentence);
                 break;

         case 2:  displayAllWords(articleTotal, articles, nounTotal, nouns, verbTotal, verbs, prepTotal, preps);
                  break;

         case 3:  type = readType();
                  if(type == 1)
                    articleTotal = addWord(&articles, articleTotal);

                  else if(type == 2)
                    nounTotal = addWord(&nouns, nounTotal);

                  else if(type == 3)
                    verbTotal = addWord(&verbs, verbTotal);

                  else
                    prepTotal = addWord(&preps, prepTotal);

                  break;

         case 4:  allWords = allWordsSorted(articleTotal, articles, nounTotal, nouns, verbTotal, verbs, prepTotal, preps);
                  display(allWords, articleTotal + nounTotal + verbTotal + prepTotal);
                  allWords = clean(articleTotal + nounTotal + verbTotal + prepTotal, allWords);
                  break;

         case 5:  printf("Program Ending\n");

      }// end switch



   }while(choice != 5);


   // giving back the memory
   articles = clean(articleTotal, articles);
   nouns = clean(nounTotal, nouns);
   verbs = clean(verbTotal, verbs);
   preps = clean(prepTotal, preps);

   return 0;
}// end main