#include "json.hpp"

std::string folder_path2 = fs::current_path();

// Json::Json()
// {
// }

// Json::~Json()
// {
// }

int Json::openJson(std::string json_path)
{
    std::ifstream fJson(json_path);
    j = json::parse(fJson);

}

void Json::printJson()
{
    for (auto it = j.begin(); it != j.end(); ++it)
    {
        std::cout << "key: " << it.key() << '\n';
    }
}

void Json::teste()
{
    std::cout << "teste";
}