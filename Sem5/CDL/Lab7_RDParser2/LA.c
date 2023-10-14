#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row = 1, column = 1;
int symboltableindex = -1;
int lexemeindex = 0;
char buff[80];
char dbuf[80] = "int";

struct Token{
	char *token_name;
	int index;
	int row, col; 
	char *type;
};

struct Node{
	char lexeme[20];
	int size;
	char type[50];
} symboltable[10][100];

char symboltablename[10][100];
int symboltablesize[10];

const char *keywords[] = {"int", "return", "for", "while", "do", "else", "case", "break",
"unsigned","const"};
const char *dataTypes[] = {"int", "char", "void", "float", "bool"};
const char specialsymbols[] = {'?', ';', ':', ','};

int isKeyword(char *id){
	for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++){
		if (strcmp(id, keywords[i]) == 0)
			return 1;
	}
	return 0;
}

int isDataType(char *id){
	for (int i = 0; i < sizeof(dataTypes) / sizeof(char *); i++){
		if (strcmp(id, dataTypes[i]) == 0)
			return 1;
	}
	return 0;
}

int isspecialSymbol(char id){
	for (int i = 0; i < sizeof(specialsymbols) / sizeof(char); i++){
		if (id == specialsymbols[i])
			return 1;
	}
	return 0;
}

int isAlpha(char in){
	if ((in >= (int)('A') && in <= (int)('Z')) || (in >= (int)('a') && in <= (int)('z')))
		return 1;
	return 0;
}

int isDigit(char in){
	if ((in >= (int)('0') && in <= (int)('9')))
		return 1;
	return 0;
}

void printToken(struct Token tk){
	printf("< %s , %d , %d >\n", tk.token_name, tk.row, tk.col);
}

void fillToken(struct Token *tok, char *token_name, int row, int column){
	tok->token_name = token_name;
	tok->row = row;
	tok->col = column;
}

struct Token getNextToken(FILE *fp){
	int k = 0;
	char c = fgetc(fp);
	struct Token tok;
	while (c != EOF){
	
		if (c == '#'){
			buff[0] = '\0';
			int k = 0;
			c = fgetc(fp);

			while (isAlpha(c)){
				buff[k++] = c;
				c = fgetc(fp);
			}
			fseek(fp, -1, SEEK_CUR);
			buff[k] = '\0';

			if (strcmp(buff, "include") == 0 || strcmp(buff, "define") == 0){
				c = fgetc(fp);
				while (c != '\n')
					c = fgetc(fp);
				row++;
				column = 0;
				c = fgetc(fp);
				continue;
			}
			fillToken(&tok, "#", row, column);
			column++;
			return tok;
		}
		if (c == '/'){
			c = fgetc(fp);
			int k = 0;
			column++;
			if (c == '/'){
				while (c != '\n')
					c = fgetc(fp);
				row++;
				column = 0;
				c = fgetc(fp);
				continue;
			}
			else if (c == '*'){
				do{
					while (c != '*'){
						if (c == '\n'){
							row++;
							column = 0;
						}
						else{
							column++;
						}
						c = fgetc(fp);
					}
					if (c == '\n'){
						row++;
						column = 0;
					}
					else
						column++;
					c = fgetc(fp);
				} while (c != '/');
			}
		}
		buff[0] = '\0';
		if (c == '='){
			c = fgetc(fp);
			if (c == '='){
				fillToken(&tok, "==", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "=", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '<'){
			c = fgetc(fp);
			if (c == '='){
				fillToken(&tok, "<=", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "<", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '>'){
			c = fgetc(fp);
			if (c == '='){
				fillToken(&tok, ">=", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, ">", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '!'){
			c = fgetc(fp);
			if (c == '='){
				fillToken(&tok, "!=", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "!", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '&'){
			c = fgetc(fp);
			if (c == '&'){
				fillToken(&tok, "&&", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "&", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '|'){
			c = fgetc(fp);
			if (c == '|'){
				fillToken(&tok, "||", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "|", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (isspecialSymbol(c)){
			buff[0] = c;
			buff[1] = '\0';
			fillToken(&tok, buff, row, column);
			column++;
			if (buff[0] == ';')
				strcpy(dbuf, "int");
			return tok;
		}
		else if (c == '+'){
			c = fgetc(fp);
			if (c == '+'){
				fillToken(&tok, "++", row, column);
				column += 2;
			}
			else if (c == '='){
				fillToken(&tok, "+=", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "+", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '-'){
			c = fgetc(fp);
			if (c == '-'){
				fillToken(&tok, "--", row, column);
				column += 2;
			}
			else if (c == '='){
				fillToken(&tok, "-=", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "-", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '*'){
			c = fgetc(fp);
			if (c == '='){
				fillToken(&tok, "*=", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "*", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (c == '/'){
			c = fgetc(fp);
			if (c == '='){
				fillToken(&tok, "=/", row, column);
				column += 2;
			}
			else{
				fillToken(&tok, "/", row, column);
				column++;
				fseek(fp, -1, SEEK_CUR);
			}
			return tok;
		}
		else if (isAlpha(c)){
			int k = 0;
			do{
				buff[k++] = c;
				c = fgetc(fp);
			} while (isAlpha(c) || isDigit(c) || c == '_');
			fseek(fp, -1, SEEK_CUR);
			buff[k] = '\0';
			if (isKeyword(buff)){
				fillToken(&tok, buff, row, column);
				if (isDataType(buff)){
					strcpy(dbuf, buff);
				}
			}
			else{
				fillToken(&tok, "id", row, column);
			}
			column += k;
			return tok;
		}
		else if (c == '\"'){
			int k = 0;
			buff[k++] = c;
			do{
				c = getc(fp);
				buff[k++] = c;
			} while ((char)c != '\"');
			buff[k] = '\0';
			fillToken(&tok, buff, row, column);
			column += k;
			return tok;
		}
		else if (isDigit(c)){
			int k = 0;
			do{
				buff[k++] = c;
				c = getc(fp);
			} while (isDigit(c));
			buff[k] = '\0';
			fillToken(&tok, "num", row, column);
			fseek(fp, -1, SEEK_CUR);
			column += k;
			return tok;
		}
		else{
			if (c != '\n')
				column++;
			else{
				row++;
				column = 1;
			}
		}
		c = fgetc(fp);
	}
	tok.row = -1;
	return tok;
}

