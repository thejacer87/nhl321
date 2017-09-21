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
      calculateChange (rows, offset) {
        rows.sort(function (a, b) {
          return b.pts - a.pts
        })
        rows.forEach(function (row, index) {
          row.change = row.rank - (index + offset)
        })
        return rows
      },
      createWildcardTable (body, conference, divisionLeaders) {
        let rows = []
        let self = this
        let leaders = []
        divisionLeaders.forEach(function (leader) {
          leaders.push(leader.team)
        })
        // Filter out the division leaders.
        let teams = body.filter(function (team) {
          let conf = team.conference === conference
          let leader = leaders.indexOf(team.team.abbreviation)
          return conf && leader < 0
        })
        teams.forEach(function (row) {
          let wins = row.wins
          let otwins = row.overtime_wins
          let loss = row.losses
          let otloss = row.overtime_losses
          let points = self.calculatePoints(wins, otwins, otloss)
          let standing = {
            team: row.team.abbreviation,
            logo: row.team.logos.small,
            gp: row.games_played,
            w: wins - otwins,
            otw: otwins,
            otl: otloss,
            l: loss,
            pts: points,
            change: '',
            rank: row.conference_rank,
          }
          rows.push(standing)
        })
        return self.calculateChange(rows, 7)
      },
      createTable (body, division) {
        let rows = []
        let self = this
        let teams = body.filter(function (obj) {
          return obj.division === division
        })
        teams.forEach(function (row) {
          let team = row.team.abbreviation
          let logo = row.team.logos.small
          let wins = row.wins
          let otwins = row.overtime_wins
          let loss = row.losses
          let otloss = row.overtime_losses
          let points = self.calculatePoints(wins, otwins, otloss)
          let standing = {
            team: team,
            logo: logo,
            gp: row.games_played,
            w: wins - otwins,
            otw: otwins,
            otl: otloss,
            l: loss,
            pts: points,
            change: '',
            rank: row.division_rank,
          }
          rows.push(standing)
        })
        return self.calculateChange(rows, 1).slice(0, 3)
      },
      calculatePoints (wins, otwins, otloss) {
        return (wins - otwins) * 3 + otwins * 2 + otloss
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

        this.west_wildcard = this.createWildcardTable(response.body, 'Western', this.pacific.concat(this.central))
        this.east_wildcard = this.createWildcardTable(response.body, 'Eastern', this.atlantic.concat(this.metro))
        this.west_wildcard_fields = this.createFields('Wildcard')
        this.east_wildcard_fields = this.createFields('Wildcard')
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

