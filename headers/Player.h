struct Player{
    char firstName[100];
    char secondName[100];
    int points;
};
typedef struct Player Player;

typedef struct Team{
    int nrPlayeri;
    char numeEchipa[100];
    float scorEchipa;
    Player jucator[12];
} Team;