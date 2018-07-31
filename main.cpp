//
// Created by Michael Rokitko on 12/06/2018.
//
#include <iostream>
#include "menu.h"
#include "Book.h"
#include "Order.h"
#include "Customer.h"
#include "Supplier.h"
using namespace std;
void clearCin();

int main()
{
//    Store MyStore;
//    Book MyBook;
//    Order MyOrder;
//    Customer myCustomer;
//    Supplier mySupplier;
//    MyBook.showAllBooksInStore();
//    MyOrder.showAllOrdersInStore();
//    myCustomer.showAllCustomersInStore();
//    mySupplier.showAllSuppliers();
//    MyBook.showBooksWithDiscounts();
//    string bookName = "Alice's Adventures in Wonderland";
//    string BookWow = "wow";
//    MyBook.checkIfInStorage(bookName);
//    MyBook.checkIfInStorage(BookWow);                         //gives error
//    mySupplier.checkAllSuppliersOfABook(bookName);
//    string start = "2018-03-12";                                //change 03 to 06 to see changes in "booksSoldFrom" function
//    string end = "2018-10-12";
//    MyBook.booksSoldFrom(start,bookName);
//    MyStore.showAllTransactions(start,end);
//    string ssn = "676128868";
//    string startBookOredredByCustomerSince = "2018-05-12 09:34:09";
//    myCustomer.bookOredredByCustomerSince(ssn,startBookOredredByCustomerSince);
//    myCustomer.maxBooksBought();
//    mySupplier.maximumBooksProvided(start);

//    MyOrder.checkAllOrdersBetween(startBookOredredByCustomerSince,end);
//    MyOrder.checkAllCompletedOrdersBetween(startBookOredredByCustomerSince,end);
//    string moneySavedSSN = "824241642";
//    myCustomer.moneySavedBySpecificCustomer(moneySavedSSN,start);
//    myCustomer.showAllCustomersInStore();
//    string yearMoney = "2018";
//    MyStore.showYearlyEarning(yearMoney);
//    myCustomer.newCustomersSince(start);
//    string id_supplier = "1513";
//    mySupplier.allDealsWithSupplier(id_supplier,start,end);
//    string id = "3";
//    MyStore.checkSalesOfAnEmployee(id,start,end);
//    MyBook.topTenBookBetween(start,end);






    int userChoise = -1;
    int endProg = 23;
    string start,end,id_supplier,bookName,id_employee,ssn;
    Store MyStore;
    Book MyBook;
    Order MyOrder;
    Customer myCustomer;
    Supplier mySupplier;
    while (userChoise != 23) {
        userChoise = menu(endProg);
        char input[100] = {};
        switch (userChoise) {
            case 1:{
                MyBook.showAllBooksInStore();
                break;
            }
            case 2:{
                MyOrder.showAllOrdersInStore();
                break;
            }
            case 3:{
                myCustomer.showAllCustomersInStore();
                break;
            }
            case 4:{
                mySupplier.showAllSuppliers();
                break;
            }case 5:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                cout << "Please enter end date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> end;
                MyStore.showAllTransactions(start,end);
                break;
            }
            case 6:{
                MyBook.showBooksWithDiscounts();
                break;
            }
            case 7:{
                cout << "Please enter book name:" << endl;
                cin.clear();
                clearCin();
                getline(cin, bookName);
                MyBook.checkIfInStorage(bookName);
                break;
            }
            case 8:{
                cout << "Please enter book name:" << endl;
                cin.clear();
                clearCin();
                cin >> bookName;
                mySupplier.checkAllSuppliersOfABook(bookName);
                break;
            }
            case 9:{
                cout << "Please enter book name:" << endl;
                cin.clear();
                clearCin();
                cin >> bookName;
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                MyBook.booksSoldFrom(start,bookName);
                break;
            }
            case 10:{
                cout << "Please enter book name:" << endl;
                cin.clear();
                clearCin();
                cin >> ssn;                                                     //should change to phone number?
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                myCustomer.bookOredredByCustomerSince(ssn,start);
                break;
            }
            case 11:{
                myCustomer.maxBooksBought();
                break;
            }
            case 12:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                mySupplier.maximumBooksProvided(start);
                break;
            }
            case 13:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                cout << "Please enter end date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> end;
                MyOrder.checkAllOrdersBetween(start,end);
                break;
            }
            case 14:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                cout << "Please enter end date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> end;
                MyOrder.checkAllCompletedOrdersBetween(start,end);
                break;
            }
            case 15:{
                cout << "Please enter customer ssn" << endl;
                cin.clear();
                clearCin();
                cin >> ssn;
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                myCustomer.moneySavedBySpecificCustomer(ssn,start);  //needs to be switched to phone number?
                break;
            }
            case 16:{
                cout << "Please enter year ****" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                MyStore.showYearlyEarning(start);
                break;
            }
            case 17:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                myCustomer.newCustomersSince(start);

                break;
            }
            case 18:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                cout << "Please enter end date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> end;
                cout << "Please enter supplier ID" << endl;
                cin.clear();
                clearCin();
                cin >> id_supplier;
                mySupplier.allDealsWithSupplier(id_supplier,start,end);
                break;
            }
            case 19:{
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                cout << "Please enter end date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> end;
                cout << "Please enter employee ID" << endl;
                cin.clear();
                clearCin();
                cin >> id_employee;
                MyStore.checkSalesOfAnEmployee(id_employee,start,end);
                break;
            }
            case 20:{                             //problem
                cout << "Please enter start date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> start;
                cout << "Please enter end date ****-**-**" << endl;
                cin.clear();
                clearCin();
                cin >> end;
                MyBook.topTenBookBetween(start,end);
                break;
            }
            case 21:{
                system ("CLS");
                break;
            }
            case 23:{

                break;
            }
            default:
                break;

        }
    }
    return 0;
}



void clearCin()
{
    string temp;
    getline(cin, temp);
}

