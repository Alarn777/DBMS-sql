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
//    MyBook.checkIfInStorage(757230);
//    MyBook.checkIfInStorage(111111);
//    MyBook.checkIfInStorage(437396);
//    mySupplier.checkAllSuppliersOfABook(757230);
//    mySupplier.checkAllSuppliersOfABook(378249);
//    mySupplier.checkAllSuppliersOfABook(111111);
    string start = "2018-03-12 09:34:09";
    string end = "2018-10-12 10:34:09";
//    MyBook.booksSoldFrom(start,378249);
//    MyStore.showAllTransactions(start,end);
    string ssn = "676128868";
    string startBookOredredByCustomerSince = "2018-05-12 09:34:09";
    myCustomer.bookOredredByCustomerSince(ssn,startBookOredredByCustomerSince);










//    int userChoise = -1;
//    while (userChoise != 9) {
//        userChoise = menu();
//        switch (userChoise) {
//            case 1:{
//                myStore.showAllBooksInStore();
//
//                break;
//            }
//            default:
//                break;
//
//        }
//    }
}





