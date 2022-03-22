BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "security" (
	"id"	integer UNIQUE,
	"access"	integer,
	"password"	text
);
CREATE TABLE IF NOT EXISTS "services" (
	"price"	,
	"name"	
);
CREATE TABLE IF NOT EXISTS "workers" (
	"name"	TEXT NOT NULL,
	"id"	INTEGER,
	PRIMARY KEY("id" AUTOINCREMENT)
);
CREATE TABLE IF NOT EXISTS "orders" (
	"number"	INTEGER,
	"client"	TEXT,
	"worker"	TEXT,
	"date"	TEXT,
	"status"	TEXT,
	"cost"	TEXT,
	"services"	TEXT,
	"discount"	Integer DEFAULT (0),
	"phone"	TEXT
);
COMMIT;