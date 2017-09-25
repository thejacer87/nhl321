<template>
  <div class="conference">
    <h2>Conference Standings</h2>
    <div class="col-md-6">
      <b-table striped head-variant="inverse" id="western"
               :items="west" :fields="west_fields">
        <template slot="team" scope="data">
          {{ data.index + 1 }}<img class="logo"
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
    <div class="col-md-6">
      <b-table striped head-variant="inverse" id="eastern"
               :items="east" :fields="east_fields">
        <template slot="team" scope="data">
          {{ data.index + 1 }}<img class="logo"
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
  </div>
</template>

<script>
  export default {
    name: 'conference',
    data () {
      return {
        west: [],
        west_fields: [],
        east: [],
        east_fields: [],
      }
    },
    created: function () {
      this.$http.get('https://api.thescore.com/nhl/standings').then(response => {
        // success callback
        this.west = this.createTable(response.body, 'conference', 'Western', 'conference_rank', 1)
        this.west_fields = this.getTableFields('Western')
        this.east = this.createTable(response.body, 'conference', 'Eastern', 'conference_rank', 1)
        this.east_fields = this.getTableFields('Eastern')
        console.log(response.body)
      }, response => {
        // error callback
        this.standings = response
      })
    },
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="scss" scoped>
  @import '../../assets/styles/partials/variables';
</style>

