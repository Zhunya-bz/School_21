CREATE SCHEMA IF NOT EXISTS chat;

DROP TABLE IF EXISTS chat.messages, chat.room, chat.users;

CREATE TABLE IF NOT EXISTS chat.users (
    id          SERIAL PRIMARY KEY,
    login       VARCHAR(100) NOT NULL ,
    password    VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS chat.room (
    id          SERIAL PRIMARY KEY,
    owner_room  INT NOT NULL REFERENCES chat.users(id) ,
    name_room   VARCHAR(100) NOT NULL
);

CREATE TABLE IF NOT EXISTS chat.messages (
    id          SERIAL PRIMARY KEY,
    room_id     INT NOT NULL REFERENCES chat.room(id),
    author      INT NOT NULL REFERENCES chat.users(id),
    message     VARCHAR(100) NOT NULL ,
    times       TIMESTAMP DEFAULT NOW()
);