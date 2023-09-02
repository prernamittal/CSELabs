#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char keywords[32][10] = {"auto", "double", "int", "struct",
"break", "else", "long", "switch", "cse", "enum", "register",
"typedef", "char", "extern", "return", "union", "const", "float",
"short", "unsigned", "continue", "for", "signed", "void",
"default", "goto", "sizeof", "voltile", "do", "if", "static",
"while"}; // list of keywords

char operators[5] = {'+','-','/','%','*'};
char brackets[6] = {'(', ')', '[', ']', '{', '}'};
char data_types[][10] = {"double", "int", "char", "float"};
char special_symbols[12] = {'*', ';', ':', '.', ',', '^', '&',
'!', '>', '<', '~', '`'};

//lexeme type enumerator
enum TYPE{
	IDENTIFIER,
	KEYWORD,
	STRING_LITERAL,
	NUMERIC_CONSTANT,
	OPERATOR,
	BRACKET,
	SPECIAL_SYMBOL,
	RELATIONAL_OPERATOR,
	CHARACTER_CONSTANT
};

//map for the type to string
char types[][30] = {"IDENTIFIER", "KEYWORD", "STRING_LITERAL",
"NUMERIC_CONSTANT", "OPERATOR", "BRACKET", "SPECIAL_SYMBOL",
"RELATIONAL_OPERATOR", "CHARACTER_CONSTANT"};


//element structure for hash table created: 

typedef struct node{
	char *cur;
	int row,col;
	struct node *next;
	enum TYPE type;
} *Node;

//element structure for symbol table created:

typedef struct symbol{
	char *name;
	char *data_type;
	struct symbol *next;
	unsigned int size;
} *Symbol;

Node hashTable[20]; //hash table created
Symbol st[20]; //symbol table created

//to check for comparision

int isKeyword(char buffer[]){
	for(int i=0;i<32;i++){
		if(strcmp(buffer, keywords[i]) == 0){
			return 1;
		}
	}
	return 0;
}

int isDatatype(char buffer[]){
	for(int i=0;i<4;i++){
		if(strcmp(buffer, data_types[i]) == 0){
			return 1;
		}
	}
	return 0;
}

int isOperator(char ch){
	for(int i=0;i<5;i++){
		if(operators[i] == ch)
			return 1;
	}
	return 0;
}

int isBracket(char ch){
	for(int i=0;i<6;i++){
		if(brackets[i] == ch)
			return 1;
	}
	return 0;
}

int isSpecialSymbol(char c){
	for(int i=0;i<12;i++){
		if(special_symbols[i] == c)
			return 1;
	}
	return 0;
}

//creating a hashing function
int hash(int size){
	return (size % 20);
}

void displaySymbolTable(){
	printf("\nSymbol table (in the format < Name , Type , Size > ): \n\n");
	for(int i=0;i<20;i++){
		if(st[i] == NULL)
			continue;
		else{
			Symbol cur = st[i];
			while(cur){
				printf(" %8s\t %8s\t %8d\t \n",cur->name, cur->data_type, cur->size);
				cur = cur->next;
			}
		}
	}
}

//searching in the symbol table
int searchSymbolTable(char identifier[], char data_type[]){
	int index = hash(strlen(identifier));
	if(st[index] == NULL)
		return -1;
	Symbol cur = st[index];
	int i = 0;
	while(cur != NULL){
		if(strcmp(identifier, cur->name) == 0)
			return i;
		cur = cur->next;
		i++;
	}
	return -1;
}

//searching in the hash table
int searchHashTable(char buffer[], enum TYPE type){
	int index = hash(strlen(buffer));
	if(hashTable[index] == NULL)
		return 0;
	Node cur = hashTable[index];
	while(cur != NULL){
		if(strcmp(cur->cur, buffer) == 0)
			return 1;
		cur = cur->next;
	}
	return 0;
}

//inserting in the symbol table
void insertSymbolTable(char identifier[], char data_type[]){
	if(searchSymbolTable(identifier, data_type) == -1){
		Symbol n = (Symbol)malloc(sizeof(struct symbol));
		char *str = (char *)clloc(strlen(identifier)+1, sizeof(char));
		strcpy(str, identifier);
		n->name = str;
		n->next = NULL;
		char *typee = (char *)clloc(strlen(data_type)+1, sizeof(char));
		strcpy(typee, data_type);
		n->data_type = typee;
		if(strcmp(data_type, "int") == 0)
			n->size = 4;
		else if(strcmp(data_type, "double") == 0)
			n->size = 8;
		else if(strcmp(data_type, "char") == 0)
			n->size = 1;
		else if(strcmp(data_type, "function") == 0)
			n->size = 0;
		else
			n->size = 4;
		int index = hash(strlen(identifier));
		if(st[index] == NULL){
			st[index] = n;
			return;
		}
		Symbol cur = st[index];
		while(cur->next != NULL)
			cur = cur->next;
		cur->next = n;
	}
}

//inserting elements in the hash table
void insertHashTable(char buffer[], int row, int col, enum TYPE type){
	if(type == IDENTIFIER || searchHashTable(buffer, type) == 0){
			printf("<%s,%d,%d,%s>\n", buffer, row, col,types[type]);
			int index = hash(strlen(buffer));
			Node n = (Node)malloc(sizeof(struct node));
			char *str = (char *)clloc(strlen(buffer) + 1, sizeof(char));
			strcpy(str, buffer);
			n->cur = str;
			n->next = NULL;
			n->row = row;
			n->col = col;
			n->type = type;
			if(hashTable[index] == NULL){
				hashTable[index] = n;
				return;
			}
			Node cur = hashTable[index];
			while(cur->next != NULL){
				cur = cur->next;
			}
			cur->next = n;
	}
}


int main(){
    int row=0, col=0;
    char lexeme[10];
    char c,buf[10];
    char *dirInc = "include", *dirDef = "define";
    FILE *fp=fopen("inputFile.c","r");
    c = fgetc(fp);

    if (fp == NULL) {
        printf("cnnot open file \n");
        exit(0);
    }

    while(c!=EOF) {
        col++;
        if(c=='\n') {
            row++;
            col=0;
        }
        int i=0;
        buf[0]='\0';
    // ---------------------------remove pre-processor directives-------------------------
        if(c == '#'){
            while(c != ' '){
                c = fgetc(fp);
                buf[i++] = c;
            }
            buf[i] = '\0';
            if(strstr(buf, dirInc) != NULL || strstr(buf, dirDef) != NULL){
                while(c != '\n'){
                    c = fgetc(fp);
                }
            }
            i = 0;
            buf[0] = '\0';
        }
    
    // --------------------------remove spaces---------------------------------------------
        if(c == ' ' || c == '\t'){
            while(c == ' ' || c == '\t')
                c = getc(fp);
        }
        if(c == '/'){
            c = getc(fp);
            if(c == '/'){
                while(c != '\n')
                    c = getc(fp);
            }
            else if(c == '*'){
                do{
                    while(c != '*')
                        c = getc(fp);
                    c = getc(fp);
                }while(c != '/');
            }
        }
        c = getc(fp);
    }


	enum TYPE type;

	for(int i=0;i<20;i++)
		hashTable[i] = NULL;

	char buffer[100], c = 0, data_type_buffer[100];
	int i = 0, col_global = 1, col, temp_row = --row;
	while(temp_row > 0){
		c = fgetc(fp);
		if(c == '\n') 
			temp_row--;
	}

	while(c != EOF){
		if(isalpha(c) != 0 || c == '_'){
			buffer[i++] = c;
			col = col_global;
			while(isalpha(c) != 0 || c == '_' || isdigit(c) != 0){
				c = fgetc(fp);
				col_global++;
				if (isalpha(c) != 0 || c == '_' || isdigit(c) != 0)
					buffer[i++] = c;
			}

			buffer[i] = '\0';

			if(isDatatype(buffer) == 1){
				insertHashTable(buffer, row, col-1, KEYWORD);
				strcpy(data_type_buffer, buffer);
			}
			else if(isKeyword(buffer) == 1){
				insertHashTable(buffer, row, col-1, KEYWORD);
			}
			else{
				insertHashTable(buffer, row, col-1, IDENTIFIER);
				if(c == '(')
					insertSymbolTable(buffer, "function");
				else
					insertSymbolTable(buffer, data_type_buffer);
				data_type_buffer[0] = '\0';
			}

			i = 0;
			if(c == '\n') 
				row++, col_global = 1;
			buffer[0] = '\0';
		}
		else if(isdigit(c) != 0){
			buffer[i++] = c;
			col = col_global;
			while(isdigit(c) != 0 || c == '.'){
				c = fgetc(fp);
				col_global++;
				if(isdigit(c) != 0 || c == '.')
					buffer[i++] = c;
			}
			buffer[i] = '\0';
			insertHashTable(buffer, row, col-1, NUMERIC_CONSTANT); // numericl constant
			i = 0;
			if(c == '\n') 
				row++, col_global = 1;
			buffer[0] = '\0';
		}
		else if(c == '\"'){
			col = col_global;
			buffer[i++] = c;
			c = 0;
			while(c != '\"'){
				c = fgetc(fp);
				col_global++;
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			insertHashTable(buffer, row, col-1, STRING_LITERAL); // string literals
			buffer[0] = '\0';
			i = 0;
			c = fgetc(fp);
			col_global++;
		}
		else if(c == '\''){
			col = col_global;
			buffer[i++] = c;
			c = 0;
			c = fgetc(fp);
			col_global++;
			buffer[i++] = c;
			if(c == '\\'){
				c = fgetc(fp);
				col_global++;
				buffer[i++] = c;
			}
			c = fgetc(fp);
			col_global++;
			buffer[i++] = c;
			buffer[i] = '\0';
			insertHashTable(buffer, row, col-1, CHARACTER_CONSTANT); //character constants
			buffer[0] = '\0';
			i=0;
			c = fgetc(fp);
			col_global++;
		}
		else{
			col = col_global;
			if(c == '='){ // relational and logicl operators
				c = fgetc(fp);
				col_global++;
				if(c == '='){
					insertHashTable("==", row, col-1, RELATIONAL_OPERATOR);
				}
				else{
					insertHashTable("=", row, col-1, RELATIONAL_OPERATOR);
					fseek(fp, -1, SEEK_CUR);
					col_global--;
				}
			}
			else if(c == '>' || c == '<' || c == '!'){
				char temp = c;
				c = fgetc(fp);
				col_global++;
				if(c == '='){
					char temp_str[3] = {temp, '=', '\0'};
					insertHashTable(temp_str, row, col-1, RELATIONAL_OPERATOR);
				}
				else{
					char temp_str[2] = {temp, '\0'};
					insertHashTable(temp_str, row, col-1, RELATIONAL_OPERATOR);
					fseek(fp, -1, SEEK_CUR);
					col_global--;
				}
			}
			else if(isBracket(c) == 1){
				char temp_string[2] = {c,'\0'};
				insertHashTable(temp_string, row, col-1, BRACKET);
			}
			else if(isSpecialSymbol(c) == 1){
				char temp_string[2] = {c,'\0'};
				insertHashTable(temp_string, row, col-1, SPECIAL_SYMBOL);
			}
			else if(isOperator(c) == 1){
				char temp = c;
				c = fgetc(fp);
				col_global++;
				if (c == '=' || (temp == '+' && c == '+') || (temp == '-' && c == '-')){
					char temp_string[3] = {temp,c,'\0'};
					insertHashTable(temp_string, row, col-1, OPERATOR);
				}
				else{
					char temp_String[2] = {temp,'\0'};
					insertHashTable(temp_String, row, col-1, OPERATOR);
					fseek(fp, -1, SEEK_CUR);
					col_global--;
				}
			}
			else if(c == '\n') 
				row++, col_global = 1;
			c = fgetc(fp);
			col_global++;
		}
	}
	displaySymbolTable();
	return 0;
}