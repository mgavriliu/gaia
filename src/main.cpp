#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "args.h"  // Updated include path
#include "gaia_star.h"


using json   = nlohmann::json;
namespace fs = std::filesystem;

fs::path getWorkspacePath() {
  // Get the executable path and go up two levels (build/Debug -> workspace)
  return fs::absolute(fs::current_path()).parent_path().parent_path();
}

json loadJsonFromFile(const std::string& filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    throw std::runtime_error("Unable to open file: " + filepath);
  }
  return json::parse(file);
}

int main(int argc, char* argv[]) {
  try {
    // Parse command line arguments
    Args args = Args::parse(argc, argv);

    // Get the workspace directory and append assets path
    fs::path workspacePath = getWorkspacePath();
    fs::path assetsPath    = workspacePath / "assets";

    // Load the JSON file from command line argument
    json data = loadJsonFromFile((assetsPath / args.getJsonFile()).string());

    // Parse the JSON into GaiaData structure
    GaiaData gaia_data = GaiaData::from_json(data);

    // Print summary of loaded data
    std::cout << "Loaded " << gaia_data.stars.size() << " stars\n";
    std::cout << "Showing first 3 stars:\n\n";

    // Print only first 3 stars
    for (size_t i = 0; i < std::min(size_t(3), gaia_data.stars.size()); ++i) {
      gaia_data.stars[i].print();
    }

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
