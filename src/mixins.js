export default {
  methods: {
    calculatePoints (wins, otwins, otloss) {
      return (wins - otwins) * 3 + otwins * 2 + otloss
    },
    reseed (rows, offset) {
      rows.sort(function (a, b) {
        return b.pts - a.pts
      })
      rows.forEach(function (row, index) {
        row.change = row.rank - (index + offset)
      })
      return rows
    },
    getTableFields (label) {
      return {
        team: {label: label},
        gp: {label: 'GP'},
        w: {label: 'W'},
        otw: {label: 'OTW'},
        otl: {label: 'OTL'},
        l: {label: 'L'},
        pts: {label: 'PTS'},
        change: {label: 'Change'},
      }
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
      return self.reseed(rows, 7)
    },
    /**
     * Converts the body response from api.thescore.ca, to a usable format for
     * bootstrap tables.
     * @param {array} body - The array of NHL team info.
     * @param {string} standingsType - The type of standings (ie Division,
     *     Conference, etc.).
     * @param {string} value - The value associated with the standingsType (ie
     *     Pacific, Eastern, etc.).
     * @param {string} rank - The rankings to reseed.
     * @param {number} offset - The offset needed for reseeding.
     * @param {boolean} divisionLeaderFlag - Flag determines if we slice just
     *     the top 3 teams.
     * @returns {array} - The teams reseeded.
     */
    createTable (body, standingsType, value, rank, offset, divisionLeaderFlag) {
      let rows = []
      let teams = []
      let self = this
      if (standingsType !== null) {
        teams = body.filter(function (obj) {
          return obj[standingsType] === value
        })
      } else {
        teams = body
      }
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
          rank: row[rank],
        }
        rows.push(standing)
      })
      return !divisionLeaderFlag ? self.reseed(rows, offset) : self.reseed(rows, offset).slice(0, 3)
    },
  }
  ,
}
