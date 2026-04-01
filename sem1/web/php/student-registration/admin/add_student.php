<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("DB Error"); }

    $message = '';
    $msg_type = ''; // success or error

    // Fetch existing roll numbers to disable them in dropdown
    $existing_rollnos = [];
    $roll_query = mysqli_query($conn, "SELECT rollno FROM student");
    while ($row = mysqli_fetch_assoc($roll_query)) { $existing_rollnos[] = (int)$row['rollno']; }

    if ($_SERVER["REQUEST_METHOD"] === "POST") {
        $name = mysqli_real_escape_string($conn, $_POST['name']);
        $rollno = (int)$_POST['rollno'];
        $gender = mysqli_real_escape_string($conn, $_POST['gender']);
        $email = mysqli_real_escape_string($conn, $_POST['email']);
        $password = mysqli_real_escape_string($conn, $_POST['password']);

        $check = mysqli_query($conn, "SELECT email FROM student WHERE email = '$email' OR rollno = $rollno");
        if (mysqli_num_rows($check) > 0) {
            $message = "Conflict: Email or Roll Number already in use.";
            $msg_type = 'error';
        } else {
            $sql = "INSERT INTO student (name, rollno, gender, email, password) VALUES ('$name', $rollno, '$gender', '$email', '$password')";
            if (mysqli_query($conn, $sql)) {
                $message = "Student successfully onboarded!";
                $msg_type = 'success';
                $existing_rollnos[] = $rollno; // Update local list
            } else {
                $message = "System Error: Unable to save record.";
                $msg_type = 'error';
            }
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Student</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .form-card { max-width: 600px; margin: 0 auto; background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .form-group { margin-bottom: 1.5rem; }
        label { display: block; margin-bottom: 0.5rem; font-weight: 600; font-size: 0.9rem; }
        input[type="text"], input[type="email"], input[type="password"], select { 
            width: 100%; padding: 0.75rem; border: 1px solid #cbd5e1; border-radius: 8px; transition: border-color 0.2s;
        }
        .radio-group { display: flex; gap: 1.5rem; padding: 0.5rem 0; }
        .alert { padding: 1rem; border-radius: 8px; margin-bottom: 1.5rem; text-align: center; font-weight: 600; }
        .alert-success { background: #dcfce7; color: #166534; }
        .alert-error { background: #fee2e2; color: #991b1b; }
    </style>
</head>
<body class="fade-in">
    <div class="form-card">
        <h2 style="text-align: center; margin-bottom: 2rem;">Student Enrollment</h2>

        <?php if($message): ?>
            <div class="alert alert-<?php echo $msg_type; ?>"><?php echo $message; ?></div>
        <?php endif; ?>

        <form method="POST">
            <div class="form-group">
                <label>Full Name</label>
                <input type="text" name="name" placeholder="John Doe" required>
            </div>

            <div style="display: grid; grid-template-columns: 1fr 1fr; gap: 1.5rem;">
                <div class="form-group">
                    <label>Roll Number</label>
                    <select name="rollno" required>
                        <option value="" disabled selected>Available IDs...</option>
                        <?php for ($i = 1; $i <= 60; $i++) if (!in_array($i, $existing_rollnos)) echo "<option value='$i'>$i</option>"; ?>
                    </select>
                </div>
                <div class="form-group">
                    <label>Gender Selection</label>
                    <div class="radio-group">
                        <label style="font-weight: 400;"><input type="radio" name="gender" value="male" required> Male</label>
                        <label style="font-weight: 400;"><input type="radio" name="gender" value="female"> Female</label>
                    </div>
                </div>
            </div>

            <div class="form-group">
                <label>Institutional Email</label>
                <input type="email" name="email" placeholder="student@university.edu" required>
            </div>

            <div class="form-group">
                <label>Temporary Password</label>
                <input type="password" name="password" placeholder="Min 8 characters" required>
            </div>

            <button type="submit" class="btn" style="width: 100%; margin-top: 1rem; border: none; cursor: pointer;">Register Student</button>
        </form>
    </div>
</body>
</html>
