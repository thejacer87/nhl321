<template>
  <div class="wildcard">
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
               :items="central" :fields="central_fields"
               sort-by.sync="pts">
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
      <b-table striped head-variant="inverse" id="west_wildcard"
               :items="west_wildcard" :fields="west_wildcard_fields"
               sort-by.sync="pts" class="wildcard">
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
               :items="atlantic" :fields="atlantic_fields"
               sort-by.sync="pts">
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
               :items="metro" :fields="metro_fields"
               sort-by.sync="pts">
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
      <b-table striped head-variant="inverse" id="east_wildcard"
               :items="east_wildcard" :fields="west_wildcard_fields"
               sort-by.sync="pts" class="wildcard">
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
    name: 'wildcard',
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
        west_wildcard: [],
        west_wildcard_fields: [],
        east_wildcard: [],
        east_wildcard_fields: [],
      }
    },
    created: function () {
      this.$http.get('https://api.thescore.com/nhl/standings').then(response => {
        // success callback
        this.pacific_fields = this.getTableFields('Pacific')
        this.central_fields = this.getTableFields('Central')
        this.atlantic_fields = this.getTableFields('Atlantic')
        this.metro_fields = this.getTableFields('Metropolitan')
        this.pacific = this.createTable(response.body, 'division', 'Pacific', 'division_rank', 1, true)
        this.central = this.createTable(response.body, 'division', 'Central', 'division_rank', 1, true)
        this.atlantic = this.createTable(response.body, 'division', 'Atlantic', 'division_rank', 1, true)
        this.metro = this.createTable(response.body, 'division', 'Metropolitan', 'division_rank', 1, true)

        this.west_wildcard = this.createWildcardTable(response.body, 'Western', this.pacific.concat(this.central))
        this.east_wildcard = this.createWildcardTable(response.body, 'Eastern', this.atlantic.concat(this.metro))
        this.west_wildcard_fields = this.getTableFields('Wildcard')
        this.east_wildcard_fields = this.getTableFields('Wildcard')
      }, response => {
        // error callback
        this.error = response
      })
    },
  }
</script>

<style lang="scss">
  table.wildcard {
    tr:nth-child(2) {
      border-bottom: 10px solid grey;
    }
  }
</style>

