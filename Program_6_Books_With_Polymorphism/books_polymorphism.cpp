/*
Umar Khan
014477331
CECS275
Program 6
*/


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Enumeration for possible book types
enum Books { FICTION, NON_FICTION, REFERENCE, UNSPECIFIED };

/**
 * Class Book contains name, numberPages and type as members
 */
class Book {
protected:
    string name;     // name of book
    int numberPages; // number of pages in book
    Books type;      // type of book

public:
    // Static member to save total number of pages across all books
    static int totalPages;

    // Default constructor, intializes name with empty string and numberPages to zero and type to UNSPECIFIED
    Book(): name(""), numberPages(0), type(UNSPECIFIED) {}

    // Parameterized construtor
    Book(string& name, int numberPages) {
        setName(name);
        setNumberOfPages(numberPages);
        type = UNSPECIFIED;
        totalPages += numberPages;
    }

    // Setter for number of pages
    void setNumberOfPages(int num) { numberPages = num; }

    // Setter for name
    void setName(string& n) { name = n; }

    // Getter for name 
    string getName() const { return name; }

    // Getter for number of pages
    int getNumberOfPages() const { return numberPages; }

    // Getter for type of book
    Books getType() const { return type; }

    virtual void read(ifstream& fin) = 0;
    virtual void print() const = 0;
};

int Book::totalPages = 0;

// A subclass of Book, fiction has addition member genre
class Fiction: public Book {
    string genre;
public:
    // Default constructor, calls base class constructor, initalizes type with FICTION
    Fiction():Book(), genre("") { type = FICTION; }

    // Parameterized constructor, calls base class constructor and initalizes type with FICTION and genre
    // with user specified value
    Fiction(string& name, int numberPages, string& genreRef): Book(name, numberPages), genre(genreRef) { type = FICTION; }

    // Getter for genre
    string getGenre() const { return genre; }

    // Setter for genre
    void setGenre(string& genreRef) { genre = genreRef; }

    // Method to read the book data from the given input stream
    void read(ifstream& fin) {
        fin >> name >> numberPages >> genre;
        //Update total number of pages
        totalPages += numberPages;
    }

    // Method to print the book details
    void print() const {
        cout << "Name:" << setw(20) << left << name << "\tType:Fiction\t\tPages:" << numberPages << "\tGenre:" << setw(20) << left << genre << endl;
    }
};

// A subclass of Book, non-fiction has addition member subject and number of illustrations
class Nonfiction: public Book {
    string subject;
    int numberOfIllustrations;
public:
    // Default constructor, calls base class constructor, initalizes type with NON_FICTION
    Nonfiction():Book() { type = NON_FICTION; }

    // Parameterized constructor, calls base class constructor and initalizes type with NON_FICTION 
    Nonfiction(string& name, int numberPages, string& subject, int illustrationsCount): Book(name, numberPages) { 
        type = NON_FICTION; 
        numberOfIllustrations = illustrationsCount;
        this->subject = subject;
    }

    // Getter for number of illustrations
    int getNumberOfIllustrations() const { return numberOfIllustrations; }

    // Setter for number of illustrations
    void setNumberOfIllustrations(int num) { numberOfIllustrations = num; } 

    // Getter for subject
    string getSubject() const { return subject; }

    // Setter for subject
    void setSubject(string& subject) { this->subject = subject; } 

    // Method to read the book data from the given input stream
    void read(ifstream& fin) {
        fin >> name >> numberPages >> subject >> numberOfIllustrations;
        //Update total number of pages
        totalPages += numberPages;
    }

    // Method to print the book details
    void print() const {
        cout << "Name:" << setw(20) << left << name << "\tType:Nonfiction\t\tPages:" << numberPages << "\tSubject:" << setw(20) << left << subject
             << "\tIllustrations:" << numberOfIllustrations << endl;
    }
};

class Reference: public Book {
public:
    //Default constructor
    Reference():Book() { type = REFERENCE; }

    // Parameterized constructor
    Reference(string& name, int numberPages): Book(name, numberPages) { type = REFERENCE; }

    // Method to read the book data from the given input stream
    void read(ifstream& fin) {
        fin >> name >> numberPages;

        //Update total number of pages
        totalPages += numberPages;
    }

    // Method to print the book details
    void print() const {
        cout << "Name:" << setw(20) << left << name << "\tType:Reference\t\tPages:" << numberPages << endl;
    }
};

// A factory method, that creates  a book of given type from the data available on given input stream
Book* BookFactory(int type, ifstream& fin) {
    switch(type) {
        // If type is fiction then create a fiction book
        case FICTION: {
            Fiction* fiction = new Fiction();
            // Construct the book from data on input stream
            fiction->read(fin);     
            return fiction;
        }

        // If type is nonfiction then create a nonfiction book
        case NON_FICTION: {
            Nonfiction* nonfiction = new Nonfiction();

            // Construct the book from data on input stream
            nonfiction->read(fin);
            return nonfiction;    
        }

        // If type is reference then create a reference book
        case REFERENCE: {
            Reference* reference = new Reference();
            reference->read(fin);
            return reference;
        }

        // default
        default:
            return NULL;
    }
}

// Function to print a book, it calls the virtual print method of book
void PrintAll(Book* book) {
    if (book != NULL) {
        book->print();
    }
}

int main() {
    ifstream fin("books.txt");
    Book* book = NULL;
    int type;
    while (fin >> type) {
        // Create a book of type from data in file
        book = BookFactory(type, fin);
        // Print the book details
        PrintAll(book);

        // Free the memory
        if (book != NULL) 
            delete book;
        book = NULL;
    }

    // Print total pages
    cout << "Total pages:" << Book::totalPages;

    fin.close();
    return 0;
}