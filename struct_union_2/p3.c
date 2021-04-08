#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    float price;
    int selectedQuantity;
} Item;

void readItemQuantity(Item *item)
{
    static char _buffer[64];
    static int _bufferUsed;

    printf("%s \t\t INR %.2f", item->name, item->price);

    printf("Quantity: ");
    scanf("%d", &(item->selectedQuantity));

    printf("\n");
}

void applyDiscount(Item *item)
{
    item->price *= 0.97;
}

void forEach(Item *head, int n, const void (*delegate)(Item *))
{
    while (n--)
        delegate(head++);
}

void _internal_updateItem(Item *head, int index, char *name, float price)
{
    (head + index)->name = name;
    (head + index)->price = price;
}

void main()
{
    int nItems = 6;
    Item *items = (Item *)malloc(sizeof(Item) * nItems);

    _internal_updateItem(items, 0, "HP Laptop", 35000.0f);
    _internal_updateItem(items, 0, "HP Laptop Charges", 1500.0f);
    _internal_updateItem(items, 0, "HP Headset", 250.0f);
    _internal_updateItem(items, 0, "HP 1TB Hard Disk", 4000.0f);
    _internal_updateItem(items, 0, "HP 16GB Pen Drive", 800.0f);
}