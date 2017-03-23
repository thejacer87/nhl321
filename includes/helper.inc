<?php

function output_row($team, $rank, $old_rank = NULL) {
  $output = '';
  $logo = $team['team']['logos']['small'];
  $img = '<img class="logo" src="' . $logo . '">';

  $wins = $team['wins'];
  $otw = $team['overtime_wins'];
  $output .= '<tr>';
  $output .= '<td class="team-standings">' . $rank . $img . $team['team']['medium_name'] . '</td>';
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
