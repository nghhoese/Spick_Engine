#include "../Facade_Headers/Tileson/tileson.hpp"
#include "../Facade_Headers/TiledFacade.hpp"

using namespace spic;

TiledFacade::TiledFacade() {}

std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> TiledFacade::Read(const std::filesystem::path& path)
{
    tson::Tileson parser;
    std::unique_ptr<tson::Map> map;

    try {
        map = parser.parse(path);

        if (map->getStatus() != tson::ParseStatus::OK) {
            throw std::exception();
        }
    }
    catch (std::exception e) {
        throw std::runtime_error("Something went wrong parsing the level file");
    }

    std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> _retVal = {};
    std::vector<std::pair<int, std::vector<std::vector<int>>>> tiles = {};
    std::vector<std::vector<std::pair<std::string, std::any>>> objects = {};

    for (auto& layer : map->getLayers())
    {
        if (layer.getType() == tson::LayerType::TileLayer) {
            int width = map->getSize().x;

            std::pair<int, std::vector<std::vector<int>>> new_tile_layer{ layer.getId(), ReadTiles(layer.getData(), width) };

            tiles.push_back(new_tile_layer);
        }
        else if (layer.getType() == tson::LayerType::ObjectGroup)
        {
            for (auto& obj : layer.getObjects())
            {
                std::vector<std::pair<std::string, std::any>> _obj = {};
                _obj.push_back({ "id", obj.getId() });
                _obj.push_back({ "type", obj.getType() });
                _obj.push_back({ "name", obj.getName() });

                const tson::Vector2i pos = obj.getPosition();
                _obj.push_back({ "position", std::tuple<int,int>(pos.x, pos.y) });

                for (std::pair<std::string, tson::Property> prop : obj.getProperties().getProperties()) {
                    _obj.push_back({ prop.first, prop.second.getValue() });
                }

                objects.push_back(_obj);
            }
        }
    }

    _retVal.first = tiles;
    _retVal.second = objects;

    return _retVal;

}

std::vector<std::vector<int>> TiledFacade::ReadTiles(const std::vector<uint32_t>& tiles, int width)
{
    std::vector<int> row = {};
    std::vector<std::vector<int>> rows = {};

    int curwidth = 0;
    for (uint32_t i : tiles) {
        row.push_back(--i);
        ++curwidth;

        if (curwidth == width) {
            rows.push_back(row);
            curwidth = 0;
            row.clear();
        }
    }

    return rows;
}
