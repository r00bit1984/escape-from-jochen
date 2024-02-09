// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct {
    char name[50]; 
} Item;

extern Item inventory[10];  // Declare the variable

#endif // INVENTORY_H