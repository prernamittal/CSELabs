// not used 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "LA.c"

struct Token retToken;
FILE *fp;

void match();
void Program();
void declarations();
int data_type();
void identifier_list();
void identifier_listprime();
void assign_stat();
void assign_statprime();

void valid()
{
	printf("\n----------SUCCESS!----------\n\n");
	exit(0);
}

void invalid()
{
	printf("\n----------ERROR!----------\n\n");
}

void match()
{
	retToken = getNextToken(fp);
	if (retToken.row == -1)
		return;
	if (strcmp(retToken.token_name, "eof") == 0)
		return;
	printToken(retToken);
}

void Program()
{
	if (strcmp(retToken.token_name, "main") == 0)
	{
		if (strcmp(retToken.token_name, "(") == 0)
		{
				if (strcmp(retToken.token_name, ")") == 0)
			{
						if (strcmp(retToken.token_name, "{") == 0){
							declarations();
							assign_stat();
					if (strcmp(retToken.token_name, "}") == 0)
					{
						valid();
						}
					else
					{
						invalid();
					}
				}
				else
				{
					invalid();
				}
			}
			else
			{
				invalid();
			}
		}
		else
		{
			invalid();
		}
	}
	else
	{
		invalid();
	}
}

void declarations()
{
	if (data_type())
	{
		identifier_list();
		if (strcmp(retToken.token_name, ";") == 0)
		{
				declarations();
		}
		else
		{
			invalid();
		}
	}
}

int data_type()
{
	if (strcmp(retToken.token_name, "int") == 0)
	{
		return 1;
	}
	else if (strcmp(retToken.token_name, "char") == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void identifier_list()
{
	if (strcmp(retToken.token_name, "id") == 0)
	{
		identifier_listprime();
	}
	else
	{
		invalid();
	}
}

void identifier_listprime()
{
	if (strcmp(retToken.token_name, ",") == 0)
	{
		identifier_list();
	}
}

void assign_stat()
{
	if (strcmp(retToken.token_name, "id") == 0)
	{
		if (strcmp(retToken.token_name, "=") == 0)
		{
				assign_statprime();
		}
		else
		{
			invalid();
		}
	}
	else
	{
		invalid();
	}
}

void assign_statprime()
{
	if (strcmp(retToken.token_name, "id") == 0)
	{
		if (strcmp(retToken.token_name, ";") == 0)
		{
			}
		else
		{
			invalid();
		}
	}
	else if (strcmp(retToken.token_name, "num") == 0)
	{
		if (strcmp(retToken.token_name, ";") == 0)
		{
			}
		else
		{
			invalid();
		}
	}
	else
	{
		invalid();
	}
}

int main(int argc, char const *argv[])
{
	fp = fopen("input.c", "r");
	if (fp == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	Program();
	if (strcmp(retToken.token_name, "eof") == 0 || feof(fp))
		valid();
	else
		invalid();
}