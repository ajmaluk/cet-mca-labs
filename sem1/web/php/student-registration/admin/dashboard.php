<?php
session_start();
if (!isset($_SESSION['admin_logged_in']) || $_SESSION['admin_logged_in'] !== true) {
    header("Location: login.php");
    exit;
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Dashboard</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { margin: 0; padding: 0; display: flex; height: 100vh; overflow: hidden; }
        .sidebar { width: 280px; background: #1e293b; color: white; display: flex; flex-direction: column; padding: 2rem 0; }
        .sidebar h2 { padding: 0 2rem; margin-bottom: 2.5rem; font-size: 1.5rem; }
        .nav-list { list-style: none; padding: 0; flex-grow: 1; }
        .nav-link { 
            display: block; padding: 1rem 2rem; color: #94a3b8; text-decoration: none; font-weight: 600; transition: all 0.2s; border-left: 4px solid transparent;
        }
        .nav-link:hover { background: #334155; color: white; border-left-color: var(--primary-color); }
        .logout-btn { background: #ef4444; color: white; text-decoration: none; padding: 0.8rem 2rem; font-weight: 700; margin: 0 1rem; border-radius: 8px; text-align: center; }
        
        .main-frame { flex-grow: 1; border: none; background: #f8fafc; }
    </style>
</head>
<body>
    <div class="sidebar">
        <h2>Admin Panel</h2>
        <ul class="nav-list">
            <li><a href="student.php" target="contentFrame" class="nav-link">Student Roster</a></li>
            <li><a href="add_student.php" target="contentFrame" class="nav-link">Add New Student</a></li>
            <li><a href="edit_student.php" target="contentFrame" class="nav-link">Modify Records</a></li>
            <li><a href="mark_add.php" target="contentFrame" class="nav-link">Grade Management</a></li>
            <li><a href="top_students.php" target="contentFrame" class="nav-link">Performance Analytics</a></li>
        </ul>
        <a href="logout.php" class="logout-btn">Log Out</a>
    </div>
    <iframe name="contentFrame" src="student.php" class="main-frame"></iframe>
</body>
</html>
