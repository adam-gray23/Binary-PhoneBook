/* 
Authors : Nacé van Wyk (Nacevw) and Adam Gray (adam-gray23)
Date : 25/10/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "functions.h"
#include <ctype.h>
//function declarations
void check_input(int input); //checks if input is valid
void loop(); //main loop
void global_update(); //updates global variables
void mycontact(); // function to create the users personal contact
struct node* new_node(char storename[50], char storeaddress[50], char storenum[20]); //function for new node creation 


//main function
int main(int argc, char const *argv[])
{
    //call mycontact function
    mycontact();
    return 0;
}

//loop function
void loop(){
    while (1){
        //print new line
        printf("\n");
        //print menu
        printf("================MENU=================\n");
        //print astrix box
        //print in green
        printf("\033[0;32m");
        printf("*************************************\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("1. Add Contact                    ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("2. Remove Contact                 ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("3. Search Name                    ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("4. Search Phone Number            ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("5. Show All Contacts              ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("6. Quit                           ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("* ");
        //set back to default
        printf("\033[0m");
        printf("7. Help                           ");
        //print in green
        printf("\033[0;32m");
        printf("*\n");
        printf("*************************************\n\n");
        //set back to default
        printf("\033[0m");
        int input, temp, status; //define variables
        //ask for input
        printf("Please enter a number: ");
        //scan input, and check if it successful
        status = scanf("%d", &input);
        //while input is not successful
        while(status!=1){
            //while input is not a number
            while((temp=getchar()) && temp != '\n');
            //print in red
            printf("\033[0;31m");
            printf("Invalid input!\n");
            printf("Please try again!\n");
            //set back to default
            printf("\033[0m");
            //scan input, and check if it successful, loop again if needed
            status = scanf("%d", &input);
        }
        //else call check input function
        check_input(input);
    }
}
//check input function
void check_input(int input){
    if (input == 1){
        //add a contact into a binary tree
        //update gloabl variables
        global_update();
        //create a new node
        insertname(storename, storeaddress, storenum);
        insertnum(storename, storeaddress, storenum);
    }
    else if (input == 2){
        delsearch(); //call delsearch function to delete a contact
    }
    else if (input == 3){
        //call namesearch function to search for a contact by name
        namesearch();
    }
    else if (input == 4){
        searchnumber(); //call searchnumber function to search for a contact by number
    }
    else if (input == 5){
        
        print_tree(head); // calls print tree function to print all contacts
    }
    else if (input == 6){
        //exit
        exit(0);
    }
    else if (input == 7){
        system("more README.md"); //display manual
    }
    else{
        //set to red
        printf("\033[0;31m");
        printf("Invalid input\n");
        printf("Please enter a number between 1 and 7\n");
        printf("\n\n");
        //set back to default
        printf("\033[0m");
    }
}

void global_update(){
    //update global variables with user input
    printf("Enter first name: ");
    scanf("%s", storename);
    printf("Enter email address: ");
    scanf("%s", storeaddress);
    printf("Enter phone number: ");
    char tmp[50];
    checknum:
    scanf("%s", tmp);
    for (int i = 0; i < strlen(tmp); i++){
        if (!isdigit(tmp[i])){
            printf("Invalid input\n");
            printf("Please enter a number\n");
            goto checknum;
        }
    }
    strcpy(storenum, tmp);
    
}

void mycontact(){
    //print in green
    printf("\033[0;32m");
    printf("Welcome to our phonebook!\n");
    printf("To begin, please add your contact information:\n");
    // set back to default color
    printf("\033[0m");
    //takes in users personal contact and sets it to the head of the tree
    printf("First Name:\n");
    scanf("%s", checkname);
    printf("Email:\n");
    scanf("%s", checkaddress);
    printf("Phone Number:\n");
    //make sure scanned input is a number
    char tmp[50];
    check:
    scanf("%s", tmp);
    for (int i = 0; i < strlen(tmp); i++){
        if (!isdigit(tmp[i])){
            printf("Invalid input\n");
            printf("Please enter a number\n");
            goto check;
        }
    }
    strcpy(checknum, tmp);
    insertname(checkname, checkaddress, checknum);
    insertnum(checkname, checkaddress, checknum);
    //call loop function
    loop();
}