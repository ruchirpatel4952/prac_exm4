
#ifndef SPOT_H
#define SPOT_H
#include <tuple>
class Spot {
private:
    std::tuple<int, int> location;
    char category;

public:
    Spot(int x, int y, char category) : location(x, y), category(category) {}
    virtual ~Spot(){}

    std::tuple<int, int> getLoc() const { return location; }
    char getCategory() const { return category; }

    void setLoc(int x, int y) { location = std::make_tuple(x, y); }
    void setCategory(char category_val) { category = category_val; }
};
#endif
