<?php
    $conn = mysqli_connect("localhost", "root", "", "ajmal");
    if (!$conn) { die("Database Error"); }

    $query = "
        SELECT s.name, s.rollno, (m.mark1 + m.mark2 + m.mark3) as total_marks 
        FROM student s 
        JOIN mark m ON s.rollno = m.rollno 
        ORDER BY total_marks DESC 
        LIMIT 5
    ";
    $result = mysqli_query($conn, $query);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Top Performers</title>
    <link rel="stylesheet" href="../../../styles/main.css">
    <style>
        body { padding: 2rem; background: transparent; }
        .analytics-card { background: white; padding: 2.5rem; border-radius: var(--border-radius); box-shadow: var(--shadow); }
        .leaderboard { margin-top: 2rem; }
        .rank-row { display: flex; align-items: center; padding: 1rem; border-radius: 12px; margin-bottom: 0.75rem; background: #f8fafc; transition: transform 0.2s; }
        .rank-row:hover { transform: scale(1.02); background: #f1f5f9; }
        .rank-num { width: 40px; height: 40px; border-radius: 50%; display: flex; align-items: center; justify-content: center; font-weight: 800; color: white; margin-right: 1.5rem; }
        .rank-1 { background: #fbbf24; }
        .rank-2 { background: #94a3b8; }
        .rank-3 { background: #b45309; }
        .rank-other { background: #e2e8f0; color: #64748b; }
        .student-info { flex-grow: 1; }
        .score-display { font-weight: 700; color: var(--primary-color); font-size: 1.125rem; }
    </style>
</head>
<body class="fade-in">
    <div class="analytics-card">
        <h2>Top Performers</h2>
        <p style="color: var(--text-muted);">Recognition of the highest scoring students across all subjects.</p>

        <div class="leaderboard">
            <?php if ($result && mysqli_num_rows($result) > 0): 
                $rank = 1;
                while ($row = mysqli_fetch_assoc($result)): 
                    $rankClass = ($rank <= 3) ? "rank-$rank" : "rank-other";
            ?>
                <div class="rank-row">
                    <div class="rank-num <?php echo $rankClass; ?>"><?php echo $rank; ?></div>
                    <div class="student-info">
                        <h4 style="margin: 0; font-size: 1.125rem;"><?php echo htmlspecialchars($row['name']); ?></h4>
                        <span style="font-size: 0.875rem; color: #64748b;">Roll No: #<?php echo $row['rollno']; ?></span>
                    </div>
                    <div class="score-display">
                        <?php echo $row['total_marks']; ?> <small style="font-size: 0.7rem; opacity: 0.6;">/ 300</small>
                    </div>
                </div>
            <?php 
                $rank++;
                endwhile; 
            else: ?>
                <p style="text-align: center; color: #94a3b8; padding: 2rem;">No grading data available for ranking.</p>
            <?php endif; ?>
        </div>
    </div>
</body>
</html>
