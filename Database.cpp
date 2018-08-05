#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;
	
	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema(DB_NAME);
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			string q = "CREATE DATABASE IF NOT EXISTS ";
			q.append(DB_NAME);
			stmt->execute(q);
			con->setSchema(DB_NAME); // switch database
			stmt->execute("CREATE TABLE `Address` (`idAddress` int(11) NOT NULL,`City` varchar(45) DEFAULT NULL,`Street` varchar(45) DEFAULT NULL,`House` int(11) DEFAULT NULL, PRIMARY KEY (`idAddress`))");
            stmt->execute("LOCK TABLES `Address` WRITE");
            stmt->execute("INSERT INTO `Address` VALUES (112312311,'Madrid','Ramolini',121),(113939393,'Berlin','Swartzkov',11),(121244444,'Budapest','Vaci',11),(123124441,'New York','Fifth Ave',188),(155204906,'Rome',' Via Cavour',11),(346097735,'Rome','Via della Conciliazione',1),(495497003,'Rome','Via del Corso',56),(676128868,'Rome','Via dei Fori Imperiali',11),(824241642,'Rome','Via Giulia',6),(881999911,'Lviv','Zaroma',1),(918181881,'Kiev','Grkogo',121)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `Author`");
            stmt->execute("CREATE TABLE `Author` (`idBook` int(11) DEFAULT NULL,"
            " `FName` varchar(45) DEFAULT NULL,"
            " `LName` varchar(45) DEFAULT NULL");
            stmt->execute("LOCK TABLES `Author` WRITE");
            stmt->execute("INSERT INTO `Author` VALUES (437396,'Arthur ','Conan Doyle'),(757230,'Enthoven',' R. E.'),(611936,'Homer',' '),(757230,'Jackson','A. M. T.'),(907419,'Jane','Austen'),(378249,'Lewis','Carroll'),(907411,'Rowling','Joanne'),(888811,'James','Madison'),(172111,'Rick','Riordan'),(123114,' Terry','Pratchett'),(989999,'David','Sedaris')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `Book`");
            stmt->execute("CREATE TABLE `Book` ("
            "`ISBN` int(11) NOT NULL,"
            "`book_name` varchar(45) DEFAULT NULL,"
            "`Quantity` int(11) DEFAULT NULL,"
            "`global_discount` float DEFAULT NULL,"
            "  PRIMARY KEY (`ISBN`),"
            "UNIQUE KEY `ISBN_UNIQUE` (`ISBN`)");
            stmt->execute("LOCK TABLES `Book` WRITE");
            stmt->execute("INSERT INTO `Book` VALUES (123114,'Equal Rites',8,1),(172111,'The Battle of the Labyrinth',111,1),(378249,'Alice\'s Adventures in Wonderland',11,1),(437396,'The Adventures of Sherlock Holmes',0,1),(611936,'The Iliad',21,1),(757230,'Folk Lore Notes. Vol. II',14,1),(888811,'The Mind of the Founder',11,0.9),(907411,'Harry Potter and the Deathly Hallows',100,0.5),(907419,'Equal Rites',10,0.9),(989999,'Naked',110,0.6)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `Customer`");
            stmt->execute("CREATE TABLE `Customer` ("
            "`SSN` int(11) NOT NULL,"
            "`PhoneNumber` varchar(45) DEFAULT NULL,"
            "`Discount` float DEFAULT NULL,"
            "`date_joined` datetime DEFAULT NULL,"
            "        PRIMARY KEY (`SSN`),"
            "UNIQUE KEY `SSN_UNIQUE` (`SSN`)");
            stmt->execute("LOCK TABLES `Customer` WRITE");
            stmt->execute("INSERT INTO `Customer` VALUES (112312311,'041-1231141',1,'2015-09-12 09:34:09'),(113939393,'094-2445114',1,'2018-01-12 09:34:09'),(121244444,'042-9099911',1,'2015-09-12 09:34:09'),(123124441,'024-1512555',1,'2018-10-12 09:34:09'),(155204906,'054-1231231',1,'2017-05-12 09:34:09'),(346097735,'054-4141412',1,'2015-05-12 09:34:09'),(495497003,'054-4124214',1,'2018-05-10 09:34:09'),(676128868,'054-2415678',1,'2018-11-12 09:34:09'),(824241642,'054-4124661',0.9,'2018-09-12 09:34:09'),(881999911,'025-1512244',1,'2017-06-12 09:34:09'),(918181881,'042-1244111',1,'2014-09-12 09:34:09')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `FullName`");
            stmt->execute("CREATE TABLE `FullName` ("
            "`SSN` int(11) NOT NULL,"
            "`FName` varchar(45) DEFAULT NULL,"
            "`LName` varchar(45) DEFAULT NULL,"
            "        PRIMARY KEY (`SSN`),"
            "UNIQUE KEY `SSN_UNIQUE` (`SSN`)");
            stmt->execute("LOCK TABLES `FullName` WRITE");
            stmt->execute("INSERT INTO `FullName` VALUES (112312311,'Yuval','Golan'),(113939393,'Marina','Solomon'),(121244444,'Masad','Aromas'),(123124441,'Yael','Barak'),(155204906,'Mika','Sano'),(346097735,'Rita','Mazur'),(495497003,'Nomi','Salem'),(676128868,'Mora','Saban'),(824241642,'Mano','Innako'),(881999911,'Moras','Goparinus'),(918181881,'Elena','Salomiki')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `Orders`");
            stmt->execute("CREATE TABLE `Orders` ("
            "`idOrder` int(11) NOT NULL,"
            "`TotalPrice` int(11) DEFAULT NULL,"
            "`date` datetime DEFAULT NULL,"
            "`status` enum('Opened','Notified','Delivered','Canceled','Closed') DEFAULT NULL,"
            "        PRIMARY KEY (`idOrder`),"
            "UNIQUE KEY `idOrder_UNIQUE` (`idOrder`)");
            stmt->execute("LOCK TABLES `Orders` WRITE");
            stmt->execute("INSERT INTO `Orders` VALUES (1,453,'2018-06-12 10:34:09','Closed'),(2,100,'2018-05-12 09:34:09','Closed'),(3,100,'2018-05-12 11:34:09','Closed'),(4,255,'2018-07-12 11:34:09','Opened'),(5,115,'2018-04-12 11:34:09','Closed'),(6,25,'2018-04-11 11:34:09','Canceled'),(7,230,'2017-04-11 10:34:09','Closed'),(8,900,'2018-12-11 11:34:09','Closed'),(9,135,'2018-12-30 11:34:09','Closed'),(10,140,'2017-11-30 11:34:09','Closed')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `Supplier`");
            stmt->execute("CREATE TABLE `Supplier` ("
            "`idSupplier` int(11) NOT NULL,"
            "`name` varchar(45) DEFAULT NULL,"
            "`phone` varchar(45) DEFAULT NULL,"
            "        PRIMARY KEY (`idSupplier`)");
            stmt->execute("LOCK TABLES `Supplier` WRITE");
            stmt->execute("INSERT INTO `Supplier` VALUES (1342,'Moshe\'s and Sons','05-21312311'),(1415,'Encore Books','03-99444777'),(1513,'Borders Books and Music','03-34677744'),(1551,'Halper\'s Books','03-12415111'),(1919,'Selexyz Dominicanen Bookstore','03-19991991'),(5512,'Crown Books','03-22333322'),(6163,'Daunt Books Marylebone','08-09888112'),(6621,'El Ateneo Grand Splendid','01-29917771'),(7344,'Atlantic Books','05-21231233'),(7676,'Shakespeare and Company','02-01113333')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `Supplier_address`");
            stmt->execute("CREATE TABLE `Supplier_address` ("
                                  "`idSupplier_address` int(11) NOT NULL,"
                                  "`City` varchar(45) DEFAULT NULL,"
                                  "`Street` varchar(45) DEFAULT NULL,"
                                  "`House` varchar(45) DEFAULT NULL,"
                                  "PRIMARY KEY (`idSupplier_address`)");
            stmt->execute("LOCK TABLES `Supplier_address` WRITE");
            stmt->execute("INSERT INTO `Supplier_address` VALUES (1342,'Rishon Le Zion','Herzel','100'),(1415,'New York','Bowery','111'),(1513,'Rome','Via Sacra','9'),(1551,'Ramla','Herzl','113'),(1919,'Florence','Via Maso di Banco','30'),(5512,'New York','Broadway','9'),(6163,'Miramonti','Via Monte Rosa','13'),(6621,'Caposile','Via Caposile','12'),(7344,'Tel Aviv','Dizengoff','99'),(7676,'Moosheim','Griesshoferweg','1')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `book_price`");
            stmt->execute("CREATE TABLE `book_price` ("
                                  "`idbook` int(11) NOT NULL,"
                                  "`customer_price` int(11) DEFAULT NULL,"
                                  "`real_price` int(11) DEFAULT NULL,"
                                  "PRIMARY KEY (`idbook`)");
            stmt->execute("LOCK TABLES `book_price` WRITE");
            stmt->execute("INSERT INTO `book_price` VALUES (123114,10,5),(172111,75,60),(378249,97,87),(437396,85,80),(611936,75,70),(757230,87,78),(888811,100,85),(907411,50,45),(907419,100,90),(989999,50,40)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `books_in_order`");
            stmt->execute("CREATE TABLE `books_in_order` ("
                                  "`order_id` int(11) NOT NULL,"
                                  "`books_id` int(11) NOT NULL,"
                                  "`quantity_in_order` int(11) DEFAULT NULL,"
                                  "        PRIMARY KEY (`order_id`,`books_id`)");
            stmt->execute("LOCK TABLES `books_in_order` WRITE");
            stmt->execute("INSERT INTO `books_in_order` VALUES (1,378249,3),(1,611936,1),(1,757230,1),(2,378249,1),(2,907419,1),(3,907419,1),(4,437396,3),(5,888811,1),(5,907411,1),(6,907411,1),(7,123114,3),(7,611936,2),(7,989999,1),(8,888811,5),(8,907419,5),(9,989999,3),(10,123114,5),(10,907411,3)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `customer_order`");
            stmt->execute("CREATE TABLE `customer_order` ("
                                  "`customer_id` int(11) NOT NULL,"
                                  "`order_id` int(11) NOT NULL,"
                                  "       PRIMARY KEY (`customer_id`,`order_id`)");

            stmt->execute("LOCK TABLES `customer_order` WRITE");
            stmt->execute("INSERT INTO `customer_order` VALUES (112312311,7),(113939393,10),(495497003,2),(676128868,1),(676128868,3),(824241642,5),(824241642,6),(824241642,8),(824241642,9),(918181881,4)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `employee`");
            stmt->execute("CREATE TABLE `employee` ("
                                  "`id_employee` int(11) NOT NULL,"
                                  "`SSN` int(11) DEFAULT NULL,"
                                  "        PRIMARY KEY (`id_employee`)");
            stmt->execute("LOCK TABLES `employee` WRITE");
            stmt->execute("INSERT INTO `employee` VALUES (1,346092235),(2,312312735),(3,991097735),(4,341227735),(5,191991991),(6,634232211),(7,411122233),(8,151552224),(9,132523666),(10,123422211)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `employee_name`");
            stmt->execute("CREATE TABLE `employee_name` ("
                                  "`id_employee_name` int(11) NOT NULL,"
                                  "`FName` varchar(45) DEFAULT NULL,"
                                  "`LName` varchar(45) DEFAULT NULL,"
                                  "       PRIMARY KEY (`id_employee_name`)");

            stmt->execute("LOCK TABLES `employee_name` WRITE");
            stmt->execute("INSERT INTO `employee_name` VALUES (1,'Marok','Ibansu'),(2,'Mashila','Hareno'),(3,'Omar','Ramer'),(4,'Sami','Inbal'),(5,'Bobo','Marod'),(6,'Kilo','Asa'),(7,'Marok','Falon'),(8,'Rob','Stark'),(9,'Ben','Solo'),(10,'Robin','Hood')");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `employee_sales`");
            stmt->execute("CREATE TABLE `employee_sales` ("
            "`employee_id` int(11) DEFAULT NULL,"
                                  "`order_id` int(11) NOT NULL,"
                                  "       PRIMARY KEY (`order_id`)");
            stmt->execute("LOCK TABLES `employee_sales` WRITE");
            stmt->execute("INSERT INTO `employee_sales` VALUES (1,1),(1,2),(2,3),(3,4),(3,5),(3,6),(4,7),(5,8),(6,9),(9,10)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `resupply`");
            stmt->execute("CREATE TABLE `resupply` ("
                                  "`resupply_id` int(11) NOT NULL,"
                                  "`total_price` int(11) DEFAULT NULL,"
                                  "`date_time` varchar(45) DEFAULT NULL,"
                                  "`status` enum('ordered','shipped','supplied') DEFAULT NULL,"
                                  "`supplier_id` int(11) DEFAULT NULL,"
                                  "       PRIMARY KEY (`resupply_id`)");
            stmt->execute("LOCK TABLES `resupply` WRITE");
            stmt->execute("INSERT INTO `resupply` VALUES (1,218,'2018-03-12 10:24:09','shipped',1513),(2,174,'2018-09-12 11:34:09','supplied',1551),(3,225,'2018-07-12 11:34:09','supplied',1513),(4,195,'2017-07-12 11:34:09','supplied',6621),(5,338,'2016-07-12 11:34:09','supplied',7344),(6,750,'2018-01-12 11:34:09','supplied',7676),(7,200,'2018-02-12 11:34:09','supplied',1415),(8,180,'2018-09-12 11:34:09','supplied',1551),(9,480,'2018-11-12 11:34:09','supplied',5512),(10,440,'2017-10-12 11:34:09','supplied',6163),(11,40,'2017-11-12 11:34:09','supplied',6621)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `resupply_books`");
            stmt->execute("CREATE TABLE `resupply_books` ("
                                  "`book_isbn` int(11) NOT NULL,"
                                  "`resuply_id` int(11) NOT NULL,"
                                  "`book_quantity` int(11) DEFAULT NULL,"
                                  "PRIMARY KEY (`book_isbn`,`resuply_id`)");

            stmt->execute("LOCK TABLES `resupply_books` WRITE");
            stmt->execute("INSERT INTO `resupply_books` VALUES (123114,4,3),(123114,10,10),(172111,6,5),(172111,8,3),(378249,2,2),(437396,5,1),(437396,10,4),(611936,1,2),(611936,4,2),(611936,9,2),(611936,10,1),(757230,1,1),(757230,5,1),(888811,9,3),(907411,3,1),(907411,5,2),(907411,6,10),(907419,3,2),(907419,5,1),(989999,4,1),(989999,7,5),(989999,11,1)");
            stmt->execute("UNLOCK TABLES");

            stmt->execute("DROP TABLE IF EXISTS `supplier_books`");
            stmt->execute("CREATE TABLE `supplier_books` ("
                                  "`id_supplier` int(11) NOT NULL,"
                                  "`book_isbn` varchar(45) NOT NULL,"
                                  "        PRIMARY KEY (`id_supplier`,`book_isbn`)");
            stmt->execute("LOCK TABLES `supplier_books` WRITE");
            stmt->execute("INSERT INTO `supplier_books` VALUES (1342,'378249'),(1415,'757230'),(1551,'611936'),(1551,'907419'),(1919,'437396'),(1919,'907419'),(5512,'888811'),(5512,'907411'),(6163,'611936'),(6163,'907411'),(7344,'123114'),(7344,'378249'),(7344,'437396'),(7344,'611936'),(7344,'757230'),(7676,'989999')");
            stmt->execute("UNLOCK TABLES");

            delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
		throw e;
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	} catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}
