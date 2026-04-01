<?php 
    session_start();
    if (!isset($_SESSION['user_logged_in']) || $_SESSION['user_logged_in'] !== true) {
        header("Location: login.php");
        exit;
    }

    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("Connection Failure"); }

    $email = mysqli_real_escape_string($conn, $_SESSION['user_email']);
    $query = "SELECT m.* FROM mark m JOIN student s ON m.rollno = s.rollno WHERE s.email = '$email'";
    $result = mysqli_query($conn, $query);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Grades</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 3rem; background: transparent; }
        .mark-card { max-width: 600px; margin: 0 auto; background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .score-row { display: flex; align-items: center; margin-bottom: 2rem; gap: 1.5rem; }
        .score-circle { width: 60px; height: 60px; border-radius: 50%; background: #f1f5f9; display: flex; align-items: center; justify-content: center; font-weight: 800; font-size: 1.25rem; color: var(--primary-color); border: 2px solid #e2e8f0; }
        .score-label { flex-grow: 1; }
        .score-label h3 { margin: 0; font-size: 1rem; color: #64748b; text-transform: uppercase; letter-spacing: 1px; }
        .score-bar { height: 8px; background: #f1f5f9; border-radius: 4px; margin-top: 8px; overflow: hidden; }
        .score-fill { height: 100%; background: var(--primary-color); border-radius: 4px; transition: width 1s ease-out; }
        .total-box { background: #eff6ff; padding: 1.5rem; border-radius: 12px; border: 1px dashed #3b82f6; text-align: center; }
    </style>
</head>
<body class="fade-in">
    <div class="mark-card">
        <h2 style="margin-bottom: 2.5rem;">Academic Performance</h2>

        <?php if ($result && mysqli_num_rows($result) > 0): 
            $row = mysqli_fetch_assoc($result);
            $scores = [
                "Subject Theory" => $row['mark1'],
                "Practical Lab" => $row['mark2'],
                "Internal Assessment" => $row['mark3']
            ];
            $total = array_sum($scores);
            $avg = round($total / 3, 1);
        ?>
            <?php foreach($scores as $label => $val): ?>
                <div class="score-row">
                    <div class="score-circle"><?php echo $val; ?></div>
                    <div class="score-label">
                        <h3><?php echo $label; ?></h3>
                        <div class="score-bar"><div class="score-fill" style="width: <?php echo $val; ?>%;"></div></div>
                    </div>
                </div>
            <?php endforeach; ?>

            <div class="total-box">
                <p style="margin: 0; color: #1e40af; font-weight: 700; font-size: 0.875rem;">CUMULATIVE SCORE</p>
                <p style="margin: 0.5rem 0; font-size: 2.5rem; font-weight: 900; color: #1d4ed8;"><?php echo $total; ?> <span style="font-size: 1rem; opacity: 0.6;">/ 300</span></p>
                <span class="status-badge" style="background: #3b82f6; color: white;">Average: <?php echo $avg; ?>/100</span>
            </div>
        <?php else: ?>
            <div style="text-align: center; padding: 2rem; color: #94a3b8;">
                <p style="font-size: 1.25rem; font-weight: 600;">Results Pending</p>
                <p>Grades have not been posted for your account yet.</p>
            </div>
        <?php endif; ?>
    </div>
</body>
</html>