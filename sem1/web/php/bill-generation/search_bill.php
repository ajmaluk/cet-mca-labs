<?php
    $conn = mysqli_connect('localhost', 'root', '', 'ajmal');
    if (!$conn) {
        die("Database connection failed");
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Bills - EB System</title>
    <link rel="stylesheet" href="../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .search-card { max-width: 600px; margin: 0 auto; background: white; padding: 2rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .search-box { display: grid; grid-template-columns: 1fr 1fr auto; gap: 10px; margin-top: 1rem; }
        input, select { padding: 0.6rem; border: 1px solid #cbd5e1; border-radius: 8px; }
        .result-area { margin-top: 2rem; padding: 1.5rem; border-radius: 8px; background: #f8fafc; display: none; }
        .data-row { display: flex; justify-content: space-between; padding: 0.5rem 0; border-bottom: 1px solid #e2e8f0; }
        .data-label { font-weight: 600; color: var(--primary-dark); }
    </style>
</head>
<body class="fade-in">
    <div class="search-card">
        <h2>Quick Search</h2>
        <form method="post" class="search-box">
            <input type="number" name="consumer_id" placeholder="ID (e.g. 101)" required>
            <select name="month" required>
                <?php
                    $months = ['January','February','March','April','May','June','July','August','September','October','November','December'];
                    foreach($months as $m) echo "<option value='$m'>$m</option>";
                ?>
            </select>
            <button type="submit" class="btn" style="border: none; cursor: pointer; padding: 0.6rem 1.5rem;">Find</button>
        </form>

        <?php
        if ($_SERVER['REQUEST_METHOD'] == "POST") {
            $cid = mysqli_real_escape_string($conn, $_POST['consumer_id']);
            $mon = mysqli_real_escape_string($conn, $_POST['month']);

            $query = "SELECT b.*, c.consumer_name FROM bill b JOIN consumer c ON b.consumer_id = c.consumer_id WHERE b.consumer_id='$cid' AND b.month='$mon'";
            $res = mysqli_query($conn, $query);

            if ($res && mysqli_num_rows($res) > 0) {
                $data = mysqli_fetch_assoc($res);
                echo "<div class='result-area' style='display: block;'>";
                echo "<h3>Record Found</h3>";
                echo "<div class='data-row'><span class='data-label'>Name:</span><span>".$data['consumer_name']."</span></div>";
                echo "<div class='data-row'><span class='data-label'>ID:</span><span>$cid</span></div>";
                echo "<div class='data-row'><span class='data-label'>Amount:</span><span>₹".$data['amount']."</span></div>";
                echo "<div class='data-row'><span class='data-label'>Units:</span><span>".$data['unit']." units</span></div>";
                echo "</div>";
            } else {
                echo "<p style='color: #ef4444; margin-top: 1.5rem; font-weight: 600; text-align: center;'>No billing record found for this period.</p>";
            }
        }
        ?>
    </div>
</body>
</html>