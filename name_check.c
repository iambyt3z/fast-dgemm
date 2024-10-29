#include <stdbool.h>

void name_check(char *func_name)
{
    bool valid_name = false;
    valid_name|=(strcmp("dgemm",func_name)==0);
    valid_name|=(strcmp("dgemm_opt",func_name)==0);

    if (!valid_name)
    {
        printf("Invalid function name\n");
        exit(0);
    }
}