<template>
  <div id="app">
    <div class="container">
      <app-header></app-header>
      <router-view></router-view>
    </div>
    <app-footer></app-footer>
  </div>
</template>

<script>
  import AppHeader from '@/components/AppHeader'
  import AppFooter from '@/components/AppFooter'

  export default {
    name: 'app',
    components: {
      AppHeader,
      AppFooter,
    },
  }
</script>

<style lang="scss">
  @import 'assets/styles/style';
  #app {
    font-family: 'Avenir', Helvetica, Arial, sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }
</style>
