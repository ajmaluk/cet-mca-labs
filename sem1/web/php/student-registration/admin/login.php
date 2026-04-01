<?php
    session_start();
    if (isset($_SESSION['admin_logged_in']) && $_SESSION['admin_logged_in'] === true) {
        header("Location: dashboard.php");
        exit;
    }

    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("Connection failed"); }

    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $email = mysqli_real_escape_string($conn, $_POST['email-admin']);
        $password = mysqli_real_escape_string($conn, $_POST['password-admin']);
        $sql = "SELECT * FROM admin WHERE email = '$email' AND password = '$password'";
        $result = mysqli_query($conn, $sql);

        if ($result && mysqli_num_rows($result) === 1) {
            $_SESSION['admin_logged_in'] = true;
            $_SESSION['admin_email'] = $email;
            header("Location: dashboard.php");
            exit;
        } else {
            $error = "Invalid admin credentials.";
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Login - Student System</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { display: flex; align-items: center; justify-content: center; background: #0f172a; }
        .login-box { background: var(--glass-bg); backdrop-filter: blur(12px); border: 1px solid var(--glass-border); padding: 3rem; border-radius: var(--border-radius); box-shadow: 0 25px 50px -12px rgba(0,0,0,0.5); width: 100%; max-width: 420px; }
        input { width: 100%; padding: 0.8rem; border-radius: 8px; border: 1px solid #334155; background: rgba(255,255,255,0.05); color: white; margin-top: 0.5rem; }
        input:focus { border-color: var(--primary-color); outline: none; }
        label { color: #94a3b8; font-weight: 600; font-size: 0.875rem; }
    </style>
</head>
<body class="fade-in">
    <div class="login-box">
        <h1 style="color: white; text-align: center; margin-bottom: 2rem; font-size: 1.75rem;">Admin Access</h1>
        
        <?php if(isset($error)): ?>
            <p style="color: #ef4444; background: rgba(239, 68, 68, 0.1); padding: 0.75rem; border-radius: 6px; text-align: center; margin-bottom: 1.5rem;"><?php echo $error; ?></p>
        <?php endif; ?>

        <form method="POST">
            <div style="margin-bottom: 1.5rem;">
                <label>Administrator Email</label>
                <input type="email" name="email-admin" placeholder="admin@example.com" required>
            </div>
            <div style="margin-bottom: 2rem;">
                <label>Secure Password</label>
                <input type="password" name="password-admin" placeholder="••••••••" required>
            </div>
            <button type="submit" class="btn" style="width: 100%; border: none; cursor: pointer;">Login to Dashboard</button>
        </form>
    </div>
</body>
</html>
