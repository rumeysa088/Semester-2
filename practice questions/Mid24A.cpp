#include<iostream>
#include<math.h>
using namespace std;
class FinancialStatistics{
public:
    static double calcMean(int s,int arr[]){
        double sum=0;
        for(int i=0;i<s;i++)
            sum+=arr[i];
        return sum/s;
    }
    double getVariance(int s,int arr[]) const{
        double sigma=0;
        double mean=calcMean(s,arr);
        for(int i=0;i<s;i++){
            sigma+=pow(arr[i]-mean,2);
        }
        double var=sigma/(s-1);
        return var;
    }
};

int main(){}
#include<iostream>
using namespace std;

class Comment{
    string content;
public:
    Comment(string c):content(c){}

    void editContent(string newC){
        content=newC;
    }

    string getContent(){
        return content;
    }
};

class Post{
    string title;
    string content;
    int numComments;
    Comment* arr[10];

public:
    Post(string t,string c):title(t),content(c),numComments(0){}

    void addComment(Comment* comment){
        arr[numComments]=comment;
        numComments++;
    }

    void removeComment(Comment* comment){
        int index;
        bool found=false;

        for(int i=0;i<numComments;i++){
            if(arr[i]==comment){
                index=i;
                found=true;
                break;
            }
        }

        if(!found){
            cout<<"Comment doesn't exist"<<endl;
        }
        else{
            for(int i=index;i<numComments-1;i++){
                arr[i]=arr[i+1];
            }
            numComments--;
        }
    }

    void displayInfo() const{
        cout<<"Post: "<<title<<endl;
        cout<<"Content: "<<content<<endl;

        for(int i=0;i<numComments;i++){
            cout<<"Comment: "<<arr[i]->getContent()<<endl;
        }

        cout<<endl;
    }
};

class User{
    string name;
    int numPosts;
    Post* arr[10];

public:
    User(string n):name(n),numPosts(0){}

    void createPost(string t,string c){
        arr[numPosts]=new Post(t,c);
        numPosts++;
    }

    void addCmntToPost(Post* post, Comment* comment){
        post->addComment(comment);
    }

    void remCmntFromPost(Post* post, Comment* comment){
        post->removeComment(comment);
    }

    void displayUserPostsAndComments() const{
        cout<<"User: "<<name<<endl;

        for(int i=0;i<numPosts;i++){
            arr[i]->displayInfo();
        }
    }

    Post* getPost(int i){
        return arr[i];
    }
};

int main(){

    User u("Shafiq Rehman");

    u.createPost("My Vacation Adventure","Vacation Trip");
    u.createPost("Homemade Dinner","Dinner at home");

    Post* p1=u.getPost(0);
    Post* p2=u.getPost(1);

    Comment c1("Looks amazing!");
    Comment c2("I wish I could go there too");
    Comment c3("Yum, what's the recipe?");
    Comment c4("Can I come over for dinner");

    p1->addComment(&c1);
    p1->addComment(&c2);
    p2->addComment(&c3);
    p2->addComment(&c4);

    cout<<"Before editing:\n";
    u.displayUserPostsAndComments();

    c3.editContent("Yum, can you share the recipe?");

    cout<<"\nAfter editing:\n";
    u.displayUserPostsAndComments();
}

#include<iostream>
using namespace std;

class Reward{
public:
    Reward(){
        cout<<"Reward constructor\n";
    }

    ~Reward(){
        cout<<"Reward destructor\n";
    }

    void calculateReward(int dishes,int drinks,int age){
        if(dishes>2 && drinks>=1)
            cout<<"Complimentary dish awarded\n";

        if(age<5 || age>70)
            cout<<"Free drink awarded\n";
    }
};

class Order{
protected:
    double orderAmount;
    string orderType;
    int age;
    bool loyalCustomer;

    Reward reward;

public:
    Order(double a,string t,int ag,bool l)
    :orderAmount(a),orderType(t),age(ag),loyalCustomer(l)
    {
        cout<<"Order constructor\n";
    }

    virtual ~Order(){
        cout<<"Order destructor\n";
    }

    virtual void processOrder(){
        cout<<"Processing "<<orderType<<" order\n";
    }

    double getAmount(){ return orderAmount; }
};

class DineInOrder:public Order{
    int dishes;
    int drinks;

public:
    DineInOrder(double a,int ag,bool l,int d,int dr)
    :Order(a,"DineIn",ag,l),dishes(d),drinks(dr)
    {
        cout<<"DineIn constructor\n";
    }

    ~DineInOrder(){
        cout<<"DineIn destructor\n";
    }

    void processOrder(){
        cout<<"Dine-in order processing\n";
        reward.calculateReward(dishes,drinks,age);
    }
};

class TakeoutOrder:public Order{
public:
    TakeoutOrder(double a,int ag,bool l)
    :Order(a,"Takeout",ag,l)
    {
        cout<<"Takeout constructor\n";
    }

    ~TakeoutOrder(){
        cout<<"Takeout destructor\n";
    }
};

class DeliveryOrder:public Order{
public:
    DeliveryOrder(double a,int ag,bool l)
    :Order(a,"Delivery",ag,l)
    {
        cout<<"Delivery constructor\n";
    }

    ~DeliveryOrder(){
        cout<<"Delivery destructor\n";
    }
};

int main(){

    DineInOrder d(500,72,true,3,1);

    d.processOrder();

}