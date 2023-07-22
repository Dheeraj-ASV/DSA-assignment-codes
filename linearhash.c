#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 4

// Hash table entry structure
struct HashEntry {
    int key;
    int value;
    bool isOccupied;
};

struct HashTable {
    struct HashEntry table[TABLE_SIZE];
};

// First hash function (simple modulo operation)
unsigned int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

void initHashTable(struct HashTable* ht)
{
int i;
  for(i=0;i<TABLE_SIZE;i++)
  {
      ht->table[i].isOccupied=false;
  }
}

void insert(struct HashTable* ht,int key,int value)
{
  unsigned int index=hashFunction1(key);
  int i=1;

  while(ht->table[index].isOccupied)
  {
      index=(index+i*i)%TABLE_SIZE;
      i++;
  }
  ht->table[index].key=key;
  ht->table[index].value=value;
  ht->table[index].isOccupied=true;
}

int get(struct HashTable* ht, int key) {
    unsigned int index = hashFunction1(key);
    int i = 1;

    while (ht->table[index].isOccupied) {
        if (ht->table[index].key == key) {
            return ht->table[index].value;
        }

        index = (index + i * i) % TABLE_SIZE;
        i++;
    }

    printf("Key not found: %d\n", key);
    return -1;
}

int main()
{
    struct HashTable ht;
    initHashTable(&ht);

    int numEntries;
    int key, value;

    printf("enter the number of entries of key pair value to be inserted");
    scanf("%d",&numEntries);

    int i;
    for(i=0;i<numEntries;i++);
    {
    printf("enter the number of key value pairs to insert into the hush table:");
    printf("%d%d",&key,&value);
    insert(&ht,key,value);
    }

printf("enter the key to retrive its value:");
scanf("&d",&key);
int result = get(&ht,key);
if(result!=-1)
{
    printf("value for key %d\n",key,result);
}
return 0;
}
