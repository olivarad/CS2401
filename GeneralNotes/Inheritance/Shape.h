// Company that makes block toys
class Shape{
    public:
        double cost() {return area() * cost_per;}

        //virtual double area() {return 1;} // Virtual Function calling a function with the same signature in the child class (default return of 1)
        virtual double area() = 0; // purely virtual through abstraction
        virtual void input();
    private:
        double cost_per;
};

class Triangle:public Shape{
    public:
        double area() {return 0.5 * base * height;}
        void input();
    private:
        double base;
        double height;
};

class Circle:public Shape{
    public:
        double area() {return radius * radius * 3.14;}
        void input();
    private:   
        double radius;
};

class Rectangle:public Shape{
    public:
        double area() {return base * height;}
        void input();
    private:
        double base;
        double height;
};