<template>
  <div class="divsion">
    <div class="col-md-6">
      <h2>West</h2>
      <b-table striped head-variant="inverse" id="pacific"
               :items="pacific" :fields="pacific_fields">
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
      <b-table striped head-variant="inverse" id="central"
               :items="central" :fields="central_fields">
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
      <h2>East</h2>
      <b-table striped head-variant="inverse" id="atlantic"
               :items="atlantic" :fields="atlantic_fields">
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
      <b-table striped head-variant="inverse" id="metropolitan"
               :items="metro" :fields="metro_fields">
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
    name: 'division',
    data () {
      return {
        pacific: [],
        pacific_fields: [],
        central: [],
        central_fields: [],
        atlantic: [],
        atlantic_fields: [],
        metro: [],
        metro_fields: [],
      }
    },
    created: function () {
      this.$http.get('https://api.thescore.com/nhl/standings').then(response => {
        // success callback
        this.pacific_fields = this.getTableFields('Pacific')
        this.central_fields = this.getTableFields('Central')
        this.atlantic_fields = this.getTableFields('Atlantic')
        this.metro_fields = this.getTableFields('Metropolitan')
        this.pacific = this.createTable(response.body, 'division', 'Pacific', 'division_rank', 1)
        this.central = this.createTable(response.body, 'division', 'Central', 'division_rank', 1)
        this.atlantic = this.createTable(response.body, 'division', 'Atlantic', 'division_rank', 1)
        this.metro = this.createTable(response.body, 'division', 'Metropolitan', 'division_rank')
      }, response => {
        // error callback
        this.error = response
      })
    },
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style lang="scss" scoped>
  @import '../../assets/styles/partials/variables';
</style>

