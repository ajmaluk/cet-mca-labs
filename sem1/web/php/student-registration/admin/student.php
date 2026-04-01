<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("Connection failed"); }

    $sql = "SELECT * FROM student ORDER BY rollno ASC";
    $result = mysqli_query($conn, $sql);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Roster</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .table-card { background: white; padding: 2rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        h2 { color: var(--primary-color); margin-bottom: 0.5rem; }
        .status-badge { padding: 4px 12px; border-radius: 20px; font-size: 0.75rem; font-weight: 700; text-transform: uppercase; }
        .badge-male { background: #dbeafe; color: #1e40af; }
        .badge-female { background: #fce7f3; color: #9d174d; }
    </style>
</head>
<body class="fade-in">
    <div class="table-card">
        <h2>Student Management</h2>
        <p style="color: var(--text-muted); margin-bottom: 2rem;">Overview of all registered students in the system.</p>

        <?php if (mysqli_num_rows($result) > 0): ?>
            <table>
                <thead>
                    <tr>
                        <th>Roll No</th>
                        <th>Full Name</th>
                        <th>Gender</th>
                        <th>Email Address</th>
                    </tr>
                </thead>
                <tbody>
                    <?php while ($row = mysqli_fetch_assoc($result)): ?>
                        <tr>
                            <td style="font-weight: 700; color: var(--primary-color);">#<?php echo $row['rollno']; ?></td>
                            <td style="font-weight: 600;"><?php echo htmlspecialchars($row['name']); ?></td>
                            <td>
                                <span class="status-badge badge-<?php echo strtolower($row['gender']); ?>">
                                    <?php echo $row['gender']; ?>
                                </span>
                            </td>
                            <td style="color: var(--text-muted); font-family: monospace;"><?php echo htmlspecialchars($row['email']); ?></td>
                        </tr>
                    <?php endwhile; ?>
                </tbody>
            </table>
        <?php else: ?>
            <div style="text-align: center; padding: 3rem; color: #94a3b8;">
                <p style="font-size: 1.25rem; font-weight: 600;">No students found.</p>
                <p>Start by adding a new student record.</p>
            </div>
        <?php endif; ?>
    </div>
</body>
</html>