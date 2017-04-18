<div id="overall" class="tab-pane fade <?php print $ovr_active ?>">
  <div class="col-lg-12">
    <h2 class="sub-header">League Standings</h2>
    <table class="table table-responsive table-bordered">
      <?php
      $headers['team'] = 'Teams';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      $league = array_merge($grouped_teams['Eastern']['Atlantic'], $grouped_teams['Eastern']['Metropolitan'], $grouped_teams['Western']['Pacific'], $grouped_teams['Western']['Central']);
      uasort($league, 'standings_sort');
      foreach ($league as $team) {
        echo output_table_body($team, $rank++, $team->league_rank);
      }
      ?>
      </tbody>
    </table>
  </div>
</div>