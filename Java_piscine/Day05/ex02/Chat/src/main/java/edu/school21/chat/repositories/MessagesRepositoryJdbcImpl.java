package edu.school21.chat.repositories;

import edu.school21.chat.exceptions.NotSavedSubEntityException;
import edu.school21.chat.models.Chatroom;
import edu.school21.chat.models.Message;
import edu.school21.chat.models.User;

import javax.sql.DataSource;
import java.sql.*;
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

        PreparedStatement statementUser = connection.prepareStatement("SELECT * FROM chat.users WHERE id=?");
        statementUser.setLong(1, id);
        ResultSet resultSet2 = statementUser.executeQuery();
        resultSet2.next();
        User user = new User(resultSet2.getLong("id"), resultSet2.getString("login"), resultSet2.getString("password"), null, null );
        statementUser.close();

        PreparedStatement statementChat = connection.prepareStatement("SELECT * FROM chat.room WHERE owner_room=?");
        statementChat.setLong(1, id);
        ResultSet resultSet3 = statementChat.executeQuery();
        resultSet3.next();
        Chatroom chatroom = new Chatroom(resultSet3.getLong("id"), resultSet3.getString("name_room"), null, null);
        statementChat.close();

        PreparedStatement statement = connection.prepareStatement("SELECT * FROM chat.messages WHERE author=?");
        statement.setLong(1, id);
        ResultSet resultSet = statement.executeQuery();
        resultSet.next();

//        User user = new User(1L, "saltmer", "123456", null, null);
//        Chatroom chatroom = new Chatroom(1L, "chat1", null, null);

        Message message = new Message(resultSet.getLong("id"), user, chatroom, resultSet.getString("message"),
                resultSet.getTimestamp("times").toLocalDateTime());
        statement.close();
        connection.close();
        return Optional.of(message);
    }

    @Override
    public void save(Message message) {
        String sql = "INSERT INTO chat.messages (room_id, author, message, times) VALUES (?, ?, ?, ?);";

        try (Connection connection = ds.getConnection();
                PreparedStatement statement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            statement.setLong(1, message.getRoom().getIdRoom());
            statement.setLong(2, message.getAuthor().getId());
            statement.setString(3, message.getText());
            statement.setTimestamp(4, Timestamp.valueOf(message.getTime()));
            statement.execute();
            ResultSet resultSet = statement.getGeneratedKeys();
            resultSet.next();
            message.setId(resultSet.getLong("id"));
        } catch (SQLException e) {
            throw new NotSavedSubEntityException();
        }
    }
}
