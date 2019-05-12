/**
 * @file astring.c
 * @author majinbuaa@163.com
 * @time 2019/04/30 10:00
 * @brief 
 *
**/

#include <stdlib.h>
#include <string.h>
#include "astring.h"

char * get_maximum_substring_common(const char *strA, const char *strB)
{
    int maxCount = 0;
    int count_temp = 0;
    int startIndex = 0;
    int strA_Length = 0;
    int strB_Length = 0;
    int i = 0, j = 0;

    if (!strA || !strB) {
        return NULL;
    }

    strA_Length = strlen(strA);
    strB_Length = strlen(strB);
    if ((0 == strA_Length) || (0 == strB_Length)) {
        return NULL;
    }

    for (i = 0; i < strA_Length; i++) {
        for (j = 0; j < strB_Length; j++) {
            int startA = i;
            int startB = j;
            while ((startA < strA_Length) && (startB < strB_Length) && (strA[startA++] == strB[startB++])) {
                count_temp++;
            }
            // Record max count and start index in strA.
            if (count_temp > maxCount) {
                maxCount = count_temp;
                startIndex = i;
            }

            count_temp = 0;
        }
    }

    char *strTemp = NULL;
    if (maxCount > 0) {
        strTemp = (char *)malloc(maxCount + 1);
        memcpy(strTemp, strA + startIndex, maxCount);
        strTemp[maxCount] = '\0';
    }
    return strTemp;
}
