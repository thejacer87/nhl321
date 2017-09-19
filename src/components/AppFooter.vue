<template>
  <footer class="text-center app-footer">
    <!--<p>-->
    <!--NHL 321 is proudly ad free. Please consider donating to help keep it that way :)</p>-->
    <!--<p>-->

    <!--<form action="https://www.paypal.com/cgi-bin/webscr" method="post"-->
    <!--target="_top">-->
    <!--<input type="hidden" name="cmd" value="_s-xclick">-->
    <!--<input type="hidden" name="hosted_button_id" value="R5T824CL2PSPG">-->
    <!--<input type="image"-->
    <!--src="https://www.paypalobjects.com/en_US/i/btn/btn_donate_SM.gif"-->
    <!--border="0" name="submit"-->
    <!--alt="PayPal - The safer, easier way to pay online!">-->
    <!--<img alt="" border="0"-->
    <!--src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1"-->
    <!--height="1">-->
    <!--</form>-->
    <!--</p>-->
    <p>&copy; {{ new Date().getFullYear() }} Copyright.</p>
    <p>Created by <a href="https://twitter.com/Thejacer87" target="_blank">@thejacer87</a>
    </p>
    <p><a href="https://github.com/thejacer87/nhl321" target="_blank">View on
      GitHub</a></p>
  </footer>
</template>

<script>
  export default {
    name: 'app-footer',
    data () {
      return {}
    },
  }
</script>

<style lang="scss" scoped>
  @import '../assets/styles/partials/variables';

  footer {
    background-color: #2d2d2d;
    color: #fff;
    padding: 20px;
    text-align: center;
    margin: 0;
    position: relative;

    a {
      &:hover {
        color: #7eb1dc;
      }
    }
  }
</style>
