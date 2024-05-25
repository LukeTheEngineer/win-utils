/* System libraries */
#include<stdio.h>
#include<windows.h>

/* Local includes */
#include "../common/util.h"

int
main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Error: Insufficient arguments\n");
        printf("Usage: touch filename<.extension>\n");
        return 1;
    }

    /* Iterate over the arguments to create n files.*/
    for (int i = 1; i < argc; i++) {
        HANDLE hFile = CreateFile(argv[i],
                                  GENERIC_READ | GENERIC_WRITE,
                                  0,
                                  NULL,
                                  OPEN_ALWAYS,
                                  FILE_ATTRIBUTE_NORMAL,
                                  NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            printf("Error: Unable to create or open file %s\n", argv[i]);
            return 1;
        }

        FILETIME ft;
        SYSTEMTIME st;
        GetSystemTime(&st);
        SystemTimeToFileTime(&st, &ft);
        SetFileTime(hFile, &ft, &ft, &ft);

        CloseHandle(hFile);
    }

    return 0;
}