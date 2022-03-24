#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Vertex {
	char name;
	int mark;
	struct Node* list;
};
struct Node {
	struct Vertex* vertex;
	struct Node* next;
};
struct Queue {
};
typedef struct Vertex Vertex;
typedef struct Node Node;

// creates a new vertex and return pointer to it
Vertex* new_vertex(char name) {
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
	vertex->name = name;
	vertex->list = 0;
	return vertex;
}

// connect the vertex a to vertex b
// by adding b to a's linked list!
void do_connect(Vertex* a, Vertex* b) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->vertex = b;
	node->next = a->list;
	a->list = node;
}

// connects a to b and b to a
void connect(Vertex* a, Vertex* b) {
	do_connect (a, b);
	do_connect (b, a);
}

// visit function
void visit(Vertex* vertex) {
	printf ("\n%5d. %c", vertex->mark, vertex->name);
}

// do a depth first search
void do_dfs(Vertex *vertex, int* count) {
	Node* p = vertex->list;
	vertex->mark = ++(*count);
	visit (vertex);
	while (p != 0) {
		if (!p->vertex->mark) {
			do_dfs (p->vertex, count);
		}
		p = p->next;
	}
}

void dfs(Vertex *graph[],int NUM_VERTEX) {///////////////////////////
	int i;
	int count = 0;
	// set all to unvisited
	for (i = 0; i < NUM_VERTEX; i ++) {
		graph[i]->mark = 0;
	}
	// each vertex dfs it
	for (i = 0; i < NUM_VERTEX; i ++) {
		if (graph[i]->mark == 0) {
			do_dfs (graph[i], &count);
		}
	}
}

// breadth first search
void do_bfs(Vertex *vertex, int* count) {
	Node *initialQueue, *front, *rear, *p, *temp;
	Vertex *w;
	// count = count + 1, mark vertex with count
	vertex->mark = ++(*count);
	visit (vertex);
	// initialize a queue, and initialize with vertex.
	initialQueue = (Node*)malloc(sizeof(Node));
	initialQueue->vertex = vertex;
	initialQueue->next = 0;
	front = initialQueue;
	rear  = initialQueue;
	// while queue is not empty
	while (front != 0) {
		// for vertyex w in V adjacent to the front vertex
		p = front->vertex->list;
		while (p != 0) {
			w = p->vertex;
			// if w is marked with 0
			if (w->mark == 0) {
				Node* nextQueue;
				// count = count + 1, mark w with count
				w->mark = ++(*count);
				visit (w);
				// add w to queue
				nextQueue = (Node*)malloc(sizeof(Node));
				nextQueue->vertex = w;
				nextQueue->next = 0;
				rear->next = nextQueue;
				rear = nextQueue;
			}
			p = p->next;
		}
		// remove front vertex from queue
		temp = front;
		front = front->next;
		free (temp);
	}
}

void bfs(Vertex *graph[],int NUM_VERTEX) {///////////////////////
	int i;
	int count = 0;
	// set all to unvisited
	for (i = 0; i < NUM_VERTEX; i ++) {
		graph[i]->mark = 0;
	}
	// each vertex bfs it
	for (i = 0; i < NUM_VERTEX; i ++) {
		if (graph[i]->mark == 0) {
			do_bfs (graph[i], &count);
		}
	}
}

// main function
int main() {
	int NUM_VERTEX;
	Vertex *graph[25];
	char letra;
	int numaristas;
	// create a adjacency list

	cout<<"\n\t*************************************\n";
	cout<<"\n\t         DFS Y BFS                  "<<endl;
	cout<<"\n\t*************************************\n";
	
	cout<<"Ingrese la cantidad de vertices: "; cin>>NUM_VERTEX;
	
	cout<<"\n\nIngrese vertices (letra): \n"<<endl;
	for(int i=0;i<NUM_VERTEX;i++){
		cout<<"Vertice ["<<i<<"]: ";
		cin>>letra;
		graph[i]=new_vertex(letra);
	}
		
	// connect the vertices
	cout<<"\n\nIngrese la cantidad de aristas: "; cin>>numaristas;
	for (int i = 0; i < numaristas; ++i) {
		int x, y;
		cout<<"\n\tConexion ["<<i+1<<"]: "<<endl;
		cout<<"Vertice inicio: ";cin >> x;
		cout<<"Vertice final: ";cin >> y;// Leo arista (x,y) del grafo

		connect(graph[x],graph[y]);
		cout<<endl;
	}

	// depth first search
	printf ("DFS: ");
	dfs (graph,NUM_VERTEX);
	
	// breadth first search
	printf ("\n\n");
	printf ("BFS: ");
	bfs (graph,NUM_VERTEX);
	
	printf ("\n\nRealizado");
	getchar ();
	
}
