#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>


void readMapChip(const std::string &path, std::vector<std::vector<int>> &out)
{
    std::ifstream ifs(path);
    if (!ifs)
    {
        std::cerr << "Failed to open file: " << path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ','))
        {
            // trim spaces
            size_t start = cell.find_first_not_of(" \t\r\n");
            size_t end = cell.find_last_not_of(" \t\r\n");
            if (start == std::string::npos)
                cell = "";
            else
                cell = cell.substr(start, end - start + 1);

            if (cell.empty())
                continue;

            try
            {
                int v = std::stoi(cell);
                row.push_back(v);
            }
            catch (...) 
            {
               
                row.push_back(0);
            }
        }
        if (!row.empty())
            out.push_back(row);
    }
}

int main()
{
    const std::string path = "MapChip/MapChip.csv"; 

    std::vector<std::vector<int>> map;

  
    std::thread reader(readMapChip, std::cref(path), std::ref(map));

   
    reader.join();

    if (map.empty())
    {
        std::cout << "No data read from " << path << std::endl;
        return 0;
    }

    
    for (size_t r = 0; r < map.size(); ++r)
    {
        for (size_t c = 0; c < map[r].size(); ++c)
        {
            std::cout << map[r][c];
            if (c + 1 < map[r].size())
                std::cout << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}
