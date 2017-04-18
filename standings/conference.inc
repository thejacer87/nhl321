<div id="conference"
     class="tab-pane fade table-wrapper <?php print $conf_active ?>">
  <h2 class="sub-header col-lg-12">Conference Standings</h2>
  <div class="col-md-6">
    <table class="table table-responsive table-bordered" id="west">
      <?php
      $headers['team'] = 'Western';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      $west = array_merge($grouped_teams['Western']['Pacific'], $grouped_teams['Western']['Central']);
      uasort($west, 'standings_sort');
      foreach ($west as $team) {
        echo output_table_body($team, $rank++, $team->conf_rank);
      }
      ?>
      </tbody>
    </table>
  </div>
  <div class="col-md-6">
    <table class="table table-responsive table-bordered" id="east">
      <?php
      $headers['team'] = 'Eastern';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      $east = array_merge($grouped_teams['Eastern']['Atlantic'], $grouped_teams['Eastern']['Metropolitan']);
      uasort($east, 'standings_sort');
      foreach ($east as $team) {
        echo output_table_body($team, $rank++, $team->conf_rank);
      }
      ?>
      </tbody>
    </table>
  </div>
</div>