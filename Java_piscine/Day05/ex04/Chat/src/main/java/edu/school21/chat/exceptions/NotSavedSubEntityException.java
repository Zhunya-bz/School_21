package edu.school21.chat.exceptions;

public class NotSavedSubEntityException extends RuntimeException {
    public NotSavedSubEntityException() {
        super("Cannot save the message");
    }

}
