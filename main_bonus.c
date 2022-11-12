#include "get_next_line_bonus.h"
#include <stdio.h>
# include <fcntl.h>

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 main_bonus.c get_next_line.c get_next_line_utils.c 
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=0 main_bonus.c get_next_line.c get_next_line_utils.c 
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main_bonus.c get_next_line.c get_next_line_utils.c 
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main_bonus.c get_next_line.c get_next_line_utils.c 
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 main_bonus.c get_next_line.c get_next_line_utils.c 
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 main_bonus.c get_next_line.c get_next_line_utils.c (does not work because the stack is smaller than 10000000 bytes)



int main()
{
    // int fd = open ("aymen.txt" , O_RDONLY);
    printf ("%s", get_next_line(-6546));
}


