(function ($) {
  $(function () {
    var $loading = $('#loading').hide();
    $(document)
        .ajaxStart(function () {
          $loading.show();
        })
        .ajaxStop(function () {
          $loading.hide();
        });

    $('select#season').change(function () {
      var season = 'season=' + this.value;
      var view = '&view=' + $('#standings .nav li.active a').attr('id');
      $('.icon').remove();
      $('body').load('?' + season + view);
    });

    $('.tie-breaker-wrapper h3').click(function () {
      $('.tie-breaker-wrapper .icon').toggleClass('transform');
    });

    $('.points-breakdown-wrapper h3').click(function () {
      $('.points-breakdown-wrapper .icon').toggleClass('transform');
    });
  });
})(jQuery);
