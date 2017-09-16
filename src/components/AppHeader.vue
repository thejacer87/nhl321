<template>
  <header class="app-header">
    <h1>NHL 321 Standings</h1>
    <h5>What if the NHL had 3 point games...</h5>
  </header>
</template>

<script>
  export default {
    name: 'app-header',
    data () {
      return {}
    },
  }
</script>

<style lang="scss" scoped>
  @import '../assets/styles/partials/mixins';
  @import '../assets/styles/partials/variables';

  header {
    background-color: #2d2d2d;
    color: #fff;
    padding: 20px;
    text-align: center;
    margin-bottom: 15px;
    position: relative;
  }
</style>
