#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class massiv
{
public:
    std::vector <double> mass;
    int n;

    // create mass
    void new_mass()
    {
        double temp;

        std::cin >> n;

        for (int i = 0; i < n; i++)
        {
            std::cin >> temp;
            mass.push_back(temp);
        }

        std::cout << mass.size() << std::endl;
        result_cout();

        menu();
    }

private:
    // choose action
    void menu()
    {
        int point = -1;

        while (point != 0)
        {
            std::cin >> point;

            if (point == 0)
            {
                break;
            }
            else if (point == 1)
            {
                add_el();
            }
            else if (point == 2)
            {
                del_el();
            }

            result_cout();
        }
    }

    // new element
    void add_el()
    {
        double temp;
        std::cin >> temp;

        mass.push_back(temp);

        std::cout << "+: " << mass.size() << std::endl;
    }

    // delete element
    void del_el()
    {
        mass.pop_back();

        std::cout << "-: " << mass.size() << std::endl;
    }

    // summa and arith
    void math_methods()
    {
        double summ = 0, arith_mean = 0;

        for (int i = 0; i < mass.size(); i++)
        {
            summ += mass[i];
        }

        arith_mean = summ / mass.size();

        mass.push_back(summ);
        mass.push_back(arith_mean);
    }

    // dop quest
    void dop_quest()
    {
        double fOtr = 0, sOtr = 0, mnoj = 1;

        for (int i = 0; i < mass.size(); i++)
            if (mass[i] < 0)
            {
                fOtr = mass[i];
                break;
            }

        for (int i = mass.size() - 1; i >= 0; i--)
            if (mass[i] < 0)
            {
                sOtr = mass[i];
                break;
            }

        if (fOtr != 0 && sOtr != 0)
        {
            mnoj = 2 * (fOtr + sOtr);

            for (int i = 2; i < mass.size(); i += 3)
            {
                mass[i] *= mnoj;
            }
        }
    }

    // print
    void result_cout()
    {
        print_mass();

        math_methods();
        print_mass();

        dop_quest();
        print_mass();
    }
    // print mass
    void print_mass()
    {
        //std::cout.setf(std::ios::fixed);
        //std::cout.precision(3);

        std::cout << std::setprecision(3) << std::fixed;
        for (int i = 0; i < mass.size(); i++)
        {
            std::cout << mass[i] << ' ';
        }
        std::cout << std::endl;
    }
};


int main()
{
    massiv M;

    M.new_mass();

    return 0;
}