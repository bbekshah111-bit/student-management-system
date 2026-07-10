#include<iostream>

using namespace std;

class Tempreture
{
    private:
        float celsius;

    public:
        float fahrenheit;

        Tempreture(float TempretureCelsius)
        {
            celsius = TempretureCelsius;
        }

        float getCelsius()
        {
            return celsius;
        }

        float getFahrenheit()
        {
            return celsius*9/5 + 32;
        }


        void Describe()
        {
            cout << celsius << " degree celsius is " << getFahrenheit() << " fahrenheit";
        }
};


int main()
{
    Tempreture t1(32);
    t1.Describe();


    return 0;
}
