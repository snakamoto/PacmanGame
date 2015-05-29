#include "tiledmap.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QDebug>
#include <QXmlQuery>
#include <QList>

TiledMap::TiledMap()
{
}

TiledMap::TiledMap(QString fileName)
{
    filename = fileName;
}

void TiledMap::LoadCollisionLayer(TileNode **grid, int TILES_X)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QXmlQuery query;
    query.bindVariable("kmlFile", &file);

    //query.setQuery("declare default element namespace \"http://earth.google.com/kml/2.0\"; declare variable $kmlFile external; doc($kmlFile)/kml/Document/Placemark[last()]/GeometryCollection/LineString/coordinates/text()");

    query.setQuery("declare variable $kmlFile external; doc($kmlFile)/map/objectgroup[@name='Collision']/object");


    QString result;

    query.evaluateTo(&result);
    file.close();


    TileNode *pathingArr = *grid;

    QList<QString> results = result.split('\n');
    for(int i = 0; i < results.size(); i++)
    {
        //qDebug() << results[i];
        QXmlStreamReader reader(results[i]);
        reader.readNextStartElement();


        if(reader.tokenString() == "StartElement")
        {
            int xi = reader.attributes().at(1).value().toInt();
            int yi = reader.attributes().at(2).value().toInt();
            int wi = reader.attributes().at(3).value().toInt();
            int hi = reader.attributes().at(4).value().toInt();
            qDebug() << xi << yi << wi << hi;

            for(int x = xi; x<xi+wi; x+=32)
            {
                for(int y=yi; y<yi+hi; y+=32)
                {
                    int i = x / 32;
                    int j = y / 32;
                    pathingArr[j*TILES_X + i].type = TileNode::WALL;
                }
            }


        }
    }
}

vector<Tileset*> TiledMap::LoadTilesets()
{
    vector<Tileset*> sets;

    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QXmlQuery query;
    query.bindVariable("kmlFile", &file);

    query.setQuery("declare variable $kmlFile external; doc($kmlFile)/map/tileset");

    QString result;

    query.evaluateTo(&result);
    file.close();

    Tileset *tileset = new Tileset();

    QList<QString> results = result.split('\n');
    for(int i = 0; i < results.size(); i++)
    {
        QString res = results[i];

        if(res.size() < 2)
            continue;

        //qDebug() << results[i];
        QXmlStreamReader reader(results[i]);
        reader.readNextStartElement();

        if(reader.tokenString() == "StartElement")
        {
            if(res.contains("<image"))//Image
            {
                QString img = reader.attributes().at(0).value().toString();
                int width = reader.attributes().at(2).value().toInt();
                int height = reader.attributes().at(3).value().toInt();
                tileset->h = height;
                tileset->w = width;
                tileset->src = img;
                sets.push_back(tileset);
                qDebug() << tileset->id << img << width << height;
                tileset = new Tileset();


            }
            else
            {
                int gid = reader.attributes().at(0).value().toInt();
                tileset->id = gid;
            }

        }
    }
    return sets;
}

int* TiledMap::LoadTiles()
{
      int* tiles = 0;
      tiles = new int[TILES_Y*TILES_X];

      for(int x = 0; x < TILES_X; x++)
          for(int y = 0; y< TILES_Y; y++)
          {
              tiles[y*W+x] = 0;
          }


      QFile file(filename);
      file.open(QIODevice::ReadOnly);

      QXmlQuery query;
      query.bindVariable("kmlFile", &file);

      query.setQuery("declare variable $kmlFile external; doc($kmlFile)/map/layer");

      QString result;

      query.evaluateTo(&result);
      file.close();


      QList<QString> results = result.split('\n');
      QString res = results[0];
      QXmlStreamReader reader(res);
      reader.readNextStartElement();
      QString name = reader.attributes().at(0).value().toString();
      int width = reader.attributes().at(1).value().toInt();
      int height = reader.attributes().at(2).value().toInt();
      int x = 0;
      int y = 0;


      QFile file2(filename);
      file2.open(QIODevice::ReadOnly);
      query = QXmlQuery();
      query.bindVariable("kmlFile", &file2);
      query.setQuery("declare variable $kmlFile external; doc($kmlFile)/map/layer[@name='Image']/data/tile");
      result = QString();
      query.evaluateTo(&result);
      file2.close();


      results.clear();
      results = result.split('\n');
      for(int i = 0; i < results.size(); i++)
      {

          QString res = results[i];
          QXmlStreamReader reader(results[i]);
          reader.readNextStartElement();
          if(reader.tokenString() == "StartElement")
          {
                  int gid = reader.attributes().at(0).value().toInt();
                  tiles[y*W+x] = gid;
          }

          x++;
          if(x==width)
          {
              x=0;
              y++;
          }
      }



      return tiles;
}
