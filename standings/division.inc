<div id="division" class="tab-pane fade table-wrapper <?php print $div_active?>">
  <div class="col-md-6">
    <h2 class="sub-header">West</h2>
    <table class="table table-responsive table-bordered" id="pac-div">
      <?php
      $headers['team'] = 'Pacific';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      usort($grouped_teams['Western']['Pacific'], 'standings_sort');
      foreach ($grouped_teams['Western']['Pacific'] as $team) {
        echo output_table_body($team, $rank, $team->div_rank);
        $rank++;
      }
      ?>
      </tbody>
    </table>
    <table class="table table-responsive table-bordered" id="cen-div">
      <?php
      $headers['team'] = 'Central';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      usort($grouped_teams['Western']['Central'], 'standings_sort');
      foreach ($grouped_teams['Western']['Central'] as $team) {
        echo output_table_body($team, $rank, $team->div_rank);
        $rank++;
      }
      ?>
      </tbody>
    </table>
  </div>
  <div class="col-md-6">
    <h2 class="sub-header">East</h2>
    <table class="table table-responsive table-bordered" id="atl-div">
      <?php
      $headers['team'] = 'Atlantic';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      usort($grouped_teams['Eastern']['Atlantic'], 'standings_sort');
      foreach ($grouped_teams['Eastern']['Atlantic'] as $team) {
        echo output_table_body($team, $rank, $team->div_rank);
        $rank++;
      }
      ?>
      </tbody>
    </table>
    <table class="table table-responsive table-bordered" id="met-div">
      <?php
      $headers['team'] = 'Metro';
      print output_table_header($headers);
      ?>
      <tbody>
      <?php
      $rank = 1;
      usort($grouped_teams['Eastern']['Metropolitan'], 'standings_sort');
      foreach ($grouped_teams['Eastern']['Metropolitan'] as $team) {
        echo output_table_body($team, $rank, $team->div_rank);
        $rank++;
      }
      ?>
      </tbody>
    </table>
  </div>
</div>