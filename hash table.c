#include &lt;stdio.h&gt;
#define TABLE_SIZE 10
int hashTable[TABLE_SIZE];
// Initialize hash table with -1 (indicating empty)
void initHashTable() {
for (int i = 0; i &lt; TABLE_SIZE; i++) {
hashTable[i] = -1;
}
}
// Simple hash function: key modulo table size
int hashFunction(int key) {
return key % TABLE_SIZE;
}
// Insert key into hash table
void insert(int key) {
int hashIndex = hashFunction(key);
int originalIndex = hashIndex;
// Linear probing in case of collision
while (hashTable[hashIndex] != -1) {
hashIndex = (hashIndex + 1) % TABLE_SIZE;

if (hashIndex == originalIndex) {
printf(&quot;Hash table is full, cannot insert %d\n&quot;, key);
return;
}
}
hashTable[hashIndex] = key;
}
// Search for a key in hash table, returns index or -1 if not found
int search(int key) {
int hashIndex = hashFunction(key);
int originalIndex = hashIndex;
while (hashTable[hashIndex] != -1) {
if (hashTable[hashIndex] == key)
return hashIndex;
hashIndex = (hashIndex + 1) % TABLE_SIZE;
if (hashIndex == originalIndex)
break;
}
return -1;
}
// Display the hash table
void display() {
printf(&quot;Hash Table:\n&quot;);
for (int i = 0; i &lt; TABLE_SIZE; i++) {
if (hashTable[i] == -1)
printf(&quot;[%d]: Empty\n&quot;, i);
else
printf(&quot;[%d]: %d\n&quot;, i, hashTable[i]);
}
}
int main() {

initHashTable();
insert(23);
insert(43);
insert(13);
insert(27);
insert(37);
display();
int key = 13;
int result = search(key);
if (result != -1)
printf(&quot;Key %d found at index %d\n&quot;, key, result);
else
printf(&quot;Key %d not found in hash table\n&quot;, key);
key = 50;
result = search(key);
if (result != -1)
printf(&quot;Key %d found at index %d\n&quot;, key, result);
else
printf(&quot;Key %d not found in hash table\n&quot;, key);
return 0;
}
