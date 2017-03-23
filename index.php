<?php
$json = file_get_contents('https://api.thescore.com/nhl/standings');
$teams = json_decode($json, TRUE);

foreach ($teams as &$nhl_team) {
  $wins = $nhl_team['wins'];
  $otw = $nhl_team['overtime_wins'];
  $otl = $nhl_team['overtime_losses'];
  $new_points = (($wins - $otw) * 3) + ($otw * 2) + $otl;
  $nhl_team['new_points'] = $new_points;
  $grouped_teams[$nhl_team['conference']][$nhl_team['division']][] = $nhl_team;
}


usort($teams, 'standings_sort');
usort($grouped_teams['Western']['Pacific'], 'standings_sort');
usort($grouped_teams['Western']['Central'], 'standings_sort');
usort($grouped_teams['Eastern']['Metropolitan'], 'standings_sort');
usort($grouped_teams['Eastern']['Atlantic'], 'standings_sort');


?>
<!doctype html>

<html lang="en">
<head>
  <meta charset="utf-8">

  <title>NHL Standings 321</title>
  <link rel="icon" href="gfx/favicon.ico">
  <link
      href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u"
      crossorigin="anonymous">
  <script
      src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"
      integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa"
      crossorigin="anonymous"></script>
  <script src="http://code.jquery.com/jquery-1.10.0.min.js"></script>
  <script src="js/script.js"></script>
  <link rel="stylesheet" href="css/style.css">
</head>
<body>
<h1>NHL Standings 321</h1>
<h5>what if the nhl had 3 point games...</h5>

<navbar>
  <ul class="tabs">
    <li class="tab-link current" data-tab="wildcard"><a>Wildcard</a></li>
    <li class="tab-link" data-tab="division"><a>Division</a></li>
    <li class="tab-link" data-tab="conference"><a>Conference</a></li>
    <li class="tab-link" data-tab="overall"><a>Overall</a></li>
  </ul>
</navbar>

<div class="tab-content table-wrapper current" id="wildcard">
  <table class="table table-responsive table-bordered" id="pac-wild">
    <caption>Western</caption>
    <thead>
    <tr>

      <th>Pacific</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $pac3 = array_slice($grouped_teams['Western']['Pacific'], 0, 3, TRUE);
    $rank = 1;
    foreach ($pac3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="cen-wild">
    <thead>
    <tr>

      <th>Central</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $cen3 = array_slice($grouped_teams['Western']['Central'], 0, 3, TRUE);
    $rank = 1;
    foreach ($cen3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="west-wild">
    <thead>
    <tr>

      <th>Wild Cards</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $cen_wild = array_slice($grouped_teams['Western']['Central'], 3, 4, TRUE);
    $pac_wild = array_slice($grouped_teams['Western']['Pacific'], 3, 4, TRUE);
    $wild = array_merge($pac_wild, $cen_wild);
    usort($wild, 'standings_sort_reverse');
    foreach ($wild as &$wild_team) {
      $wild_team['wild_rank'] = $wild_team['conference_rank'] - 6;
    }
    usort($wild, 'standings_sort');
    $rank = 1;
    foreach ($wild as $team) {
      echo output_row($team, $rank, $team['wild_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <br>
  <br>
  <table class="table table-responsive table-bordered" id="atl-wild">
    <caption>Eastern</caption>
    <thead>
    <tr>

      <th>Atlantic</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $atl3 = array_slice($grouped_teams['Eastern']['Atlantic'], 0, 3, TRUE);
    $rank = 1;
    foreach ($atl3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="met-wild">
    <thead>
    <tr>

      <th>Central</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $met3 = array_slice($grouped_teams['Eastern']['Metropolitan'], 0, 3, TRUE);
    $rank = 1;
    foreach ($met3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="east-wild">
    <thead>
    <tr>

      <th>Wild Cards</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $atl_wild = array_slice($grouped_teams['Eastern']['Atlantic'], 3, 5, TRUE);
    $met_wild = array_slice($grouped_teams['Eastern']['Metropolitan'], 3, 5, TRUE);
    $wild = array_merge($atl_wild, $met_wild);
    usort($wild, 'standings_sort_reverse');
    foreach ($wild as &$wild_team) {
      $wild_team['wild_rank'] = $wild_team['conference_rank'] - 6;
    }
    usort($wild, 'standings_sort');
    $rank = 1;
    foreach ($wild as $team) {
      echo output_row($team, $rank, $team['wild_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>
<div class="tab-content table-wrapper" id="division">
  <table class="table table-responsive table-bordered" id="pac-div">
    <caption>Western</caption>
    <thead>
    <tr>

      <th>Pacific</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $rank = 1;
    foreach ($grouped_teams['Western']['Pacific'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="cen-div">
    <thead>
    <tr>

      <th>Central</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $rank = 1;
    foreach ($grouped_teams['Western']['Central'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="atl-div">
    <caption>Eastern</caption>
    <thead>
    <tr>

      <th>Atlantic</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $rank = 1;
    foreach ($grouped_teams['Eastern']['Atlantic'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="met-div">
    <thead>
    <tr>

      <th>Central</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $rank = 1;
    foreach ($grouped_teams['Eastern']['Metropolitan'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>
<div class="tab-content table-wrapper" id="overall">
  <table>
    <caption>Overall</caption>
    <thead>
    <tr>

      <th>Team</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $rank = 1;
    foreach ($teams as $team) {
      echo output_row($team, $rank, $team['league_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>
<div class="tab-content table-wrapper" id="conference">
  <table class="table table-responsive table-bordered" id="west">
    <caption>Conference</caption>
    <thead>
    <tr>

      <th>Western</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    usort($teams, 'standings_sort');
    $rank = 1;
    foreach ($teams as &$conf_team) {
      if ($conf_team['conference'] == 'Western') {
        $conf_team['custom_conf_rank'] = $rank++;
      }
    }
    usort($teams, 'standings_sort');
    $rank = 1;
    foreach ($teams as $team) {
      if ($team['conference'] == 'Western') {
        echo output_row($team, $rank++, $team['custom_conf_rank']);
      }
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="east">
    <thead>
    <tr>

      <th>Eastern</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $rank = 1;
    foreach ($teams as $team) {
      if ($team['conference'] == 'Eastern') {
        echo output_row($team, $rank, $team['conference_rank']);
        $rank++;
      }
    }
    ?>
    </tbody>
  </table>

</div>

</body>
</html>

<?php

function output_row($team, $rank, $old_rank = NULL) {
  $output = '';
  $logo = $team['team']['logos']['small'];
  $img = '<img class="logo" src="' . $logo . '">';

  $wins = $team['wins'];
  $otw = $team['overtime_wins'];
  $output .= '<tr>';
  $output .= '<td class="team-standings">' . $rank . $img . $team['team']['medium_name'] .'</td>';
  $output .= '<td>' . $team['games_played'] . '</td>';
  $output .= '<td>' . ($wins - $otw) . '</td>';
  $output .= '<td>' . $otw . '</td>';
  $output .= '<td>' . $team['overtime_losses'] . '</td>';
  $output .= '<td>' . $team['losses'] . '</td>';
  $output .= '<td>' . $team['new_points'] . '</td>';
  $output .= '<td>' . output_rank_change($rank, $old_rank) . '</td>';
  $output .= '</tr>';

  return $output;
}

function output_rank_change($rank, $old_rank) {
  if (empty($old_rank)) {
    return '';
  }

  $change = $old_rank - $rank;
  if ($change == 0) {
    return '';
  }
  elseif ($change > 0) {
    return '<span class="change change-up"><div class="arrow arrow-up"></div>' . $change . '</span>';
  }
  else {
    return '<span class="change change-down"><div class="arrow arrow-down"></div>' . abs($change) . '</span>';
  }

}

function standings_sort($a, $b) {
  return $b['new_points'] <=> $a['new_points'];
}

function standings_sort_reverse($a, $b) {
  return $a['new_points'] <=> $b['new_points'];
}

?>

