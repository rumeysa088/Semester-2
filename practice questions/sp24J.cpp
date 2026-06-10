#include<iostream>
using namespace std;
class Media {
protected:
    Media** items;   
    int itemCount;
    int maxItems;
public:
    Media(int m = 0) {
        maxItems = m;
        itemCount = 0;
        items = new Media*[maxItems];
    }
    virtual void add_media() = 0;
    virtual void update_media() = 0;
    virtual void remove_media() = 0;
    virtual void display() {
        cout << "Media item\n";
    }
};
class Video : public Media {
    int resolution;
    float duration;
    string title;
public:
    Video(string t, int r, float d, int m = 0)
        : Media(m), title(t), resolution(r), duration(d) {}
    void add_media() override {
        if (itemCount < maxItems) {
            items[itemCount++] = new Video(*this);
            cout << "Video added: " << title << endl;
        }
    }

    void update_media() override {
        cout << "Video updated: " << title << endl;
    }

    void remove_media() override {
        cout << "Video removed: " << title << endl;
    }

    void display() override {
        cout << "Video: " << title
             << " | " << resolution << "p"
             << " | " << duration << " min\n";
    }
};

// ---------------- AUDIO ----------------
class Audio : public Media {
    string artist;
    string pitch;
    string title;

public:
    Audio(string t, string a, string p, int m = 0)
        : Media(m), title(t), artist(a), pitch(p) {}

    void add_media() override {
        if (itemCount < maxItems) {
            items[itemCount++] = new Audio(*this);
            cout << "Audio added: " << title << endl;
        }
    }

    void update_media() override {
        cout << "Audio updated: " << title << endl;
    }

    void remove_media() override {
        cout << "Audio removed: " << title << endl;
    }

    void display() override {
        cout << "Audio: " << title
             << " | Artist: " << artist
             << " | Pitch: " << pitch << endl;
    }
};

// ---------------- MAIN ----------------
int main() {

    Media* library[2];

    library[0] = new Video("Movie1", 1080, 2.5, 2);
    library[1] = new Audio("Song1", "Atif", "High", 2);

    // polymorphic calls
    library[0]->display();
    library[1]->display();

    return 0;
}
#include<iostream>
using namespace std;

class SensitiveDatabase {
    string* data_storage;
    int data_count;
    string encryption_key;
    int cap;
public:
    SensitiveDatabase(int c) {
        cap = c;
        data_count = 0;
        try {
            data_storage = new string[cap];
            if (!data_storage)
                throw "Memory allocation failed!";
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
    void update_data(string msg) {
        if (data_count < cap) {
            data_storage[data_count++] = msg;
        } else {
            cout << "Database full!" << endl;
        }
    }

    void fetch_data() {
        for (int i = 0; i < data_count; i++) {
            cout << data_storage[i] << endl;
        }
    }

    void remove_data() {
        if (data_count > 0)
            data_count--;
    }
    friend void access_sensitive_data(SensitiveDatabase obj);
    friend void perform_complex_computation(SensitiveDatabase obj, int key);
};
void access_sensitive_data(SensitiveDatabase obj) {
    cout << "Sensitive Data:\n";

    for (int i = 0; i < obj.data_count; i++) {

        if (obj.data_storage[i] == "") {
            obj.data_storage[i] = "No message received & encrypt using (string + 2)";
        }

        cout << obj.data_storage[i] << endl;
    }
}
void perform_complex_computation(SensitiveDatabase obj, int key) {
    cout << "\nEncrypted Data:\n";

    for (int i = 0; i < obj.data_count; i++) {
        string s = obj.data_storage[i];

        for (int j = 0; j < s.length(); j++) {
            if (isalpha(s[j])) {
                char base = islower(s[j]) ? 'a' : 'A';
                s[j] = (s[j] - base + key) % 26 + base;
            }
        }

        cout << s << endl;
    }
}
int main() {
    SensitiveDatabase db(3);

    db.update_data("Meeting at 10");
    db.update_data("Search operation");
    db.update_data("");

    access_sensitive_data(db);

    perform_complex_computation(db, 2);

    return 0;
 }
#include<iostream>
using namespace std;

// ---------------- BASE CLASS ----------------
class Person {
protected:
    string name;
    int age;
    string work;
    float salary;

public:
    Person() {
        name = "";
        age = 0;
        work = "";
        salary = 0;
    }

    Person(string n, int a, string w, float s) {
        name = n;
        age = a;
        work = w;
        salary = s;
    }

    string getName() { return name; }
    int getAge() { return age; }
    string getWork() { return work; }
    float getSalary() { return salary; }
};

// ---------------- PLAYER CLASS ----------------
class Player : public Person {
protected:
    int runs, matches, ODIs, T20s, wickets, fours, sixes;

public:
    Player(string n, int a, float s,
           int r, int m, int o, int t, int w, int f, int si)
        : Person(n, a, "Player", s) {
        runs = r;
        matches = m;
        ODIs = o;
        T20s = t;
        wickets = w;
        fours = f;
        sixes = si;
    }

    string getWork() override {
        return "Cricket Player";
    }

    // pre-increment (10%)
    float operator++() {
        salary += salary * 0.10;
        return salary;
    }

    // post-increment (15%)
    float operator++(int) {
        float temp = salary;
        salary += salary * 0.15;
        return temp;
    }

    void display() {
        cout << "Player: " << name
             << "\nAge: " << age
             << "\nWork: " << getWork()
             << "\nSalary: " << salary << endl;
    }
};

// ---------------- UMPIRE CLASS ----------------
class Umpire : public Player {
    int startYear, noT20s, noODIs, noTests;

public:
    Umpire(string n, int a, float s,
           int sy, int t20, int odi, int test)
        : Player(n, a, s, 0, 0, 0, 0, 0, 0, 0) {
        startYear = sy;
        noT20s = t20;
        noODIs = odi;
        noTests = test;
    }

    string getWork() override {
        return "Cricket Umpire";
    }

    void display() {
        cout << "Umpire: " << name
             << "\nAge: " << age
             << "\nWork: " << getWork()
             << "\nSalary: " << salary << endl;
    }

    // same operator logic
    float operator++() {
        salary += salary * 0.10;
        return salary;
    }

    float operator++(int) {
        float temp = salary;
        salary += salary * 0.15;
        return temp;
    }
};

// ---------------- MAIN ----------------
int main() {

    Player p("Babar", 28, 50000, 5000, 100, 50, 30, 10, 200, 150);

    cout << "Before increment:\n";
    p.display();

    ++p;      // 10%
    p++;      // 15%

    cout << "\nAfter increments:\n";
    p.display();

    Umpire u("Aleem", 45, 70000, 2005, 20, 50, 100);

    cout << "\nUmpire before:\n";
    u.display();

    ++u;
    u++;

    cout << "\nUmpire after:\n";
    u.display();

    return 0;
}

#include<iostream>
using namespace std;

// ---------------- ABSTRACT BASE CLASS ----------------
class Book {
protected:
    int book_id;
    string title;
    string author;
    float price;
    int quantity;

public:
    Book(int id, string t, string a, float p, int q) {
        if (p < 0) throw "Invalid Price!";
        if (q < 0) throw "Invalid Quantity!";

        book_id = id;
        title = t;
        author = a;
        price = p;
        quantity = q;
    }

    virtual void addBook() = 0;
    virtual void removeBook() = 0;
    virtual void updateBook() = 0;
    virtual void display() = 0;

    virtual ~Book() {}
};

// ---------------- NOVEL ----------------
class Novel : public Book {
    string genre;
    string publication_year;
    float rating;

public:
    Novel(int id, string t, string a, float p, int q,
          string g, string py, float r)
        : Book(id, t, a, p, q) {
        genre = g;
        publication_year = py;
        rating = r;
    }

    void addBook() override {
        cout << "Novel added\n";
    }

    void removeBook() override {
        cout << "Novel removed\n";
    }

    void updateBook() override {
        cout << "Novel updated\n";
    }

    void display() override {
        cout << "\n--- Novel ---\n";
        cout << "ID: " << book_id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nPrice: " << price
             << "\nQuantity: " << quantity
             << "\nGenre: " << genre
             << "\nYear: " << publication_year
             << "\nRating: " << rating << endl;
    }
};

// ---------------- TEXTBOOK ----------------
class Textbook : public Book {
    string subject;
    int edition;
    string publisher;

public:
    Textbook(int id, string t, string a, float p, int q,
             string s, int e, string pub)
        : Book(id, t, a, p, q) {
        subject = s;
        edition = e;
        publisher = pub;
    }

    void addBook() override {
        cout << "Textbook added\n";
    }

    void removeBook() override {
        cout << "Textbook removed\n";
    }

    void updateBook() override {
        cout << "Textbook updated\n";
    }

    void display() override {
        cout << "\n--- Textbook ---\n";
        cout << "ID: " << book_id
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nPrice: " << price
             << "\nQuantity: " << quantity
             << "\nSubject: " << subject
             << "\nEdition: " << edition
             << "\nPublisher: " << publisher << endl;
    }
};

// ---------------- MAIN (POLYMORPHISM) ----------------
int main() {

    try {
        Book* library[2];

        library[0] = new Novel(1, "Harry Potter", "J.K. Rowling", 500, 10,
                               "Fantasy", "1997", 4.9);

        library[1] = new Textbook(2, "Physics", "Halliday", 800, 5,
                                  "Science", 12, "Wiley");

        for (int i = 0; i < 2; i++) {
            library[i]->display();
        }

    } catch (const char* e) {
        cout << "Error: " << e << endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

// ---------------- BASE TEMPLATE CLASS ----------------
template <class T>
class Person {
protected:
    string name;
    T age;
    string role;
    float salary;

public:
    Person(string n, string r, T a, float s = 0) {
        name = n;
        role = r;
        age = a;
        salary = s;
    }

    string getName() { return name; }
    string getRole() { return role; }
    T getAge() { return age; }
    float getSalary() { return salary; }

    virtual void display() {
        cout << "Name: " << name
             << "\nRole: " << role
             << "\nAge: " << age
             << "\nSalary: " << salary << endl;
    }
};

// ---------------- TA CLASS ----------------
template <class T>
class TA : public Person<T> {
    string program;
    float GPA;
    string courses;
    int credits;

public:
    TA(string n, T a, float s, string p, float g, string c, int cr)
        : Person<T>(n, "TA", a, s) {
        program = p;
        GPA = g;
        courses = c;
        credits = cr;
    }

    string getRole() {
        return "Teaching Assistant";
    }

    void display() override {
        Person<T>::display();
        cout << "Program: " << program
             << "\nGPA: " << GPA << endl;
    }

    // ++ salary (10%)
    float operator++() {
        this->salary += this->salary * 0.10;
        return this->salary;
    }

    // post ++ (5%)
    float operator++(int) {
        float temp = this->salary;
        this->salary += this->salary * 0.05;
        return temp;
    }
};

// ---------------- PROFESSOR CLASS ----------------
template <class T>
class Professor : public Person<T> {
    string department;
    string position;
    int experience;
    string research;

public:
    Professor(string n, T a, float s, string d, string p, int e, string r)
        : Person<T>(n, "Professor", a, s) {
        department = d;
        position = p;
        experience = e;
        research = r;
    }

    string getRole() {
        return "Professor";
    }

    void display() override {
        Person<T>::display();
        cout << "Department: " << department
             << "\nPosition: " << position
             << "\nExperience: " << experience
             << "\nResearch: " << research << endl;
    }

    // ++ salary (10%)
    float operator++() {
        this->salary += this->salary * 0.10;
        return this->salary;
    }

    // post ++ (5%)
    float operator++(int) {
        float temp = this->salary;
        this->salary += this->salary * 0.05;
        return temp;
    }
};

// ---------------- MAIN ----------------
int main() {

    TA<int> t1("Ali", 25, 50000, "CS", 3.5, "OOP, DLD", 6);
    Professor<int> p1("Dr. Ahmed", 45, 120000, "CS", "Associate Prof", 15, "AI");

    cout << "Before increment:\n";
    t1.display();
    p1.display();

    ++t1;
    p1++;

    cout << "\nAfter increment:\n";
    t1.display();
    p1.display();

    return 0;
}