#include &lt;stdio.h&gt;
void swap(int* a, int* b) {
int t = *a;
*a = *b;
*b = t;
}
int partition(int arr[], int low, int high) {
int pivot = arr[high]; // pivot
int i = low - 1; // Index of smaller element
for (int j = low; j &lt;= high - 1; j++) {
if (arr[j] &lt; pivot) {
i++;
swap(&amp;arr[i], &amp;arr[j]);
}
}
swap(&amp;arr[i + 1], &amp;arr[high]);
return i + 1;
}
void quickSort(int arr[], int low, int high) {
if (low &lt; high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void printArray(int arr[], int n) {
for (int i = 0; i &lt; n; i++)
printf(&quot;%d &quot;, arr[i]);

printf(&quot;\n&quot;);
}
int main() {
int arr[] = {10, 7, 8, 9, 1, 5};
int n = sizeof(arr)/sizeof(arr[0]);
printf(&quot;Original array: &quot;);
printArray(arr, n);
quickSort(arr, 0, n - 1);
printf(&quot;Sorted array (Quick Sort): &quot;);
printArray(arr, n);
return 0;
}
