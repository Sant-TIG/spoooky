#include <unistd.h>
#include "spooky.h"

int ft_putstr(char *str)
{
    return (write(1, str, ft_strlen(str)));
}
