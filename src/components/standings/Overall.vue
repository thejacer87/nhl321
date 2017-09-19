<template>
  <div class="overall">
    <h2>League Standings</h2>
    <b-table striped head-variant="inverse" id="overall"
             :items="standings" :fields="fields"
             sort-by.sync="pts">
      <template slot="team" scope="data">
        <img class="logo " :src="data.item.logo">{{ data.item.team }}
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
    methods: {
      createTable (body) {
        let rows = []
        let self = this
        body.forEach(function (row) {
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
        this.standings = this.createTable(response.body)
        this.fields = {
          team: {label: 'Teams'},
          gp: {label: 'GP'},
          w: {label: 'W'},
          otw: {label: 'OTW'},
          otl: {label: 'OTL'},
          l: {label: 'L'},
          pts: {label: 'PTS'},
          change: {label: 'Change'},
        }
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

