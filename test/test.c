#include <limits.h>
#include <stdio.h>
#include "../main.h"

void generate_string(int byte_len, char *buffer)
{
	int index = 0;

	for (; index < byte_len; index++)
	{
		if (index == byte_len - 1)
		{
			buffer[index] = 'z';
			continue;
		}
		buffer[index] = 'a';
	}
	buffer[byte_len] = '\0';
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;
	char long_str[5014];

	char *str = "When you invoke GCC , it normally does preprocessing, compilation, assembly and linking. The \"overall options\" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler.\n\nOther options are passed on to one stage of processing. Some options control the preprocessor and others the compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them.\n\nMost of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C ++ ), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages.\n\nThe gcc program accepts options and file names as operands. Many options have multi-letter names; therefore multiple single-letter options may not be grouped: -dv is very different from -d -v.\n\nYou can mix options and other arguments. For the most part, the order you use doesn't matter. Order does matter when you use several options of the same kind; for example, if you specify -L more than once, the directories are searched in the order specified. Also, the placement of the -l option is significant.\n\nMany options have long names starting with -f or with -W---for example, -fmove-loop-invariants, -Wformat and so on. Most of these have both positive and negative forms; the negative form of -ffoo would be -fno-foo. This manual documents only one of these two forms, whichever one is not the default.\n";
	char *str2 = "When you invoke GCC , it normally does preprocessing, compilation, assembly and linking. The \"overall options\" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler.\n\nOther options are passed on to one stage of processing. Some options control the preprocessor and others the compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them.\n\nMost of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C ++ ), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages.\n\nThe gcc program accepts options and file names as operands. Many options have multi-letter names; therefore multiple single-letter options may not be grouped:\n";
	/* correct input long str */
	generate_string(5014, long_str);
	_printf("Testing Alx long string S: \n");
	len = _printf(str);
	len2 = printf(str);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2, str2[0]);
	/* correct input long str */
	_printf("Testing Alx long string as arg S: \n");
	len = _printf("%s", str);
	len2 = printf("%s", str);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2, str2[0]);
	/* correct input long str */
	/* _printf("Testing Correct Input long str 5014: \n");
	len = _printf("long str 5014:[%s]\n", long_str);
	len2 = printf("long str 5014:[%s]\n", long_str);
	printf("Length my printf: %d, Length orig printf: %d\n", len, len2); */
	/* correct input capital S */
	/* _printf("Testing Correct Input capital S: \n");
	len = _printf("String:[%S]\n", "New line: \n Tab: \t backspace: \b return: \r");
	printf("Length my printf: %d\n", len); */
	/* correct input len S */
	/* _printf("Testing length, should be 14?:\n");
	len = _printf("%S\n", "New line:\n");
	printf("Length my printf: %d\n", len); */
	return (0);
}
