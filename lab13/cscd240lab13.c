#include "lab13.h"
#include "fileUtil.h"


int main(int argc, char **argv)
{
    int runs = 0;
    int solution[16];
    int andromida[10][10];
    char outputFile[MAX];  // MAX is 100
    FILE * fin = NULL, *fout = NULL;

    fin = openInputFile_Args(argc, argv);
    readFileName_type(outputFile, "output");  // new function for fileUtil
    fout = openOutputFile_FileName(outputFile);

    runs = readTotal(fin);
    fillSolutionsArray(fin, solution);
    fillAndromida(fin, andromida);
    fclose(fin);

    checkSolutionAndDisplay(runs, solution, andromida, fout);
    fclose(fout);

    return 0;
}