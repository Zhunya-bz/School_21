package edu.school21.chat.models;

import java.util.List;
import java.util.Objects;

public class User {
    private Long id;
    private String login;
    private String password;
    private List<Chatroom> listRoom;
    private List<Chatroom> listRoomUserVisited;

    public User(Long id, String login, String password, List<Chatroom> listRoom, List<Chatroom> listRoomUserVisited) {
        this.id = id;
        this.login = login;
        this.password = password;
        this.listRoom = listRoom;
        this.listRoomUserVisited = listRoomUserVisited;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setListRoom(List<Chatroom> listRoom) {
        this.listRoom = listRoom;
    }

    public void setListRoomUserVisited(List<Chatroom> listRoomUserVisited) {
        this.listRoomUserVisited = listRoomUserVisited;
    }

    public String getLogin() {
        return login;
    }

    public String getPassword() {
        return password;
    }

    public List<Chatroom> getListRoom() {
        return listRoom;
    }

    public List<Chatroom> getListRoomUserVisited() {
        return listRoomUserVisited;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", login='" + login + '\'' +
                ", password='" + password + '\'' +
                ", listRoom=" + listRoom +
                ", listRoomUserVisited=" + listRoomUserVisited +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return Objects.equals(id, user.id) && Objects.equals(login, user.login) && Objects.equals(password, user.password) && Objects.equals(listRoom, user.listRoom) && Objects.equals(listRoomUserVisited, user.listRoomUserVisited);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, login, password, listRoom, listRoomUserVisited);
    }
}