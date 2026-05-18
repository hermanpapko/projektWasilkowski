#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(int x, int y, char symbol, const std::string& name);
    virtual ~Item() = default;

    int getX() const { return m_x; }
    int getY() const { return m_y; }
    char getSymbol() const { return m_symbol; }
    std::string getName() const { return m_name; }

protected:
    int m_x;
    int m_y;
    char m_symbol;
    std::string m_name;
};

#endif
