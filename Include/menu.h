#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include "fileIO.h"
#include <windows.h>

void printProductsCatalogue(){
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Stock", "Price");
    printf("------------------------------------------------------------\n");
    // int size = 6;
    // data = fopen("Product_Catalogue.csv","r");
    readFile();
    int i = 0;
    for(int i = 0; i < jumlahProd;i++)
    {
        /* code */
    	Sleep(50);
        printf("%-5d %-20s %-10d %-10.2d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
        // i++;
    }
    // fclose(data);
        
}
void printSortedProducts(){
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Product Name", "Stock", "Price");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < jumlahProd; i++)
    {
        /* code */
    	Sleep(50);
        printf("%-5d %-20s %-10d %-10.2d\n", products[i].ID, products[i].productName, products[i].stock, products[i].price);
    }
}


void displayLogo() {
    const char* rainbow[] = {
        "\033[31m", // Merah
        "\033[33m", // Kuning
        "\033[32m", // Hijau
        "\033[36m", // Cyan
        "\033[34m", // Biru
        "\033[35m",  // Ungu
        "\033[31m"
    };
    
    const char* reset = "\033[0m";

    printf("\n	*****************************************\n");
	Sleep(150);
    printf("	*                ");
	Sleep(150);
    for (int i = 0; i < 7; i++) {
        printf("%s%c", rainbow[i], "SHOPINT"[i]);
        Sleep(125);
    }
    printf("%s     	        *\n", reset);
	Sleep(150);
    printf("	*****************************************\n");
    
    			


    printf("     %s _____ _    _  ____  _____ _____ _   _ _______ _%s\n", rainbow[2], reset);
	Sleep(50);
    printf("    %s / ____| |  | |/ __ \\|  __ \\_   _| \\ | |__   __| |  %s\n", rainbow[4], reset);
	Sleep(50);
    printf("    %s| (___ | |__| | |  | | |__) || | |  \\| |  | |  | |%s\n", rainbow[3], reset);
	Sleep(50);
    printf("    %s \\___ \\|  __  | |  | |  ___/ | | | . ` |  | |  | |%s\n", rainbow[5], reset);
	Sleep(50);
    printf("   %s  ____) | |  | | |__| | |    _| |_| |\\  |  | |  |_|%s\n", rainbow[0], reset);
	Sleep(50);
    printf("    %s|_____/|_|  |_|\\____/|_|   |_____|_| \\_|  |_|  (_)%s\n", rainbow[1], reset);
    printf("\n");

    printf("\033[34m	    Your One-Stop Shop for Everything!     \033[0m\n");
	Sleep(150);
    printf("\033[32m 			Made By:\n");
	printf("			  Adi\n");
    printf("			 Ronald\n");
    printf("			 Carlos\033[0m\n");
    printf("\033[33m----------------------------------------------------------\033[0m\n");
	Sleep(150);
    printf("\033[37m	Press Enter to start your shopping journey...\033[0m");
}

void displayLogoend() {
    const char* rainbow[] = {
        "\033[31m", // Merah
        "\033[33m", // Kuning
        "\033[32m", // Hijau
        "\033[36m", // Cyan
        "\033[34m", // Biru
        "\033[35m",  // Ungu
        "\033[31m"
    };
    
    const char* reset = "\033[0m";

    printf("\n	*****************************************\n");
	Sleep(150);
    printf("	*                ");
	Sleep(150);
    for (int i = 0; i < 7; i++) {
        printf("%s%c", rainbow[i], "SHOPINT"[i]);
        Sleep(125);
    }
    printf("%s     	        *\n", reset);
	Sleep(150);
    printf("	*****************************************\n");
    
    			


    printf("     %s _____ _    _  ____  _____ _____ _   _ _______ _%s\n", rainbow[2], reset);
	Sleep(50);
    printf("    %s / ____| |  | |/ __ \\|  __ \\_   _| \\ | |__   __| |  %s\n", rainbow[4], reset);
	Sleep(50);
    printf("    %s| (___ | |__| | |  | | |__) || | |  \\| |  | |  | |%s\n", rainbow[3], reset);
	Sleep(50);
    printf("    %s \\___ \\|  __  | |  | |  ___/ | | | . ` |  | |  | |%s\n", rainbow[5], reset);
	Sleep(50);
    printf("   %s  ____) | |  | | |__| | |    _| |_| |\\  |  | |  |_|%s\n", rainbow[0], reset);
	Sleep(50);
    printf("    %s|_____/|_|  |_|\\____/|_|   |_____|_| \\_|  |_|  (_)%s\n", rainbow[1], reset);
    printf("\n");

    printf("\033[34m	    Your One-Stop Shop for Everything!     \033[0m\n");
	Sleep(150);
    printf("\033[32m 			Made By:\n");
	printf("			  Adi\n");
    printf("			 Ronald\n");
    printf("			 Carlos\033[0m\n");
    printf("\033[33m----------------------------------------------------------\033[0m\n");
	Sleep(150);
    printf("\033[37m	Thank you for using our software!\033[0m");
}

void displaymenu(){
	
}
void transactionMenu(){
    char choose;
    int id,index, sold;
    long int pay,total;
    total = 0;
    printProductsCatalogue();
    while (1)
    {
        /* code */
        printf("\n input the id of a product: ");
        scanf("%d",&id);
        if (id > jumlahProd || id < 0)
        {
            /* code */
            perror("Product's not found");
        }
        else{
            getProductById(id,jumlahProd,&index);
            printf("\nHow much? ");
            scanf("%d",&sold);
            if (products[index].stock <= 0 )
            {
                /* code */
                printf("Product's sold out!");
            }
            else{
                products[index].stock -= sold;
                total += products[index].price;
            }            
        }
        getchar();
        printf("Did you want to continue the transaction ?(Y/N): ");
        scanf("%c",&choose);
        if(choose == 'N' || 'n') {
            printf("\ntotal Price: %ld",total);
            printf("\nplease input your money: ");
            scanf("%ld",&pay);
            if(pay < total){
                printf("\nYou don't have enough money to pay!");
                getchar();
                break;
            }
            else{
                if(pay > total) printf("\nYour return: %d",pay - total);
                updateData();
                getchar();
                break;
            }
        };

    }        
}
void addDataMenu(){
    struct Product Data;
    char choose;
    while (1)
    {
        /* code */
        printf("\nProduct Name: ");
        scanf("%s",Data.productName);
        printf("\nPrice: ");
        scanf("%ld",&Data.price);
        printf("\nStocks: ");
        scanf("%d",&Data.stock);
        Data.ID = jumlahProd + 1;
        jumlahProd++;
        appendData(Data);
        

        getchar();
        printf("Did you want to add another product? (Y/N): ");
        scanf("%c",&choose);
        if (choose == 'N' || 'n')
        {
            /* code */
            break;
        }
        
    }
    
}

#endif
