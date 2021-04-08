# C++ Project

## Project Statement

A book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as `author`, `title`, `price`, `publisher` and `stock position`.
Whenever a customer wants a book, the sales person inputs the `title` and `author` and the system searches the list and displays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the system displays the book details and requests for the number of copies required. If the requested copies are available, the `total cost` of the requested copies is displayed; otherwise `“Required copies not in stock”` is displayed. Design a system using a class called books with suitable member functions and constructors. Use `new` operator in constructors to allocate memory space required.

### Add the following features also

- [x] The `price` of the books should be updated as and when required. Use a `private` member function to implement this.
- [x] The stock value of each book should be automatically updated as soon as a transaction is completed.
- [x] The number of `successful` and `unsuccessful` transactions should be recorded for the purpose of statistical analysis. Use `static` data members to keep count of transactions.

## Building the binaries

*Pre-built binaries are available in the `bin` folder.*

**To compile & run:**

```sh
c++ main.cpp -o "bin/<platform>-<architecture>" && "./bin/<platform>-<architecture>"
```

## Output

### Raw Text

```text
coffeelake in /media/coffeelake/dev/CSE1002/Project on main ● λ g++ main.cpp -o "bin/linux-x64" && "./bin/linux-x64"

+-------------------------------------------------------------+
|   Welcome to Rithvik's Book Inventory Management Software   |
+-------------------------------------------------------------+

[0]     Exit
[1]     Check-out book
[2]     Show all available books
[3]     Update / Add Book to Inventory
[4]     Show analytics

Enter menu option (number) (0 or [Enter] to exit): 2


                        Author                                                                 Title                     Publisher               Price      Stock Position
                  Ashlee Vance                                                             Elon Musk                 HarperCollins                 100                 100
             Bjarne Stroustrup                                          The C++ Programming Language                Addison-Wesley                  10                  20
                  J.K. Rowling                                                          Harry Potter                    Pottermore                 300                 220
                Linus Torvalds                                                          Just for Fun                       Unknown                 100                   0
                  Paulo Coelho                                                         The Alchemist                 HarperCollins                 200                  20
               Walter Isaacson                                                            Steve Jobs              Simon & Schuster                 100                   0

Press any key to continue...

[0]     Exit
[1]     Check-out book
[2]     Show all available books
[3]     Update / Add Book to Inventory
[4]     Show analytics

Enter menu option (number) (0 or [Enter] to exit): 1


Check-out a Book
Enter title of the book: elon musk
Enter author of the book: ashlee vance

                        Author                                                                 Title               Price      Stock Position
                  Ashlee Vance                                                             Elon Musk                 100                 100

No. of copies to be fetched: (1) 2
                        Author                                                                 Title               Price                 Qty     Payable Amount 
                  Ashlee Vance                                                             Elon Musk                 100                   2                 200

Press [Enter] to confirm, or any other key to cancel: 

Press any key to continue...

[0]     Exit
[1]     Check-out book
[2]     Show all available books
[3]     Update / Add Book to Inventory
[4]     Show analytics

Enter menu option (number) (0 or [Enter] to exit): 4



Analytics: 

Successful Transactions   :    1
Unsuccessful Transactions :    0
Total Transactions        :    1


Press any key to continue...

[0]     Exit
[1]     Check-out book
[2]     Show all available books
[3]     Update / Add Book to Inventory
[4]     Show analytics

Enter menu option (number) (0 or [Enter] to exit): 3


Update/Add a book in/to the inventory
TITLE         : elon musk
AUTHOR        : ashlee vance

For the following fields, press [Enter] to ignore updation of field

PUBLISHER (HarperCollins) : 
PRICE (100) : 
STOCK DELTA (0) : 14

Press any key to continue...

[0]     Exit
[1]     Check-out book
[2]     Show all available books
[3]     Update / Add Book to Inventory
[4]     Show analytics

Enter menu option (number) (0 or [Enter] to exit): 2


                        Author                                                                 Title                     Publisher               Price      Stock Position
                  Ashlee Vance                                                             Elon Musk                 HarperCollins                 100                  98
             Bjarne Stroustrup                                          The C++ Programming Language                Addison-Wesley                  10                  20
                  J.K. Rowling                                                          Harry Potter                    Pottermore                 300                 220
                Linus Torvalds                                                          Just for Fun                       Unknown                 100                   0
                  Paulo Coelho                                                         The Alchemist                 HarperCollins                 200                  20
               Walter Isaacson                                                            Steve Jobs              Simon & Schuster                 100                   0

Press any key to continue...

[0]     Exit
[1]     Check-out book
[2]     Show all available books
[3]     Update / Add Book to Inventory
[4]     Show analytics

Enter menu option (number) (0 or [Enter] to exit): 
coffeelake in /media/coffeelake/dev/CSE1002/Project on main ● λ 
```

### Screenshots

![Page 1](https://github.com/rithviknishad/CSE1002/blob/ebf5a271174c23e1dd4307d96ff66d4fd672d924/Project/screenshots/1.png)
![Page 2](https://github.com/rithviknishad/CSE1002/blob/ebf5a271174c23e1dd4307d96ff66d4fd672d924/Project/screenshots/2.png)
![Page 3](https://github.com/rithviknishad/CSE1002/blob/ebf5a271174c23e1dd4307d96ff66d4fd672d924/Project/screenshots/3.png)
