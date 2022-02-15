class ComplexNumbers
{

private:
    int real;
    int imag;

public:
    ComplexNumbers(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void print()
    {
        cout << real << " + "
             << "i" << imag << endl;
    }

    void plus(ComplexNumbers const &c2)
    {
        this->real = real + c2.real;
        this->imag = imag + c2.imag;
    }

    void multiply(ComplexNumbers const &c2)
    {
        int x = (real * c2.real) - (imag * c2.imag);
        int y = (real * c2.imag) + (imag * c2.real);
        real = x;
        imag = y;
    }
};
