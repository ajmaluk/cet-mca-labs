<?php
    session_start();
    if (isset($_SESSION['user_logged_in']) && $_SESSION['user_logged_in'] === true) {
        header("Location: dashboard.php");
        exit;
    }

    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("DB Error"); }

    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $email = mysqli_real_escape_string($conn, $_POST['email']);
        $password = mysqli_real_escape_string($conn, $_POST['password']);
        $sql = "SELECT * FROM student WHERE email = '$email' AND password = '$password'";
        $result = mysqli_query($conn, $sql);

        if ($result && mysqli_num_rows($result) === 1) {
            $_SESSION['user_logged_in'] = true;
            $_SESSION['user_email'] = $email;
            header("Location: dashboard.php");
            exit;
        } else {
            $error = "Invalid student credentials.";
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Login</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { display: flex; align-items: center; justify-content: center; background: #f1f5f9; }
        .login-container { background: white; padding: 3rem; border-radius: var(--border-radius); box-shadow: var(--shadow); width: 100%; max-width: 400px; }
        input { width: 100%; padding: 0.8rem; border-radius: 8px; border: 1px solid #cbd5e1; margin-top: 0.5rem; }
        label { color: #64748b; font-weight: 600; font-size: 0.875rem; }
    </style>
</head>
<body class="fade-in">
    <div class="login-container">
        <h1 style="text-align: center; margin-bottom: 2rem; color: var(--primary-color);">Student Login</h1>
        
        <?php if(isset($error)): ?>
            <p style="color: #ef4444; text-align: center; margin-bottom: 1.5rem;"><?php echo $error; ?></p>
        <?php endif; ?>

        <form method="POST">
            <div style="margin-bottom: 1.5rem;">
                <label>Student Email</label>
                <input type="email" name="email" placeholder="student@example.com" required>
            </div>
            <div style="margin-bottom: 2rem;">
                <label>Password</label>
                <input type="password" name="password" placeholder="••••••••" required>
            </div>
            <button type="submit" class="btn" style="width: 100%; border: none; cursor: pointer;">Sign In</button>
        </form>
    </div>
</body>
</html>
