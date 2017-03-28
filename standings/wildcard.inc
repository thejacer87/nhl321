<div id="wildcard" class="tab-pane fade in active table-wrapper">
  <div class="col-md-6">
    <h2 class="sub-header">West</h2>
    <table class="table table-responsive table-bordered" id="pac-wild">
      <?php
      $headers['team'] = 'Pacific';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      uasort($grouped_teams['Western']['Pacific'], 'standings_sort');
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
      uasort($grouped_teams['Western']['Central'], 'standings_sort');
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
        if ($team['division_rank'] <= 3) {
          $team['wild_rank']++;
        }
        echo output_table_body($team, $rank, $team['wild_rank']);
        $rank++;
      }
      ?>
      </tbody>
    </table>
  </div>
  <div class="col-md-6">
    <h2 class="sub-header">East</h2>
    <table class="table table-responsive table-bordered" id="atl-wild">
      <?php
      $headers['team'] = 'Atlantic';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      uasort($grouped_teams['Eastern']['Atlantic'], 'standings_sort');
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
      $headers['team'] = 'Metro';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      uasort($grouped_teams['Eastern']['Metropolitan'], 'standings_sort');
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
        if ($team['division_rank'] <= 3) {
          $team['wild_rank']++;
        }
        echo output_table_body($team, $rank, $team['wild_rank']);
        $rank++;
      }
      ?>
      </tbody>
    </table>
  </div>
</div>