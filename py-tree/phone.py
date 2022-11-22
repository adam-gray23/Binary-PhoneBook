# Authors : Nacé van Wyk (Nacevw) and Adam Gray (adam-gray23)
# Date : 25/10/2022

import os
#global check variables
yournamecheck = ""
yourphonecheck = ""
glo = 0

#tree class
class Tree:
    #attributes of the tree
    def __init__(self, name, address, phone):
        #has a left and right
        self.left = None
        self.right = None
        #and a name email and number
        self.name = name
        self.address = address
        self.phone = phone
    
    #function to insert names into first tree
    def insertName(self, name, address, phone):
        #if current node is none, add node
        if self.name is None:
            self.name = name
            self.address = address
            self.phone = phone
        else:
            #error if details already exist
            if self.name == name:
                print("A contact already exists with that name")
            elif self.address == address:
                print("A contact already exists with that address")
            elif self.phone == phone:
                print("A contact already exists with that phone number")
            #if name is less than current name
            elif self.name > name:
                #if no left branch
                if self.left is None:
                    #add node into left branch
                    self.left = Tree(name, address, phone)
                else:
                    #else call insert on left branch to keep searching
                    self.left.insertName(name, address, phone)
            else:
                #if no right branch
                if self.right is None:
                    #add node into right branch
                    self.right = Tree(name, address, phone)
                else:
                    #else call insert on right branch to keep searching
                    self.right.insertName(name, address, phone)
    
    #function to insert names into second tree
    def insertNum(self, name, address, phone):
        #if current node is none, add node
        if self.phone is None:
            self.name = name
            self.address = address
            self.phone = phone
        else:
            #error if details already exist
            if self.name == name:
                os.system("clear")
                print("\033[91m" + "A contact already exists with that name")
            elif self.address == address:
                os.system("clear")
                print("\033[91m" + "A contact already exists with that address")
            elif self.phone == phone:
                os.system("clear")
                print("\033[91m" + "A contact already exists with that phone number")
            #if number is less than current number
            elif self.phone > phone:
                #if no left branch
                if self.left is None:
                    #add node into the left branch
                    self.left = Tree(name, address, phone)
                else:
                    #else call insert on left branch to keep searching
                    self.left.insertNum(name, address, phone)
            else:
                #if no right branch
                if self.right is None:
                    #add node into right branch
                    self.right = Tree(name, address, phone)
                else:
                    #else call insert on left branch to keep searching
                    self.right.insertNum(name, address, phone)

    #function to search names
    def searchname(self, head, contact):
        try:
            #if name is found
            if head.name == contact:
                #print contact
                print(f'Name: {head.name}, Address: {head.address}, Phone: {head.phone}')
                return
            #if name is less than current name
            elif head.name > contact:
                #if left branch exists
                if self.left:
                    #call search on left branch
                    self.searchname(head.left, contact)
                else:
                    #else print not found
                    print("\033[91m" + "Contact not found")
            #if name is greater than current name
            elif head.name < contact:
                #if right branch exists
                if self.right:
                    #call search on right branch
                    self.searchname(head.right, contact)
                #else print not found
                else:
                    print("\033[91m" + "Contact not found")
        except AttributeError:
            print("\033[91m" + "Contact not found")

    #function to search numbers
    def searchnum(self, nums, number):
        #if number is found
        try:
            if nums.phone == number:
                print(f'Name: {nums.name}, Address: {nums.address}, Phone: {nums.phone}')
                return
            #if number is less than current number
            elif nums.phone > number:
                #if left branch exists
                if self.left:
                    #call search on left branch
                    self.searchnum(nums.left, number)
                else:
                    #else print not found
                    #print in red
                    print("\033[91m" + "Contact not found")
            #if number is greater than current number
            elif nums.phone < number:
                #if right branch exists
                if self.right:
                    #call search on right branch
                    self.searchnum(nums.right, number)
                #else print not found
                else:
                    print("\033[91m" + "Contact not found")
        except AttributeError:
            print("\033[91m" + "Contact not found")

    def findnum(self, name):
        #use the name to find the number of the contact
        if self.name == name:
            glo = self.phone
        else:
            if self.name > name:
                if self.left:
                    self.left.findnum(name)
                else:
                    print("\033[91m" + "Contact not found")
            elif self.name < name:
                if self.right:
                    self.right.findnum(name)
                else:
                    print("\033[91m" + "Contact not found")

    #function to delete contacts name from first tree
    def deletename(self, name):
        try:
            if name == yournamecheck:
                print("\033[91m" + "You cannot delete your own contact")
            #if name is greater than current name
            if self is None:
                return self
            if name > self.name:
                #go right
                self.right = self.right.deletename(name)
            #if name is less than current name
            elif name < self.name:
                #go left
                self.left = self.left.deletename(name)
            else:
                #if no left branch
                if self.left is None and self.right is not None:
                    #find smallest on the right branch
                    tmp = self.right.smallest(self.right)
                    #set current node to smallest node
                    nums.deletenum(self.phone)
                    self.name = tmp.name
                    self.address = tmp.address
                    self.phone = tmp.phone
                    #delete smallest node
                    self.right = self.right.deletename(tmp.name)
                #if no right branch
                elif self.left is not None and self.right is None:
                    #find smallest on the left branch
                    tmp = self.left.largest(self.left)
                    #set current node to smallest node
                    nums.deletenum(self.phone)
                    self.name = tmp.name
                    self.address = tmp.address
                    self.phone = tmp.phone
                    #delete smallest node
                    self.left = self.left.deletename(tmp.name)
                #if no child nodes delete node
                if self.left is None and self.right is None and self.name == name:
                    nums.deletenum(self.phone)
                    return None
                #if both child nodes exist
                elif self.left and self.right:
                    #find smallest on the right branch
                    tmp = self.right.smallest(self.right)
                    nums.deletenum(self.phone)
                    #set current node to smallest node
                    self.name = tmp.name
                    self.address = tmp.address
                    self.phone = tmp.phone
                    #delete smallest node
                    self.right = self.right.deletename(tmp.name)
            #call delete on second tree
            return self
        except AttributeError:
            print("\033[91m" + "Contact does not exist")
            return self

    #function to delete contacts number from second tree
    def deletenum(self, num):
        try: 
            #if number is greater than current number
            if self is None:
                return self
            if num > self.phone:
                #go right
                self.right = self.right.deletenum(num)
            #if number is less than current number
            elif num < self.phone:
                #go left
                self.left = self.left.deletenum(num)
            else:
                #if no left branch
                if self.left is None and self.right is not None:
                    #find smallest on the right branch
                    tmp = self.right.smallest(self.right)
                    #set current node to smallest node
                    self.name = tmp.name
                    self.address = tmp.address
                    self.phone = tmp.phone
                    #delete smallest node
                    self.right = self.right.deletenum(tmp.phone)
                #if no right branch
                elif self.left is not None and self.right is None:
                    #find smallest on the left branch
                    tmp = self.left.largest(self.left)
                    #set current node to smallest node
                    self.name = tmp.name
                    self.address = tmp.address
                    self.phone = tmp.phone
                    #delete smallest node
                    self.left = self.left.deletenum(tmp.phone)
                #if no child nodes delete node
                elif self.left is None and self.right is None:
                    return None
                #if both child nodes exist
                elif self.left and self.right:
                    #find smallest on the right branch
                    tmp = self.right.smallest(self.right)
                    #set current node to smallest node
                    self.name = tmp.name
                    self.address = tmp.address
                    self.phone = tmp.phone
                    #delete smallest node
                    self.right = self.right.deletenum(tmp.phone)
            return self
        except AttributeError:
            return self

    #function to find smallest node
    def smallest(self, root):
        #start at root
        curr = root
        #while lft branch exists
        while curr.left != None:
            #advnace to left branch
            curr = curr.left
        #return smallest node
        return curr

    #function to print tree
    def printTree(self):
        #if left branch exists
        if self.left != None:
            #print the left branch
            self.left.printTree()
        if self.name is not None or self.address is not None or self.phone is not None:
            print(f'Name: {self.name}, Address: {self.address}, Phone: {self.phone}')
        #if right branch exists
        if self.right != None:
            #print the right branch
            self.right.printTree()

head = Tree(None, None, None)
nums = Tree(None, None, None)

#main function
def main(head, nums):
    #start by clearing the screen
    os.system('clear')
    #two trees, one for names one for numbers
    try:
        #print in blue
        print("\033[94m")
        print("Welcome to the phone book")
        print("To begin, enter your own contact details:")
        print("First Name:" + "\033[0m")
        yourname = input()
        yournamecheck = yourname
        print("\033[94m" + "Email:" + "\033[0m")
        youremail = input()
        print("\033[94m" + "Phone:" + "\033[0m")
        yourphone = int(input())
        yourphonecheck = yourphone
        head.insertName(yourname, youremail, yourphone)
        nums.insertName(yourname, youremail, yourphone)
    except ValueError:
        print("\033[91m" + "Invalid input detected, please try again!")
        input("Press Enter to continue..."  + "\033[0m")
        main(head, nums)
    except TypeError:
        print("\033[91m" + "Invalid input detected, please try again!")
        input("Press Enter to continue..."  + "\033[0m")
        main(head, nums)
    os.system('clear')
    #loop
    while True:
        try:
            print("\033[1;32m")
            print("================MENU=================");
            print()
            print("*************************************")
            print("* 1.          Add Contact           *")
            print("* 2.        Remove Contact          *")
            print("* 3.        Search by Name          *")
            print("* 4.     Search by Phone Number     *")
            print("* 5.       Show All Contacts        *")
            print("* 6.             Quit               *")
            print("* 7.             Help               *")
            print("*************************************")
            print()
            print()
            print("\033[1;37m")
            #enter 1-7 to pick an option
            choice = int(input("Enter your choice: "))
            #1 to insert a name into the phonebook
            if choice == 1:
                print("Please enter the following information:")
                print("First Name: ")
                name = input()
                print("Email Address: ")
                address = input()
                print("Phone Number: ")
                number = int(input())
                #calls insert on both trees, one sorted on names and one on numbers
                head.insertName(name, address, number)
                nums.insertNum(name, address, number)
            #2 to delete contacts
            elif choice == 2:
                if head is None:
                    print("\033[91m" + "No contacts to delete")
                else:
                    print("Enter the name of the contact you would like to delete:")
                    name = input()
                    #print("Enter the phone number of the contact you would like to delete:")
                    #num = int(input())
                    if name == yournamecheck:
                        print("\033[91m" + "You cannot delete your own contact")
                    else:
                        head.deletename(name)
            #3 to search for the name in the name trees
            elif choice == 3:
                if head is None:
                    print("\033[91m" + "No contacts to search")
                else:
                    print("Please enter the name you want to search for :")
                    contact = input()
                    #call search on the tree using inputed name
                    head.searchname(head, contact)
            #4 to search for the name in the numbers tree
            elif choice == 4:
                if nums is None:
                    print("\033[91m" + "No contacts to search")
                else:
                    print("Please enter the number you want to search for :")
                    number = int(input())
                    #call search on the tree using inputed number
                    foundname = nums.searchnum(nums, number)
            #5 to print all contacts
            elif choice == 5:
                #if no contacts error
                if head == None:
                    print("\033[91m" + "No contacts")
                #else print tree
                else:
                    head.printTree()
            #6 to exit
            elif choice == 6:
                print("\033[91m" + "Thank you for using the phone book!")
                exit(0)
            #everything else is invalid
            elif choice == 7:
                os.system('more README.md')
                pass
            else:
                print("\033[91m" + "Invalid choice")
        except ValueError:
            print("\033[91m" + "Invalid input detected, please try again!")
            input("Press Enter to continue..." + "\033[0m")
            os.system('clear')

if __name__ == "__main__":
    main(head, nums)