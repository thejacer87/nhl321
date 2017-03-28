<?php

function output_table_header($headers) {
  $output = '<thead><tr>';

  foreach ($headers as $header) {
    $output .= '<th>' . $header . '</th>';
  }

  return $output . '</tr></thead>';
}

function output_table_body($team, $rank, $old_rank = NULL) {
  $output = '';
  $logo = $team['team']['logos']['small'];
  $img = '<img class="logo" src="' . $logo . '">';

  $wins = $team['wins'];
  $otw = $team['overtime_wins'];
  $output .= '<tr>';
  $output .= '<td class="team-standings">' . $rank . $img;
  $output .= '<span class="team-name">' . $team['team']['short_name'] . '</span></td>';
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
  if (!isset($old_rank)) {
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

// Tie Breakers: W > OTW
function standings_sort($a, $b) {
  if ($a['new_points'] > $b['new_points']) {
    return -1;
  }
  if ($a['new_points'] < $b['new_points']) {
    return 1;
  }
  $real_wins_a = $a['wins'] - $a['overtime_wins'];
  $real_wins_b = $b['wins'] - $b['overtime_wins'];
  if ($real_wins_a > $real_wins_b) {
    return -1;
  }
  if ($real_wins_a < $real_wins_b) {
    return 1;
  }
  if ($a['overtime_wins'] > $b['overtime_wins']) {
    return -1;
  }
  if ($a['overtime_wins'] < $b['overtime_wins']) {
    return 1;
  }

  return 0;
}

function standings_sort_reverse($a, $b) {
  if ($a['new_points'] < $b['new_points']) {
    return -1;
  }
  if ($a['new_points'] > $b['new_points']) {
    return 1;
  }
  $real_wins_a = $a['wins'] - $a['overtime_wins'];
  $real_wins_b = $b['wins'] - $b['overtime_wins'];
  if ($real_wins_a < $real_wins_b) {
    return -1;
  }
  if ($real_wins_a > $real_wins_b) {
    return 1;
  }
  if ($a['overtime_wins'] < $b['overtime_wins']) {
    return -1;
  }
  if ($a['overtime_wins'] > $b['overtime_wins']) {
    return 1;
  }

  return 0;
}
