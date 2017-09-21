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
    methods: {
      createFields (division) {
        return {
          team: {label: 'Teams'},
          gp: {label: 'GP'},
          w: {label: 'W'},
          otw: {label: 'OTW'},
          otl: {label: 'OTL'},
          l: {label: 'L'},
          pts: {label: 'PTS'},
          change: {label: 'Change'},
        }
      },
      calculateChange (rows) {
        rows.sort(function (a, b) {
          return b.pts - a.pts
        })
        rows.forEach(function (row, index) {
          console.log(index + ': ' + row.rank)
          row.change = row.rank - (index + 1)
        })
        return rows
      },
      createTable (body) {
        let rows = []
        let self = this
        console.log(body)
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
            w: wins - otwins,
            otw: otwins,
            otl: otloss,
            l: loss,
            pts: points,
            change: '',
            rank: row.league_rank,
          }
          rows.push(standing)
        })
        return self.calculateChange(rows)
      },
      calculatePoints (wins, otwins, otloss) {
        return (wins - otwins) * 3 + otwins * 2 + otloss
      },
    },
    created: function () {
      this.$http.get('https://api.thescore.com/nhl/standings').then(response => {
        // success callback
        this.standings = this.createTable(response.body)
        this.fields = this.createFields()
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

