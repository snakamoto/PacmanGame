#ifndef POWERUP_H
#define POWERUP_H


class PowerUp
{
public:
    PowerUp();
    ~PowerUp();
    const int GetX();
    const int GetY();
    const int GetType();
    const int GetEaten();
    void SetX(int x);
    void SetY(int y);
    void SetType(int t);
    void SetEaten(bool e);
private:
    int x;
    int y;
    int type;
    bool eaten;
};

#endif // POWERUP_H
