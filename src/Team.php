<?php

class Team {
  public $conference;
  public $division;
  public $full_name;
  public $short_name;
  public $games_played;
  public $wins;
  public $losses;
  public $otw;
  public $otl;
  public $old_points;
  public $points;
  public $league_rank;
  public $conf_rank;
  public $div_rank;
  public $wild_rank;
  public $logo_url;

  function __construct($team) {
    $this->conference = $team['conference'];
    $this->division = $team['division'];
    $this->long_name = $team['team']['long_name'];
    $this->short_name = $team['team']['short_name'];
    $this->games_played = $team['games_played'];
    $this->wins = $team['wins'];
    $this->losses = $team['losses'];
    $this->otw = $team['overtime_wins'];
    $this->otl = $team['overtime_losses'];
    $this->old_points = $team['points'];
    $this->points = (($this->wins - $this->otw) * 3) + ($this->otw * 2) + $this->otl;
    $this->league_rank = $team['league_rank'];
    $this->conf_rank = $team['conference_rank'];
    $this->div_rank = $team['division_rank'];
    $this->logo_url = $team['team']['logos']['small'];

//    $this->wild_rank = $team['conference_rank'];
  }
}