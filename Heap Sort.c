#include &lt;stdio.h&gt;
void heapify(int arr[], int n, int i) {
int largest = i; // Initialize largest as root
int left = 2 * i + 1;
int right = 2 * i + 2;
int temp;
if (left &lt; n &amp;&amp; arr[left] &gt; arr[largest])
largest = left;
if (right &lt; n &amp;&amp; arr[right] &gt; arr[largest])
largest = right;
if (largest != i) {
temp = arr[i];
arr[i] = arr[largest];
arr[largest] = temp;

heapify(arr, n, largest);
}
}
void heapSort(int arr[], int n) {

int temp;
// Build max heap
for (int i = n / 2 - 1; i &gt;= 0; i--)
heapify(arr, n, i);
// Extract elements from heap one by one
for (int i = n - 1; i &gt; 0; i--) {
// Move current root to end
temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
// Call max heapify on the reduced heap
heapify(arr, i, 0);
}
}
void printArray(int arr[], int n) {
for (int i = 0; i &lt; n; i++)
printf(&quot;%d &quot;, arr[i]);
printf(&quot;\n&quot;);
}
int main() {
int arr[] = {12, 11, 13, 5, 6, 7};
int n = sizeof(arr)/sizeof(arr[0]);

printf(&quot;Original array: &quot;);
printArray(arr, n);
heapSort(arr, n);
printf(&quot;Sorted array (Heap Sort): &quot;);
printArray(arr, n);
return 0;
}