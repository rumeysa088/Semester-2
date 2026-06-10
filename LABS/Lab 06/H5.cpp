#include<iostream>
using namespace std;
class Media {
protected:
    string title;
public:
    void setTitle(string t) {title = t;}
    void showTitle() {cout << "Title: " << title << endl;}
};
class Book : public Media {
public:
    void showAuthor(string author) { cout << "Author: " << author << endl;}
};
class Video : public Media {
public:
    void showDuration(int minutes) {cout << "Duration: " << minutes << " minutes" << endl;}
};
class Audio : public Media {
public:
    void showSinger(string singer) {cout << "Singer: " << singer << endl;}
};
int main() {
    Book b;
    Video v;
    Audio a;
    b.setTitle("C++ Programming");
    b.showTitle();              // Shared feature
    b.showAuthor("Bjarne");     // Specific feature
    v.setTitle("OOP Tutorial");
    v.showTitle();              // Shared feature
    v.showDuration(45);         // Specific feature
    a.setTitle("Classical Music");
    a.showTitle();              // Shared feature
    a.showSinger("Ali");        // Specific feature
    return 0;
}