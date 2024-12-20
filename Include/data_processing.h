#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include <stdio.h>

struct Product
{
    /* data */
    int ID;
    char productName[30];
    int stock;
    long int price;
};
struct Sales
{
    /* data */
    int ID;
    char Name[20];
    int productId[6];
    long int total;
};
struct Product products[100];
struct Sales Sale;

// int product_size = sizeof(products)/sizeof(products[0]);

void getProductById(int id,int size,int *index){
    int i = 0;
    int found;
    for (;i < size; i++)
    {
        /* code */
        found++;
        if(products[i].ID == id) {
            *index = i;
            break;
        }        
    }
    
    if(*index == -1) {
        printf("Product Not Found");
        return;
    }
    
    
    
}
void sortProductById(int jumlahProd){
    struct Product temp;
    int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].ID > products[j+1].ID){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
            
        }
        
    }

    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].ID < products[j+1].ID){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
            
        }
        
    }
}
void sortProductByStock(int jumlahProd){
    struct Product temp;
     int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
    if(sortType == 1){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].stock > products[j+1].stock){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
            
        }
    }
    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].stock < products[j+1].stock){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
                    
    }
    
}
void sortProductByPrice(int jumlahProd){
       struct Product temp;
       int sortType = 0;
       while (1)
       {
            printf("Ascending or Descending ?\n");
            printf("Ascending = 1\n");
            printf("Descending = 2\n");
            printf("Your Choice : ");
            scanf("%d", &sortType);
            if(sortType == 1) break;
            else if(sortType == 2) break;
       }
       
    if(sortType == 1)
    {
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].price > products[j+1].price){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;

                }
            }
            
        }        
    }
    else if(sortType == 2){
        for (int i = 0; i < jumlahProd - 1; i++)
        {
            /* code */
            for (int j = 0; j < jumlahProd - i -1; j++)
            {
                /* code */
                if(products[j].price < products[j+1].price){
                    temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;

                }
            }
            
        }
    }
}
void deleteProduct(int id, const char* filePath){  
    int index;
    getProductById(id,jumlahProd,&index);
    struct Product temp[jumlahProd - 1];
    if(index == -1){
        perror("Record not found!");
        return;
    }
    for(int i = 0;i < jumlahProd;i++){
        if(i != index){
            temp[i] = products[i];
        }
    }

    deleteData(temp);
}



#endif
