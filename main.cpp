//
// Created by Michael Rokitko on 12/06/2018.
//
#include <iostream>
#include <cstdlib>
#include "menu.h"
#include "Book.h"
#include "Order.h"
#include "Customer.h"
#include "Supplier.h"
using namespace std;
int main()
{
    Store MyStore;
    Book MyBook;
    Order MyOrder;
    Customer myCustomer;
    Supplier mySupplier;
//    MyBook.showAllBooksInStore();
//    MyOrder.showAllOrdersInStore();
//    myCustomer.showAllCustomersInStore();
//    mySupplier.showAllSuppliers();
//    MyBook.showBooksWithDiscounts();
    string bookName = "Alice's Adventures in Wonderland";
    string BookWow = "wow";
//    MyBook.checkIfInStorage(bookName);
//    MyBook.checkIfInStorage(BookWow);                         //gives error
//    mySupplier.checkAllSuppliersOfABook(bookName);
    string start = "2018-03-12";                                //change 03 to 06 to see changes in "booksSoldFrom" function
    string end = "2018-10-12 10:34:09";
//    MyBook.booksSoldFrom(start,bookName);
//    MyStore.showAllTransactions(start,end);
    string ssn = "676128868";
    string startBookOredredByCustomerSince = "2018-05-12 09:34:09";
//    myCustomer.bookOredredByCustomerSince(ssn,startBookOredredByCustomerSince);
//    myCustomer.maxBooksBought();
//    mySupplier.maximumBooksProvided(start);
//    MyOrder.checkAllOrdersBetween(startBookOredredByCustomerSince,end);
//    MyOrder.checkAllCompletedOrdersBetween(startBookOredredByCustomerSince,end);
    string moneySavedSSN = "824241642";
    myCustomer.moneySavedBySpecificCustomer(moneySavedSSN,start);





//    int userChoise = -1;
//    int endProg = 23;
//    string start,end;
//    Store MyStore;
//    Book MyBook;
//    Order MyOrder;
//    Customer myCustomer;
//    Supplier mySupplier;
//    while (userChoise != 23) {
//        userChoise = menu(endProg);
//        switch (userChoise) {
//            case 1:{
//                MyBook.showAllBooksInStore();
//                break;
//            }
//            case 2:{
//                MyOrder.showAllOrdersInStore();
//                break;
//            }
//            case 3:{
//                myCustomer.showAllCustomersInStore();
//                break;
//            }
//            case 4:{
//                mySupplier.showAllSuppliers();
//                break;
//            }case 5:{
//                cin.clear();
//                fflush(stdin);
//                cout << "Please enter start date ****-**-**" << endl;
//                cin >> start;
//                cin.clear();
//                fflush(stdin);
//                cout << "Please enter end date ****-**-**" << endl;
//                cin >> end;
//                MyStore.showAllTransactions(start,end);
//                break;
//            }
//            case 6:{
//                MyBook.showBooksWithDiscounts();
//                break;
//            }
//            case 7:{
//                cout << "Please enter book name:" << endl;
//                cin.clear();
//                fflush(stdin);
//                cin >> bookName;
//                MyBook.checkIfInStorage(bookName);
//                break;
//            }
//            case 8:{
//                cout << "Please enter book name:" << endl;
//                cin.clear();
//                fflush(stdin);
//                cin >> bookName;
//                mySupplier.checkAllSuppliersOfABook(bookName);
//                break;
//            }
//            case 9:{
//                cout << "Please enter book name:" << endl;
//                cin.clear();
//                fflush(stdin);
//                cin >> bookName;
//                cout << "Please enter start date ****-**-**" << endl;
//                cin.clear();
//                fflush(stdin);
//                cin >> start;
//                MyBook.booksSoldFrom(start,bookName);
//                break;
//            }
//            case 10:{
//                cout << "Please enter book name:" << endl;
//                cin.clear();
//                fflush(stdin);
//                cin >> ssn;                                                     //should change to phone number?
//                cout << "Please enter start date ****-**-**" << endl;
//                cin.clear();
//                fflush(stdin);
//                cin >> start;
//                myCustomer.bookOredredByCustomerSince(ssn,start);
//                break;
//            }
//            case 11:{
//                myCustomer.maxBooksBought();
//                break;
//            }
//            case 22:{
//                break;
//            }
//
//            default:
//                break;
//
//        }
//    }
    return 0;
}





