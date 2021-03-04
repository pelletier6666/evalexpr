#include "help_message.h"

void help_message(void)
{
    printf( "Usage: evalexpr [OPTION]\n" 
        "Options:\n"
        "  -h: prints this message\n"
        "  -l: prints the lexers output\n"
        "  -p <prefix|infix|suffix>: prints the ast traversal in the demanded order\n"
        "  -b <base>: changes the base\n"
        "  -o <opr>: changes the operators, has to be exactly 8 chars\n"
        );
}
