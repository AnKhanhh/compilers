#include <stdio.h>
#include "parser/parser_stack.c"

#define INPUT_FILE_PATH "C:/Users/admin/CLionProjects/comp/input/input1.txt"
#define LEXER_FILE_PATH "C:/Users/admin/CLionProjects/comp/output/l_output1.txt"
#define PARSER_FILE_PATH "C:/Users/admin/CLionProjects/comp/output/p_output1.txt"

int main() {
	FILE *f_in, *f_lexer, *f_parser;
	if (( f_in = fopen(INPUT_FILE_PATH, "r")) == NULL) { perror("input file"); }
	else if (( f_lexer = fopen(LEXER_FILE_PATH, "r+")) == NULL) { perror("lexer file"); }
	else if (( f_parser = fopen(PARSER_FILE_PATH, "r+")) == NULL) { perror("parser file"); }
	else {
		lexical_analysis(f_in, f_lexer);
		syntax_analysis(f_lexer,f_parser);

		fclose(f_in);
		fclose(f_lexer);
		return 0;
	}
	return 1;
}
