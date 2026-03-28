import java.util.Scanner;

// Custom exception for invalid credentials
class InvalidCredentialsException extends Exception {
	public InvalidCredentialsException(String message) {
		super(message);
	}
}

public class UserException {
	// Method to validate username and password
	public static void validate(String username, String password) throws InvalidCredentialsException {
		if (username == null || username.length() < 4) {
			throw new InvalidCredentialsException("Username must be at least 4 characters long.");
		}
		if (password == null || password.length() < 6) {
			throw new InvalidCredentialsException("Password must be at least 6 characters long.");
		}
		// Add more validation as needed
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter username: ");
		String username = sc.nextLine();
		System.out.print("Enter password: ");
		String password = sc.nextLine();
		try {
			validate(username, password);
			System.out.println("Login successful!");
		} catch (InvalidCredentialsException e) {
			System.out.println("Login failed: " + e.getMessage());
		}
		sc.close();
	}
}
