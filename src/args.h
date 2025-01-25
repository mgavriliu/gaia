
#pragma once
#include <stdexcept>
#include <string>

class Args {
 public:
  static Args parse(int argc, char* argv[]) {
    if (argc < 2) {
      throw std::runtime_error("Usage: " + std::string(argv[0]) + " <json_file>");
    }
    return Args{argv[1]};
  }

  const std::string& getJsonFile() const { return jsonFile; }

 private:
  Args(const std::string& jsonFile) : jsonFile(jsonFile) {}
  std::string jsonFile;
};