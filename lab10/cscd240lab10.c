#include "fileUtil.h"

int main(int argc, char * argv[])
{
    int num = 0;
    char fileName[MAX];
    FILE * fin = NULL, * fout = NULL;


    /* Filename passed in to main */
    fin = openInputFile_Args(argc, argv);
    num = countRecords(fin, 1);
    rewind(fin);
    displayFileContents(num, fin);
    fclose(fin);

    /* filename read from the keyboard*/
    readFileName(fileName);
    fin = openInputFile_String(fileName);
    displayFile_FilePointer(fin);
    fclose(fin);
    
    /* filename read from the keyboard in the FileUtil class*/
    /* output file name sent to the function */
    fin = openInputFile_Prompt();
    readFileName(fileName);
    fout = openOutputFile_FileName(fileName);
    displayFile_FilePointer(fin);
    rewind(fin);
    displayFile_OutputFile(fin, fout);
    fclose(fin);
    fclose(fout);
    
    /* filename read from the keyboard in the FileUtil class*/
    /* output file name read in the function */
    fin = openInputFile_Prompt();
    fout = openOutputFile_Prompt();
    displayFile_OutputFile(fin, fout);
    fclose(fin);
    fclose(fout);

    return 0;
}// end main