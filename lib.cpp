/*=================================================================================*/
/*  @File        : main.cpp                                                        */
/*  @Description : the library system by cpp programming                           */
/*  @Author      : Mustafa khaled Elkhokh                                          */
/*  @Date        : 6/12/2024                                                       */
/*  @mail        : mustafaelkhokhy@gmil.com                                        */
/*=================================================================================*/
#include <iostream>
#include<string>
using namespace std;
class BookSystem
{
private:
    int Id;
    string Name;

public:
    int Quantity;
    int GetId()
    {
        return Id;
    }
    int GetQuantity()
    {
        return Quantity;
    }
    string GetName()
    {
        return Name;
    }
   
    int GetPrefex1()
    {
        int OneChar;
     OneChar = int(Name[0]);
     return OneChar;
    }

    int GetPrefex2()
    {
        int  TwoChar;
        TwoChar = int(Name[1]);
        return TwoChar;
    }

    void FillDataForBook()
    {
        cout << "Enter ID: ";
        cin >> Id;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Quantity: ";
        cin >> Quantity;
    }
    void PrintBook()
    {
      
            cout << "Id : " << Id << endl;
            cout << "Name : " << Name << endl;
            cout << "Id : " << Quantity << endl;
            cout << "";
       
    }

};
class user
{
private:
    int NationalID;
    string UserName;

public:
    string GetName()
    {
        return UserName;
    }

    void GetData()
    {
        cout << "Enter National ID: ";
        cin >> NationalID;
        cout << "Enter Name: ";
        cin >> UserName;
    }
    void PrintUsers()
    {
        cout << "National ID : " << NationalID << endl;
        cout << "UserName : " << UserName << endl;
        cout << "";
    }
};

class UserManger
{
private:
    user  user[1000];
    int Length;
public:
    UserManger()
    {
        Length = 0;
    }

    int GetLength()
    {
        return Length;
    }

    void AddUser()
    {
        if (Length >= 1000)
        {
            cout << "users Is Full \n";
            return;
        }
        user[Length].GetData();
        Length++;
        cout << "user Add Successfully\n";
    }

    void PrintAllUsers()
    {

        if (Length == 0) {
            cout << "There is no users in library " << endl;
        }
        else {
            for (int i = 0; i < Length; i++) {
                cout << "\nuser Number [" << i + 1 << "]" << endl;
                user[i].PrintUsers();
            }
        }
    }

    bool FindUserName(string UserName)
    {
        for (int i = 0; i < Length ; i++)
        {
            if (UserName == user[i].GetName())
            {
                return true;
            }
        }
        cout << "user not found";
        return false;
    }

};


class BookManger
{
private:
    UserManger UserManger;
    BookSystem Books[1000];
    int Length;

public:
    BookManger()
    {
        Length = 0;
    }

    struct BorrowInfo {
        string UserName;
        string BookName;
    };

    BorrowInfo BorrowedBooks[1000];
    int BorrowCount = 0;


    void AddBook()
    {
        if (Length >= 1000)
        {
            cout << "Library Is Full \n";
            return;
        }
        Books[Length].FillDataForBook();
        Length++;
            cout << "Book Add Successfully\n";
    }

    void PrintAllBooks()
    {

        if (Length == 0) {
            cout << "There is no books in library " << endl;
        }
        else {
            for (int i = 0; i < Length; i++){
                cout << "\nBook Number [" << i + 1 << "]" << endl;
                Books[i].PrintBook();
            }
        }
    }

    void SearchBooksByPrefex()
    {
        string Prefex;
        bool found = false;

        cout << "enter Prefex Of the Book : ";
        cin >> Prefex;
        int PrefexSize = size(Prefex);
        for(int i=0 ; i< PrefexSize ; i++)
        {        
            if (int(Prefex[0]) == int(Books[i].GetPrefex1()) && int(Prefex[1]) == int(Books[i].GetPrefex2()))
            {
                Books[i].PrintBook();
                cout << endl;
          }

        }

    }

    bool FindBookName(string BookName)
    {
        for (int i = 0; i < Length; i++)
        {
            if (BookName == Books[i].GetName())
            {
                return true;  
        }
            }
        cout << "book not found";
        return false;
        
    }

    void BorrowBook()
    {
        string UserName, BookName;
        cout << "enter user name : ";
        cin >> UserName;

        cout << "enter book name to borrow : ";
        cin >> BookName;

        if (!UserManger.FindUserName(UserName))
        {
            cout << "User not found.\n";
            return;
        }

        for (int i = 0; i < Length; i++) {

            if (Books[i].GetName() == BookName) {
                if (Books[i].GetQuantity() > 0) {
                   Books[i].Quantity--;

                   BorrowedBooks[BorrowCount].UserName = UserName;
                   BorrowedBooks[BorrowCount].BookName = BookName;
                   BorrowCount++;


                    cout << "Book borrowed successfully!\n";
                }
                else {
                    cout << "Book is out of stock.\n";
                }
                return;
            }
        }

        cout << "Book not found.\n";
    }
    
    void PrintWhoBorrowedBook() {
        string BookName;
        cout << "Enter the name of the book: ";
        cin >> BookName;

        bool found = false;
        for (int i = 0; i < BorrowCount; i++) {
            if (BorrowedBooks[i].BookName == BookName) {
                cout << "User who borrowed the book: " << BorrowedBooks[i].UserName << endl;
                found = true;
            }
        }

        if(!found) {
            cout << "No users found who borrowed this book.\n";
        }
    }

    void ReturnBook()
    {
        string UserName, BookName;
        cout << "enter user name : ";
        cin >> UserName;

        cout << "enter book name to borrow : ";
        cin >> BookName;

        if (!UserManger.FindUserName(UserName))
        {
            cout << "User not found\n";
        }

        for (int i = 0; i < Length; i++) 
        {

            if (Books[i].GetName() == BookName) 
                {
                    Books[i].Quantity++;
                    cout << "Book Return successfully!\n";
                }
            
        }

        cout << "Book not found.\n";
    }

    void StartProgram() {
        int choice;
        do {
            cout << "\nChoose an operation:\n";
            cout << "(1) add Book\n";
            cout << "(2) Search Books By Prefex\n";
            cout << "(3) Print Library By Id\n";
            cout << "(4) Print Library By Name\n";
            cout << "(5) User Borow Book\n";
            cout << "(6) Add User\n";
            cout << "(7) Print All Users\n";
            cout << "(8) Return Book\n";
            cout << "(9) Print Who Borrowed Book By Name \n";
            cout << "(10) Exit\n";

            cout << "\nEnter Your Choice\n";
            cin >> choice;

            switch (choice) {
            case 1:
                AddBook();
                break;
            case 2:
                SearchBooksByPrefex();
                break;
            case 3:
                PrintAllBooks();
                break;
            case 4:
                PrintAllBooks();
                break;
            case 5 :
                BorrowBook();
                break;
            case 6:
                UserManger.AddUser();
                break;
            case 7:
                UserManger.PrintAllUsers();
                break;
            case 8:
                ReturnBook();
                break;
            case 9 :
                PrintWhoBorrowedBook();
                break;
            case 10:
                cout << "Thank you for using the program!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
            }
        } while (choice != 10);
    }
};
int main()
{
    BookManger Book;
    Book.StartProgram();
    return 0;
}