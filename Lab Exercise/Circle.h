class Circle {
private:
    int radius;
    int x, y;
public:
    Circle ();
    ~Circle ();
    void setRadius (int);
    int getRadius ();
    void setPos (int, int);
    void getPos (int&, int&);  
};
