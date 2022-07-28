package school21.spring.service.config;

import com.zaxxer.hikari.HikariDataSource;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
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
@ComponentScan("school21.spring.service")
public class ApplicationConfig {

//    @Autowired
//    private Environment env;

    @Value("${db.driver.name}")
    private String dbDriverName;

    @Value("${db.url}")
    private String dbUrl;

    @Value("${db.user}")
    private String dbUsername;

    @Value("${db.password}")
    private String dbPassword;

    @Bean
    public DataSource dataSource() {
        DriverManagerDataSource dataSource = new DriverManagerDataSource();
        dataSource.setDriverClassName(dbDriverName);
        dataSource.setUrl(dbUrl);
        dataSource.setUsername(dbUsername);
        dataSource.setPassword(dbPassword);
        return dataSource;
    }

    @Bean
    public HikariDataSource hikariDataSource() {
        HikariDataSource hikari = new HikariDataSource();
        hikari.setDriverClassName(dbDriverName);
        hikari.setJdbcUrl(dbUrl);
        hikari.setUsername(dbUsername);
        hikari.setPassword(dbPassword);
        return hikari;
    }

    @Bean
    public JdbcTemplate jdbcTemplateSource() {
        return new JdbcTemplate(dataSource());
    }
//
//    @Bean
//    public UsersRepositoryJdbcImpl usersRepositoryJdbc() {
//        return new UsersRepositoryJdbcImpl(dataSource());
//    }
//
//    @Bean
//    public UsersRepositoryJdbcTemplateImpl usersRepositoryJdbcTemplate() {
//        return new UsersRepositoryJdbcTemplateImpl(jdbcTemplateSource());
//    }

}
