#include <iostream>
#include <string>
#include <limits>

// ������� ����
class Product {
protected:
    std::string name;       // ����� ������
    int quantity;           // ʳ������ ������

public:
    Product(const std::string& name = "", int quantity = 0)
        : name(name), quantity(quantity) {}

    // ������ ��� ����� �����
    virtual void input() {
        std::cout << "������ ����� ������: ";
        std::cin >> name;

        while (true) {
            std::cout << "������ ������� ������: ";
            std::cin >> quantity;

            if (std::cin.fail() || quantity < 0) {
                std::cout << "���������� ��������. ��������� �� ���.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
    }

    // ����� ��� ������ �����
    virtual void display() const {
        std::cout << "�����: " << name << ", ʳ������: " << quantity;
    }
};

// ������� ����
class PricedProduct : public Product {
private:
    struct Details {        // �������� ���������
        double price;       // ֳ�� �� �������
    } details;

public:
    PricedProduct(const std::string& name = "", int quantity = 0, double price = 0.0)
        : Product(name, quantity) {
        details.price = price;
    }

    // �������������� ����� ��� ����� �����
    void input() override {
        Product::input(); // ��������� ����� �������� �����

        while (true) {
            std::cout << "������ ���� �� ������� ������: ";
            std::cin >> details.price;

            if (std::cin.fail() || details.price < 0) {
                std::cout << "���������� ��������. ��������� �� ���.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else break;
        }
    }

    // �������������� ����� ��� ������ �����
    void display() const override {
        Product::display(); // ��������� ����� �������� �����
        std::cout << ", ֳ�� �� �������: " << details.price
            << ", �������� �������: " << calculateTotal() << '\n';
    }

    // ����� ��� ���������� �������� �������
    double calculateTotal() const {
        return quantity * details.price;
    }
};

int main() {
    // ��������� ��'���� ���������� �����
    PricedProduct product;

    std::cout << "������ ��� ��� �����:\n";
    product.input(); // �������� ����� ������������

    std::cout << "\n���������� ��� �����:\n";
    product.display(); // ���� ����� �� �����

    return 0;
}