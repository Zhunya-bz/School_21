package edu.school21.chat.repositories;

import edu.school21.chat.models.Chatroom;
import edu.school21.chat.models.Message;
import edu.school21.chat.models.User;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.Optional;

public class MessagesRepositoryJdbcImpl implements MessagesRepository {
    private final DataSource ds;

    public MessagesRepositoryJdbcImpl(DataSource ds) {
        this.ds = ds;
    }
    @Override
    public Optional<Message> findById(Long id) throws SQLException {


        Connection connection = ds.getConnection();
        System.out.println("HHHHEEEEE");
        System.exit(-1);

        PreparedStatement statementUser = connection.prepareStatement("SELECT * FROM chat.users WHERE id=?");
        System.out.println("HHHHEEEEE");
        System.exit(-1);
        statementUser.setLong(1, id);
        ResultSet resultSet2 = statementUser.executeQuery();
        resultSet2.next();
        User user = new User(resultSet2.getLong("id"), resultSet2.getString("login"), resultSet2.getString("password"), null, null );

        System.out.println(user);
        System.exit(-1);

        PreparedStatement statementChat = connection.prepareStatement("SELECT * FROM chat.room WHERE owner_room=?");
        statementChat.setLong(1, id);
        ResultSet resultSet3 = statementChat.executeQuery();
        resultSet2.next();
        Chatroom chatroom = new Chatroom(resultSet3.getLong("id"), resultSet3.getString("name_room"), user, null);

        PreparedStatement statement = connection.prepareStatement("SELECT * FROM chat.messages WHERE author=?");
        statement.setLong(1, id);
        ResultSet resultSet = statement.executeQuery();
        resultSet.next();

        String times = String.valueOf(resultSet.getTimestamp("times"));
        Message message = new Message(resultSet.getLong("id"), user, chatroom, resultSet.getString("message"),
                LocalDateTime.parse(times));
        return Optional.of(message);
    }
}
