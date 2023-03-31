#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <list>

class product{
    public:
        virtual void input(product* p) = 0; // Product selection
        virtual void output(std::ostream outs) = 0; // Outputs data
    private:
};

class shirt:public product{
    public:
        void input(product* p); // Class mutator function
        void output(std::ostream outs);
    private:
        std::string size; // Shirt size
        std::string color; // Shirt color
};

class skirt:public product{
    public:
        void input(product* p); // Class mutator function
        void output(std::ostream outs);
    private:
        std::string size; // Skirt size
        double length; // Skirt length
        std::string color; // Skirt color
};

class heel:public product{
    public:
        void input(product* p); // Class mutator function
        void output(std::ostream outs);
    private:
        double size;
        double height; // Heel height
        std::string color; // Product color
};

class ears:public product{
    public:
        void input(product* p); // Class mutator function
        void output(std::ostream outs);
    private:
        std::string animal; // Animal the ears are modeled after
        std::string color; // Product color
};

class knife:public product{
    public:
        void input(product* p); // Class mutator function
        void output(std::ostream outs);
    private:
        double length; // Knife Length
        std::string handle; // Product handle material
};

#endif