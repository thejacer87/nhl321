<template>
  <div class="divsion">
    <div class="col-md-6">
      <h2>West</h2>
      <b-table striped head-variant="inverse" id="pacific"
               :items="pacific" :fields="pacific_fields"
               sort-by.sync="pts">
        <template slot="team" scope="data">
          <img class="logo " :src="data.item.logo">{{ data.item.team }}
        </template>
      </b-table>
      <b-table striped head-variant="inverse" id="central"
               :items="central" :fields="central_fields"
               sort-by.sync="pts">
        <template slot="team" scope="data">
          <img class="logo " :src="data.item.logo">{{ data.item.team }}
        </template>
      </b-table>
    </div>
    <div class="col-md-6">
      <h2>East</h2>
      <b-table striped head-variant="inverse" id="atlantic"
               :items="atlantic" :fields="atlantic_fields"
               sort-by.sync="pts">
        <template slot="team" scope="data">
          <img class="logo " :src="data.item.logo">{{ data.item.team }}
        </template>
      </b-table>
      <b-table striped head-variant="inverse" id="metropolitan"
               :items="metro" :fields="metro_fields"
               sort-by.sync="pts">
        <template slot="team" scope="data">
          <img class="logo " :src="data.item.logo">{{ data.item.team }}
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
    methods: {
      createFields (division) {
        return {
          team: {label: division},
          gp: {label: 'GP'},
          w: {label: 'W'},
          otw: {label: 'OTW'},
          otl: {label: 'OTL'},
          l: {label: 'L'},
          pts: {label: 'PTS'},
          change: {label: 'Change'},
        }
      },
      createTable (body, division) {
        let rows = []
        let self = this
        let teams = body.filter(function (obj) {
          return obj.division === division
        })
        teams.forEach(function (row) {
          let logo = row.team.logos.small
          let wins = row.wins
          let otwins = row.overtime_wins
          let loss = row.losses
          let otloss = row.overtime_losses
          let points = self.calculatePoints(wins, otwins, otloss)
          let standing = {
            team: row.team.abbreviation,
            logo: logo,
            gp: row.games_played,
            w: wins,
            otw: otwins,
            otl: otloss,
            l: loss,
            pts: points,
            change: '',
          }
          rows.push(standing)
        })
        return rows
      },
      calculatePoints (wins, otwins, otloss) {
        return wins * 3 + otwins * 2 + otloss
      },
    },
    created: function () {
      this.$http.get('https://api.thescore.com/nhl/standings').then(response => {
        // success callback
        this.pacific_fields = this.createFields('Pacific')
        this.central_fields = this.createFields('Central')
        this.atlantic_fields = this.createFields('Atlantic')
        this.metro_fields = this.createFields('Metropolitan')
        this.pacific = this.createTable(response.body, 'Pacific')
        this.central = this.createTable(response.body, 'Central')
        this.atlantic = this.createTable(response.body, 'Atlantic')
        this.metro = this.createTable(response.body, 'Metropolitan')
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

