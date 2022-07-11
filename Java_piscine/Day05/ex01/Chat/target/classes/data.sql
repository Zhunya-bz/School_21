INSERT INTO chat.users (login, password) VALUES ('saltmer', '123456');
INSERT INTO chat.users (login, password) VALUES ('milkfist', 'milk');
INSERT INTO chat.users (login, password) VALUES ('lol', '343');
INSERT INTO chat.users (login, password) VALUES ('vleida', '012');
INSERT INTO chat.users (login, password) VALUES ('mcarry', '123456453');
INSERT INTO chat.users (login, password) VALUES ('login', 'login');

INSERT INTO chat.room (owner_room, name_room) VALUES (1, 'chat1');
INSERT INTO chat.room (owner_room, name_room) VALUES (2, 'chat2');
INSERT INTO chat.room (owner_room, name_room) VALUES (3, 'chat3');
INSERT INTO chat.room (owner_room, name_room) VALUES (4, 'chat4');
INSERT INTO chat.room (owner_room, name_room) VALUES (5, 'chat5');

INSERT INTO chat.messages (room_id, author, message, times) VALUES (1, 2, 'hello friends', to_timestamp('2015/12/31 10:13', 'YYYY/MM/DD HH:MI'));
INSERT INTO chat.messages (room_id, author, message, times) VALUES (3, 2, 'hello friends', to_timestamp('2001/01/01 01:01', 'YYYY/MM/DD HH:MI'));
INSERT INTO chat.messages (room_id, author, message, times) VALUES (4, 2, 'hello friends', to_timestamp('2022/12/12 03:23', 'YYYY/MM/DD HH:MI'));
INSERT INTO chat.messages (room_id, author, message, times) VALUES (1, 2, 'hello friends', to_timestamp('2018/01/31 09:43', 'YYYY/MM/DD HH:MI'));
INSERT INTO chat.messages (room_id, author, message, times) VALUES (1, 3, 'hello friends', to_timestamp('2014/10/21 11:18', 'YYYY/MM/DD HH:MI'));
INSERT INTO chat.messages (room_id, author, message, times) VALUES (2, 3, 'hello friends', to_timestamp('2019/11/25 12:33', 'YYYY/MM/DD HH:MI'));
INSERT INTO chat.messages (room_id, author, message, times) VALUES (2, 1, 'hello friends', to_timestamp('2021/12/30 05:13', 'YYYY/MM/DD HH:MI'));