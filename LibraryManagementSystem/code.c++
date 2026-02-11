#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class book {
    private:
    string title;
    string author;
    bool isAvailable;

    public:
    book(string t, string a) : title(t), author(a), isAvailable(true){ }

    string getTitle() const {return title; }
    string getAuthor() const {return author; }
    bool getisAvailablity() const {return isAvailable; }

    void borrow() {isAvailable = false; }
    void returnBook() { isAvailable = true; }
};  

class library {
    private:
    vector<book> books;

    public:
    void addBook(book& book) {
        books.push_back(book);
    }

    void viewBooks(){
 
        for(const auto& book : books){
            cout<<"Title: " << book.getTitle()
            <<", Author: " << book.getAuthor()
            <<", Available: " <<(book.getisAvailablity() ? "Yes" : "No") << endl;
        }
    }

    bool borrowedBook(const string& title){
        for(auto& book : books){
            if (book.getTitle() == title && book.getisAvailablity()) {
                book.borrow();
                return true;
            }
        }
        return false;
    }

    void saveToFile(const string& filename) {   
        ofstream outFile (filename);
        for(const auto& book : books ) {
            outFile << book.getTitle() <<", "<<book.getAuthor() <<"," <<book.getisAvailablity()<<endl;
        }
        outFile.close();
    }

    void loadFromFile(const string& filename) {
        ifstream inFile (filename);

        string title, author, availability;
        while (getline(inFile, title, ',') && getline(inFile, author, ',') && getline(inFile, availability)) {
            book b(title, author);

            if (availability == "0") {
                b.borrow();
            }
                addBook(b);
        }
        inFile.close();
    }
};
