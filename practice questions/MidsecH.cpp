#include<iostream>
using namespace std;

class Employee{
    static int nextEmpID;
    static const float MAX_SALARY;

    int salary;
    int empID;
    string name;
public:
    Employee(string n){
        name = n;
        empID = nextEmpID++;
        salary = 0;
    }
    static int generateEmployeeID(){
        return nextEmpID;
    }
    void setSalary(int s){
        if(s > MAX_SALARY)
            salary = MAX_SALARY;
        else
            salary = s;
    }
    void displayEmployeeInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<empID<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
int Employee::nextEmpID = 100;
const float Employee::MAX_SALARY = 50000;

int main(){

    Employee e1("Ali");
    Employee e2("Sara");
    cout<<"Next Employee ID: "<<Employee::generateEmployeeID()<<endl;
    e1.setSalary(60000);   // exceeds max
    e1.displayEmployeeInfo();
}
#include<iostream>
using namespace std;

class User; // forward declaration

// ---------------- COMMENT ----------------
class Comment{
    int commentID;
    string content;
    User* author;
public:
    Comment(){}
    Comment(int id,string c,User* u){
        commentID=id;
        content=c;
        author=u;
    }
};

// ---------------- POST ----------------
class Post{
    int postID;
    string content;
    Comment comments[10];
    int commentCount;
public:
    Post(){
        commentCount=0;
    }

    Post(int id,string c){
        postID=id;
        content=c;
        commentCount=0;
    }

    void addComment(int cid,string c,User* u){
        comments[commentCount++] = Comment(cid,c,u);
    }

    void display(){
        cout<<"Post: "<<content<<endl;
    }
};

// ---------------- USER ----------------
class User{
    int userID;
    string userName;
    Post posts[10];
    int postCount;
public:
    User(){
        postCount=0;
    }

    User(int id,string name){
        userID=id;
        userName=name;
        postCount=0;
    }

    void createPost(int pid,string c){
        posts[postCount++] = Post(pid,c);
    }

    void addCommentToPost(int postIndex,int cid,string c,User* u){
        posts[postIndex].addComment(cid,c,u);
    }

    void displayFeed(){
        for(int i=0;i<postCount;i++){
            posts[i].display();
        }
    }
};

// ---------------- PLATFORM ----------------
class SocialMediaPlatform{
    User users[10];
    int userCount;
public:
    SocialMediaPlatform(){
        userCount=0;
    }

    void registerUser(int id,string name){
        users[userCount++] = User(id,name);
    }

    void createPost(int userIndex,int pid,string content){
        users[userIndex].createPost(pid,content);
    }

    void addComment(int userIndex,int postIndex,int cid,string content,int authorIndex){
        users[userIndex].addCommentToPost(postIndex,cid,content,&users[authorIndex]);
    }

    void displayFeed(int userIndex){
        users[userIndex].displayFeed();
    }
};

// ---------------- MAIN ----------------
int main(){

    SocialMediaPlatform app;

    // register users
    app.registerUser(1,"Ali");
    app.registerUser(2,"Asif");

    // create posts
    app.createPost(0,101,"Hello World");
    app.createPost(1,102,"Second Post");

    // add comment
    app.addComment(0,0,201,"Nice post!",1);

    // display feed
    app.displayFeed(0);
}

#include<iostream>
using namespace std;
class Employees{
protected:
    string name;
    int age;
    string joiningDate;
public:
    Employees(){}
    Employees(string n, int a, string jd):name(n),age(a),joiningDate(jd){}
};
class Developer:virtual public Employees{
protected:
    string role;
public:
    Developer(){}
    Developer(string r):role(r){}
};
class Debugger:virtual public Employees{
protected:
    string role;
public:
    Debugger(){}
    Debugger(string r):role(r){}
};
class TeamLead: public Developer,public Debugger{
public:
    TeamLead(){}
    TeamLead(string r1,string r2,string n, int a, string jd):Developer(r1),Debugger(r2),Employees(n,a,jd){}
      void display(){
        cout<<"Name: "<<name<<"\nAge: "<<age<<"\nJoining Date: "<<joiningDate<<"\nDeveloper Role: "<<Developer::role<<"\nDebugger Role: "<<Debugger::role<<endl;
      }
};
int main(){
   TeamLead tl("Front end","Manual Debugger","Ali",26,"26-03-22");
   tl.display();
}