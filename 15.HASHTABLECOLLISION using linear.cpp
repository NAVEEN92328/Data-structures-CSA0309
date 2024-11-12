 #include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct HashTable {
    int *table;
};

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->table = (int*)malloc(TABLE_SIZE * sizeof(int));
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = -1;
    }
    return ht;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(struct HashTable* ht, int key) {
    int index = hash(key);

    while (ht->table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    ht->table[index] = key;
}

int search(struct HashTable* ht, int key) {
    int index = hash(key);

    while (ht->table[index] != -1) {
        if (ht->table[index] == key) {
            return index; 
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1; 
}

void display(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] == -1) {
            printf("Index %d: Empty\n", i);
        } else {
            printf("Index %d: %d\n", i, ht->table[i]);
        }
    }
}

int main() {
    struct HashTable* ht = createHashTable();

    insert(ht, 12);
    insert(ht, 22);
    insert(ht, 32);
    insert(ht, 42);

    printf("Hash Table:\n");
    display(ht);
    
    int key = 22;
    int index = search(ht, key);
    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found.\n", key);
    }

    return 0;
}

