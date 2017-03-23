<div class="tab-content table-wrapper" id="division">
  <table class="table table-responsive table-bordered" id="pac-div">
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
    $rank = 1;
    foreach ($grouped_teams['Western']['Pacific'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="cen-div">
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
    $rank = 1;
    foreach ($grouped_teams['Western']['Central'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="atl-div">
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
    $rank = 1;
    foreach ($grouped_teams['Eastern']['Atlantic'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
  <table class="table table-responsive table-bordered" id="met-div">
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
    $rank = 1;
    foreach ($grouped_teams['Eastern']['Metropolitan'] as $team) {
      echo output_row($team, $rank, $team['division_rank']);
      $rank++;
    }
    ?>
    </tbody>
  </table>
</div>