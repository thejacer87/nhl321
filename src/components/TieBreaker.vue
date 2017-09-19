<template>
  <div class="tie-breaker-wrapper information">
    <h3>
      <a v-b-toggle.tie-breaker @click="icon = !icon">
        <div class="icon" :class="{transform: icon }">
        <div class="one"></div>
          <div class="two"></div>
        </div>
        Tie-Breaking Procedure</a></h3>
    <b-collapse id="tie-breaker">
      <ol>
        <li>Wins</li>
        <li>Overtime Wins</li>
        <li>I don't know! This is all hypothetical. If you have a suggestion,
          <a href="https://twitter.com/Thejacer87" target="_blank">send me a
            tweet</a>,
          or create an issue on
          <a href="https://github.com/thejacer87/nhl321/issues" target="_blank">GitHub</a>.
        </li>
      </ol>
    </b-collapse>
  </div>
</template>

<script>
  export default {
    name: 'tie-breaker',
    data () {
      return {
        icon: false
      }
    },
  }
</script>

<style lang="scss" scoped>
  @import '../assets/styles/partials/variables';
</style>
