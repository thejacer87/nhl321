<?php
include 'src/Team.php';

$season = isset($_GET['season']) ? $_GET['season'] : '2016';
//$json = file_get_contents('https://api.thescore.com/nhl/standings/' . $season);
$json = file_get_contents('https://api.thescore.com/nhl/standings');
$teams = json_decode($json, TRUE);

foreach ($teams as $nhl_team) {
  $team = new Team($nhl_team);
  $grouped_teams[$team->conference][$team->division][] = $team;
}
