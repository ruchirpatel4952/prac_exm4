class Spot {
private:
    std::tuple<int, int> location;
    char category;

public:
    // Constructor
    Spot(int x, int y, char category) : location(x, y), category(category) {}

    // Virtual Destructor
    virtual ~Spot() {}

    // Getters
    std::tuple<int, int> getLoc() const { return location; }
    char getCategory() const { return category; }

    // Setters
    void setLoc(int x, int y) { location = std::make_tuple(x, y); }
    void setCategory(char category_val) { category = category_val; }
};
