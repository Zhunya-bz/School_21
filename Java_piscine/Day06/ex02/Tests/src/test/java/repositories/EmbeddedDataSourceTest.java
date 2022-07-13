package repositories;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import javax.sql.DataSource;
import org.junit.jupiter.api.Test;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;
import java.sql.SQLException;

public class EmbeddedDataSourceTest {
    private DataSource dataSource;

    @BeforeEach
    void init() {
        // Построитель, предоставляющий удобный API для построения встроенной базы данных.
        dataSource = new EmbeddedDatabaseBuilder().setType(EmbeddedDatabaseType.HSQL)
                .addScript("schema.sql")
                .addScript("data.sql")
                .build();
    }

    @Test
    void checkGetConnection() throws SQLException {
        Assertions.assertNotNull(dataSource.getConnection());
    }
}
