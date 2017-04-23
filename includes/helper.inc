<?php

/**
 * Get all the rows from the standings table for the season passed in.
 *
 * @param int $season
 *   The year of the standings table to retrieve.
 *
 * @return array
 *   The rows from the standings table.
 */
function get_standings_for_season($season = 2016) {
  $connection = get_connection();
  $query = 'SELECT * from Standings_' . $season . ' ORDER BY points DESC, league_rank';
  $result = mysqli_query($connection, $query);
  mysqli_close($connection);

  $standings = [];
  if (mysqli_num_rows($result) > 0) {
    // output data of each row
    while ($row = mysqli_fetch_assoc($result)) {
      $standings[] = $row;
    }
  }

  return $standings;
}

function get_table_header($headers) {
  $output = '<thead><tr>';

  foreach ($headers as $header) {
    $output .= '<th>' . $header . '</th>';
  }

  return $output . '</tr></thead>';
}

/**
 * Builds the table row for the team.
 *
 * @param $team Team
 * @param $rank
 * @param $old_rank
 *
 * @return string
 *  The row output.
 */
function get_standings_row_for_team($team, $rank, $old_rank) {
  $img = '<img class="logo" src="' . $team->logo_url . '">';
  $wins = $team->wins;
  $otw = $team->otw;

  $output = '';
  $output .= '<tr>';
  $output .= '<td class="team-standings">' . $rank . $img;
  $output .= '<span class="team-name">' . $team->short_name . '</span></td>';
  $output .= '<td>' . $team->games_played . '</td>';
  $output .= '<td>' . ($wins - $otw) . '</td>';
  $output .= '<td>' . $otw . '</td>';
  $output .= '<td>' . $team->otl . '</td>';
  $output .= '<td>' . $team->losses . '</td>';
  $output .= '<td>' . $team->points . '</td>';
  $output .= '<td>' . get_rank_change($rank, $old_rank) . '</td>';
  $output .= '</tr>';

  return $output;
}

function get_rank_change($rank, $old_rank) {
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

function standings_sort($team_a, $team_b) {
  return $team_a->league_rank <=> $team_b->league_rank;
}

function wildcard_sort($team_a, $team_b) {
  return $team_a->wild_rank <=> $team_b->wild_rank;
}

function conference_sort($team_a, $team_b) {
  return $team_a->conf_rank <=> $team_b->conf_rank;
}

function get_wild_standings($conference, $divisions) {
  global $headers;
  $wildcards = [];
  $output = '<div class="col-md-6"><h2 class="sub-header">';
  $output .= $conference . '</h2>';
  foreach ($divisions as $name => $division) {
    $wildcards[] = array_slice($division, 3);
    $output .= '<table class="table table-responsive table-bordered">';
    $headers['team'] = $name;
    $output .= get_table_header($headers);
    $output .= '<tbody>';
    foreach (array_slice($division, 0, 3) as $team) {
      $new_rank = $team->div_rank;
      $old_rank = $team->old_wild_rank ? $team->old_wild_rank  + 3: $team->old_div_rank;
      $output .= get_standings_row_for_team($team, $new_rank, $old_rank);
    }
    $output .= '</tbody></table>';
  }

  $headers['team'] = 'Wild Cards';

  $output .= '<table class="table table-responsive table-bordered wildcard">';
  $output .= get_table_header($headers);
  $output .= '<tbody>';

  $wildcards = array_merge($wildcards[0], $wildcards[1]);
  usort($wildcards, 'wildcard_sort');
  foreach ($wildcards as $team) {
    $output .= get_standings_row_for_team($team, $team->wild_rank, $team->old_wild_rank);
  }
  $output .= '</tbody></table></div>';

  return $output;
}

function get_division_standings($conference, $divisions) {
  global $headers;
  $output = '<div class="col-md-6"><h2 class="sub-header">';
  $output .= $conference . '</h2>';
  foreach ($divisions as $name => $division) {
    $output .= '<table class="table table-responsive table-bordered">';
    $headers['team'] = $name;
    $output .= get_table_header($headers);
    $output .= '<tbody>';
    foreach ($division as $team) {
      $output .= get_standings_row_for_team($team, $team->div_rank, $team->old_div_rank);
    }
    $output .= '</tbody></table>';
  }
  $output .= '</div>';

  return $output;
}

function get_conference_standings($conference, $divisions) {
  global $headers;
  $output = '<div class="col-md-6"><table class="table table-responsive table-bordered">';
  $headers['team'] = $conference;
  $output .= get_table_header($headers);
  $output .= '<tbody>';
  $divs = [];

  foreach ($divisions as $division) {
    $divs[] = $division;
  }

  $conference_teams = array_merge($divs[0], $divs[1]);
  uasort($conference_teams, 'conference_sort');
  foreach ($conference_teams as $team) {
    $output .= get_standings_row_for_team($team, $team->conf_rank, $team->old_conf_rank);
  }
  $output .= '</tbody></table></div>';

  return $output;

}
