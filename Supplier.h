//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_SUPPLIER_H
#define DBMS_SQL_SUPPLIER_H

#include "Database.h"
#include <iostream>

#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;


class Supplier {
public:
    void showAllSuppliers() {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Supplier");
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Supplier ID: " + rset->getString("idSupplier") << endl;
            cout << "Supplier Name: " + rset->getString("name") << endl;
            cout << "Phone Number: " + rset->getString("phone") << endl;
            PreparedStatement *pstmtForAddress = con->prepareStatement(
                    "SELECT * FROM Supplier_address WHERE idSupplier_address = ? ");
            pstmtForAddress->setString(1, rset->getString("idSupplier"));
            ResultSet *Address = pstmtForAddress->executeQuery();
            Address->first();
            cout << "Address: " + Address->getString("City");
            cout << "," + Address->getString("Street");
            cout << "," + Address->getString("House") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }
        delete pstmt;
        delete rset;
        delete con;
    }

    void checkAllSuppliersOfABook(string& book_name) {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Book INNER JOIN supplier_books WHERE Book.ISBN =  supplier_books.book_isbn AND Book.book_name = ? ");
        pstmt->setString(1, book_name);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        if (all < 1) {
            cout << "-------------------------------------" << endl;
            cout << "Book name : " << book_name;
            cout << " Does not in not exist!" << endl;
            cout << "-------------------------------------" << endl;
        } else {
            cout << "-------------------------------------" << endl;
            cout << "Book: " + rset->getString("book_name") << endl;
            cout << "Can be provided by: " << endl;
            while (all >= 1) {
                PreparedStatement *pstmtForSupplier = con->prepareStatement(
                        "SELECT * FROM Supplier WHERE idSupplier = ? ");
                pstmtForSupplier->setString(1, rset->getString("id_supplier"));
                ResultSet *rsetForSupplier = pstmtForSupplier->executeQuery();
                rsetForSupplier->first();
                cout << rsetForSupplier->getString("name") << endl;
                rset->next();
                all--;
            }
            cout << "-------------------------------------" << endl;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
    void maximumBooksProvided(string& date){
        int maxCount[2] = {};
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Bookstore.resupply INNER JOIN resupply_books where resupply.resupply_id = resupply_books.resuply_id  and date_time > ? ORDER BY resuply_id DESC");
        pstmt->setString(1,date);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            int supplier_id = rset->getInt("supplier_id");
            int tempcount = 0;
            while (all > 0 && rset->getInt("supplier_id") == supplier_id) {
                tempcount += rset->getInt("book_quantity");
                rset->next();
                all--;
            }
            if (tempcount > maxCount[0]) {
                maxCount[0] = tempcount;
                rset->previous();
                maxCount[1] = rset->getInt("supplier_id");
                rset->next();
            }
        }
        pstmt = con->prepareStatement("SELECT * FROM Bookstore.Supplier INNER JOIN Supplier_address WHERE idSupplier = ? and idSupplier= idSupplier_address");
        pstmt->setString(1,to_string(maxCount[1]));
        rset = pstmt->executeQuery();
        if(rset->rowsCount() > 0) {
            rset->first();
            cout << "-------------------------------------" << endl;
            cout << "Supplier: " << rset->getString("name") << ". Located In: " << rset->getString("City")  << ". Supplied " << maxCount[0] << " books. Which is the maximum for our store!" << endl;
            cout << "-------------------------------------" << endl;
        }
        delete pstmt;
        delete rset;
        delete con;
    }
    void allDealsWithSupplier(string& id_supplier,string& start,string& end)  //expects ID of a supplier
    {
        int money_spent = 0;
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM Bookstore.resupply where date_time between ? and ? and status = 'supplied' and supplier_id = ?");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        pstmt->setString(3, id_supplier);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();

        size_t all = rset->rowsCount();
        while (all >= 1) {
            money_spent += rset->getInt("total_price");
            rset->next();
            all--;
        }
        cout << "-------------------------------------" << endl;
        cout << "Total money paid to supplier with ID: " << id_supplier << " between: " << start << " and " << end << " is: " << money_spent << "$" << endl;
        cout << "-------------------------------------" << endl;











    }
};


#endif //DBMS_SQL_SUPPLIER_H
