<?php
    $conn = mysqli_connect('localhost', 'root', '', 'ajmal');
    if (!$conn) {
        die("Database connection failed: " . mysqli_connect_error());
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Login - EB Bill System</title>
    <link rel="stylesheet" href="../../styles/main.css">
    <style>
        body { display: flex; align-items: center; justify-content: center; background: linear-gradient(135deg, #2563eb 0%, #1e40af 100%); }
        .login-card { background: var(--glass-bg); backdrop-filter: blur(10px); padding: 3rem; border-radius: var(--border-radius); box-shadow: 0 20px 25px -5px rgba(0,0,0,0.3); width: 100%; max-width: 400px; border: 1px solid var(--glass-border); }
        .form-group { margin-bottom: 1.5rem; }
        label { color: var(--primary-dark); font-weight: 600; font-size: 0.9rem; }
        input[type="text"], input[type="password"] { 
            width: 100%; padding: 0.8rem; border-radius: 8px; border: 1px solid #cbd5e1; margin-top: 0.5rem; 
        }
    </style>
</head>
<body class="fade-in">
    <div class="login-card">
        <h2 style="text-align: center; margin-bottom: 2rem;">EB Admin Portal</h2>
        
        <?php
        if($_SERVER["REQUEST_METHOD"] == "POST"){
            $username = mysqli_real_escape_string($conn, $_POST["username"]);
            $pass = mysqli_real_escape_string($conn, $_POST["password"]);

            $query = "SELECT * FROM admin WHERE username='$username' and password='$pass'";
            $result = mysqli_query($conn, $query);

            if($result && mysqli_num_rows($result) == 1){
                echo "<script>window.location.href='dashboard.php'</script>";
                exit;
            } else {
                echo "<p style='color: #ef4444; text-align: center; margin-bottom: 1rem; font-weight: 600;'>Invalid credentials.</p>";
            }
        }
        ?>

        <form method="post">
            <div class="form-group">
                <label for="username">Username</label>
                <input type="text" name="username" id="username" placeholder="Enter admin username" required>
            </div>
            <div class="form-group">
                <label for="password">Password</label>
                <input type="password" name="password" id="password" placeholder="••••••••" required>
            </div>
            <button type="submit" class="btn" style="width: 100%; border: none; cursor: pointer;">Sign In</button>
        </form>
    </div>
</body>
</html>
