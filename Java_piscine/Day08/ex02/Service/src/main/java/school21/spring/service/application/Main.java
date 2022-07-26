package school21.spring.service.application;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import school21.spring.service.config.ApplicationConfig;
import school21.spring.service.model.User;
import school21.spring.service.repositories.UsersRepository;
import school21.spring.service.repositories.UsersRepositoryJdbcImpl;

public class Main {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(ApplicationConfig.class);
        UsersRepository usersRepository = context.getBean(UsersRepositoryJdbcImpl.class);
        System.out.println("------------------");
        System.out.println(usersRepository.findAll());

//        ApplicationContext context = new ClassPathXmlApplicationContext("context.xml");
//        UsersRepository usersRepository = context.getBean("usersRepositoryJdbc", UsersRepository.class);
//        System.out.println("------------------");
//        System.out.println(usersRepository.findAll());
////        usersRepository = context.getBean("usersRepositoryJdbcHikari", UsersRepository.class);
////        System.out.println("------------------");
////        System.out.println(usersRepository.findAll());
//        usersRepository = context.getBean("usersRepositoryJdbcTemplate", UsersRepository.class);
//        System.out.println("------------------");
//        System.out.println(usersRepository.findAll());
    }
}
