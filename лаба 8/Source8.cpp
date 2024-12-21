#include <iostream>
#include <string>
#include <limits>

// Базовий клас
class Product {
protected:
    std::string name;       // Назва товару
    int quantity;           // Кількість товару

public:
    Product(const std::string& name = "", int quantity = 0)
        : name(name), quantity(quantity) {}

    // Методи для вводу даних
    virtual void input() {
        std::cout << "Введіть назву товару: ";
        std::cin >> name;

        while (true) {
            std::cout << "Введіть кількість товару: ";
            std::cin >> quantity;

            if (std::cin.fail() || quantity < 0) {
                std::cout << "Некоректне значення. Спробуйте ще раз.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
    }

    // Метод для виводу даних
    virtual void display() const {
        std::cout << "Назва: " << name << ", Кількість: " << quantity;
    }
};

// Дочірній клас
class PricedProduct : public Product {
private:
    struct Details {        // Вкладена структура
        double price;       // Ціна за одиницю
    } details;

public:
    PricedProduct(const std::string& name = "", int quantity = 0, double price = 0.0)
        : Product(name, quantity) {
        details.price = price;
    }

    // Перевизначений метод для вводу даних
    void input() override {
        Product::input(); // Викликаємо метод базового класу

        while (true) {
            std::cout << "Введіть ціну за одиницю товару: ";
            std::cin >> details.price;

            if (std::cin.fail() || details.price < 0) {
                std::cout << "Некоректне значення. Спробуйте ще раз.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
    }

    // Перевизначений метод для виводу даних
    void display() const override {
        Product::display(); // Викликаємо метод базового класу
        std::cout << ", Ціна за одиницю: " << details.price
            << ", Загальна вартість: " << calculateTotal() << '\n';
    }

    // Метод для обчислення загальної вартості
    double calculateTotal() const {
        return quantity * details.price;
    }
};

int main() {
    // Створення об'єкта дочірнього класу
    PricedProduct product;

    std::cout << "Введіть дані про товар:\n";
    product.input(); // Введення даних користувачем

    std::cout << "\nІнформація про товар:\n";
    product.display(); // Вивід даних на екран

    return 0;
}