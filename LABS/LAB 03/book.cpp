#include <iostream>
#include "book.h"
using namespace std;

void Book::setTitle(string t) {
    title=t;
}
void Book::setAuthor(string a) {
    author=a;
}
void Book::setPages(int p) {
    if (p>0)pages=p;
    else pages=0;
}
string Book::getTitle() {
    return title;
}
string Book::getAuthor() {
    return author;
}
int Book::getPages() {
    return pages;
}
int main() {
    Book b;
    b.setTitle("One of us is dead");
    b.setAuthor("Jeneva Rose");
    b.setPages(464);
    cout << b.getTitle() << endl;
    cout << b.getAuthor() << endl;
    cout << b.getPages() << endl;
return 0;
}
