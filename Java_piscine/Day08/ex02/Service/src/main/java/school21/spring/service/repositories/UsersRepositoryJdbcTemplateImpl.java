package school21.spring.service.repositories;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.RowMapperResultSetExtractor;
import org.springframework.stereotype.Component;
import school21.spring.service.model.User;

import javax.jws.soap.SOAPBinding;
import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
import java.util.Optional;

@Component
public class UsersRepositoryJdbcTemplateImpl implements UsersRepository {

    @Autowired
//    @Qualifier("UsersRepositoryJdbcTemplateImpl")
    private final JdbcTemplate jdbcTemplate;

    public UsersRepositoryJdbcTemplateImpl(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public User findById(Long id) {
        return  jdbcTemplate.query("SELECT * FROM db.users WHERE id=?;",
                new myRowMapper(), id).stream().findAny().orElse(null);
    }

    @Override
    public List<User> findAll() {
        return jdbcTemplate.query("SELECT * FROM db.users", new myRowMapper());
    }

    @Override
    public void save(User entity) {
        jdbcTemplate.update("INSERT INTO db.users (email) VALUES (?);", entity.getEmail());
    }

    @Override
    public void update(User entity) {
        jdbcTemplate.update("UPDATE db.users SET room_id=?, email=? WHERE id = ?;", entity.getId(), entity.getEmail(), entity.getId());
    }

    @Override
    public void delete(User entity) {
        jdbcTemplate.update("DELETE FROM db.users WHERE id = ?;", entity.getId());
    }

    @Override
    public Optional<User> findByEmail(String email) {
        User user = jdbcTemplate.query("SELECT * FROM db.users WHERE email=?", new myRowMapper(), email).stream().findAny().orElse(null);
        return Optional.of(user);
    }
}

class myRowMapper implements RowMapper<User> {
    @Override
    public User mapRow(ResultSet rs, int rowNum) throws SQLException {
        return new User(rs.getLong("id"), rs.getString("email"));
    }
}