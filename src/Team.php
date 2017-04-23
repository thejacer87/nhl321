<?php

class Team {
  public $conference;
  public $team_id;
  public $division;
  public $full_name;
  public $short_name;
  public $games_played;
  public $wins;
  public $otw;
  public $otl;
  public $losses;
  public $points;
  public $league_rank;
  public $conf_rank;
  public $div_rank;
  public $wild_rank;
  public $old_points;
  public $old_league_rank;
  public $old_conf_rank;
  public $old_div_rank;
  public $old_wild_rank;
  public $logo_url;

  function __construct($team) {
    $this->populate_team_info($team);
    $this->games_played = $team['games_played'];
    $this->wins = $team['wins'];
    $this->losses = $team['losses'];
    $this->otw = $team['overtime_wins'];
    $this->otl = $team['overtime_losses'];
    $this->old_points = $team['old_points'];
    $this->points = $team['points'];
    $this->league_rank = $team['league_rank'];
    $this->conf_rank = $team['conference_rank'];
    $this->div_rank = $team['division_rank'];
    $this->wild_rank = $team['wildcard_rank'];
    $this->old_league_rank = $team['old_league_rank'];
    $this->old_conf_rank = $team['old_conference_rank'];
    $this->old_div_rank = $team['old_division_rank'];
    $this->old_wild_rank = $team['old_wildcard_rank'];

  }

  function populate_team_info($team) {
    $connection = get_connection();
    $query = 'SELECT * from Conference c JOIN Team t on c.conference_ID = t.conference_ID where t.team_ID = ' . $team['team_ID'];
    $result = mysqli_query($connection, $query);

    if (mysqli_num_rows($result) > 0) {
      // output data of each row
      while ($row = mysqli_fetch_assoc($result)) {
        $this->full_name = $row['name'];
        $this->short_name = $row['abv'];
        $this->team_id = $row['team_ID'];
        $this->division = $row['division_ID'];
        $this->conference = $row['conference_ID'];
        $this->logo_url = $row['url'];

      }
    }
    mysqli_close($connection);
  }
}
