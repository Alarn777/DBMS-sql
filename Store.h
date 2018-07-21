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
    virtual void showAllCustomersInStore() {};
    virtual ~Store() {}
private:

};


#endif //DBMS_SQL_STORE_H
