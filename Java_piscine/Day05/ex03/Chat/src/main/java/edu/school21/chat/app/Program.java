package edu.school21.chat.app;

import com.zaxxer.hikari.HikariDataSource;
import edu.school21.chat.models.Chatroom;
import edu.school21.chat.models.Message;
import edu.school21.chat.models.User;
import edu.school21.chat.repositories.MessagesRepository;
import edu.school21.chat.repositories.MessagesRepositoryJdbcImpl;

import java.sql.SQLException;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Optional;

public class Program {
    public static void main(String[] args) throws SQLException {

        HikariDataSource ds = new HikariDataSource();
        ds.setJdbcUrl("jdbc:postgresql://localhost:5432/postgres");
        ds.setUsername("saltmer");
        ds.setPassword("123");

        MessagesRepository messagesRepository = new MessagesRepositoryJdbcImpl(ds);
        Optional<Message> messageOptional = messagesRepository.findById(3L);
        if (messageOptional.isPresent()) {
            Message message = messageOptional.get();
            message.setText("ByeBye");
            message.setDateTime(LocalDateTime.now());
            messagesRepository.update(message);
        }

    }
}
