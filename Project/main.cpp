#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

/** 
 * Helper function for handling inputs with default value.
 * @tparam T the input type. Ignore for auto.
 * @param[in, out] value The value that may or may not change based on the user input.
 * 
 * @returns `true` if nothing was entered and default value is used else `false`.
*/
template <typename T>
bool default_input(T *value)
{
    string input;
    getline(cin, input);

    if (!input.empty())
    {
        istringstream(input) >> (*value);
        return false;
    }

    return true;
}

/** 
 * The Book model as per the requirement specified in the project statement.
*/
class Book
{
public:
    /** 
     * Shows all the books available in the inventory.
    */
    static void show_inventory()
    {
        cout << setw(30) << "Author" << setw(70) << "Title" << setw(30) << "Publisher" << setw(20) << "Price" << setw(20) << "Stock Position" << endl;
        for (auto const &a : inventory_map)
            for (auto const &t : a.second)
                t.second->show_book();
    }

    /** 
     * Searches for the book in the inventory_map.
     * @param[in, out] title The title of the book to be searched for (not case sensitive).
     * @param[in, out] author The author of the book to be searched for (not case sensitive).
     * 
     * @returns Book *` pointing to the instance of the found book from inventory. `nullptr` if not found.
    */
    static Book *search(string title, string author)
    {
        try
        {
            Book *result = inventory_map.at(key(author)).at(key(title));
            return result;
        }
        catch (out_of_range _)
        {
            return nullptr;
        }
    }

    /** 
     * Updates existing book in the inventory or else creates a new book with the specified properties.
     * Override default values to update the field.
     * @param[in, out] author Used for searching the inventory, and to create if not found in inventory.
     * @param[in, out] title Used for searching the inventory, and to create if not found in inventory.
     * @param[in] publisher Necessary for adding a new book. If empty string, ignored for field update.
     * @param[in] price Necessary for adding a new book. Ignored for field update if `< 0.0`.
     * @param[in] stock_delta Necessary for adding a new book. Not ignored for field update as `delta=0` won't cause a change.
     * 
     * @returns Book *` pointing to the instance of the updated / created book.
    */
    static Book *update_inventory(string author, string title, const string publisher = "", const double price = -1.0, const int stock_delta = 0)
    {
        Book *book = search(title, author);

        return (book == nullptr)
                   // Add book to the inventory if not found.
                   ? (inventory_map[key(author)][key(title)] = new Book(author, title, publisher, price, stock_delta))
                   // Update the properties of the book if found.
                   : book->update(publisher, price, stock_delta);
    }

    /**
     * Updates existing book in the inventory or else creates a new book with the specified properties.
     * Override default values to update the field.
     * @param[in, out] author Used for searching the inventory, and to create if not found in inventory.
     * @param[in, out] title Used for searching the inventory, and to create if not found in inventory.
     * @param[in] publisher Necessary for adding a new book. If empty string, ignored for field update.
     * @param[in] price Necessary for adding a new book. Ignored for field update if `< 0.0`.
     * @param[in] stock_delta Necessary for adding a new book. Not ignored for field update as `delta=0` won't cause a change.
     * 
     * @returns Book *` pointing to the instance of the updated / created book.
    */
    Book *update(const string publisher = "", const double price = -1.0, const int stock_delta = 0)
    {
        m_StockPosition += stock_delta;

        if (price > 0)
            m_Price = price;

        if (!publisher.empty() && !m_Publisher.compare(publisher))
            m_Publisher = publisher;

        return this;
    }

    /**
     * Attempts to take the specified book if found in inventory.
     * 
     * @param[in, out] author Used for searching the inventory.
     * @param[in, out] title Used for searching the inventory.
    */
    static void take(string author, string title)
    {
        Book *book = search(title, author);

        if (book != nullptr)
            book->take();
        else
            cout << '`' << title << "`  by  `" << author << "`  couldn't be found in the inventory." << endl;
    }

    /** 
     * @returns The publisher of this book.
    */
    string publisher() { return m_Publisher; }

    /** 
     * @returns The price of this book.
    */
    double price() { return m_Price; }

    /** 
     * @returns The stock position of this book.
    */
    int stock_position() { return m_StockPosition; }

    /** 
     * @returns The number of successful transactions occured in this runtime.
    */
    static int successful_transactions() { return _successful_transactions; }

    /** 
     * @returns The number of unsuccessful transactions occured in this runtime.
    */
    static int unsuccessful_transactions() { return _unsuccessful_transactions; }

    /** 
     * @returns The total number of transactions occured in this runtime.
    */
    static int total_transactions() { return _successful_transactions + _unsuccessful_transactions; }

private:
    // typedef for { Author : { Title : (Book *) } }
    using __BOOK_DB__ = map<string, map<string, Book *>>;

    /**
     * A nested map that stores the pointers to the instances of the Book in inventory.
     * 
     * @param key -> string : Author
     * @param key -> string : Title
     * @param value -> (Book *) : Pointer to the instance
    */
    static __BOOK_DB__ inventory_map;

    /**
     * @param _successful_transactions The number of successful transactions for analytics purpose.
     * @param _unsuccessful_transactions The number of unsuccessful transactions for analytics purpose.
    */
    static int _successful_transactions, _unsuccessful_transactions;

    /**
     * Converts the string to a valid key for handling inventory.
     * 
     * @param[in, out] str The string that is to be converted to a valid key. (The receiver is transformed and same is returned).
     * @returns The valid key string (same as `str`) after transforming.
    */
    static string key(string &str)
    {
        for (char &ch : str)
            ch = toupper(ch);
        return str;
    }

    /**
     * Generative constructor of `Book` to initialize all properties.
     * 
     * @param[in] author The author of the book.
     * @param[in] title The title of the book.
     * @param[in] publisher The publisher of the book.
     * @param[in] price The price of the book.
     * @param[in] stock The stock position of the book.
    */
    Book(const string author, const string title, const string publisher, const double price, const int stock)
        : m_Author(author),
          m_Title(title),
          m_Publisher(publisher),
          m_Price(price),
          m_StockPosition(stock)
    {
    }

    Book(const Book &) = delete; // Copy constructor strictly not implemented.

    /**
     * Shows the properties of the book as per table alignment made by static method: `Book::show_inventory`.
     * May not convey a proper context if called externally. Shall be called by `Book::show_inventory` to 
     * get a meaningful context.
    */
    void show_book()
    {
        cout << setw(30) << m_Author << setw(70) << m_Title << setw(30) << m_Publisher << setw(20) << m_Price << setw(20) << m_StockPosition << endl;
    }

    /**
     * Requests the user for take quantity.
     * 
     * @returns The number of copies of the book the client intends to take from the inventory.
    */
    int request_take_qty()
    {
        if (m_StockPosition)
        {
            int takes = 1;

            cout << "No. of copies to be fetched: (1) ";
            default_input(&takes);

            // Make sure [takes] not greater than available stock
            while (takes > m_StockPosition)
            {
                cout << "Exceeds available stock" << endl
                     << "Press [Enter] to cancel or enter a new value: ";
                if (default_input(&takes))
                    return 0;
            }
            return takes;
        }
        else
            cout << "Oops! The requested book is OUT-OF-STOCK :(" << endl;
        return 0;
    }

    /**
     * Attempts to follow take-away procedure based on client's requirement.
    */
    void take()
    {
        cout << setw(30) << "Author" << setw(70) << "Title" << setw(20) << "Price" << setw(20) << "Stock Position" << endl
             << setw(30) << m_Author << setw(70) << m_Title << setw(20) << m_Price << setw(20) << m_StockPosition << endl
             << endl;

        int takes = request_take_qty();
        if (takes)
        {
            cout << setw(30) << "Author" << setw(70) << "Title" << setw(20) << "Price" << setw(20) << "Qty" << setw(20) << "Payable Amount " << endl
                 << setw(30) << m_Author << setw(70) << m_Title << setw(20) << m_Price << setw(20) << takes << setw(20) << (takes * m_Price) << endl
                 << endl
                 << "Press [Enter] to confirm, or any other key to cancel: ";

            if (default_input(new char))
            {
                m_StockPosition -= takes;
                _successful_transactions++;
            }
            else
                _unsuccessful_transactions++;
        }
    }

    string m_Author, m_Title, m_Publisher;

    double m_Price;

    int m_StockPosition;
};

Book::__BOOK_DB__ Book::inventory_map = __BOOK_DB__();
int Book::_successful_transactions = 0;
int Book::_unsuccessful_transactions = 0;

/** 
 * Populates the inventory with demo data.
*/
void init_demo_inventory()
{
    Book::update_inventory("J.K. Rowling", "Harry Potter", "Pottermore", 300.0, 220);
    Book::update_inventory("Paulo Coelho", "The Alchemist", "HarperCollins", 200.0, 20);
    Book::update_inventory("Bjarne Stroustrup", "The C++ Programming Language", "Addison-Wesley", 10.0, 20);
    Book::update_inventory("Linus Torvalds", "Just for Fun", "Unknown", 100.0, 0);
    Book::update_inventory("Walter Isaacson", "Steve Jobs", "Simon & Schuster", 100.0, 0);
    Book::update_inventory("Ashlee Vance", "Elon Musk", "HarperCollins", 100.0, 100);
}

/** 
 * Menu option driver to take a book.
*/
void take_a_book()
{
    string title, author;

    cout << "Check-out a Book" << endl
         << "Enter title of the book: ";
    getline(cin, title);

    cout << "Enter author of the book: ";
    getline(cin, author);
    cout << endl;
    Book::take(author, title);
}

/** 
 * Menu option driver to update inventory (update / add book).
*/
void update_inventory()
{
    string title, author, publisher = "";
    double price = -1.0;
    int stock_delta = 0;

    cout << "Update/Add a book in/to the inventory" << endl
         << "TITLE         :\t";
    getline(cin, title);

    cout << "AUTHOR        :\t";
    getline(cin, author);

    Book *book = Book::search(title, author);

    if (book == nullptr)
    {
        cout << endl
             << "No matching book found in inventory. (Ctrl+C) to terminate in-between." << endl
             << endl;

        cout << "PUBLISHER     :\t";
        getline(cin, publisher);

        cout << "PRICE         :\t";
        cin >> price;

        cout << "STOCK         :\t";
        cin >> stock_delta;

        Book::update_inventory(author, title, publisher, price, stock_delta);
    }
    else
    {
        cout << endl
             << "For the following fields, press [Enter] to ignore updation of field" << endl
             << endl;

        cout << "PUBLISHER (" << book->publisher() << ") : ";
        default_input(&publisher);

        cout << "PRICE (" << book->price() << ") : ";
        default_input(&price);

        cout << "STOCK DELTA (0) : ";
        default_input(&stock_delta);
    }
}

/** 
 * Menu option driver show analytics parameters.
*/
void show_analytics()
{
    cout << endl
         << "Analytics: " << endl
         << endl
         << "Successful Transactions   :    " << Book::successful_transactions() << endl
         << "Unsuccessful Transactions :    " << Book::unsuccessful_transactions() << endl
         << "Total Transactions        :    " << Book::total_transactions() << endl
         << endl;
}

using menu_option_cb = auto (*)() -> void;
using menu_option = pair<string, menu_option_cb>;

const menu_option menu_options[]{
    menu_option("Exit", [] {}),
    menu_option("Check-out book", take_a_book),
    menu_option("Show all available books", Book::show_inventory),
    menu_option("Update / Add Book to Inventory", update_inventory),
    menu_option("Show analytics", show_analytics),
};

/** 
 * Menu driver.
 * 
 * @returns `0` if user inputs exit option.
*/
int show_menu(bool pause = true)
{
    if (pause)
    {
        cout << endl
             << "Press any key to continue..." << endl;
        default_input(new char);
    }

    int selection = 0;
    for (auto const &option : menu_options)
        cout << '[' << selection++ << "]\t" << option.first << endl;
    selection = 0;

    cout << endl
         << "Enter menu option (number) (0 or [Enter] to exit): ";
    if (default_input(&selection))
        return 0;

    cout << endl
         << endl;
    menu_options[selection].second();
    return selection;
}

int main()
{
    init_demo_inventory();

    try
    {
        // system("clear"); // Clear the screen (deprecating as platform dependent)
        cout << endl
             << "+-------------------------------------------------------------+" << endl
             << "|   Welcome to Rithvik's Book Inventory Management Software   |" << endl
             << "+-------------------------------------------------------------+" << endl
             << endl;

        show_menu(false);

        // Event loop of the program
        while (show_menu() != 0)
            ;

        return 0;
    }
    catch (exception e)
    {
        cout << "Caught unhandled exception." << endl
             << e.what();

        return 0xBAD;
    }
}