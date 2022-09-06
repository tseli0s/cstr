/***********************************************************************************************************
 * cstr is a header-only C99 library for strings. The strings of this library do not touch the stack at all.
 * the aims of this library are to provide a safe and reliable interface to strings.
 * cstr is licensed under the Unlicense. License text follows, see COPYING too.
 * ----------------------------------------------------------------------------
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
*************************************************************************************/

#ifndef __cstr__h__
#define __cstr__h__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Returns the length of the string. */
static size_t cstr_strlen(const char *str)
{
        size_t len = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
                len = i;
        }
        return len;
}

/*
 * Returns a new empty string allocated in the heap.
 * Make sure you call cstr_delete() to avoid memory leaks.
*/
char* cstr_new(void)
{
        char* buffer = (char*) calloc(1, sizeof(char));
        if (!buffer)
        {
                perror("cstr_new");
                return NULL;
        }
        buffer[0] = '\0';
        return buffer;
}

/* Creates a new string with the given parameter. */
char* cstr_new_from_string(const char* string)
{
        char* ptr = (char*) calloc(1, cstr_strlen(string));
        for (int i = 0; i < cstr_strlen(string); i++)
        {
                ptr[i] = string[i];
        }
        return ptr;
}

/*
 * Adds a new string to the existing string.
*/
void cstr_push(char* previous,
               const char* newstr) {
        size_t len    = cstr_strlen(previous);
        size_t newlen = cstr_strlen(newstr);

        char* ptr = (char*) realloc(previous, len + newlen);
        if (!ptr) {
                perror("cstr_push");
                return;
        }

        previous = ptr;
        for (int i = len; i < newlen; i++)
        {
                previous[i] = newstr[i];
        }
}

/*
 * Deletes a string from memory.
*/
void cstr_delete(char* buffer)
{
        assert(buffer != NULL);
        free(buffer);
}


#ifdef __cplusplus
}
#endif

#endif /* __cstr__h__ */