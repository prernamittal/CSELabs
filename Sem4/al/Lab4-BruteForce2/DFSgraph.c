#include <stdio.h>
#include <stdlib.h>

int isEmpty(int top){
	if (top == -1)
		return 1;
	return 0;
}
int isFull(int top, int size){
	if (top == size - 1)
		return 1;
	return 0;
}
void push(int **stack, int *top, int *size, int key){
	if (isFull(*top, *size)){
		*stack = (int *)realloc(*stack,sizeof(int)*(*size)*2);
		*size *= 2;
	}
	(*top)++;
	(*stack)[*top] = key;
}
int pop(int **stack, int *top){
	int temp = (*stack)[*top];
	(*top)--;
	return temp;
}
void display(int *stack, int top){
    printf("stack : ");
    for (int i = 0; i <= top; i++)
        printf("%d ", *(stack + i));
    printf("\n");
}
void addEdge(int **matrix, int first, int second){
	matrix[first][second] = 1;
	matrix[second][first] = 1;
}
void disp(int **matrix, int n){
    printf("\nThe adjacency matrix is:\n");
	for (int i = -1; i < n; i++){
		if (i != -1)
			printf("%d -> ", i);
		for (int j = 0; j < n; j++){
			if (i == -1){
				if (j == 0)
					printf("\t");
				printf("%d\t", j);
				continue;
			}
			if (j == 0)
				printf("\t");
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}
void DFS(int **matrix, int num, int **stack, int *top, int *size){
	int *visited = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++){
		visited[i] = 0;
	}
	char result[20],popped[20];
	int resindex = 0,popindex = 0;
	push(stack, top, size, 0);
	printf("\npushed : %d\n", 0);
	char p = (char)('0' + 0);
	result[resindex++] = p;
	display(*stack, *top);
	visited[0] = 1;
	int cur = *stack[*top];
	int flag, ele;
	while (1){
		if(!(isEmpty(*top))){
			flag = 0;
			for (int i = 0; i < num; i++){
				if (visited[i] == 0 && matrix[cur][i] == 1){
					visited[i] = 1;
					printf("\npushed : %d\n", i);
					p = (char)('0' + i);
					result[resindex++] = p;
					push(stack, top, size, i);
					display(*stack, *top);
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				ele = pop(stack, top);
				p = (char)('0' + ele);
				popped[popindex++] = p;
				printf("\npopped : %d\n", ele);
				display(*stack, *top);
			}
			cur = (*stack)[*top];
		}
		else{
			flag = 1;
			for (int i = 0; i < num && flag; i++){
				if(visited[i]==0){
					visited[i] = 1;
					printf("\npushed : %d\n", i);
					p = (char)('0' + i);
					result[resindex++] = p;
					push(stack, top, size, i);
					display(*stack, *top);
					flag = 0;
					cur = (*stack)[*top];
					break;
				}
			}
			if(flag == 1){
				break;
			}
		}
	}
	while (!(isEmpty(*top))){
		int rem = pop(stack, top);
		p = (char)('0' + rem);
		popped[popindex++] = p;
		printf("\npopped : %d\n", rem);
		display(*stack, *top);
	}
	printf("\nThe DFS traversal is : ");
	for (int i = 0; i < resindex; i++){
		printf("%c ", result[i]);
	}
	printf("\nThe pop order is : ");
	for (int i = 0; i < popindex; i++){
		printf("%c ", popped[i]);
	}
	printf("\n");
}

int main(){
	int num;
    printf("Enter number of vertices: ");
    scanf("%d", &num);
	int **matrix = (int **)calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++){
		matrix[i] = (int *)calloc(num, sizeof(int));
		for (int j = 0; j < num; j++){
			matrix[i][j] = 0;
		}
	}
    int m,n;
    do{
        printf("\nEnter edges to be joined (-1,-1 to end):\n");
        scanf("%d %d",&m,&n);
        if(m!=-1 && n!=-1)
            addEdge(matrix, m, n);
    } while(m!=-1);
	disp(matrix, num);
	int top = -1, size = 2;
	int *stack = (int *)calloc(size, sizeof(int));
	DFS(matrix, num, &stack, &top, &size);
	return 0;
}