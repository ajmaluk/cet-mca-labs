import java.util.Scanner;
import java.util.regex.Pattern;

class ExecptionHandlingAuth {
    private String username, password;

    // Signup method
    void signup() {
        Scanner s = new Scanner(System.in);
        System.out.println("SIGNUP: Enter new username:");
        String newUsername = s.nextLine();
        System.out.println("Enter new password:");
        String newPassword = s.nextLine();
        try {
            validate(newUsername, newPassword);
            this.username = newUsername;
            this.password = newPassword;
            System.out.println("Signup successful!");
        } catch (ValidationException e) {
            System.out.println("Signup failed: " + e.getMessage());
        }
    }

    // Login method
    void login() {
        Scanner s = new Scanner(System.in);
        System.out.println("LOGIN: Enter your username:");
        String inputUsername = s.nextLine();
        System.out.println("Enter your password:");
        String inputPassword = s.nextLine();
        try {
            if (this.username == null || this.password == null) {
                throw new AuthenticationException("No user registered. Please signup first.");
            }
            if (this.username.equals(inputUsername) && this.password.equals(inputPassword)) {
                System.out.println("Login successful!");
            } else {
                throw new AuthenticationException("Invalid username or password");
            }
        } catch (AuthenticationException e) {
            System.out.println("Login failed: " + e.getMessage());
        }
    }

    // Validate username and password patterns
    void validate(String username, String password) throws ValidationException {
        // Username: at least 4 chars, only letters and digits
        if (!Pattern.matches("[a-zA-Z0-9]{4,}", username)) {
            throw new ValidationException("Username must be at least 4 characters and contain only letters and digits.");
        }
        // Password: at least 6 chars, at least one digit, one letter
        if (!Pattern.matches("(?=.*[a-zA-Z])(?=.*\\d).{6,}", password)) {
            throw new ValidationException("Password must be at least 6 characters, with at least one letter and one digit.");
        }
    }
}

// Custom exception for authentication failure
class AuthenticationException extends Exception {
    public AuthenticationException(String message) {
        super(message);
    }
}

// Custom exception for validation failure
class ValidationException extends Exception {
    public ValidationException(String message) {
        super(message);
    }
}