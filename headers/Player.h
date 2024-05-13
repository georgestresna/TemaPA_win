struct Player{
    char* firstName;
    char* secondName;
    int points;
};
typedef struct Player Player;

typedef struct Team{
    int nrPlayeri;
    char numeEchipa[100];
    float scorEchipa;
    Player *jucator;
} Team;