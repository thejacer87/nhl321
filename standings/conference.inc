<div id="conference" class="tab-pane fade table-wrapper">
  <table class="table table-responsive table-bordered" id="west">
    <?php
    $headers['team'] = 'Western';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $rank = 1;
    foreach ($teams as $team) {
      if ($team['conference'] == 'Western') {
        echo output_table_body($team, $rank++, $team['conference_rank']);
      }
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="east">
    <?php
    $headers['team'] = 'Eastern';
    print output_table_header($headers);
    ?>
    <tbody>
    <?php
    $rank = 1;
    foreach ($teams as $team) {
      if ($team['conference'] == 'Eastern') {
        echo output_table_body($team, $rank, $team['conference_rank']);
        $rank++;
      }
    }
    ?>
    </tbody>
  </table>
</div>