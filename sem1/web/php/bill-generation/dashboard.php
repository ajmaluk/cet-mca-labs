<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>EB Billing Dashboard</title>
    <!-- Using iframe for the layout as requested by the original structure, but improving the UI -->
    <style>
        html, body {
            margin: 0;
            padding: 0;
            height: 100%;
            overflow: hidden;
            font-family: 'Inter', sans-serif;
        }
        .main-wrapper {
            display: flex;
            height: 100vh;
            width: 100vw;
        }
        .sidebar-frame {
            width: 280px;
            height: 100%;
            border: none;
            border-right: 1px solid #e2e8f0;
        }
        .content-frame {
            flex-grow: 1;
            height: 100%;
            border: none;
            background: #f8fafc;
        }
    </style>
</head>
<body>
    <div class="main-wrapper">
        <iframe src="sidebar.html" class="sidebar-frame" name="sideBar"></iframe>
        <iframe src="consumer_reg.php" class="content-frame" name="dash"></iframe>
    </div>
</body>
</html>