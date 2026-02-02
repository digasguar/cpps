#include <fstream>
#include <iostream>
#include <cstring>

int main(int argc, char*argv[])
{
    if (argc != 4)
        return (0);
    std::string line;
    std::string contentfile;
    size_t pos = 0 ,prev = 0;
    std::string result;
    std::string buscar = argv[2];
    std::fstream file(argv[1]);
    if (!file || strlen(argv[2]) == 0)
        return (0);
    while (std::getline(file, line))
    {
        contentfile.append(line.append("\n"));
    }
    file.close();
    while (contentfile.find(argv[2], prev) != std::string::npos)
    {
        pos = contentfile.find(argv[2], prev);
        result.append(contentfile.substr(prev, pos - prev));
        result.append(argv[3]);
        prev = pos + buscar.length();
    }
    result.append(contentfile, prev);
    std::ofstream file2(strcat(argv[1],".replace"));
    file2 << result;
    file2.close();
    return (0);
}