/* 
Authors : Nacé van Wyk (Nacevw) and Adam Gray (adam-gray23)
Date : 25/10/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//global variables
//struct node*head=NULL;
//stores information of the node
char storename[50];
char storeaddress[50];
char storenum[20];

char checkname[50];
char checkaddress[50];
char checknum[20];

//struct for phonebook
struct node
{
    char name[50]; //stores name
    char address[50]; //stores address
    char num[20]; //stores number
    struct node*leftbranch; //left branch
    struct node*rightbranch; //right branch
};

//first tree, used for our names
struct node*head=NULL;
//second tree, used for our numbers
struct node*nums=NULL;
char store[20];
char saved[20];
char* ptr = store;
//pointer to store

//function declarations
void insertname(char* storename, char* storeaddress, char* storenum); //function used to insert into the name tree
void insertnum(char* storename, char* storeaddress, char* storenum); //function used to insert into the number tree
struct node* removeName(struct node*head, char* name); //function to delete from the name tree
struct node* removenum(struct node*head, char* num); //functions to delete from the num tree
struct node* new_node(char storename[50], char storeaddress[50], char storenum[20]); //function to create a new node
struct node* smallest(struct node* head); //function to find the smallest node in the tree
void namesearch(); //function to search for a name
void searchnumber(); //function to search for a number
void printPhone(); //function to print the phonebook
void delsearch(); //function to search and delete a name

//function to insert names into the name tree
void insertname(char* storename, char* storeaddress, char* storenum){
    struct node* root = head; //set root to head
    struct node* prev = NULL; //set prev to null
    //if the tree is empty
    if (root == NULL){
        head = new_node(storename, storeaddress, storenum); //create a new node
        return; //return
    }
    else{
        while (root != NULL){ //while the tree is not empty
            //prev = root;
            if (strcmp(storename, root->name) > 0){ //if the name is greater than the root
                prev = root; //set prev to root
                root = root->rightbranch; //set root to the right branch
            }
            else if (strcmp(storename, root->name) < 0){ //if the name is less than the root
                prev = root; //set prev to root
                root = root->leftbranch; //set root to the left branch
            }
            else{
                //clear screen
                system("clear");
                //print in red 
                printf("\033[0;31m");
                //print error
                printf("Error: Contact already exists\n");
                //set back to default
                printf("\033[0m");
                //return
                return;
            }
        }
    }
    struct node* temp = new_node(storename, storeaddress, storenum); //create a new node
    if (strcmp(storename, prev->name) < 0){ //if the name is less than the previous node
        prev->leftbranch = temp; //set the left branch to temp
    }
    else{
        prev->rightbranch = temp; //set the right branch to temp
    }
}


//function to insert numbers into the number tree
void insertnum(char* storename, char* storeaddress, char* storenum){
    struct node* root = nums; //set root to nums
    struct node* prev = NULL; //set prev to null

    if (root == NULL){ //if the tree is empty
        nums = new_node(storename, storeaddress, storenum); //create a new node
        return; //return
    }
    else{
        while (root != NULL){ //while the tree is not empty
            //prev = root;
            //check if name is already in the tree
            if (strcmp(storename, root->name) == 0){
                //clear screen
                system("clear");
                //print in red 
                printf("\033[0;31m");
                //print error
                printf("Error: Contact already exists\n");
                //set back to default
                printf("\033[0m");
                return;
            }
            else if (strcmp(storenum, root->num) > 0){ //if the number is greater than the root
                prev = root; //set prev to root
                root = root->rightbranch; //set root to the right branch
            }
            else if (strcmp(storenum, root->num) < 0){ //if the number is less than the root
                prev = root; //set prev to root
                root = root->leftbranch; //set root to the left branch
            }
            else{
                //clear screen
                system("clear");
                //print in red 
                printf("\033[0;31m");
                //print error
                printf("Error: Contact already exists\n");
                //set back to default
                printf("\033[0m");
                return; //return
            }
        }
    }
    struct node* temp = new_node(storename, storeaddress, storenum); //create temporary node
    if (strcmp(storenum, prev->num) < 0){ //if the number is less than the previous node
        prev->leftbranch = temp; //set the left branch to temp
    }
    else{
        prev->rightbranch = temp; //set the right branch to temp
    }
}

//function to remove a node from the name tree
struct node* removeName(struct node* head, char* name){
    //if name is less than current name of head
    if (strcmp(name, head->name) < 0){
        //go left
        //recursively call removeNode with leftbranch
        head->leftbranch = removeName(head->leftbranch, name);
    }
    //if name greater than current name of head
    else if (strcmp(name, head->name) > 0){
        //go right
        //recursively call removeNode with rightbranch
        head->rightbranch = removeName(head->rightbranch, name);
    }
    //if name is current node
    else if (strcmp(name, head->name) == 0){
        //if no left child
        if (head->leftbranch == NULL){
            //store the right child
            struct node* tmp = head->rightbranch;
            ptr = head->num;
            //delete the head
            free(head);
            //clear screen
            system("clear");
            //print in green
            printf("\033[0;32m");
            //print success message
            printf("Sucessfully removed %s from the phonebook\n", name);
            //set back to default
            printf("\033[0m");
            //return the right child
            return tmp;
        }
        //if no right child
        else if (head->rightbranch == NULL){
            //store the left child
            struct node* tmp = head->leftbranch;
            ptr = head->num;
            //delete the head
            free(head);
            //clear screen
            system("clear");
            //print in green
            printf("\033[0;32m");
            //print success message
            printf("Sucessfully removed %s from the phonebook\n", name);
            //set back to default
            printf("\033[0m");
            //return the left child
            return tmp;
        }
        // if both children exist
        else{
            //store the smallest number
            struct node* tmp = smallest(head->leftbranch);
            char* tmp2 = head->num;
            strcpy(ptr, tmp2);
            strcpy(saved, ptr);
            //copy the smallest number to the head
            strcpy(head->name, tmp->name);
            strcpy(head->address, tmp->address);
            strcpy(head->num, tmp->num);
            //recursively call removeNode with leftbranch
            head->leftbranch = removeName(head->leftbranch, tmp->name);
        }
    }
    else{
        //clear screen
        system("clear");
        //print in red
        printf("\033[0;31m");
        //print error
        printf("Error: Contact does not exist\n");
        //set back to default
        printf("\033[0m");
    }
    //return the head
    return head;
}

struct node* removeNum(struct node* head, char* num){
    //if name is less than current name of head
    if (strcmp(num, head->num) < 0){
        //go left
        //recursively call removeNode with leftbranch
        head->leftbranch = removeNum(head->leftbranch, num);
    }
    //if name greater than current name of head
    else if (strcmp(num, head->num) > 0){
        //go right
        //recursively call removeNode with rightbranch
        head->rightbranch = removeNum(head->rightbranch, num);
    }
    //if name is current node
    else{
        //if no left child
        if (head->leftbranch == NULL){
            //store the right child
            struct node* tmp = head->rightbranch;
            //delete the head
            head = NULL;
            free(head);
            //return the right child
            ptr = NULL;
            return tmp;
        }
        //if no right child
        else if (head->rightbranch == NULL){
            //store the left child
            struct node* tmp = head->leftbranch;
            //delete the head
            head = NULL;
            free(head);
            //return the left child
            ptr = NULL;
            return tmp;
        }
        // if both children exist
        else{
            //store the smallest number
            struct node* tmp = smallest(head->leftbranch);
            printf("%s\n", tmp->num);
            //copy the smallest number to the head
            strcpy(head->name, tmp->name);
            strcpy(head->address, tmp->address);
            strcpy(head->num, tmp->num);
            //recursively call removeNode with leftbranch
            head->leftbranch = removeNum(head->leftbranch, tmp->num);
        }
    }
    //return the head
    ptr = NULL;
    return head;
}

//finds the smallest number
struct node* smallest(struct node* head){
    //if no left child
    while (head->leftbranch != NULL){
        //head is the smallest
        head = head->leftbranch;
    }
    //return the smallest
    return head;
}

//function to search through the name tree
void namesearch(){
    //search tree
    struct node*root=head;
    //search by name
    //take name
    char searchname[50];
    int found = 0;
    printf("Enter name: "); //promt user to enter their name 
    scanf("%s", searchname); //scan in name 
    
    //while root is not null
    while (root != NULL){
        //if name is less than root name
        if (strcmp(searchname, root->name) < 0){
            //go left
            root = root->leftbranch;
        }
        //if name is greater than root name
        else if (strcmp(searchname, root->name) > 0){
            //go right
            root = root->rightbranch;
        }
        //if name is equal to root name print name address number
        else if (strcmp(searchname, root->name) == 0){
            //print name, address, and number
            system("clear");
            //print in green
            printf("\033[0;32m");
            printf("Name: %s\n", root->name); //print name
            printf("Address: %s\n", root->address); //print address
            printf("Phone Number: %s\n\n", root->num); //print number
            //set back to default colour
            printf("\033[0m");
            found = 1;
            return;
        }
    }
    if (found == 0){
        //print error
        system("clear");
        // print in red
        printf("\033[0;31m");
        printf("Error: Name not found\n\n");
        //set back to default colour
        printf("\033[0m");
        return;
    }
}

//function to search through the number tree
void searchnumber(){
    //search tree
    struct node*root=nums;
    //search by number
    //take number
    char searchnum[20];
    int found = 0;
    printf("Enter number: ");
    scanf("%s", searchnum);
    
    //while root is not null
    while (root != NULL){
        //if number is less than root number
        if (strcmp(searchnum, root->num) < 0){
            //go left
            root = root->leftbranch;
        }
        //if number is greater than root number
        else if (strcmp(searchnum, root->num) > 0){
            //go right
            root = root->rightbranch;
        }
        //if number is equal to root number print name address number
        else if (strcmp(searchnum, root->num) == 0){
            //print name, address, and number
            system("clear");
            //print in green
            printf("\033[0;32m");
            printf("Name: %s\n", root->name);
            printf("Address: %s\n", root->address);
            printf("Phone Number: %s\n\n", root->num);
            //set back to default colour
            printf("\033[0m");
            found = 1;
            return;
        }
    }
    if (found == 0){
        //print error
        system("clear");
        // print in red
        printf("\033[0;31m");
        printf("Error: Number not found\n\n");
        //set back to default colour
        printf("\033[0m");
        return;
    }
}

//function to print the tree
void print_tree(struct node*root){
    //print tree
    if (root == NULL){ //if tree is empty
        return; //return
    }
    //print new line
    printf("\n");
    //print in green
    printf("\033[0;32m");
    print_tree(root->leftbranch); // recursively call print_tree with leftbranch
    printf("Name: %s\n", root->name);
    printf("Address: %s\n", root->address);
    printf("Phone Number: %s\n\n", root->num);
    print_tree(root->rightbranch); // recursively call print_tree with rightbranch
    //set back to default colour
    printf("\033[0m");
    return;
}

//creates new nodes
struct node* new_node(char storename[50], char storeaddress[50], char storenum[20]){
    //create a new node
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    //copy global variables into new node
    //assign name, address, and number
    strcpy(newnode->name, storename);
    strcpy(newnode->address, storeaddress);
    strcpy(newnode->num, storenum);
    //left and right branch null
    newnode->leftbranch = NULL;
    newnode->rightbranch = NULL;
    // clear screen
    system("clear");
    // print in green
    printf("\033[0;32m");
    printf("Added new contact:\n");
    //set back to default colour
    printf("\033[0m");
    //print new node data by tabs
    printf("%s\t%s\t%s\n\n", newnode->name, newnode->address, newnode->num);
    return newnode;
}

void delsearch(){
        char name[50];
        int namefound = 0;
        //char num[20];
        printf("Enter name to remove: "); //promt user to enter a name to remove
        scanf("%s", name);
        struct node*root= head;
        while (root != NULL){
        //if name is less than root name
        if (strcmp(name, root->name) < 0){
            //go left
            root = root->leftbranch;
        }
        //if name is greater than root name
        else if (strcmp(name, root->name) > 0){
            //go right
            root = root->rightbranch;
        }
        //if name is equal to root name print you cannot delete your own contact
        else if (strcmp(name, root->name) == 0){
            namefound = 1;
            if (strcmp(name, checkname) == 0){
            //clear screen
            system("clear");
            //print in red
            printf("\033[0;31m");
            printf("Error: You cannot remove your own contact");
            //set back to default colour
            printf("\033[0m");
            }
            else{
                head = removeName(head, name); //call removeName function on the head
                if (strcmp(saved, "") != 0){
                    nums = removeNum(nums, saved); //call removeNum function on the nums
                    strcpy(saved, "");
                }
                else{
                    nums = removeNum(nums, ptr); //call removeNum function on the nums
                }
            }
            return;
        }
        }
        if(namefound == 0){
            //clear screen
            system("clear");
            //print in red
            printf("\033[0;31m");
            printf("Error: Name not found, Contact does not exist!\n");
            //set back to default colour
            printf("\033[0m");
        }
}