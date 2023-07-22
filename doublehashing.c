#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 4

// Hash table entry structure
struct HashEntry {
    int key;
    int value;
    bool isOccupied;
};

// Hash table structure
struct HashTable {
    struct HashEntry table[TABLE_SIZE];
};

// First hash function (simple modulo operation)
unsigned int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

// Second hash function (using prime number to avoid clustering)
unsigned int hashFunction2(int key) {
    return 7 - (key % 7);
}

// Initialize the hash table
void initHashTable(struct HashTable* ht)
 {
     int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].isOccupied = false;
    }
}

// Insert a key-value pair into the hash table using double hashing
void insert(struct HashTable* ht, int key, int value)
{
    int i;
    unsigned int index1 = hashFunction1(key);
    unsigned int index2 = hashFunction2(key);
    unsigned int index = index1;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (!ht->table[index].isOccupied) {
            ht->table[index].key = key;
            ht->table[index].value = value;
            ht->table[index].isOccupied = true;
            return;
        }

        index = (index1 + i * index2) % TABLE_SIZE;
    }

    printf("Hash table is full. Cannot insert key: %d\n", key);
}

// Get the value associated with a key from the hash table
int get(struct HashTable* ht, int key) {
    int i;
    unsigned int index1 = hashFunction1(key);
    unsigned int index2 = hashFunction2(key);
    unsigned int index = index1;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[index].isOccupied && ht->table[index].key == key) {
            return ht->table[index].value;
        }

        index = (index1 + i * index2) % TABLE_SIZE;
    }

    printf("Key not found: %d\n", key);
    return -1;
}

int main() {
    int i;
    struct HashTable ht;
    initHashTable(&ht);

    int key, value;

    // Insert key-value pairs into the hash table based on user input
    for (i = 0; i < TABLE_SIZE; i++)
        {
        printf("Enter key and value (separated by space) for entry %d: ", i);
        scanf("%d %d", &key, &value);
        insert(&ht, key, value);
    }

    // Get values from the hash table using keys based on user input
    printf("Enter the key to retrieve its value: ");
    scanf("%d", &key);
    int result = get(&ht, key);
    if (result != -1) {
        printf("Value for key %d: %d\n", key, result);
    }

    return 0;
}
