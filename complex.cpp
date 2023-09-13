#include <iostream>

class ComplexNumber
{
private:
    int real;
    int imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    ComplexNumber operator+(ComplexNumber &other)
    {
        return ComplexNumber(this->real + other.real, this->imaginary + other.imaginary);
    }
    ComplexNumber operator-(ComplexNumber &other)
    {
        return ComplexNumber(this->real - other.real, this->imaginary - other.imaginary);
    }
    void set_real(int real)
    {
        this->real = real;
    }
    void set_imaginary(int imaginary)
    {
        this->imaginary = imaginary;
    }
    void print()
    {
        std::cout << this->real << " + " << this->imaginary << "i" << std::endl;
    }
};

int main()
{
    ComplexNumber *complex_number = new ComplexNumber(1, 2);

    char menu[] = "1. Set real\n2. Set imaginary\n3. Add\n4. Subtract\n5. Print\n6. Exit\nEnter your choice:";
    while (true)
    {
        int choice;
        std::cout << menu;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int real;
            std::cout << "Enter real: ";
            std::cin >> real;
            complex_number->set_real(real);
            break;
        }
        case 2:
        {
            int imaginary;
            std::cout << "Enter imaginary: ";
            std::cin >> imaginary;
            complex_number->set_imaginary(imaginary);
            break;
        }
        case 3:
        {
            int real, imaginary;
            std::cout << "Enter real: ";
            std::cin >> real;
            std::cout << "Enter imaginary: ";
            std::cin >> imaginary;
            ComplexNumber *other = new ComplexNumber(real, imaginary);
            ComplexNumber result = *complex_number + *other;
            result.print();
            break;
        }
        case 4:
        {
            int real, imaginary;
            std::cout << "Enter real: ";
            std::cin >> real;
            std::cout << "Enter imaginary: ";
            std::cin >> imaginary;
            ComplexNumber *other = new ComplexNumber(real, imaginary);
            ComplexNumber result = *complex_number - *other;

            result.print();
            break;
        }
        case 5:
        {
            complex_number->print();
            break;
        }
        case 6:
            return 0;
        }
    }
}