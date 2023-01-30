#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};
typedef struct node* Node;

struct Graph {
  int numVertices;
  Node* adjlist;
};
typedef struct Graph* graph;

Node createNode(int i) {
  Node newNode = malloc(sizeof(struct node));
  newNode->vertex = i;
  newNode->next = NULL;
  return newNode;
}

graph createGraph(int vertices) {
  graph graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjlist = malloc(vertices * sizeof(struct node*));
  for (int i = 0; i < vertices; i++)
    graph->adjlist[i] = NULL;
  return graph;
}

void addEdge(graph gr, int s, int d) {
  Node newNode = createNode(d);

  newNode->next = gr->adjlist[s];
  gr->adjlist[s] = newNode;

  newNode = createNode(s);
  newNode->next = gr->adjlist[d];
  gr->adjlist[d] = newNode;
}

void displaylist(graph gr) {
  for (int i = 0; i < gr->numVertices; i++) {
    Node temp = gr->adjlist[i];
    printf("\n Vertex %d\n: ", i);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  graph g = createGraph(4);
    addEdge(g,0,0);
    addEdge(g,0,1);
    addEdge(g,1,3);
    addEdge(g,2,3);
    addEdge(g,1,4);
    addEdge(g,3,3);
    addEdge(g,3,1);
    displaylist(g);
}