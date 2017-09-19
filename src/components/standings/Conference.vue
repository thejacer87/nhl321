<template>
  <div class="conference">
    <h2>Conference Standings</h2>
    <div class="col-md-6">
      <b-table striped head-variant="inverse" id="western"
               :items="west" :fields="west_fields"
               sort-by.sync="pts">
        <template slot="team" scope="data">
          <img class="logo " :src="data.item.logo">{{ data.item.team }}
        </template>
      </b-table>
    </div>
    <div class="col-md-6">
      <b-table striped head-variant="inverse" id="eastern"
               :items="east" :fields="east_fields"
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
    name: 'conference',
    data () {
      return {
        west: [],
        west_fields: [],
        east: [],
        east_fields: [],
      }
    },
    methods: {
      createFields (conference) {
        return {
          team: {label: conference},
          gp: {label: 'GP'},
          w: {label: 'W'},
          otw: {label: 'OTW'},
          otl: {label: 'OTL'},
          l: {label: 'L'},
          pts: {label: 'PTS'},
          change: {label: 'Change'},
        }
      },
      createTable (body, conference) {
        let rows = []
        let self = this
        let teams = body.filter(function (obj) {
          return obj.conference === conference
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
        this.west = this.createTable(response.body, 'Western')
        this.west_fields = this.createFields('Western')
        this.east = this.createTable(response.body, 'Eastern')
        this.east_fields = this.createFields('Eastern')
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

