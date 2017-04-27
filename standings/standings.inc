<?php

$pacific_teams = $teams[WESTERN][PACIFIC];
$central_teams = $teams[WESTERN][CENTRAL];
$atlantic_teams = $teams[EASTERN][ATLANTIC];
$metro_teams = $teams[EASTERN][METRO];

?>

<div class="row tab-content">
  <div id="wildcard"
       class="tab-pane fade in table-wrapper <?php print $wc_active ?>">
    <?php
    print get_wild_standings('West', array(
      'Pacific' => $pacific_teams,
      'Central' => $central_teams,
    ));
    print get_wild_standings('East', array(
      'Atlantic' => $atlantic_teams,
      'Metro' => $metro_teams,
    ));
    ?>
  </div>
  <div id="division"
       class="tab-pane fade table-wrapper <?php print $div_active ?>">
    <?php
    print get_division_standings('West', array(
      'Pacific' => $pacific_teams,
      'Central' => $central_teams,
    ));
    print get_division_standings('East', array(
      'Atlantic' => $atlantic_teams,
      'Metro' => $metro_teams,
    ));
    ?>
  </div>
  <div id="conference"
       class="tab-pane fade table-wrapper <?php print $conf_active ?>">
    <h2 class="sub-header col-lg-12">Conference Standings</h2>
    <?php
    print get_conference_standings('Western', array(
      'Pacific' => $pacific_teams,
      'Central' => $central_teams,
    ));
    print get_conference_standings('Eastern', array(
      'Atlantic' => $atlantic_teams,
      'Metro' => $metro_teams,
    ));
    ?>
  </div>
  <div id="overall" class="tab-pane fade <?php print $ovr_active ?>">
    <div class="col-lg-12">
      <h2 class="sub-header">League Standings</h2>
      <table class="standings table table-responsive table-bordered">
        <?php
        $headers['team'] = 'Teams';
        print get_table_header($headers);
        ?>
        <tbody>
        <?php
        $league = array_merge($pacific_teams, $central_teams, $atlantic_teams, $metro_teams);
        uasort($league, 'standings_sort');
        foreach ($league as $team) {
          print get_standings_row_for_team($team, $team->league_rank, $team->old_league_rank);
        }
        ?>
        </tbody>
      </table>
    </div>
  </div>
</div>

<?php include_once 'points_breakdown.inc'; ?>
<?php include_once 'tie_breaker.inc'; ?>