package repositories;

import edu.school21.models.Product;
import edu.school21.repositories.ProductsRepositoryJdbcImpl;
import org.junit.jupiter.api.*;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabase;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseBuilder;
import org.springframework.jdbc.datasource.embedded.EmbeddedDatabaseType;

import java.util.Arrays;
import java.util.List;

public class ProductsRepositoryJdbcImplTest {
    private EmbeddedDatabase dataSource;
    private ProductsRepositoryJdbcImpl repository;

    final List<Product> EXPECTED_FIND_ALL_PRODUCTS = Arrays.asList(
            new Product(1L, "Mac", 100800),
            new Product(2L, "Lenovo", 45800),
            new Product(3L, "Acer", 30000),
            new Product(4L, "Dell", 21000));
    final Product EXPECTED_FIND_BY_ID_PRODUCT = new Product(3L, "Acer", 30000); // id = 3
    final Product EXPECTED_UPDATED_PRODUCT = new Product(4L, "HP", 28499);
    final Product EXPECTED_SAVED_PRODUCT = new Product(5L, "Honor", 65000);


    @BeforeEach
    void init() {
        // Построитель, предоставляющий удобный API для построения встроенной базы данных.
        dataSource = new EmbeddedDatabaseBuilder().setType(EmbeddedDatabaseType.HSQL)
                .addScript("schema.sql")
                .addScript("data.sql")
                .build();
        repository = new ProductsRepositoryJdbcImpl(dataSource);
    }

    @Test
    void testFindAll() {
        Assertions.assertEquals(EXPECTED_FIND_ALL_PRODUCTS, repository.findAll());
    }

    @Test
    void testFindById() {
        Assertions.assertEquals(EXPECTED_FIND_BY_ID_PRODUCT, repository.findById(3L).get());
    }

    @Test
    void testUpdate() {
        repository.update(EXPECTED_UPDATED_PRODUCT);
        Assertions.assertEquals(EXPECTED_UPDATED_PRODUCT, repository.findById(4L).get());
    }

    @Test
    void testDelete() {
        repository.delete(1L);
        Assertions.assertThrows(RuntimeException.class, () -> repository.findById(1L).get());
    }

    @Test
    void testSave() {
        repository.save(EXPECTED_SAVED_PRODUCT);
        Assertions.assertEquals(EXPECTED_SAVED_PRODUCT, repository.findById(5L).get());
    }

    @AfterEach
    void close() {
        dataSource.shutdown();
    }
}
