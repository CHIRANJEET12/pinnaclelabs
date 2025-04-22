#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Product {
public:
    int id;
    string name;
    double price;

    Product(int id, string name, double price) : id(id), name(name), price(price) {}
};

class ECommerceSystem {
private:
    vector<Product> products;
    vector<Product> cart;

public:
    void addProduct(int id, string name, double price) {
        products.emplace_back(id, name, price);
        cout << "Product added: " << name << endl;
    }

    void viewProducts() {
        if (products.empty()) {
            cout << "No products available." << endl;
            return;
        }

        cout << "Available Products:" << endl;
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
        for (const auto& product : products) {
            cout << setw(5) << product.id << setw(20) << product.name << setw(10) << product.price << endl;
        }
    }

    void addToCart(int id) {
        for (const auto& product : products) {
            if (product.id == id) {
                cart.push_back(product);
                cout << "Added to cart: " << product.name << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << "Your Cart:" << endl;
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
        for (const auto& product : cart) {
            cout << setw(5) << product.id << setw(20) << product.name << setw(10) << product.price << endl;
        }
    }

    void checkout() {
        if (cart.empty()) {
            cout << "Your cart is empty. Add items to checkout." << endl;
            return;
        }

        double total = 0;
        cout << "Checkout Summary:" << endl;
        for (const auto& product : cart) {
            total += product.price;
        }
        cout << "Total Amount: $" << total << endl;
        cart.clear();
        cout << "Thank you for your purchase!" << endl;
    }
};

int main() {
    ECommerceSystem system;
    int choice, id;
    string name;
    double price;

    while (true) {
        cout << "\nE-Commerce System Menu:" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. View Products" << endl;
        cout << "3. Add to Cart" << endl;
        cout << "4. View Cart" << endl;
        cout << "5. Checkout" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Product Price: ";
            cin >> price;
            system.addProduct(id, name, price);
            break;
        case 2:
            system.viewProducts();
            break;
        case 3:
            cout << "Enter Product ID to add to cart: ";
            cin >> id;
            system.addToCart(id);
            break;
        case 4:
            system.viewCart();
            break;
        case 5:
            system.checkout();
            break;
        case 6:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}