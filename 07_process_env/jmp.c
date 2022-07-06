#include "apue.h"
#include <setjmp.h>

#define TOK_NO		(0)
#define TOK_YES		(1)
#define TOK_ADD		(5)
#define TOK_CMD_YES	"y"
#define TOK_CMD_NO	"n"
#define TOK_CMD_ADD	"cmd_add"

static void do_line(char *);
static void cmd_add(void);
static int get_token(void);

static jmp_buf jmpbuffer;


int main(void) {


	char line[MAXLINE];
	int jmp_ret;

	if ((jmp_ret = setjmp(jmpbuffer)) != 0)
		if (jmp_ret == 1)
			printf("cmd_add longjmp, cas token < 0\n");
		else if (jmp_ret == 2) {
			// printf("longjmp return value: %d\n", jmp_ret);
		}
	else
		printf("setjmp success\n");

	printf("-> ");
	while (fgets(line, MAXLINE, stdin) != NULL)
		do_line(line);


	exit(0);
}


static char *tok_ptr;

static void do_line(char *line) {

	int cmd;

	tok_ptr = line;

	while ((cmd = get_token()) > 0) {
		
		switch (cmd) {
			case TOK_YES:
			case TOK_NO:
			case TOK_ADD:
				cmd_add();
			break;
			
			default:
			break;	
		}
	}

	printf("-> ");
}

static void cmd_add(void) {

	int token;
	token = get_token();
	if (token < 0)
		longjmp(jmpbuffer, 1);
	else {
	
		if (token == TOK_ADD) {
			printf("cmd add(y/n):");
			longjmp(jmpbuffer, 2);
		}
		else if (token == TOK_YES) {
			printf("cmd add success!\n");
			longjmp(jmpbuffer, 2);
		}
		else if (token == TOK_NO) {
			printf("cmd add cancel!\n");
			longjmp(jmpbuffer, 2);
		}
		else {
			printf("unknown cmd\n");
			printf("-> cmd add(y/n):");
			longjmp(jmpbuffer, 2);
		}
	}
}

static int get_token(void) {
	
	if (strncmp(TOK_CMD_ADD, tok_ptr, strlen(TOK_CMD_ADD)) == 0) {	
		return TOK_ADD;
	}
	else if (strncmp(TOK_CMD_YES, tok_ptr, strlen(TOK_CMD_YES)) == 0) { 
		return TOK_YES;
	}
	else if (strncmp(TOK_CMD_NO, tok_ptr, strlen(TOK_CMD_NO)) == 0) { 
		return TOK_NO;
	}	
	else {
		return -1;
	}
}

