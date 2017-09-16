<template>
  <div class="nhl321">
    <h1>NHL 321</h1>
    <h4>Returning soon for 2017/18 season...</h4>
    <div>
      <tabs>
        <tab name="Wild Card">
          <wildcard></wildcard>
        </tab>
        <tab name="Division">
          <division></division>
        </tab>
        <tab name="Conference">
          <conference></conference>
        </tab>
        <tab name="Overall">
          <overall></overall>
        </tab>
      </tabs>
    </div>
  </div>
</template>

<script>
  import Wildcard from '@/components/standings/Wildcard'
  import Division from '@/components/standings/Division'
  import Conference from '@/components/standings/Conference'
  import Overall from '@/components/standings/Overall'

  export default {
    name: 'kickstart',
    components: {
      Wildcard,
      Division,
      Conference,
      Overall,
    },
  }
</script>

<style lang="scss" scoped>
  @import '../assets/styles/partials/mixins';
  @import '../assets/styles/partials/variables';
  @import '../assets/styles/partials/nhl321';
</style>
