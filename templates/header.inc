<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>NHL 321 Standings</title>
  <link rel="icon" href="gfx/favicon.ico">
  <!-- Latest compiled and minified CSS -->
  <link rel="stylesheet"
        href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

  <!-- jQuery library -->
  <script
      src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>

  <!-- Latest compiled JavaScript -->
  <script
      src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <script src="//blockr.io/js_external/coinwidget/coin.js"></script>
  <script>
    CoinWidgetCom.go({
      wallet_address: '1MqU2LmqNREU49toXq1yfEfPBqin4eG8br',
      currency: 'bitcoin',
      counter: 'count',
      lbl_button: 'Donate',
      lbl_count: 'donations',
      lbl_amount: 'BTC',
      lbl_address: 'Use address below to donate. Thanks!',
      qrcode: true,
      alignment: 'bl',
      decimals: 8,
      size: "small",
      color: "dark",
      countdownFrom: "0",
      element: "#coinwidget-bitcoin-1MqU2LmqNREU49toXq1yfEfPBqin4eG8br",
      onShow: function () {
      },
      onHide: function () {
      }
    });
  </script>
  <link rel="stylesheet" href="css/style.css">
</head>

<body>
<div class="container">
  <header>
    <h1>NHL 321 Standings</h1>
    <h5>What if the NHL had 3 point games...</h5>
    <div class="bitcoin" id="coinwidget-bitcoin-1MqU2LmqNREU49toXq1yfEfPBqin4eG8br"></div>
  </header>
