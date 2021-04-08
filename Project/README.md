# C++ Project

## Project Statement

A book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as `author`, `title`, `price`, `publisher` and `stock position`.
Whenever a customer wants a book, the sales person inputs the `title` and `author` and the system searches the list and displays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the system displays the book details and requests for the number of copies required. If the requested copies are available, the `total cost` of the requested copies is displayed; otherwise `“Required copies not in stock”` is displayed. Design a system using a class called books with suitable member functions and constructors. Use `new` operator in constructors to allocate memory space required.

### Add the following features also

- [x] The `price` of the books should be updated as and when required. Use a `private` member function to implement this.
- [x] The stock value of each book should be automatically updated as soon as a transaction is completed.
- [x] The number of `successful` and `unsuccessful` transactions should be recorded for the purpose of statistical analysis. Use `static` data members to keep count of transactions.
