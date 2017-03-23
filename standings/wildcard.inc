<div class="tab-content table-wrapper current" id="wildcard">
  <table class="table table-responsive table-bordered" id="pac-wild">
    <caption>Western</caption>
    <thead>
    <tr>
      <th>Pacific</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $pac3 = array_slice($grouped_teams['Western']['Pacific'], 0, 3, TRUE);
    $rank = 1;
    foreach ($pac3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="cen-wild">
    <thead>
    <tr>

      <th>Central</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $cen3 = array_slice($grouped_teams['Western']['Central'], 0, 3, TRUE);
    $rank = 1;
    foreach ($cen3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="west-wild">
    <thead>
    <tr>

      <th>Wild Cards</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $cen_wild = array_slice($grouped_teams['Western']['Central'], 3, 4, TRUE);
    $pac_wild = array_slice($grouped_teams['Western']['Pacific'], 3, 4, TRUE);
    $wild = array_merge($pac_wild, $cen_wild);
    usort($wild, 'standings_sort_reverse');
    foreach ($wild as &$wild_team) {
      $wild_team['wild_rank'] = $wild_team['conference_rank'] - 6;
    }
    usort($wild, 'standings_sort');
    $rank = 1;
    foreach ($wild as $team) {
      echo output_row($team, $rank, $team['wild_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <br>
  <br>
  <table class="table table-responsive table-bordered" id="atl-wild">
    <caption>Eastern</caption>
    <thead>
    <tr>

      <th>Atlantic</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $atl3 = array_slice($grouped_teams['Eastern']['Atlantic'], 0, 3, TRUE);
    $rank = 1;
    foreach ($atl3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="met-wild">
    <thead>
    <tr>

      <th>Central</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $met3 = array_slice($grouped_teams['Eastern']['Metropolitan'], 0, 3, TRUE);
    $rank = 1;
    foreach ($met3 as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="east-wild">
    <thead>
    <tr>

      <th>Wild Cards</th>
      <th>GP</th>
      <th>W</th>
      <th>OTW</th>
      <th>OTL</th>
      <th>L</th>
      <th>Points</th>
      <th>Change</th>
    </tr>
    </thead>
    <tbody>
    <?php
    $atl_wild = array_slice($grouped_teams['Eastern']['Atlantic'], 3, 5, TRUE);
    $met_wild = array_slice($grouped_teams['Eastern']['Metropolitan'], 3, 5, TRUE);
    $wild = array_merge($atl_wild, $met_wild);
    usort($wild, 'standings_sort_reverse');
    foreach ($wild as &$wild_team) {
      $wild_team['wild_rank'] = $wild_team['conference_rank'] - 6;
    }
    usort($wild, 'standings_sort');
    $rank = 1;
    foreach ($wild as $team) {
      echo output_row($team, $rank, $team['wild_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>