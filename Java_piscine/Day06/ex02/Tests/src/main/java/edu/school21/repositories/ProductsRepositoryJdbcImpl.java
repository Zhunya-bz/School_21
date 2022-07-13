package edu.school21.repositories;

import edu.school21.models.Product;

import javax.sql.DataSource;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ProductsRepositoryJdbcImpl  implements  ProductsRepository {
    private final DataSource ds;

    public ProductsRepositoryJdbcImpl(DataSource ds) {
        this.ds = ds;
    }

    @Override
    public List<Product> findAll() {
        List<Product> list = new ArrayList<>();
        String sql = "SELECT * FROM product";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                Product product = new Product(resultSet.getLong("id"),
                        resultSet.getString("name"),
                        resultSet.getInt("price"));
                list.add(product);
            }
        } catch (SQLException e) {
            throw new RuntimeException("Not create a list of products");
        }
        return list;
    }

    @Override
    public Optional<Product> findById(Long id) {
        Product product = null;
        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement("SELECT * FROM product WHERE id=?")) {
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            resultSet.next();
            product = new Product(resultSet.getLong("id"),
                    resultSet.getString("name"), resultSet.getInt("price"));
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(product);
    }

    @Override
    public void update(Product product) {
        String sql = "UPDATE product" +
                " SET id = ?, name = ?, price = ? WHERE id = ?;";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setLong(1, product.getId());
            statement.setString(2, product.getName());
            statement.setInt(3, product.getPrice());
            statement.setLong(4, product.getId());
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException("Product not update");
        }
    }

    @Override
    public void save(Product product) {
        String sql = "INSERT INTO product (id, name, price) VALUES (?, ?, ?);";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setLong(1, product.getId());
            statement.setString(2, product.getName());
            statement.setInt(3, product.getPrice());
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException("Product not save");
        }
    }

    @Override
    public void delete(Long id) {
        String sql = "DELETE FROM product WHERE id = ?;";

        try (Connection connection = ds.getConnection();
             PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setLong(1, id);
            statement.execute();
        } catch (SQLException e) {
            throw new RuntimeException("Product not delete");
        }
    }
}
