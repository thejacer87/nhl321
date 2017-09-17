<template>
  <div class="nhl321">
    <div>
      <b-tabs pills>
        <b-tab title="Wild Card" active>
          <wildcard></wildcard>
        </b-tab>
        <b-tab title="Division">
          <division></division>
        </b-tab>
        <b-tab title="Conference">
          <conference></conference>
        </b-tab>
        <b-tab title="Overall">
          <overall></overall>
        </b-tab>
      </b-tabs>
    </div>
    <points-breakdown></points-breakdown>
    <tie-breaker></tie-breaker>
  </div>
</template>

<script>
  import Wildcard from '@/components/standings/Wildcard'
  import Division from '@/components/standings/Division'
  import Conference from '@/components/standings/Conference'
  import Overall from '@/components/standings/Overall'
  import PointsBreakdown from '@/components/PointsBreakdown'
  import TieBreaker from '@/components/TieBreaker'

  export default {
    name: 'kickstart',
    components: {
      Wildcard,
      Division,
      Conference,
      Overall,
      PointsBreakdown,
      TieBreaker,
    },
  }
</script>

<style lang="scss">
  @import '../assets/styles/partials/mixins';
  @import '../assets/styles/partials/variables';
  @import '../assets/styles/partials/nhl321';
</style>
