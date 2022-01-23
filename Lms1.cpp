#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class library
{
	private:
		struct Node
		{
          int id;
          string name,author,publisher;
          Node *next_add;
        };
    public:
    	Node *head = NULL;
    	void menu();
    	void insert();
    	void search();
        void update();
        void del();
        /*void sort();*/
        void show();
};
    void library::menu()
    {
    	p:
    	system("cls");
    	int choice;
    	cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
    	cout<<"\n\n 1. Insert New Record";
    	cout<<"\n\n 2. Search Record";
    	cout<<"\n\n 3. Update Record";
    	cout<<"\n\n 4. Delete Record";
    	cout<<"\n\n 5. Show all Record";
    	cout<<"\n\n 6. Exit";
    	cout<<"\n\n Enter your Choice : ";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    		  insert();
    		  break;
    		case 2:
    		  search();
    		  break;
    		case 3:
              update();
    		  break;
    		case 4:
              del();
    		  break;
//    		case 5:
//              sort();
//              show();
//    		  break;
    		case 6:
    		  exit(0);
    		 default:
    		 cout<<"\n\n Invalid Choice..Please Try Again....";           
        }
        getch();
        goto p;
    }
   void library::insert()
   {
     system("cls");	
		cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
    	Node *new_node = new Node;
    	cout<<"\n\n Book ID : ";
    	cin>>new_node -> id;
    	cout<<"\n\n Name : ";
    	cin>>new_node -> name;
        cout<<"\n\n Author Name : ";
    	cin>>new_node -> author;
    	cout<<"\n\n Publisher Name : ";
    	cin>>new_node -> publisher;
    	
     	fstream obj1("sample.txt", ios::out);
	    obj1<<"\n\n\t\t\t==============================================";
        obj1<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        obj1<<"\n\n\t\t\t==============================================";
        obj1<<"\n\n\n\n-------------Books Available in Library-------------"<<endl;
    	obj1<<"\n\n\nBook Id			"<<"Book Name								"<<"Author Name					"<<"Publisher Name                    ";
		obj1.close();
    	int bookId=new_node->id;
    	string bookName=new_node->name;
    	string authorName=new_node->author;
    	string publisher=new_node->publisher;
    	fstream obj2("sample.txt", ios::app);
		obj2<<"\n"<<"  "<<bookId<<"			"<<bookName<<"					"<<authorName<<"                    "<<publisher;
		obj2.close();   	
    	
    	
    	new_node -> next_add = NULL;
    	if(head == NULL)
    	{
    		head = new_node;
    	}
    	else
    	{
    		Node *ptr = head;
    		while(ptr -> next_add != NULL)
    		{
    			ptr = ptr -> next_add;
    		}
    		 ptr -> next_add = new_node;
    	}
    	cout<<"\n\n\t\t\tNew Book Inserted Successfully......";
   }
   void library::search()
   {
        system("cls");
        int t_id,found=0;
        cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
        if(head == NULL)
        {
            cout<<"\n\n Linked List is Empty.....";
        }
        else
        {
            cout<<"\n\n Book ID : ";
            cin>>t_id;
            Node *ptr = head;
            while(ptr != NULL)
            {
                if(t_id == ptr -> id)
                {
                  system("cls");
                 cout<<"\n\n\t\t\t==============================================";
                 cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
                 cout<<"\n\n\t\t\t==============================================";
                cout<<"\n\n Book ID : "<<ptr -> id; 
                cout<<"\n\n Book Name : "<<ptr -> name;
                cout<<"\n\n Author Name : "<<ptr -> author;
                cout<<"\n\n Publisher Name : "<<ptr -> publisher;
                found++;
                }
                ptr = ptr -> next_add;
            }
            if(found == 0)
            {
                cout<<"\n\n Book ID is Invalid....";
            }
        }
   }
   void library::update()
   {
        system("cls");
        int t_id,found=0;
        cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
        if(head == NULL)
        {
            cout<<"\n\n Linked List is Empty.....";
        }
        else
        {
            cout<<"\n\n Book ID : ";
            cin>>t_id;
            Node *ptr = head;
            while(ptr != NULL)
            {
                if(t_id == ptr -> id)
                {
                  system("cls");
                 cout<<"\n\n\t\t\t==============================================";
                 cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
                 cout<<"\n\n\t\t\t==============================================";
                cout<<"\n\n Book ID : ";
                cin>>ptr -> id; 
                cout<<"\n\n Book Name : ";
                cin>>ptr -> name;
                cout<<"\n\n Author Name : ";
                cin>>ptr -> author;
                cout<<"\n\n Publisher Name : ";
                cin>>ptr -> publisher;
                found++;
                cout<<"\n\n\t\t\tUpdate Book Successfully.....";
                }
                ptr = ptr -> next_add;
            }
            if(found == 0)
            {
                cout<<"\n\n Book ID is Invalid....";
            }
        }
   }
   void library::del()
   {
        system("cls");
        int t_id,found=0;
        cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
        if(head == NULL)
        {
            cout<<"\n\n Linked List is Empty.....";
        }
        else
        {
            cout<<"\n\n Book ID : ";
            cin>>t_id;
            if(t_id == head -> id)
            {
                Node *ptr = head;
                head = head -> next_add;
                delete ptr;
                cout<<"\n\n Delete Book Successfully......";
                found++;
            }
            else
            {
                Node *pre = head;
                Node *ptr = head;
                while(ptr != NULL)
                {
                    if(t_id == ptr -> id)
                    {
                       pre -> next_add = ptr -> next_add;
                       delete ptr;
                       cout<<"\n\n Delete Book Successfully.....";
                       found++;
                       break;
                    }
                    pre = ptr;
                    ptr = ptr -> next_add;
                }
            }
            if(found == 0)
            {
                cout<<"\n\n Book ID is Invalid....";
            }
        }
   }
   void library::sort()
   {
    if(head == NULL)
    {
        system("cls");
        cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n Linked List is Empty......";
        getch();
        menu();
    }
    int count=0,t_id;
    string t_name,t_author,t_publisher;
    Node *ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next_add;
    }
    for(int i=1;i<=count;i++)
    {
        Node * ptr = head;
        for(int j=1;j<count;j++)
        {
          if(ptr -> id > ptr -> next_add -> id)
          {
            // save data into temporary node
             t_id = ptr -> id;
             t_name = ptr -> name;
             t_author = ptr -> author;
             t_publisher = ptr -> publisher;
            // save data into current node
            ptr -> id = ptr -> next_add -> id;
            ptr -> name = ptr -> next_add -> name;
            ptr -> author = ptr -> next_add -> author;
            ptr -> publisher = ptr -> next_add -> publisher;
            // save data into next node
            ptr -> next_add -> id = t_id;
            ptr -> next_add -> name = t_name;
            ptr -> next_add -> author = t_author;
            ptr -> next_add -> publisher = t_publisher;
          }
          ptr = ptr -> next_add;
        }
    }
}
void library::show()
{
    system("cls");
        cout<<"\n\n\t\t\t==============================================";
        cout<<"\n\n\t\t\t======== LIBRARY MANAGEMENT SYSTEM ===========";
        cout<<"\n\n\t\t\t==============================================";
            Node *ptr = head;
            while(ptr != NULL)
            {
                cout<<"\n\n Book ID : "<<ptr -> id; 
                cout<<"\n\n Book Name : "<<ptr -> name;
                cout<<"\n\n Author Name : "<<ptr -> author;
                cout<<"\n\n Publisher Name : "<<ptr -> publisher;
                cout<<"\n\n\n ======================================";
                ptr = ptr -> next_add;
            }
 }
main()
{
  library obj;
  obj.menu();
}
