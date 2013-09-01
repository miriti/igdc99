#include "CLog.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void CLog::trace(char* message)
{
    FILE * f = fopen("log.txt", "wb");
    fwrite(message, sizeof(char), sizeof(message), f);
    fclose(f);

    cout << message << endl;
}
