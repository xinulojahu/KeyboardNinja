#include "ctest.h"
#include "language.h"
#include "menu.h"
#include "practice.h"
#include "texts.h"
#include "wchar.h"
#include <stdio.h>

CTEST(language, openfile_incorrect)
{
    int expected = -1;
    FILE* test = openfile("texts.t", "r");
    int result;
    if (test == NULL) {
        result = -1;
    } else {
        fclose(test);
        result = 0;
    }
    ASSERT_EQUAL(expected, result);
}

CTEST(menu, isnumber_correct)
{
    int expected = 0;
    int result = isnumber("1231");
    ASSERT_EQUAL(expected, result);
}

CTEST(menu, isnumber_incorrect)
{
    int expected = -1;
    int result = isnumber("123a1");
    ASSERT_EQUAL(expected, result);
}

CTEST(practice, char_to_int)
{
    int expected = 123;
    int result = char_to_int("123|12", '|');
    ASSERT_EQUAL(expected, result);
}

CTEST(texts, texts_end_currect)
{
    int expected = 1;
    wchar_t temp[4];
    temp[0] = temp[1] = '&';
    int result = texts_end(temp);
    ASSERT_EQUAL(expected, result);
}

CTEST(texts, texts_end_incurrect)
{
    int expected = 0;
    wchar_t temp[4];
    temp[0] = temp[1] = 'l';
    int result = texts_end(temp);
    ASSERT_EQUAL(expected, result);
}
