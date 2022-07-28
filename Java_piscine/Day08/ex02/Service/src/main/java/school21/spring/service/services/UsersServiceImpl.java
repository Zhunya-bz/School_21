package school21.spring.service.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;
import school21.spring.service.model.User;
import school21.spring.service.repositories.UsersRepository;

import java.util.UUID;

@Component
public class UsersServiceImpl implements UsersService {
    @Autowired
    @Qualifier("usersRepositoryJdbcTemplateImpl")
    private UsersRepository usersRepository;


    @Override
    public String signUp(String email) {
        if (!usersRepository.findByEmail(email).isPresent()) {
            String password = UUID.randomUUID().toString().substring(0, 8);
            User user = new User(email, password);
            usersRepository.save(user);
            return password;
        }
        return null;
    }
}
