/**
 * @file main.c
 * @author majinbuaa@163.com
 * @time 2019/04/30 10:00
 * @brief 
 *
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "astring.h"

#define MAX_LEGTH_STR 1024

int main(int argc, char *argv[])
{
    char strA[MAX_LEGTH_STR] = {0};
    char strB[MAX_LEGTH_STR] = {0};
    printf("Input string A(length < 1024): ");
    gets(strA);
    // scanf("%s", strA);
    printf("Input string B(length < 1024): ");
    gets(strB);
    // scanf("%s", strB);

    printf("Your inpsut strings:\nstrA: %s\nstrB: %s\n", strA, strB);

    char *str_ret = get_maximum_substring_common(strA, strB);
    if (!str_ret) {
        printf("Not match, no maximum sub string.\n");
    }
    else {
        printf("Maximum sub string: %s\n", str_ret);
        free(str_ret);
        str_ret = NULL;
    }
    
    return 0;
}
