<?php
    session_start();
    if (!isset($_SESSION['user_logged_in']) || $_SESSION['user_logged_in'] !== true) {
        header("Location: login.php");
        exit;
    }

    $email = $_SESSION['user_email'];
    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("System Connection Failure"); }

    $sql = "SELECT name, rollno, gender FROM student WHERE email = '{$email}'";
    $result = mysqli_query($conn, $sql);
    $data = mysqli_fetch_assoc($result);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Profile</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 3rem; background: transparent; }
        .profile-card { max-width: 500px; margin: 0 auto; background: white; border-radius: var(--border-radius); box-shadow: var(--shadow); overflow: hidden; }
        .profile-header { background: var(--primary-color); padding: 3rem 2rem; text-align: center; color: white; }
        .avatar { width: 100px; height: 100px; background: rgba(255,255,255,0.2); backdrop-filter: blur(5px); border-radius: 50%; margin: 0 auto 1.5rem; display: flex; align-items: center; justify-content: center; font-size: 2.5rem; font-weight: 800; border: 2px solid white; }
        .profile-body { padding: 2.5rem; }
        .info-group { margin-bottom: 1.5rem; border-bottom: 1px solid #f1f5f9; padding-bottom: 0.75rem; display: flex; justify-content: space-between; }
        .info-label { font-weight: 700; color: #64748b; font-size: 0.875rem; text-transform: uppercase; letter-spacing: 0.5px; }
        .info-value { font-weight: 600; color: var(--text-color); }
    </style>
</head>
<body class="fade-in">
    <div class="profile-card">
        <div class="profile-header">
            <div class="avatar"><?php echo substr($data['name'], 0, 1); ?></div>
            <h2 style="margin: 0;"><?php echo htmlspecialchars($data['name']); ?></h2>
            <p style="opacity: 0.8; margin-top: 0.5rem;">Student User</p>
        </div>
        <div class="profile-body">
            <div class="info-group">
                <span class="info-label">Roll Number</span>
                <span class="info-value">#<?php echo $data['rollno']; ?></span>
            </div>
            <div class="info-group">
                <span class="info-label">Institutional Email</span>
                <span class="info-value"><?php echo htmlspecialchars($email); ?></span>
            </div>
            <div class="info-group">
                <span class="info-label">Gender</span>
                <span class="info-value"><?php echo $data['gender']; ?></span>
            </div>
            
            <a href="change_password.php" class="btn" style="display: block; text-align: center; text-decoration: none; margin-top: 2rem; border: none;">Manage Password</a>
        </div>
    </div>
</body>
</html>
