#ifndef HIGHSCOREFILE_H
#define HIGHSCOREFILE_H
#include <string>
#include <iostream>

#include "highscore.h"

//STL
#include <vector>
#include <algorithm>

//QT
#include <QDebug>
#include <QFile>
#include <QTextStream>

class HighScoreFile
{
public:
    HighScoreFile(QString fileName);


    void WriteHighscore(std::string user, int score);
    void WriteHighscore(Highscore score);
    void WriteHighscore(QString user, int score);

    const std::vector<Highscore> GetScores();

private:
    void ReadAll();
    void SortScores();
    std::vector<Highscore> scores;
    QString filename;

};

class CompareHighscore
{
public:
    const bool operator()(const Highscore& n1,const Highscore& n2)
    {
        return n1.score > n2.score;
    }

};

#endif // HIGHSCOREFILE_H
