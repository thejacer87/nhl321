<div id="overall" class="tab-pane fade">
  <table class="table table-responsive table-bordered">
    <?php
    $headers['team'] = 'Overall';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $rank = 1;
    uasort($teams, 'standings_sort');
    foreach ($teams as $team) {
      echo output_table_body($team, $rank, $team['league_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>