#include <stdio.h>
#include <stdlib.h>

int isEmpty(int front, int rear){
	if (front == rear)
		return 1;
	return 0;
}
int isFull(int front, int rear, int maxsize){
	if ((rear + 1) % maxsize == front)
		return 1;
	return 0;
}
void display(int *queue, int front, int rear, int maxsize){
    printf("queue : ");
    for (int i = (front + 1) % maxsize; i != (rear + 1) % maxsize; i = (i + 1) % maxsize){
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void push(int **queue, int *front, int *rear, int *maxsize, int key){
	if (isFull(*front, *rear, *maxsize)){
		int *newq = (int *)calloc((*maxsize)*2,sizeof(int));
		int i, j;
		for (i = 1,j=(*front+1)%(*maxsize);j!=(*rear+1)%(*maxsize);j=(j+1)%(*maxsize),i++){
			newq[i] = (*queue)[j];
		}
		int *temp = *queue;
		*queue = newq;
		*maxsize = *maxsize * 2;
		*front = 0;
		*rear = --i;
		free(temp);
	}
	*rear = (*rear+1)%(*maxsize);
	(*queue)[*rear] = key;
}
int pop(int **queue, int *front, int *rear, int *maxsize){
	int temp = (*queue)[(*front + 1) % (*maxsize)];
	*front = (*front + 1) % (*maxsize);
	return temp;
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
void BFS(int **matrix, int num, int **queue, int *front, int *rear, int *maxsize){
	int *visited = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++){
		visited[i] = 0;
	}
	char result[20],popped[20];
	int resindex = 0,popindex = 0;
	push(queue, front, rear, maxsize, 0);
	printf("\nPushed : %d\n", 0);
	char p = (char)('0' + 0);
	result[resindex++] = p;
	display(*queue, *front, *rear, *maxsize);
	visited[0] = 1;
	int cur = *queue[*front];
	int flag, ele;
	while (1){
		if (!(isEmpty(*front, *rear))){
			for (int i = 0; i < num; i++){
				if (visited[i] == 0 && matrix[cur][i] == 1){
					visited[i] = 1;
					char p = (char)('0' + i);
					result[resindex++] = p;
					push(queue, front, rear, maxsize, i);
					printf("\nPushed : %d\n", i);
					display(*queue, *front, *rear, *maxsize);
				}
			}
			ele = pop(queue, front, rear, maxsize);
			p = (char)('0' + ele);
			popped[popindex++] = p;
			printf("\nPopped : %d\n", ele);
			display(*queue, *front, *rear, *maxsize);
			cur = (*queue)[(*front + 1) % (*maxsize)];
		}
		else{
			flag = 1;
			for (int i = 0; i < num && flag; i++){
				if (visited[i] == 0){
					visited[i] = 1;
					printf("\nPushed : %d\n", i);
					p = (char)('0' + i);
					result[resindex++] = p;
					push(queue, front, rear, maxsize, i);
					display(*queue, *front, *rear, *maxsize);
					cur = (*queue)[(*front + 1) % (*maxsize)];
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				break;
		}
	}
	while (!(isEmpty(*front, *rear))){
		ele = pop(queue, front, rear, maxsize);
		p = (char)('0' + ele);
		popped[popindex++] = p;
		printf("\nPopped : %d\n", ele);
		display(*queue, *front, *rear, *maxsize);
	}
	printf("\nThe BFS traversal is : ");
	for (int i = 0; i < resindex; i++)
		printf("%c ", result[i]);
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
    }while(m!=-1);
	disp(matrix, num);
	int front = 0, rear = 0, maxsize = 2;
	int *queue = (int *)calloc(maxsize, sizeof(int));
	BFS(matrix, num, &queue, &front, &rear, &maxsize);
	return 0;
}