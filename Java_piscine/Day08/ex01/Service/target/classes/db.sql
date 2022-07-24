CREATE SCHEMA IF NOT EXISTS db;

DROP TABLE IF EXISTS db.users;
CREATE TABLE IF NOT EXISTS db.users(
    id      SERIAL,
    email   VARCHAR(100) NOT NULL
);

INSERT INTO db.users (email) VALUES ('zhunya@ya.ru');
INSERT INTO db.users (email) VALUES ('saltmer@school21-student.com');
INSERT INTO db.users (email) VALUES ('fluffy@gmail.com');

