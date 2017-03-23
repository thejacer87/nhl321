<div class="tab-content table-wrapper" id="conference">
  <table class="table table-responsive table-bordered" id="west">
    <caption>Conference</caption>
    <thead>
    <tr>

      <th>Western</th>
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
    usort($teams, 'standings_sort');
    $rank = 1;
    foreach ($teams as &$conf_team) {
      if ($conf_team['conference'] == 'Western') {
        $conf_team['custom_conf_rank'] = $rank++;
      }
    }
    usort($teams, 'standings_sort');
    $rank = 1;
    foreach ($teams as $team) {
      if ($team['conference'] == 'Western') {
        echo output_row($team, $rank++, $team['custom_conf_rank']);
      }
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="east">
    <thead>
    <tr>

      <th>Eastern</th>
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
    $rank = 1;
    foreach ($teams as $team) {
      if ($team['conference'] == 'Eastern') {
        echo output_row($team, $rank, $team['conference_rank']);
        $rank++;
      }
    }
    ?>
    </tbody>
  </table>

</div>