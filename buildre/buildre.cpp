#include <iostream>

class ProductPartA {};
class ProductPartB {};

class Product {
public:
    void addPartA(ProductPartA* part) {}
    void addPartB(ProductPartB* part) {}

    void show() {
        std::cout << "Product built with parts A and B" << std::endl;
    }
};

class Builder {
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product* getResult() = 0;
};

class ConcreteBuilder : public Builder {
private:
    Product* product;

public:
    ConcreteBuilder() : product(new Product()) {}

    void buildPartA() override {
        // Логіка створення частини A
        product->addPartA(new ProductPartA());
    }

    void buildPartB() override {
        // Логіка створення частини B
        product->addPartB(new ProductPartB());
    }

    Product* getResult() override {
        return product;
    }
};

class Director {
private:
    Builder* builder;

public:
    Director(Builder* builder) : builder(builder) {}

    void construct() {
        builder->buildPartA();
        builder->buildPartB();
    }
};

int main() {
    Builder* builder = new ConcreteBuilder();
    Director director(builder);

    director.construct();
    Product* product = builder->getResult();
    product->show();

    // Очищення пам'яті
    delete product;
    delete builder;

    return 0;
}
