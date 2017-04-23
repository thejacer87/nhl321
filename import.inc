<?php

$season = 2016;

$json = file_get_contents('https://api.thescore.com/nhl/standings');
$standings = json_decode($json, TRUE);
//$json = file_get_contents('https://statsapi.web.nhl.com/api/v1/teams');
//$teams = json_decode($json, TRUE);

foreach ($standings as $team) {
  $teams[$team['team']['id']] = $team['team']['logos']['large'];
  $sql .= 'update Team set url = "' . $team['team']['logos']['large'] . '" where name = "'. $team['team']['full_name']. "\";\n";
}

$test =3;
//foreach ($teams['teams'] as $team) {
//  $my_teams[$team['id']] = $team;
//}
//
//$standings_sql = '';
//$team_sql = '';
//$update_sql = '';
//
//$team_ids = array(
//  1,
//  2,
//  3,
//  4,
//  5,
//  6,
//  7,
//  8,
//  9,
//  10,
//  12,
//  13,
//  14,
//  15,
//  16,
//  17,
//  18,
//  19,
//  20,
//  21,
//  22,
//  23,
//  24,
//  25,
//  26,
//  28,
//  29,
//  30,
//  52,
//  53,
//);
//foreach ($teams['teams'] as $team) {
//  $json = file_get_contents('https://statsapi.web.nhl.com/api/v1/schedule?site=en_nhlCA&leaderGameType=R&expand=schedule.teams,schedule.linescore,schedule.decisions&startDate=2014-10-08&endDate=2016-04-12&teamId=' . $team['id']);
//  $games = json_decode($json, TRUE);
//  $ot_games = [];
//  $otw = 0;
//  foreach ($games['dates'] as $game) {
//    $game_info = $game['games'][0];
//    if ($game_info['linescore']['currentPeriodOrdinal'] == 'OT') {
//      $ot_games[] = $game_info;
//    }
//  }
//  foreach ($ot_games as $ot_game) {
//
//    //if home team
//    if ($ot_game['teams']['home']['team']['id'] == $team['id']) {
//      if ($ot_game['teams']['home']['score'] > $ot_game['teams']['away']['score']) {
//        $otw++;
//      }
//    }
//    else {
//      if ($ot_game['teams']['home']['score'] < $ot_game['teams']['away']['score']) {
//        $otw++;
//      }
//    }
//  }
//  $update_sql .= 'update Standings_2014 set overtime_wins = ' . $otw . ', points = (((wins - ' . $otw . ') * 3) + (' . $otw . ' * 2) + overtime_losses) where team_ID = ' . $team['id'] . "; \n";
//}
//$wins = $team['wins'];
//$losses = $team['losses'];
//$otl = $team['overtime_losses'];
//$old_points = $team['points'];
//$points = (($wins - $otw) * 3) + ($otw * 2) + $otl;
//$team_id = $team['team']['id'];


//  $team_sql .= 'insert into Team (team_ID, name, abv, url, division_ID, conference_ID) VALUES (' .
//    $team_id . ', "' .
//    $name . '", "' .
//    $abv . '", "' .
//    '", ' .
//    $div_id . ', ' .
//    $conf_id . ");\n";
//
//  $standings_sql .= 'insert into Standings_2016 (wins, overtime_wins, losses, overtime_losses, league_rank, conferance_rank, division_rank, wildcard_rank, points, old_points, team_ID) VALUES (' .
//    $wins . ', ' .
//    $otw . ', ' .
//    $losses . ', ' .
//    $otl . ', ' .
//    $l_rank . ', ' .
//    $c_rank . ', ' .
//    $d_rank . ', ' .
//    $w_rank . ', ' .
//    $points . ', ' .
//    $old_points . ', ' .
//    $team_id . ");\n";
//}
