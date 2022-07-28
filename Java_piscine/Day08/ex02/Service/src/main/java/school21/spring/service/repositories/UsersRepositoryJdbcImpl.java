package school21.spring.service.repositories;

import com.zaxxer.hikari.HikariDataSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;
import school21.spring.service.model.User;

import javax.sql.DataSource;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

@Component
public class UsersRepositoryJdbcImpl implements UsersRepository{
    @Autowired
    @Qualifier("dataSource")
    private DataSource ds;


//    public UsersRepositoryJdbcImpl(DataSource dataSource) {
//        this.ds = dataSource;
//    }

    @Override
    public User findById(Long id) {
        String sql = "SELECT * FROM db.users WHERE id=?";
        User user = null;
        try (Connection connection = ds.getConnection();
              PreparedStatement statement = connection.prepareStatement(sql);) {
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            user = new User(resultSet.getString("email"));
        }
        catch (SQLException ex) {
            ex.printStackTrace();
        }
        return user;
    }

    @Override
    public List<User> findAll() {
        List<User> list = new ArrayList<>();
        String sql = "SELECT * FROM db.users";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                User user = new User(resultSet.getString("email"));
                list.add(user);
            }
        } catch (SQLException e) {
            throw new RuntimeException("Not create a list of users!");
        }
        return list;
    }

    @Override
    public void save(User entity) {
        String sql = "INSERT INTO db.users (email) VALUES (?);";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            statement.setString(1, entity.getEmail());
            statement.execute();
            ResultSet resultSet = statement.getGeneratedKeys();
            resultSet.next();
            entity.setId(resultSet.getLong("id"));
        } catch (SQLException e) {
            throw new RuntimeException("User's not saved!");
        }
    }

    @Override
    public void update(User entity) {
        String sql = "UPDATE db.users" +
                " SET room_id = ?, email = ? WHERE id = ?;";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            statement.setLong(1, entity.getId());
            statement.setString(2, entity.getEmail());
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException("User's not update!");
        }
    }

    @Override
    public void delete(User entity) {
        String sql = "DELETE FROM db.users WHERE id = ?;";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setLong(1, entity.getId());
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException("User's not delete!");
        }
    }

    @Override
    public Optional<User> findByEmail(String email) {
        String sql = "SELECT * FROM db.users WHERE email=?";
        User user = null;
        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql);) {
            statement.setString(1, email);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            user = new User(resultSet.getString("email"));
        }
        catch (SQLException ex) {
            ex.printStackTrace();
        }
        return Optional.of(user);
    }
}
