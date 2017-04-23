create table Conference
(
	conference_ID int not null
		primary key,
	name varchar(7) not null
)
;

create table Division
(
	division_ID int not null
		primary key,
	name varchar(255) not null,
	conference_ID int not null,
	constraint Division_ibfk_1
		foreign key (conference_ID) references nhl321.Conference (conference_ID)
)
;

create index conference_ID
	on Division (conference_ID)
;

create table Standings_2014
(
	wins int not null,
	overtime_wins int not null,
	losses int not null,
	overtime_losses int not null,
	points int not null,
	old_points int not null,
	team_ID int not null,
	old_league_rank int not null,
	old_conference_rank int null,
	old_division_rank int not null,
	old_wildcard_rank int not null,
	games_played int null,
	league_rank int null,
	conference_rank int null,
	wildcard_rank int null,
	division_rank int null,
	constraint team_ID
		unique (team_ID),
	constraint league_rank
		unique (old_league_rank)
)
;

create table Standings_2015
(
	wins int not null,
	overtime_wins int not null,
	losses int not null,
	overtime_losses int not null,
	points int not null,
	old_points int not null,
	team_ID int not null,
	old_league_rank int not null,
	old_conference_rank int null,
	old_division_rank int not null,
	old_wildcard_rank int not null,
	games_played int null,
	league_rank int null,
	conference_rank int null,
	wildcard_rank int null,
	division_rank int null,
	constraint team_ID
		unique (team_ID),
	constraint league_rank
		unique (old_league_rank)
)
;

create table Standings_2016
(
	wins int not null,
	overtime_wins int not null,
	losses int not null,
	overtime_losses int not null,
	points int not null,
	old_points int not null,
	team_ID int not null,
	old_league_rank int not null,
	old_conference_rank int null,
	old_division_rank int not null,
	old_wildcard_rank int not null,
	games_played int null,
	league_rank int null,
	conference_rank int null,
	wildcard_rank int null,
	division_rank int null,
	constraint team_ID
		unique (team_ID),
	constraint league_rank
		unique (old_league_rank)
)
;

create table Team
(
	team_ID int not null
		primary key,
	name varchar(255) not null,
	abv varchar(3) not null,
	url varchar(255) not null,
	division_ID int not null,
	conference_ID int not null,
	constraint Team_ibfk_1
		foreign key (division_ID) references nhl321.Division (division_ID),
	constraint Team_ibfk_2
		foreign key (conference_ID) references nhl321.Conference (conference_ID)
)
;

create index conference_ID
	on Team (conference_ID)
;

create index division_ID
	on Team (division_ID)
;

alter table Standings_2014
	add constraint Standings_2014_ibfk_1
		foreign key (team_ID) references nhl321.Team (team_ID)
;

alter table Standings_2015
	add constraint Standings_2015_ibfk_1
		foreign key (team_ID) references nhl321.Team (team_ID)
;

alter table Standings_2016
	add constraint Standings_2016_ibfk_1
		foreign key (team_ID) references nhl321.Team (team_ID)
;

