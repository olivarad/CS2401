#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class product{
    public:
        double cost(); // Outputs cost
        virtual void output(); // Outputs data
        virtual void input(); // Product selection
    private:
        double cost_per; // Cost per item
};

class shirt:public product{
    public:
        void input(); // Class mutator function
        void output();
        //std::string get_size(); // Size accsessor function
        //std::string get_color(); // Color accsessor function
    private:
        double cost; // Product price
        std::string size; // Shirt size
        std::string color; // Shirt color
};

class skirt:public product{
    public:
        void input(); // Class mutator function
        void output();
        //std::string get_size(); // Size accsessor function
        //double get_length(); // Length accsessor function
        //std::string get_color(); // Color accsessor function
    private:
        double cost; // Product price
        std::string size; // Skirt size
        double length; // Skirt length
        std::string color; // Skirt color
};

class heel:public product{
    public:
        void input(); // Class mutator function
        void output();
        //double get_size(); // Size accsessor function
        //double get_height(); // Heel height accsessor function
        //std::string get_color(); // Color accsessor function
    private:
        double cost; // Product price
        double size; // European sizing
        double height; // Heel height
        std::string color; // Product color
};

class ears:public product{
    public:
        void input(); // Class mutator function
        void output();
        //std::string get_animal(); // Animal ear accessor function
        //std::string get_color(); // Color accsessor function
    private:
        double cost; // Product price
        std::string animal; // Animal the ears are modeled after
        std::string color; // Product color
};

class knife:public product{
    public:
        void input(); // Class mutator function
        void output();
        //double get_length(); // Size accsessor function
        //std::string get_handle(); // Handle material accsessor function
    private:
        double cost; // Product price
        double length; // Knife Length
        std::string handle; // Product handle material
};

#endif