package edu.school21.chat.models;

import java.util.List;
import java.util.Objects;

public class Chatroom {
    private Long idRoom;
    private String nameRoom;
    private User owner;
    private List<Message> listMessages;

    public Chatroom(Long idRoom, String nameRoom, User owner, List<Message> listMessages) {
        this.idRoom = idRoom;
        this.nameRoom = nameRoom;
        this.owner = owner;
        this.listMessages = listMessages;
    }

    public void setIdRoom(Long idRoom) {
        this.idRoom = idRoom;
    }

    public void setNameRoom(String nameRoom) {
        this.nameRoom = nameRoom;
    }

    public void setOwner(User owner) {
        this.owner = owner;
    }

    public void setListMessages(List<Message> listMessages) {
        this.listMessages = listMessages;
    }

    public Long getIdRoom() {
        return idRoom;
    }

    public String getNameRoom() {
        return nameRoom;
    }

    public User getOwner() {
        return owner;
    }

    public List<Message> getListMessages() {
        return listMessages;
    }

    @Override
    public String toString() {
        return "Chatroom{" +
                "idRoom=" + idRoom +
                ", nameRoom='" + nameRoom + '\'' +
                ", owner=" + owner +
                ", listMessages=" + listMessages +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Chatroom chatroom = (Chatroom) o;
        return Objects.equals(idRoom, chatroom.idRoom) && Objects.equals(nameRoom, chatroom.nameRoom) && Objects.equals(owner, chatroom.owner) && Objects.equals(listMessages, chatroom.listMessages);
    }

    @Override
    public int hashCode() {
        return Objects.hash(idRoom, nameRoom, owner, listMessages);
    }
}
