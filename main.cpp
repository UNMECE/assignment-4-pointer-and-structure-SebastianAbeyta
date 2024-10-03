#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "item.h"

using namespace std;

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].price = price;
    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    item_list[index].name = (char *)malloc(strlen(name) + 1);

    strcpy(item_list[index].sku, sku);
    strcpy(item_list[index].category, category);
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
        free (item_list[i].sku);
        free (item_list[i].category);
        free (item_list[i].name);
    }

}

double average_price(Item *item_list, int size)
{
    double total = 0, average = 0;

    for (int i = 0; i<size; i++)
    {
        total += item_list[i].price;   
    }
    
    average = total / size;
    return (average);

}

void print_items(Item *item_list, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("############################\n");

        printf("Item Name: %s \n", item_list[i].name);
        printf("Item SKU: %s \n",item_list[i].sku );
        printf("Item Category: %s \n", item_list[i].category);
        printf("Item Price: $%.2f \n", item_list[i].price);
    }
}


int main(int argc, char * argv[])
{   
    int size = 5;
    int i = 0;
    int skumatch = 0;
    int item_found = 0;

    Item *item_list = (Item *) malloc (sizeof(Item)*size);

    add_item(item_list, 99.99,  strdup("13708"), strdup("electornic"), strdup("radio") , 0);
    add_item(item_list, 1.49, strdup("12490"), strdup("food"), strdup("soda"), 1);
    add_item(item_list, 10.99, strdup("12480"), strdup("toy"), strdup("football"), 2);
    add_item(item_list, 1.99, strdup("12470"), strdup("food"), strdup("jam"), 3);
    add_item(item_list, 699.99, strdup("13709"), strdup("electornic"), strdup("playstation"), 4);

    print_items(item_list, size);
    printf("############################\n");
    printf("Average price of items: %0.2f\n" ,average_price(item_list, size));
    printf("############################\n");

    while( i < size)
    {
        if(strcmp(item_list[i].sku, argv[1]) == 0)
        {
            printf("The item you entered is: %s \n", item_list[i].name);
            item_found = 1;
            break;
        }
        i++;
    }

    if(item_found == 0)
    {
        printf("No item found for SKU: %s", argv[1]);
    }

    free_items(item_list, size);

    return 0;
}
