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
