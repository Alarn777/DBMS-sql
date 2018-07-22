//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_BOOK_H
#define DBMS_SQL_BOOK_H


#include "Database.h"
#include <iostream>
#include "Store.h"
#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;
int returnDiscount(int value);
class Book {
public:
    Book() {};
    int realDiscount(long double value) { return ((1 - value) * 100);}
    void showAllBooksInStore() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        while (allBooks >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "ISBN: " + rset->getString("ISBN") << endl;
            cout << "Book Name: " + rset->getString("book_name") << endl;
            cout << "Price per unit: " + rset->getString("Price") << endl;
            cout << "Quantity: " + rset->getString("Quantity") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            allBooks--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
    void showBooksWithDiscounts(){
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        cout << "Books with global discount:" << endl;
        while (allBooks >= 1) {
            if (realDiscount(rset->getDouble("global_discount")) != 0) {
                cout << "-------------------------------------" << endl;
                cout << "ISBN: " + rset->getString("ISBN") << endl;
                cout << "Book Name: " + rset->getString("book_name") << endl;
                cout << "Global Discount: " << realDiscount(rset->getDouble("global_discount")) + 1 << "%" << endl;
                cout << "Price with discount per unit: " << rset->getInt("Price")*rset->getDouble("global_discount")  << endl;
                cout << "-------------------------------------" << endl;
            }
            rset->next();
            allBooks--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }

    bool checkIfInStorage(int isbn) {
        bool toReturn = false;
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book WHERE ISBN = ? ");
        pstmt->setString(1, to_string(isbn));
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        if (allBooks >= 1 && rset->getInt("Quantity") > 0) {
            cout << "-------------------------------------" << endl;
            cout << "ISBN: " + rset->getString("ISBN") << endl;
            cout << "Book Name: " + rset->getString("book_name") << endl;
            cout << "Is Currently in storage!" << endl;
            cout << "Quantity: " + rset->getString("Quantity") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            toReturn = true;
        } else {
            if(allBooks >= 1) {
                cout << "-------------------------------------" << endl;
                cout << "ISBN: " << isbn << endl;
                cout << "Book Name: " + rset->getString("book_name") << endl;
                cout << "Is not in our Storage !" << endl;
                cout << "-------------------------------------" << endl;
            } else {
                cout << "-------------------------------------" << endl;
                cout << "ISBN: " << isbn;
                cout << " Is not valid!" << endl;
                cout << "-------------------------------------" << endl;
            }
        }
        delete pstmt;
        delete rset;
        delete con;
        return toReturn;
        }
    void booksSoldInTimePeriod(string& start,string& end) {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Orders where date between ? and ? ");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        if (allBooks >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
        }

        delete pstmt;
        delete rset;
        delete con;
    }
    void booksSoldFrom(string& start,int isbn) {
        int sellCount = 0;
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book WHERE ISBN = ? ");
        pstmt->setString(1, to_string(isbn));
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        if (all < 1) {
            cout << "-------------------------------------" << endl;
            cout << "ISBN: " << isbn;
            cout << " Is not valid!" << endl;
            cout << "-------------------------------------" << endl;
        } else {
            PreparedStatement *pstmtOrder = con->prepareStatement("SELECT * FROM Orders where date > ? ");
            pstmtOrder->setString(1, start);
            ResultSet *rsetOrder = pstmtOrder->executeQuery();
            rsetOrder->first();
            size_t allOrder = rsetOrder->rowsCount();
            while (allOrder >= 1) {
                string orderId = rsetOrder->getString("idOrder");
                PreparedStatement *pstmtBookInOrder = con->prepareStatement(
                        "SELECT * FROM books_in_order where books_id = ? and order_id = " + rsetOrder->getString("idOrder"));
                pstmtBookInOrder->setString(1, to_string(isbn));
                ResultSet *rsetBookInOrder = pstmtBookInOrder->executeQuery();
                rsetBookInOrder->first();
                size_t allBookInOrder = rsetBookInOrder->rowsCount();
                while (allBookInOrder >= 1) {
                    sellCount += rsetBookInOrder->getInt("quantity");
                    allBookInOrder--;
                    rsetBookInOrder->next();
                }
                delete pstmtBookInOrder;
                delete rsetBookInOrder;
                allOrder--;
                rsetOrder->next();
            }
            delete pstmtOrder;
            delete rsetOrder;
                cout << "-------------------------------------" << endl;
                cout << "ISBN: " + rset->getString("ISBN") << endl;
                cout << "Book Name: " + rset->getString("book_name") << endl;
                cout << "Was Sold: " << sellCount << " times" << endl;
                cout << "From : " << start << endl;
                cout << "-------------------------------------" << endl;
                rset->next();
            }
        delete pstmt;
        delete rset;
        delete con;
    }

private:

};




#endif //DBMS_SQL_BOOK_H
