<?php
include 'src/Team.php';

$current_month = date('m');
$current_year = date('Y');

// If it is currently before October, the season is considered the previous calendar year.
if ($current_month < 10) {
  $current_year--;
}

$season = isset($_GET['season']) ? $_GET['season'] : $current_year;

$standings = get_standings_for_season($season);

foreach ($standings as $row) {
  $team = new Team($row);
  $teams[$team->conference][$team->division][] = $team;
}
