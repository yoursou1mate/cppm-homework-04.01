//
//  main.cpp
//  cppm-homework-04.01
//
//  Created by a1ex on 6/20/23.
//

#include <iostream>
#include <fstream>
#include <string>


class address
{
private:
    std::string city;
    std::string street;
    int house;
    int appartment;

public:
    address (std::string city, std::string street, int house, int appartment)
    {
        this->city = city;
        this->street = street;
        this->house = house;
        this->appartment = appartment;
    }
    address ()
    {
        city = "Неизвестно";
        street = "Неизвестно";
        house = 1;
        appartment = 1;
    }

    
   std::string get_output_address ()
    {
       std::string full_address;
       std::string house_1 = std::to_string(house);
       std::string appartment_1 = std::to_string(appartment);
       full_address.append(city).append(", ").append(street).append(", ").append(house_1).append(", ").append(appartment_1);
       return full_address;
   }
};


int main(int argc, const char * argv[]) {
    
    std::locale::global(std::locale("ru_RU.UTF-8"));
    int n;
    std::string line;
    
    std::ifstream fin ("in.txt");
    
    if (fin.is_open())
    {
        while (std::getline(fin, line))
        {
            std::cout << line << std::endl;
        }
    } else
    {
        std::cout << "Error while opening file" << std::endl;
        return (0);
    }
    
    fin.close();
    
    
    std::string c;
    std::string s;
    int h;
    int a;
    address Address;

    fin.open("in.txt");
    fin >> n;
    address* arr = new address[n];
    
    for (int i = 0; i<n; ++i)
    {
        fin >> c >> s >> h >> a;
        address Address (c,s,h,a);
        arr[i] = Address;
        std::cout << Address.get_output_address() << std::endl;
    }
    
    std::ofstream fout ("out.txt");

    fout << n << std::endl;
    for (int i = n-1; i>=0; --i)
    {
        fout << arr[i].get_output_address() << std::endl;
    }
    return 0;
}




//#include <iostream>
//#include <unistd.h>
//#include <limits.h>
//
//int main() {
//    char cwd[PATH_MAX];
//    if (getcwd(cwd, sizeof(cwd)) != NULL) {
//        std::cout << "Текущий рабочий каталог: " << cwd << std::endl;
//    } else {
//        perror("getcwd() error");
//        return 1;
//    }
//    return 0;
//}
