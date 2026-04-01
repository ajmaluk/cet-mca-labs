<?php
    $conn = mysqli_connect('localhost', 'root', '', 'ajmal');
    if (!$conn) {
        die("Connection Failed");
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Consumer Registration - EB System</title>
    <link rel="stylesheet" href="../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .reg-card { max-width: 500px; margin: 0 auto; background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .form-group { margin-bottom: 1.25rem; }
        label { display: block; margin-bottom: 0.5rem; font-weight: 600; }
        input { width: 100%; padding: 0.75rem; border: 1px solid #cbd5e1; border-radius: 8px; }
    </style>
</head>
<body class="fade-in">
    <div class="reg-card">
        <h2 style="text-align: center; margin-bottom: 1.5rem;">New Consumer</h2>
        
        <?php
        if($_SERVER['REQUEST_METHOD'] == "POST"){
            $cid = mysqli_real_escape_string($conn, $_POST['consumer_id']);
            $name = mysqli_real_escape_string($conn, $_POST['consumer_name']);
            $addr = mysqli_real_escape_string($conn, $_POST['adress']);
            $phone = mysqli_real_escape_string($conn, $_POST['phone_no']);

            $check = mysqli_query($conn, "SELECT * FROM consumer WHERE consumer_id='$cid'");
            if(mysqli_num_rows($check) > 0){
                echo "<p style='color: #ef4444; font-weight:600; text-align:center;'>Consumer ID already exists.</p>";
            } else {
                $query = "INSERT INTO consumer (consumer_id, consumer_name, adress, phone_no) VALUES ('$cid', '$name', '$addr', '$phone')";
                if(mysqli_query($conn, $query)){
                    echo "<p style='color: #22c55e; font-weight:600; text-align:center;'>Consumer registered successfully!</p>";
                }
            }
        }
        ?>

        <form method="post">
            <div class="form-group">
                <label>Consumer Number</label>
                <input type="number" name="consumer_id" placeholder="e.g. 101" required>
            </div>
            <div class="form-group">
                <label>Full Name</label>
                <input type="text" name="consumer_name" placeholder="John Doe" required>
            </div>
            <div class="form-group">
                <label>Mobile Number</label>
                <input type="text" name="phone_no" placeholder="10-digit number" required>
            </div>
            <div class="form-group">
                <label>Address</label>
                <input type="text" name="adress" placeholder="House name, City" required>
            </div>
            <button type="submit" class="btn" style="width: 100%; border: none; cursor: pointer;">Register Consumer</button>
        </form>
    </div>
</body>
</html>
