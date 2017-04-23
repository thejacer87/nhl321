<?php
$options = '';
$month = date('m');
$year = date('Y');
if ($month < 10) {
  $year--;
}
while ($year >= 2014) {
  if ($year == $season) {
    $selected = ' selected="selected"';
  }
  else {
    $selected = '';
  }

  $options .= '<option';
  $options .= $selected;
  $options .= ' value="';
  $options .= $year;
  $options .= '">' . $year . '/' . ($year + 1) . '</option>';
  $year--;
};

$view = isset($_GET['view']) ? $_GET['view'] : 'wc';
switch ($view) {
  case 'wc':
    $wc_active = 'active in';
    break;
  case 'div':
    $div_active = 'active in';
    break;
  case 'conf':
    $conf_active = 'active in';
    break;
  case 'ovr':
    $ovr_active = 'active in';
    break;
}

?>
<div id="standings">
  <div class="row">
    <div class="col-sm-8 col-xs-12">
      <ul class="nav nav-pills">
        <li class="<?php print $wc_active; ?>"><a data-toggle="tab" id="wc"
                                                  href="#wildcard">Wild Card</a>
        </li>
        <li class="<?php print $div_active; ?>"><a data-toggle="tab" id="div"
                                                   href="#division">Division</a>
        </li>
        <li class="<?php print $conf_active; ?>"><a data-toggle="tab" id="conf"
                                                    href="#conference">Conference</a>
        </li>
        <li class="<?php print $ovr_active; ?>"><a data-toggle="tab" id="ovr"
                                                   href="#overall">Overall</a>
        </li>
      </ul>
    </div>
    <div class="col-sm-4 col-xs-8">
      <div id="loading"><img src="../gfx/loading.gif"></div>
      <select class="form-control col-md-2" name="season" id="season">
        <?php print $options; ?>
      </select>
    </div>
  </div>
