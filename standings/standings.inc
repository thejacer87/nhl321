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
      <table class="table table-responsive table-bordered">
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
<div class="tie-breaker-wrapper">
  <h3>
    <div class="icon">
      <div class="one"></div>
      <div class="two"></div>
    </div>
    <a data-toggle="collapse" data-target="#tie-breaker-list">Tie-Breaking
      Procedure</a></h3>
  <div id="tie-breaker-list"
       class="collapse">
    <ol>
      <li>Wins</li>
      <li>Overtime Wins</li>
      <li>I don't know! This is all hypothetical, if you have a suggestion
        <a href="https://twitter.com/Thejacer87" target="_blank">send me a
          tweet</a>,
        or create an issue on
        <a href="https://github.com/thejacer87/nhl321/issues" target="_blank">GitHub</a>.
      </li>
    </ol>
  </div>
</div>