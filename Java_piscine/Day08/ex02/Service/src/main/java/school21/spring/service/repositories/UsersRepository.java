package school21.spring.service.repositories;

import school21.spring.service.model.User;

import java.util.Optional;

public interface UsersRepository extends CrudRepository<User>{
    Optional<User> findByEmail(String email);
}
