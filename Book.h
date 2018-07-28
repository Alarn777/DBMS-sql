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

    int realDiscount(long double value) { return ((1 - value) * 100); }

    void showAllBooksInStore() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book as h1 INNER JOIN  book_price as h2 \n"
                                                                 "\tON h1.ISBN = h2.idbook \n"
                                                                 "    inner JOIN Author as h3\n"
                                                                 "    ON h2.idbook = h3.idBook");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t allBooks = rset->rowsCount();
        while (allBooks >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "ISBN: " + rset->getString("ISBN") << endl;
            cout << "Book Name: " + rset->getString("book_name") << endl;
            cout << "Author: " + rset->getString("FName") << " " << rset->getString("LNAme") << endl;
            cout << "Price per unit for Customer: " + rset->getString("customer_price") << "$" << endl;
            cout << "Price per unit to Resupply: " + rset->getString("real_price") << "$" << endl;
            cout << "Quantity: " + rset->getString("Quantity") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            allBooks--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }

    void showBooksWithDiscounts() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement(
                "SELECT * FROM Book INNER JOIN  book_price ON book_price.idbook = Book.ISBN");
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
                cout << "Price with discount per unit: "
                     << rset->getInt("customer_price") * rset->getDouble("global_discount") << endl;
                cout << "-------------------------------------" << endl;
            }
            rset->next();
            allBooks--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }

    bool checkIfInStorage(string &name) {
        bool toReturn = false;
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book WHERE book_name = ? ");
        pstmt->setString(1, name);
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
            cout << "-------------------------------------" << endl;
            cout << "Book Name: " + name << endl;
            cout << "Is not in our Storage!" << endl;
            cout << "-------------------------------------" << endl;
        }
        delete pstmt;
        delete rset;
        delete con;
        return toReturn;
    }

    void booksSoldInTimePeriod(string &start, string &end) {
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

    void booksSoldFrom(string &start, string book_name) {
        int sellCount = 0;
        start = start + " 00:00:00";
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book WHERE book_name = ? ");
        pstmt->setString(1, book_name);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        if (all < 1) {
            cout << "-------------------------------------" << endl;
            cout << "Book Name: " << book_name;
            cout << " Is not present in the shop!" << endl;
            cout << "-------------------------------------" << endl;
        } else {
            PreparedStatement *pstmtOrder = con->prepareStatement(
                    "SELECT * FROM Bookstore.orders INNER JOIN books_in_order where orders.idOrder =  books_in_order.order_id and orders.date > ? and books_in_order.books_id = ?");
            pstmtOrder->setString(1, start);
            pstmtOrder->setString(2, rset->getString("ISBN"));
            ResultSet *rsetOrder = pstmtOrder->executeQuery();
            rsetOrder->first();
            size_t allOrder = rsetOrder->rowsCount();
            while (allOrder >= 1) {
                sellCount += rsetOrder->getInt("quantity");
                allOrder--;
                rsetOrder->next();
            }
            cout << "-------------------------------------" << endl;
            cout << "Book Name: " + rset->getString("book_name") << endl;
            cout << "Was Sold: " << sellCount << " times" << endl;
            unsigned long start_position_to_erase = start.find("00:00:00");
            start.erase(start_position_to_erase, 8);
            cout << "From : " << start << endl;
            cout << "-------------------------------------" << endl;
            delete pstmtOrder;
            delete rsetOrder;
        }

        delete pstmt;
        delete rset;
        delete con;
    }

    void topTenBookBetween(string& start,string& end)
    {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement(
                " SELECT books_id,SUM(quantity_in_order) FROM Bookstore.Orders as h1 INNER JOIN books_in_order\n"
                        "        where h1.idOrder = books_in_order.order_id and h1.status = 'Closed'\n"
                        "        and date between ? and ?\n"
                        "        group by books_id ORDER BY SUM(quantity_in_order) DESC ");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        cout << "Top 10 Book Sold between " + start + " and " + end + ":" << endl;
        cout << "-------------------------------------" << endl;
        int i = 1;
        while (all >= 1) {
            PreparedStatement *pstmtBook = con->prepareStatement(
                    " SELECT book_name FROM Book WHERE ISBN = ?");
            pstmtBook->setString(1, rset->getString("books_id"));
            ResultSet *rsetBooks = pstmtBook->executeQuery();
            rsetBooks->first();
            cout << i << ":" << rsetBooks->getString("book_name") << " sold " << rset->getString("SUM(quantity_in_order)") << " times" << endl;
            rset->next();
            all--;
            i++;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
private:

};


#endif //DBMS_SQL_BOOK_H
