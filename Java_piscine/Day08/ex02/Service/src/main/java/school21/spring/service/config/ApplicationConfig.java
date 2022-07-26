package school21.spring.service.config;

import com.zaxxer.hikari.HikariDataSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;
import org.springframework.core.env.Environment;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.datasource.DriverManagerDataSource;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabase;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;
import school21.spring.service.repositories.UsersRepositoryJdbcImpl;
import school21.spring.service.repositories.UsersRepositoryJdbcTemplateImpl;

import javax.sql.DataSource;

@Configuration
@PropertySource("classpath:db.properties")
public class ApplicationConfig {

    @Autowired
    private Environment env;

    @Bean
    public DataSource dataSource() {
        DriverManagerDataSource dataSource = new DriverManagerDataSource();
        dataSource.setDriverClassName(env.getRequiredProperty("db.driver.name"));
        dataSource.setUrl(env.getRequiredProperty("db.url"));
        dataSource.setUsername(env.getRequiredProperty("db.user"));
        dataSource.setPassword(env.getRequiredProperty("db.password"));
        return dataSource;
    }

    @Bean
    public HikariDataSource hikariDataSource() {
        HikariDataSource hikari = new HikariDataSource();
        hikari.setDriverClassName(env.getRequiredProperty("db.driver.name"));
        hikari.setJdbcUrl(env.getRequiredProperty("db.url"));
        hikari.setUsername(env.getRequiredProperty("db.user"));
        hikari.setPassword(env.getRequiredProperty("db.password"));
        return hikari;
    }

    @Bean
    public JdbcTemplate jdbcTemplateSource() {
        return new JdbcTemplate(dataSource());
    }

    @Bean
    public UsersRepositoryJdbcImpl usersRepositoryJdbc() {
        return new UsersRepositoryJdbcImpl(dataSource());
    }

    @Bean
    public UsersRepositoryJdbcTemplateImpl usersRepositoryJdbcTemplate() {
        return new UsersRepositoryJdbcTemplateImpl(jdbcTemplateSource());
    }

}
