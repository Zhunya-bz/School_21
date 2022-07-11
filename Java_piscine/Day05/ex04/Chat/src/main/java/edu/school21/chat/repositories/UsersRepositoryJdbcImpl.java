package edu.school21.chat.repositories;

import edu.school21.chat.exceptions.NotSavedSubEntityException;
import edu.school21.chat.models.User;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UsersRepositoryJdbcImpl implements UsersRepository {
    private final DataSource ds;

    public UsersRepositoryJdbcImpl(DataSource ds) {
        this.ds = ds;
    }
    @Override
    public List<User> findAll(int page, int size) {
        List<User> list = new ArrayList<>();
        String sql = "SELECT * FROM chat.users LIMIT ? OFFSET ?";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setLong(1, size);
            statement.setLong(2, size * page);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                User user = new User(resultSet.getLong("id"), resultSet.getString("login"), resultSet.getString("password"), null, null);
                list.add(user);
            }
        } catch (SQLException e) {
            throw new NotSavedSubEntityException();
        }
        return list;
    }
}
