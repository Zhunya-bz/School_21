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

INSERT INTO chat.messages (room_id, author, message, time) VALUES (1, 2, 'hello friends', to_timestamp('2022 Aug 13','YYYY MON DD'));
INSERT INTO chat.messages (room_id, author, message, time) VALUES (3, 2, 'hello friends', to_timestamp('2022 Aug 1','YYYY MON DD'));
INSERT INTO chat.messages (room_id, author, message, time) VALUES (4, 2, 'hello friends', to_timestamp('2022 Aug 5','YYYY MON DD'));
INSERT INTO chat.messages (room_id, author, message, time) VALUES (1, 2, 'hello friends', to_timestamp('2022 Aug 26','YYYY MON DD'));
INSERT INTO chat.messages (room_id, author, message, time) VALUES (1, 3, 'hello friends', to_timestamp('2022 Aug 17','YYYY MON DD'));
INSERT INTO chat.messages (room_id, author, message, time) VALUES (2, 3, 'hello friends', to_timestamp('2022 Aug 6','YYYY MON DD'));