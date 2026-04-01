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
    <title>Bill Entry - EB System</title>
    <link rel="stylesheet" href="../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .form-card { max-width: 500px; margin: 0 auto; background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .form-group { margin-bottom: 1.25rem; }
        label { display: block; margin-bottom: 0.5rem; font-weight: 600; }
        select, input[type="number"] { width: 100%; padding: 0.75rem; border: 1px solid #cbd5e1; border-radius: 8px; }
    </style>
</head>
<body class="fade-in">
    <div class="form-card">
        <h2 style="text-align: center; margin-bottom: 1.5rem;">Add New Bill</h2>
        
        <form method="post">
            <div class="form-group">
                <label>Select Consumer</label>
                <select name="consumer_id" required>
                    <option value="" disabled selected>Choose a consumer...</option>
                    <?php 
                        $query = "SELECT * FROM consumer";
                        $result = mysqli_query($conn, $query);
                        while ($row = mysqli_fetch_assoc($result)) {
                            echo "<option value='".$row['consumer_id']."'>".$row['consumer_name']." (".$row['consumer_id'].")</option>";
                        }
                    ?>
                </select>
            </div>
            
            <div class="form-group">
                <label>Billing Month</label>
                <select name="month" required>
                    <option value="" disabled selected>Select month...</option>
                    <?php
                        $months = ['January','February','March','April','May','June','July','August','September','October','November','December'];
                        foreach($months as $m) echo "<option value='$m'>$m</option>";
                    ?>
                </select>
            </div>

            <div class="form-group">
                <label>Total Units</label>
                <input type="number" name="unit" placeholder="e.g. 150" required>
            </div>

            <div class="form-group">
                <label>Bill Amount (₹)</label>
                <input type="number" name="amount" placeholder="e.g. 750" required>
            </div>

            <button type="submit" class="btn" style="width: 100%; border: none; cursor: pointer;">Add Bill Record</button>
        </form>

        <?php 
            if($_SERVER['REQUEST_METHOD'] == "POST"){
                $cid = mysqli_real_escape_string($conn, $_POST['consumer_id']);
                $mon = mysqli_real_escape_string($conn, $_POST['month']);
                $amt = mysqli_real_escape_string($conn, $_POST['amount']);
                $unt = mysqli_real_escape_string($conn, $_POST['unit']);
                
                $query = "INSERT INTO bill (consumer_id, month, amount, unit) VALUES ('$cid', '$mon', '$amt', '$unt')";
                if(mysqli_query($conn, $query)){
                    echo "<p style='color: #22c55e; text-align: center; margin-top: 1rem; font-weight: 600;'>Bill added successfully!</p>";
                }
            }
        ?>
    </div>
</body>
</html>