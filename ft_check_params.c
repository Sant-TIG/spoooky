#include <stddef.h>
#include "spooky.h"

int ft_check_params(size_t i)
{
    int total;


    total = ((SIZE * SIZE) * 2)  - 1;
    return (i == total);
}