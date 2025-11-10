#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
// Define the structure for a tree node
typedef struct Node {
int data;
struct Node* left;
struct Node* right;
} Node;
// Function to create a new node
Node* createNode(int value) {
Node* newNode = (Node*) malloc(sizeof(Node));
newNode-&gt;data = value;
newNode-&gt;left = NULL;
newNode-&gt;right = NULL;
return newNode;
}
// Inorder Traversal: Left, Root, Right
void inorder(Node* root) {
if (root == NULL) return;
inorder(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;data);
inorder(root-&gt;right);
}
// Preorder Traversal: Root, Left, Right
void preorder(Node* root) {
if (root == NULL) return;
printf(&quot;%d &quot;, root-&gt;data);
preorder(root-&gt;left);
preorder(root-&gt;right);
}

// Postorder Traversal: Left, Right, Root
void postorder(Node* root) {
if (root == NULL) return;
postorder(root-&gt;left);
postorder(root-&gt;right);
printf(&quot;%d &quot;, root-&gt;data);
}
// Level-order Traversal (using a simple queue)
#define MAX_QUEUE 100
typedef struct {
Node* items[MAX_QUEUE];
int front, rear;
} Queue;
void initQueue(Queue* q) {
q-&gt;front = 0;
q-&gt;rear = -1;
}
int isEmpty(Queue* q) {
return q-&gt;rear &lt; q-&gt;front;
}
void enqueue(Queue* q, Node* node) {
if (q-&gt;rear &lt; MAX_QUEUE - 1) {
q-&gt;items[++q-&gt;rear] = node;
}
}
Node* dequeue(Queue* q) {
if (!isEmpty(q)) {
return q-&gt;items[q-&gt;front++];
}
return NULL;
}

void levelOrder(Node* root) {
if (root == NULL) return;
Queue q;
initQueue(&amp;q);
enqueue(&amp;q, root);
while (!isEmpty(&amp;q)) {
Node* current = dequeue(&amp;q);
printf(&quot;%d &quot;, current-&gt;data);
if (current-&gt;left != NULL) enqueue(&amp;q, current-&gt;left);
if (current-&gt;right != NULL) enqueue(&amp;q, current-&gt;right);
}
}
int main() {
/*
1
/ \
2 3
/ \ \
4 5 6
*/
Node* root = createNode(1);
root-&gt;left = createNode(2);
root-&gt;right = createNode(3);
root-&gt;left-&gt;left = createNode(4);
root-&gt;left-&gt;right = createNode(5);
root-&gt;right-&gt;right = createNode(6);
printf(&quot;Inorder traversal: &quot;);
inorder(root);
printf(&quot;\n&quot;);
printf(&quot;Preorder traversal: &quot;);
preorder(root);

printf(&quot;\n&quot;);
printf(&quot;Postorder traversal: &quot;);
postorder(root);
printf(&quot;\n&quot;);
printf(&quot;Level-order traversal: &quot;);
levelOrder(root);
printf(&quot;\n&quot;);
return 0;
}