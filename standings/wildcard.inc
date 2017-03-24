<div id="wildcard" class="tab-pane fade in active table-wrapper">
  <table class="table table-responsive table-bordered" id="pac-wild">
    <?php
    $headers['team'] = 'Pacific';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $pac3 = array_slice($grouped_teams['Western']['Pacific'], 0, 3, TRUE);
    uasort($pac3, 'standings_sort');
    $rank = 1;
    foreach ($pac3 as $team) {
      echo output_table_body($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="cen-wild">
    <?php
    $headers['team'] = 'Central';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $cen3 = array_slice($grouped_teams['Western']['Central'], 0, 3, TRUE);
    uasort($cen3, 'standings_sort');
    $rank = 1;
    foreach ($cen3 as $team) {
      echo output_table_body($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="west-wild">
    <?php
    $headers['team'] = 'Wild Cards';
    print output_table_header($headers);
    ?>
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
      echo output_table_body($team, $rank, $team['wild_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="atl-wild">
    <?php
    $headers['team'] = 'Atlantic';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $atl3 = array_slice($grouped_teams['Eastern']['Atlantic'], 0, 3, TRUE);
    uasort($atl3, 'standings_sort');
    $rank = 1;
    foreach ($atl3 as $team) {
      echo output_table_body($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="met-wild">
    <?php
    $headers['team'] = 'Metropolitan';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $met3 = array_slice($grouped_teams['Eastern']['Metropolitan'], 0, 3, TRUE);
    uasort($met3, 'standings_sort');
    $rank = 1;
    foreach ($met3 as $team) {
      echo output_table_body($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="east-wild">
    <?php
    $headers['team'] = 'Wild Cards';
    print output_table_header($headers);
    ?>
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
      echo output_table_body($team, $rank, $team['wild_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>