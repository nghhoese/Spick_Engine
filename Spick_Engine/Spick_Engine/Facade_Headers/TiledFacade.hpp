#include <filesystem>
#include <any>
#include <vector>

namespace spic {

	class TiledFacade {
	public:
		/**
		* \brief Reads the tiled file
		*/
		std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>> Read(const std::filesystem::path& path);

		/**
		* \brief Reads the tiles
		*/
		std::vector<std::vector<int>> ReadTiles(const std::vector<uint32_t>& tiles, int width);
	};
}