#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#define MAX_VERTICES 100
// Node for adjacency list
typedef struct Node {
int vertex;
struct Node* next;
} Node;
// Graph structure
typedef struct Graph {
int numVertices;
Node* adjLists[MAX_VERTICES];
int visited[MAX_VERTICES];
} Graph;
// Create a node
Node* createNode(int v) {

Node* newNode = malloc(sizeof(Node));
newNode-&gt;vertex = v;
newNode-&gt;next = NULL;
return newNode;
}
// Initialize graph
void initGraph(Graph* graph, int vertices) {
graph-&gt;numVertices = vertices;
for (int i = 0; i &lt; vertices; i++) {
graph-&gt;adjLists[i] = NULL;
graph-&gt;visited[i] = 0;
}
}
// Add edge (undirected)
void addEdge(Graph* graph, int src, int dest) {
// Add edge src -&gt; dest
Node* newNode = createNode(dest);
newNode-&gt;next = graph-&gt;adjLists[src];
graph-&gt;adjLists[src] = newNode;
// Add edge dest -&gt; src
newNode = createNode(src);
newNode-&gt;next = graph-&gt;adjLists[dest];
graph-&gt;adjLists[dest] = newNode;
}

// DFS helper
void DFS(Graph* graph, int vertex) {
graph-&gt;visited[vertex] = 1;
printf(&quot;%d &quot;, vertex);
Node* temp = graph-&gt;adjLists[vertex];
while (temp) {

int adjVertex = temp-&gt;vertex;
if (!graph-&gt;visited[adjVertex]) {
DFS(graph, adjVertex);
}
temp = temp-&gt;next;
}
}
// Queue for BFS
typedef struct Queue {
int items[MAX_VERTICES];
int front;
int rear;
} Queue;
void initQueue(Queue* q) {
q-&gt;front = -1;
q-&gt;rear = -1;
}
int isEmpty(Queue* q) {
return q-&gt;front == -1;
}

void enqueue(Queue* q, int value) {
if (q-&gt;rear == MAX_VERTICES - 1) {
printf(&quot;Queue is full\n&quot;);
return;
}
if (q-&gt;front == -1)
q-&gt;front = 0;
q-&gt;rear++;
q-&gt;items[q-&gt;rear] = value;
}

int dequeue(Queue* q) {
if (isEmpty(q)) {
printf(&quot;Queue is empty\n&quot;);
return -1;
}
int item = q-&gt;items[q-&gt;front];
if (q-&gt;front &gt;= q-&gt;rear) {
q-&gt;front = -1;
q-&gt;rear = -1;
} else {
q-&gt;front++;
}
return item;
}
// BFS
void BFS(Graph* graph, int startVertex) {
Queue q;
initQueue(&amp;q);

graph-&gt;visited[startVertex] = 1;
enqueue(&amp;q, startVertex);
while (!isEmpty(&amp;q)) {
int currentVertex = dequeue(&amp;q);
printf(&quot;%d &quot;, currentVertex);
Node* temp = graph-&gt;adjLists[currentVertex];
while (temp) {
int adjVertex = temp-&gt;vertex;
if (!graph-&gt;visited[adjVertex]) {
graph-&gt;visited[adjVertex] = 1;
enqueue(&amp;q, adjVertex);
}

temp = temp-&gt;next;
}
}
}
int main() {
Graph graph;
int vertices = 6;
initGraph(&amp;graph, vertices);
addEdge(&amp;graph, 0, 1);
addEdge(&amp;graph, 0, 2);
addEdge(&amp;graph, 1, 3);
addEdge(&amp;graph, 1, 4);
addEdge(&amp;graph, 2, 4);
addEdge(&amp;graph, 3, 4);
addEdge(&amp;graph, 3, 5);
addEdge(&amp;graph, 4, 5);
printf(&quot;DFS starting from vertex 0:\n&quot;);
DFS(&amp;graph, 0);
// Reset visited for BFS
for (int i = 0; i &lt; vertices; i++) {
graph.visited[i] = 0;
}
printf(&quot;\nBFS starting from vertex 0:\n&quot;);
BFS(&amp;graph, 0);
return 0;
}