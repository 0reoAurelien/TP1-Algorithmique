#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;


void read_input_ex1(const char* filename, int* sequence, int* n);
void read_input_ex2(const char* filename, int* sequence, int* n, int* k);
void read_input_adjacency_matrix(const char* filename, int adjMatrix[MAX][MAX], int* n, int* m);
void read_input_adjacency_list(const char* filename, Node *adjList[MAX], int* n, int* m);
void read_input_ex5(const char* filename, int* sequence, int* n, int* k);


void addEdgeToList(int u, int v, Node** adjListPosition);
int find(int x, int* parent);
void makeSet(int n, int* parent);
void unionSets(int x, int , int *parent);
void freeAdjList(Node** adjList, int n);



void write_output_ex1(const char* filename, int* lis, int lis_length, int* indexTable);
void write_output_ex2(const char* filename, int* A, int aSize, int* bestRemovedIndexList, int bestDepth, int resSize);
void write_output_ex3(const char* filename, int* res, int resSize);
void write_output_ex4(const char* filename, int components[MAX][MAX], int componentSizes[MAX], int k);
