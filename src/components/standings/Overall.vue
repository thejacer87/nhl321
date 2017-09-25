<template>
  <div class="overall">
    <h2>League Standings</h2>
    <b-table striped head-variant="inverse" id="overall"
             :items="standings" :fields="fields">
      <template slot="team" scope="data">
        {{ data.index + 1 }}<img class="logo "
                                 :src="data.item.logo">{{ data.item.team }}
      </template>
      <template slot="change" scope="data">
          <span class="change"
                :class="data.item.change > 0 ? 'change-up' : 'change-down'">
            <div class="arrow"
                 :class="data.item.change > 0 ? 'arrow-up' : data.item.change < 0 ? 'arrow-down' : ''"></div>
            {{ data.item.change ? Math.abs(data.item.change) : '' }}</span>
      </template>
    </b-table>
  </div>
</template>

<script>
  export default {
    name: 'overall',
    data () {
      return {
        standings: [],
        fields: [],
      }
    },
    created: function () {
      this.$http.get('https://api.thescore.com/nhl/standings').then(response => {
        // success callback
        this.standings = this.createTable(response.body, null, null, 'league_rank', 1)
        this.fields = this.getTableFields('Team')
      }, response => {
        // error callback
        this.standings = response
      })
    },
  }

</script>

<style lang="scss" scoped>
  @import '../../assets/styles/partials/variables';
</style>

