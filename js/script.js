(function ($) {
  $(function () {

    $('select#season').change(function () {
      var season = 'season=' + this.value;
      var view = '&view=' + $('#standings .nav li.active a').attr('id');
      $('body').load('index.php/?' + season + view);
    });

  });
})(jQuery);
