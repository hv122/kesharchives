#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecord
{
    std::string Name;
    int Population;
    double Latitude, Longitude;
};

namespace std{

    template<>
    struct hash<CityRecord> // assigns a 64 bit uint to the name of city
    {
        size_t operator()(const CityRecord& key)
        {
            return hash<std::string>()(key.Name);
        }
    };
};


int main()
{
   /* std::vector <CityRecord> cities; // a vector works pretty well, but only allows us to search with index, maps allow for alternate indexing 

    cities.emplace_back("Melbourne", 500000, 2.4, 9.4);
    cities.emplace_back("Berlin", 500000, 2.4, 9.4);
    cities.emplace_back("Paris", 500000, 2.4, 9.4);
    cities.emplace_back("Tokyo", 500000, 2.4, 9.4);
    cities.emplace_back("London", 500000, 2.4, 9.4);

    for(const auto& city : cities)
    {
        if (city.Name == "Berlin")
        {
            city.Population;
            break; // leaves the for loop when Berlin found
        }
        
    }*/

    std::map<CityRecord, int> foundedMap; // unable to hash CityRecord, so we need to provide a hash function for it

    foundedMap[CityRecord{"Melbourne", 500000, 2.4, 9.4}] = 1850;

    std::map<std::string, CityRecord> cityMap; // ordered alphabetically
    cityMap["Melbourne"] = CityRecord {"Melbourne", 500000, 2.4, 9.4};
    cityMap["London"] = CityRecord {"London", 500000, 2.4, 9.4};
    cityMap["Tokyo"] = CityRecord {"Tokyo", 500000, 2.4, 9.4};
    cityMap["Paris"] = CityRecord {"Paris", 500000, 2.4, 9.4};
    cityMap["Berlin"] = CityRecord {"Berlin", 500000, 2.4, 9.4};

    CityRecord& berlinData = cityMap["Berlin"]; // if Berlin wasn't in the cityMap, this syntax would create a record for it and then return the new record

    const auto& cities = cityMap;
    if(cities.find("Berlin") != cities.end()) // this if loop is used to prevent a crash, using .at(), when Berlin is not present
    {
        const CityRecord& berlinData = cities.at("Berlin"); // .at() is used when you don't want to create a record if it is missing
    }
    // As maps are not contiguous memory, it is not recommended to iterate through them, however it has to be used


    for (auto& [name, city] : cityMap)
    {
        std::cout << name << "\n Population: " << city.Population << std::endl;

    }

    std::cin.get();
    
}
