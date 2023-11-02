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
//    address ()
//    {
//        city = "Неизвестно";
//        street = "Неизвестно";
//        house = 1;
//        appartment = 1;
//    }
//
    void write_address ()
    {
        std::ifstream fin ("in.txt");
        fin >> city;
        fin >> street;
        fin >> house;
        fin >> appartment;
    }
    
   std::string get_output_address ()
    {
       std::string full_address;
        return full_address;
    }
};


int main(int argc, const char * argv[]) {
    
    setlocale(LC_ALL,"Russian");
    int n = 13;
    std::string line;
    
    std::ifstream fin ("in.txt");
    
    fin.open("in.txt");
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

    fin.open("in.txt");
    fin >> n;
    int *arr1 = new int[n]{};
    for (int i = 0; i<n; ++i)
    {
        fin >> arr1[i];
    }

    std::cout << arr1[n] << std::endl;
//    address Address("Город", "Улица", 1, 1);
//
//    for (int i = n; i>0 ; ++i)
//    {
//      Address.write_address();
//    }
//
//    Address.get_output_address();

    return 0;
}
