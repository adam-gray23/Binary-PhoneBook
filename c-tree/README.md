How to compile

******************************************************************

The zip file contains a makefile which compiles and runs the program.

To compile and run the program in a terminal type: make

The program can also be compiled manually in a terminal by running

gcc -o phone phone.c

The program can be ran manually in a terminal by running:

./phone

******************************************************************

Test cases

******************************************************************

Note: 

All test cases are based off a single run of make

******************************
* 1. Add Contact             *
* 2. Delate Contact          *
* 3. Search Name             *
* 4. Search Phone Number     *
* 5. Display All Contacts    *
* 6. Quit                    *
* 7. Help                    *
******************************

******************************************************************

******************************************************************

Test case 1 (Successful insert contacts)
————————————————————————————————————————
Name:
niall
Email:
niall@niall.com
1
Please enter a number: 1
Enter name: adam
Enter email address: adam@adam.com
Enter number: 2
Please enter a number: 1
Enter name: scott
Enter email address: scott@scott.com
Enter number: 3
Please enter a number: 1
Enter name: rob
Enter email address: rob@rob.com
Enter number: 4
Please enter a number: 1
Enter name: will
Enter email address: will@will.com
Enter number: 5
Please enter a number: 5

******************************************************************

******************************************************************

Test case 2 (Failure insert contacts)
—————————————————————————————————————
Please enter a number: 1
Enter name: aaron
Enter email address: aaron@aaron.com
Enter number: abc

******************************************************************

******************************************************************

Test case 3( Successful delete contact)
———————————————————————————————————————
Please enter a number: 2
Enter name to remove: scott
Please enter number: 5

******************************************************************

******************************************************************

Test case 4 (Delete contact failure)
———————————————————————————————————
Please enter a number: 2
Enter a name to remove: john

******************************************************************

******************************************************************

Test case 5(Successful search by name)
—————————————————————————————————————
Please enter a number: 3
Enter a name: adam

******************************************************************

******************************************************************

Test case 6(Failure search by name)
——————————————————————————————————
Please enter number: 3
Enter a name: john

******************************************************************

******************************************************************

Test case 7(Successful search by phone number)
—————————————————————————————————————————————
Please enter a number: 4
Enter number: 2

******************************************************************

****************************************************************** 

Test case 8 (Failure search by phone number)
———————————————————————————————————————————
Please enter a number: 4
Enter number: 6

******************************************************************

******************************************************************

Test case 9 (Successful Display all contacts)
————————————————————————————————————————————
Please enter a number: 5

******************************************************************

******************************************************************

Test case 10 (Successful Manual access)
——————————————————————————————————————
Please enter a number: 7

******************************************************************

******************************************************************

Test case 11 (Successful Exit the program)
—————————————————————————————————————————
Please enter a number: 6

******************************************************************