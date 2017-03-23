<div class="tab-content table-wrapper" id="overall">
  <table>
    <caption>Overall</caption>
    <thead>
    <tr>

      <th>Team</th>
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
      echo output_row($team, $rank, $team['league_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>