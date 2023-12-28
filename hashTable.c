#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic hash function - can be improved for real-world applications
int hashFunction(const char *key, int tableSize) {
    int hash = 0;
    while (*key) {
        hash = (hash + *key) % tableSize;
        key++;
    }
    return hash;
}

// Simple Caesar cipher encryption
void encrypt(char *value, int shift) {
    while (*value) {
        if (*value >= 'A' && *value <= 'Z') {
            *value = ((*value - 'A' + shift) % 26) + 'A';
        } else if (*value >= 'a' && *value <= 'z') {
            *value = ((*value - 'a' + shift) % 26) + 'a';
        }
        value++;
    }
}

// Simple Caesar cipher decryption
void decrypt(char *value, int shift) {
    while (*value) {
        if (*value >= 'A' && *value <= 'Z') {
            *value = ((*value - 'A' - shift + 26) % 26) + 'A';
        } else if (*value >= 'a' && *value <= 'z') {
            *value = ((*value - 'a' - shift + 26) % 26) + 'a';
        }
        value++;
    }
}

#define TABLE_SIZE 100

// Structure for key-value pair
typedef struct {
    char key[50];
    char value[50];
} KeyValuePair;

// Hash table structure
typedef struct {
    KeyValuePair table[TABLE_SIZE];
} HashTable;

// Function to insert key-value pair
void insert(HashTable *hashTable, const char *key, const char *value) {
    int index = hashFunction(key, TABLE_SIZE);
    strcpy(hashTable->table[index].key, key);
    encrypt(hashTable->table[index].value, 3); // Encrypt the value before storing
    strcpy(hashTable->table[index].value, value);
}

// Function to retrieve value using key
char *retrieve(HashTable *hashTable, const char *key) {
    int index = hashFunction(key, TABLE_SIZE);
    decrypt(hashTable->table[index].value, 3); // Decrypt the value before retrieving
    if (strcmp(hashTable->table[index].key, key) == 0) {
        return hashTable->table[index].value;
    }
    return NULL;
}

int main() {
    HashTable hashTable;
    memset(&hashTable, 0, sizeof(HashTable));

    int numPairs;
    printf("Enter the number of key-value pairs to insert: ");
    scanf("%d", &numPairs);
    getchar(); // Consume newline character

    for (int i = 0; i < numPairs; i++) {
        char key[50], value[50];
        printf("Enter key for pair %d: ", i + 1);
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0'; // Remove newline

        printf("Enter value for pair %d: ", i + 1);
        fgets(value, sizeof(value), stdin);
        value[strcspn(value, "\n")] = '\0'; // Remove newline

        insert(&hashTable, key, value);
    }

    char searchKey[50];
    printf("Enter the key to retrieve its value: ");
    fgets(searchKey, sizeof(searchKey), stdin);
    searchKey[strcspn(searchKey, "\n")] = '\0'; // Remove newline

    char *retrievedValue = retrieve(&hashTable, searchKey);
    if (retrievedValue != NULL) {
        printf("Retrieved value for key '%s' is: %s\n", searchKey, retrievedValue);
    } else {
        printf("Value not found for key '%s'\n", searchKey);
    }

    return 0;
}

