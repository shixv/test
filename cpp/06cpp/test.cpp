RatedPlayer rplayer(1140,"mallory","Duck",true);
rplayer1.Name();

RatedPlayer rplayer1(1140,"Mallory","Duck",true);
TableTennisPlayer &rt=rplayer;
TableTennisPlayer *pt=&rplayer;
rt.Name();
pt->Name();
