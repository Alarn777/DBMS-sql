//
// Created by Michael Rokitko on 21/07/2018.
//

#ifndef DBMS_SQL_STORE_H
#define DBMS_SQL_STORE_H
#include "Database.h"
#include <iostream>

#define CON Database &db = Database::getInstance();Connection *con = db.getConnection();
using namespace std;

class Store {
public:
    Store() {}
    void showAllCustomers();
    void showAllTransactions(string& start,string& end){
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM resupply where date_time between ? and ? ");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        ResultSet *rset = pstmt->executeQuery();
        rset->first();
        size_t all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Resupply ID: "<< rset->getInt("resupply_id") << endl;
            cout << "Total Price paid: " << rset->getInt("total_price") << endl;
            cout << "Status: " << rset->getString("status") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }
        pstmt = con->prepareStatement("SELECT * FROM Orders where date between ? and ? ");
        pstmt->setString(1, start);
        pstmt->setString(2, end);
        rset = pstmt->executeQuery();
        rset->first();
        all = rset->rowsCount();
        while (all >= 1) {
            cout << "-------------------------------------" << endl;
            cout << "Purchase ID: "<< rset->getInt("idOrder") << endl;
            cout << "Total Money received: " << rset->getInt("TotalPrice") << endl;
            cout << "Status: " << rset->getString("status") << endl;
            cout << "-------------------------------------" << endl;
            rset->next();
            all--;
        }

        delete pstmt;
        delete rset;
        delete con;













    }
    virtual ~Store() {}
private:

};


#endif //DBMS_SQL_STORE_H
