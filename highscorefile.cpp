#include "highscorefile.h"


HighScoreFile::HighScoreFile(QString fileName)
{
    filename = fileName;
    ReadAll();
}

void HighScoreFile::WriteHighscore(QString user, int score)
{
    Highscore s;
    s.user = user.toUtf8().constData();
    s.score = score;
    WriteHighscore(s);
}

void HighScoreFile::WriteHighscore(std::string user, int score)
{
    Highscore s;
    s.user = user;
    s.score = score;
    WriteHighscore(s);
}

void HighScoreFile::WriteHighscore(Highscore score)
{
    scores.push_back(score);
    SortScores();


    QFile file(filename);

    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);


    for(int i = 0; i < scores.size(); i++)
    {
        Highscore curScore = scores[i];
        QString outStr = QString::fromStdString(curScore.user) + "," + QString::number(curScore.score) + "\n";
        out << outStr;
    }

    file.close();
}

const std::vector<Highscore> HighScoreFile::GetScores()
{
    return scores;
}

void HighScoreFile::SortScores()
{
    std::sort (scores.begin(), scores.end(), CompareHighscore());
}

void HighScoreFile::ReadAll()
{
    QFile file(filename);

    scores.clear();

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "ERROR: " + file.errorString();
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        QString user = fields[0];
        int score = fields[1].toInt();

        Highscore h;
        h.user = user.toUtf8().constData();
        h.score = score;
        scores.push_back(h);
    }

    file.close();
    SortScores();
}
