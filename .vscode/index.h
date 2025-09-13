const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Arduino Web Server</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      margin: 0;
      padding: 0;
      background-color: #f0f0f0;
    }
    h1 {
      color: #333;
    }
    p {
      font-size: 1.2em;
    }
    .button {
      display: inline-block;
      padding: 15px 25px;
      font-size: 16px;
      cursor: pointer;
      text-align: center;
      text-decoration: none;
      outline: none;
      color: #fff;
      background-color: #4CAF50;
      border: none;
      border-radius: 5px;
      box-shadow: 0 9px #999;
    }
    .button:hover {
      background-color: #45a049;
    }
    .button:active {
      background-color: #45a049;
      box-shadow: 0 5px #666;
      transform: translateY(4px);
    }
  </style>
</head>
<body>
  <h1>Arduino Web Server</h1>
  <p>Control the LED from here:</p>
  <a href="/led/on" class="button">Turn ON</a>
  <a href="/led/off" class="button">Turn OFF</a>
</body>
</html>
)rawliteral";