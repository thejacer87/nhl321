<template>
  <div class="points-breakdown-wrapper information">
    <h3>
      <a v-b-toggle.points-breakdown @click="icon = !icon">
        <div class="icon" :class="{transform: icon }">
          <div class="one"></div>
          <div class="two"></div>
        </div>
        Points Breakdown</a></h3>
    <b-collapse id="points-breakdown">
      <ul>
        <li>Wins (<strong>W</strong>) - <strong>3 points</strong></li>
        <li>OT/SO Wins (<strong>OTW</strong>) - <strong>2
          points</strong></li>
        <li>OT/SO Losses (<strong>OTL</strong>) - <strong>1
          point</strong></li>
        <li>Losses (<strong>L</strong>) - <strong>0 points</strong></li>
      </ul>
    </b-collapse>
  </div>
</template>

<script>
  export default {
    name: 'points-breakdown',
    data () {
      return {
        icon: false
      }
    },
  }
</script>

<style lang="scss" scoped>
  @import '../assets/styles/partials/mixins';
  @import '../assets/styles/partials/variables';
</style>
