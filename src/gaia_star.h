#pragma once
#include <string>
#include <nlohmann/json.hpp>

class GaiaStar {
public:
    std::string designation;
    long long source_id;
    double ra;
    double dec;
    double parallax;
    double pmra;
    double pmdec;
    double radial_velocity;
    double phot_g_mean_mag;
    double bp_rp;
    
    // JSON deserialization
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(GaiaStar, 
        designation, source_id, ra, dec, parallax, 
        pmra, pmdec, radial_velocity, phot_g_mean_mag, bp_rp)
};

struct GaiaData {
    std::vector<GaiaStar> stars;
    
    static GaiaData from_json(const nlohmann::json& j) {
        GaiaData data;
        // Check if the JSON is an array
        if (j.is_array()) {
            data.stars = j.get<std::vector<GaiaStar>>();
        }
        // If not an array, try to find data field
        else if (j.contains("data")) {
            data.stars = j["data"].get<std::vector<GaiaStar>>();
        }
        else {
            throw std::runtime_error("Invalid JSON format: expected array or object with 'data' field");
        }
        return data;
    }
};
