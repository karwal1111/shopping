#include <iostream>
#include <string>
#include <vector>

struct Product {
    std::string name;
    double price;
    int quantity;
};

class ShoppingCart {
private:
    std::vector<Product> items;

public:
    void addProduct(const Product& product) {
        items.push_back(product);
    }

    void removeProduct(int index) {
        if (index >= 0 && index < items.size()) {
            items.erase(items.begin() + index);
        }
    }

    double getTotalPrice() const {
        double totalPrice = 0.0;
        for (const auto& product : items) {
            totalPrice += product.price * product.quantity;
        }
        return totalPrice;
    }

    void displayItems() const {
        std::cout << "Shopping Cart:\n";
        for (int i = 0; i < items.size(); ++i) {
            const Product& product = items[i];
            std::cout << i + 1 << ". " << product.name << " - $" << product.price << " x " << product.quantity << "\n";
        }
        std::cout << "Total Price: $" << getTotalPrice() << "\n";
    }
};

int main() {
    Product product1{"Shirt", 19.99, 2};
    Product product2{"Jeans", 29.99, 1};
    Product product3{"Shoes", 49.99, 1};

    ShoppingCart cart;
    cart.addProduct(product1);
    cart.addProduct(product2);
    cart.addProduct(product3);

    cart.displayItems();

    cart.removeProduct(1);

    cart.displayItems();

    return 0;
}
