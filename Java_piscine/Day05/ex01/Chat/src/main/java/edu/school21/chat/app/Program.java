package edu.school21.chat.app;

import com.zaxxer.hikari.HikariDataSource;
import edu.school21.chat.models.Message;
import edu.school21.chat.repositories.MessagesRepository;
import edu.school21.chat.repositories.MessagesRepositoryJdbcImpl;

import java.sql.SQLException;
import java.util.Optional;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) throws SQLException {

        HikariDataSource ds = new HikariDataSource();
        ds.setJdbcUrl("jdbс:postgresql://localhost:5433/postgres");
        ds.setUsername("saltmer");
        ds.setPassword("");


        MessagesRepository mr = new MessagesRepositoryJdbcImpl(ds);

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a message ID:\n-> ");
        long id = sc.nextLong();
        System.out.println(mr.findById(id));
    }
}
