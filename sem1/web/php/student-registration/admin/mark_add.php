<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("DB Connection failed"); }

    $msg = '';
    $type = '';

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $rollno = mysqli_real_escape_string($conn, $_POST['rollno']);
        $m1 = (int)$_POST['mark1'];
        $m2 = (int)$_POST['mark2'];
        $m3 = (int)$_POST['mark3'];

        $check = mysqli_query($conn, "SELECT * FROM mark WHERE rollno = '$rollno'");
        if (mysqli_num_rows($check) > 0) {
            $sql = "UPDATE mark SET mark1 = $m1, mark2 = $m2, mark3 = $m3 WHERE rollno = '$rollno'";
            $msg = "Academic marks updated successfully!";
        } else {
            $sql = "INSERT INTO mark (rollno, mark1, mark2, mark3) VALUES ('$rollno', $m1, $m2, $m3)";
            $msg = "New marks recorded for student #$rollno";
        }
        
        if (mysqli_query($conn, $sql)) { $type = 'success'; }
        else { $msg = "Error: " . mysqli_error($conn); $type = 'error'; }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Manage Marks</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .mark-form-card { max-width: 500px; margin: 0 auto; background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .form-group { margin-bottom: 1.25rem; }
        label { display: block; margin-bottom: 0.5rem; font-weight: 700; color: var(--text-color); font-size: 0.875rem; }
        input[type="number"], select { width: 100%; padding: 0.75rem; border: 1px solid #cbd5e1; border-radius: 8px; }
        .alert { padding: 1rem; border-radius: 8px; margin-bottom: 1.5rem; text-align: center; font-weight: 600; }
        .alert-success { background: #dcfce7; color: #166534; }
        .alert-error { background: #fee2e2; color: #991b1b; }
    </style>
</head>
<body class="fade-in">
    <div class="mark-form-card">
        <h2 style="margin-bottom: 1.5rem;">Grade Management</h2>
        
        <?php if($msg): ?>
            <div class="alert alert-<?php echo $type; ?>"><?php echo $msg; ?></div>
        <?php endif; ?>

        <form method="POST">
            <div class="form-group">
                <label>Target Student</label>
                <select name="rollno" required>
                    <option value="" disabled selected>Identify student...</option>
                    <?php
                        $res = mysqli_query($conn, "SELECT rollno, name FROM student");
                        while ($row = mysqli_fetch_assoc($res)) {
                            echo "<option value='".$row['rollno']."'>#".$row['rollno']." - ".$row['name']."</option>";
                        }
                    ?>
                </select>
            </div>

            <div style="display: grid; grid-template-columns: repeat(3, 1fr); gap: 1rem;">
                <div class="form-group">
                    <label>Theory</label>
                    <input type="number" name="mark1" min="0" max="100" placeholder="0-100" required>
                </div>
                <div class="form-group">
                    <label>Practical</label>
                    <input type="number" name="mark2" min="0" max="100" placeholder="0-100" required>
                </div>
                <div class="form-group">
                    <label>Internal</label>
                    <input type="number" name="mark3" min="0" max="100" placeholder="0-100" required>
                </div>
            </div>

            <button type="submit" class="btn" style="width: 100%; margin-top: 1rem; border: none; cursor: pointer;">Commit Grades</button>
        </form>
    </div>
</body>
</html>