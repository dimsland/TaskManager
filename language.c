#include <stdio.h>
#include "language.h"

Language select_language(const char *path)
{
    Language lang;

    FILE *file = fopen(path, "r");

    for (int i = 0; i < lang.menu_height; i++)
    {
        int j = 0;
        for(;(lang.menu[i][j] = fgetc(file)) != '\n';j++);
        lang.menu[i][j] = '\0';    
    }
}