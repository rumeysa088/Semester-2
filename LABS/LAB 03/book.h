
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int pages;

public:
    void setTitle(string t);
    void setAuthor(string a);
    void setPages(int p);

    string getTitle();
    string getAuthor();
    int getPages();
};

#endif