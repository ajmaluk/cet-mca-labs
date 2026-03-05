<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("Connection failed"); }

    $message = "";
    $msg_type = "";
    $student = null;

    // Fetch all existing roll numbers for dropdown
    $rollnos = [];
    $q = mysqli_query($conn, "SELECT rollno, name FROM student ORDER BY rollno ASC");
    while ($row = mysqli_fetch_assoc($q)) { $rollnos[] = $row; }

    // Load student data
    if (isset($_POST['load_student'])) {
        $rollno = (int)$_POST['rollno_select'];
        $query = mysqli_query($conn, "SELECT * FROM student WHERE rollno = $rollno");
        if (mysqli_num_rows($query) > 0) { $student = mysqli_fetch_assoc($query); }
        else { $message = "Student record not found."; $msg_type = "error"; }
    }

    // Save student data
    if (isset($_POST['save_student'])) {
        $rollno = (int)$_POST['rollno'];
        $name = mysqli_real_escape_string($conn, $_POST['name']);
        $gender = mysqli_real_escape_string($conn, $_POST['gender']);
        $email = mysqli_real_escape_string($conn, $_POST['email']);
        $password = mysqli_real_escape_string($conn, $_POST['password']);

        $sql = "UPDATE student SET name='$name', gender='$gender', email='$email', password='$password' WHERE rollno = $rollno";
        if (mysqli_query($conn, $sql)) { $message = "Record updated successfully!"; $msg_type = "success"; }
        else { $message = "Error: " . mysqli_error($conn); $msg_type = "error"; }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Student</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .edit-card { max-width: 600px; margin: 0 auto; background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .alert { padding: 1rem; border-radius: 8px; margin-bottom: 2rem; text-align: center; font-weight: 600; animation: fadeIn 0.3s; }
        .alert-success { background: #dcfce7; color: #166534; }
        .alert-error { background: #fee2e2; color: #991b1b; }
        .load-row { display: grid; grid-template-columns: 1fr auto; gap: 10px; align-items: end; margin-bottom: 2rem; padding-bottom: 2rem; border-bottom: 1px dashed #e2e8f0; }
        input, select { width: 100%; padding: 0.75rem; border: 1px solid #cbd5e1; border-radius: 8px; margin-top: 0.5rem; }
        .form-group { margin-bottom: 1.5rem; }
    </style>
</head>
<body class="fade-in">
    <div class="edit-card">
        <h2 style="margin-bottom: 1.5rem;">Modify Student Record</h2>

        <?php if($message): ?>
            <div class="alert alert-<?php echo $msg_type; ?>"><?php echo $message; ?></div>
        <?php endif; ?>

        <form method="POST" class="load-row">
            <div>
                <label style="font-weight: 600; font-size: 0.875rem;">Select Student to Edit</label>
                <select name="rollno_select" required>
                    <option value="" disabled selected>Choose student...</option>
                    <?php foreach ($rollnos as $r) echo "<option value='".$r['rollno']."'>#".$r['rollno']." - ".$r['name']."</option>"; ?>
                </select>
            </div>
            <button type="submit" name="load_student" class="btn" style="border: none; cursor: pointer;">Load Profile</button>
        </form>

        <?php if ($student): ?>
            <form method="POST">
                <input type="hidden" name="rollno" value="<?php echo $student['rollno']; ?>">
                
                <div class="form-group">
                    <label style="font-weight: 600;">Full Name</label>
                    <input type="text" name="name" value="<?php echo htmlspecialchars($student['name']); ?>" required>
                </div>

                <div class="form-group">
                    <label style="font-weight: 600;">Gender</label>
                    <div style="display: flex; gap: 2rem; padding: 0.5rem 0;">
                        <label style="font-weight: 400;"><input type="radio" name="gender" value="male" <?php echo ($student['gender']=='male'?'checked':''); ?>> Male</label>
                        <label style="font-weight: 400;"><input type="radio" name="gender" value="female" <?php echo ($student['gender']=='female'?'checked':''); ?>> Female</label>
                    </div>
                </div>

                <div class="form-group">
                    <label style="font-weight: 600;">Email Address</label>
                    <input type="email" name="email" value="<?php echo htmlspecialchars($student['email']); ?>" required>
                </div>

                <div class="form-group">
                    <label style="font-weight: 600;">System Password</label>
                    <input type="text" name="password" value="<?php echo htmlspecialchars($student['password']); ?>" required>
                </div>

                <button type="submit" name="save_student" class="btn" style="width: 100%; margin-top: 1.5rem; border: none; cursor: pointer;">Update Student Record</button>
            </form>
        <?php endif; ?>
    </div>
</body>
</html>
