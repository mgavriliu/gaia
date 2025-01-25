#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

class GaiaStar {
 public:
  // Core identifier fields
  std::string designation;  // Unique source designation
  int64_t     source_id;    // Unique source identifier

  // Position and motion fields
  double ra;              // Right ascension (deg)
  double dec;             // Declination (deg)
  double parallax;        // Parallax (mas)
  float  parallax_error;  // Standard error of parallax (mas)
  double pmra;            // Proper motion in RA (mas/yr)
  double pmdec;           // Proper motion in Dec (mas/yr)
  float  ruwe;            // Renormalised unit weight error

  // Photometric fields
  float phot_g_mean_mag;   // G-band mean magnitude (mag)
  float phot_bp_mean_mag;  // BP mean magnitude (mag)
  float phot_rp_mean_mag;  // RP mean magnitude (mag)
  float bp_rp;             // BP - RP colour (mag)
  float bp_g;              // BP - G colour (mag)
  float g_rp;              // G - RP colour (mag)
  float radial_velocity;   // Radial velocity (km/s)

  // Flags and status fields
  std::string phot_variable_flag;    // Photometric variability flag
  int16_t     non_single_star;       // Non-single star flag
  bool        has_xp_continuous;     // Has continuous BP/RP spectrum
  bool        has_xp_sampled;        // Has sampled BP/RP spectrum
  bool        has_rvs;               // Has RVS spectrum
  bool        has_epoch_photometry;  // Has epoch photometry
  bool        has_epoch_rv;          // Has epoch radial velocity
  bool        has_mcmc_gspphot;      // Has GSP-Phot MCMC samples
  bool        has_mcmc_msc;          // Has MSC MCMC samples

  // Astrophysical parameters
  float teff_gspphot;      // Effective temperature (K)
  float logg_gspphot;      // Surface gravity (log(cm/s²))
  float mh_gspphot;        // Iron abundance (dex)
  float distance_gspphot;  // Distance (pc)
  float azero_gspphot;     // Monochromatic extinction at 547.7nm (mag)
  float ag_gspphot;        // Extinction in G band (mag)
  float ebpminrp_gspphot;  // E(BP-RP) reddening (mag)

  // Target-specific fields
  std::string target_id;               // Target identifier
  double      target_ra;               // Target right ascension
  double      target_dec;              // Target declination
  double      target_parallax;         // Target parallax
  double      target_pm_ra;            // Target proper motion in RA
  double      target_pm_dec;           // Target proper motion in Dec
  double      target_radial_velocity;  // Target radial velocity
  int         epoch;                   // Epoch
  double      target_separation;       // Target separation (deg)

  // JSON deserialization
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(GaiaStar,
                                 designation,
                                 source_id,
                                 ra,
                                 dec,
                                 parallax,
                                 parallax_error,
                                 pmra,
                                 pmdec,
                                 ruwe,
                                 phot_g_mean_mag,
                                 phot_bp_mean_mag,
                                 phot_rp_mean_mag,
                                 bp_rp,
                                 bp_g,
                                 g_rp,
                                 radial_velocity,
                                 phot_variable_flag,
                                 non_single_star,
                                 has_xp_continuous,
                                 has_xp_sampled,
                                 has_rvs,
                                 has_epoch_photometry,
                                 has_epoch_rv,
                                 has_mcmc_gspphot,
                                 has_mcmc_msc,
                                 teff_gspphot,
                                 logg_gspphot,
                                 mh_gspphot,
                                 distance_gspphot,
                                 azero_gspphot,
                                 ag_gspphot,
                                 ebpminrp_gspphot,
                                 target_id,
                                 target_ra,
                                 target_dec,
                                 target_parallax,
                                 target_pm_ra,
                                 target_pm_dec,
                                 target_radial_velocity,
                                 epoch,
                                 target_separation)

  void print() const {
    std::cout << "Core identifiers:\n"
              << "  Designation: " << designation << "\n"
              << "  Source ID: " << source_id << "\n\n"
              << "Position and motion:\n"
              << "  RA: " << ra << " deg\n"
              << "  Dec: " << dec << " deg\n"
              << "  Parallax: " << parallax << " mas\n"
              << "  Parallax error: " << parallax_error << " mas\n"
              << "  PM RA: " << pmra << " mas/yr\n"
              << "  PM Dec: " << pmdec << " mas/yr\n"
              << "  RUWE: " << ruwe << "\n\n"
              << "Photometry:\n"
              << "  G mag: " << phot_g_mean_mag << "\n"
              << "  BP mag: " << phot_bp_mean_mag << "\n"
              << "  RP mag: " << phot_rp_mean_mag << "\n"
              << "  BP-RP: " << bp_rp << "\n"
              << "  BP-G: " << bp_g << "\n"
              << "  G-RP: " << g_rp << "\n"
              << "  Radial velocity: " << radial_velocity << " km/s\n\n"
              << "Flags and status:\n"
              << "  Variable flag: " << phot_variable_flag << "\n"
              << "  Non-single star: " << non_single_star << "\n"
              << "  Has XP continuous: " << has_xp_continuous << "\n"
              << "  Has XP sampled: " << has_xp_sampled << "\n"
              << "  Has RVS: " << has_rvs << "\n"
              << "  Has epoch photometry: " << has_epoch_photometry << "\n"
              << "  Has epoch RV: " << has_epoch_rv << "\n"
              << "  Has MCMC GSPPhot: " << has_mcmc_gspphot << "\n"
              << "  Has MCMC MSC: " << has_mcmc_msc << "\n\n"
              << "Astrophysical parameters:\n"
              << "  Teff: " << teff_gspphot << " K\n"
              << "  log(g): " << logg_gspphot << "\n"
              << "  [M/H]: " << mh_gspphot << "\n"
              << "  Distance: " << distance_gspphot << " pc\n"
              << "  A0: " << azero_gspphot << " mag\n"
              << "  AG: " << ag_gspphot << " mag\n"
              << "  E(BP-RP): " << ebpminrp_gspphot << " mag\n\n"
              << "Target info:\n"
              << "  Target ID: " << target_id << "\n"
              << "  Target RA: " << target_ra << " deg\n"
              << "  Target Dec: " << target_dec << " deg\n"
              << "  Target parallax: " << target_parallax << " mas\n"
              << "  Target PM RA: " << target_pm_ra << " mas/yr\n"
              << "  Target PM Dec: " << target_pm_dec << " mas/yr\n"
              << "  Target RV: " << target_radial_velocity << " km/s\n"
              << "  Epoch: " << epoch << "\n"
              << "  Separation: " << target_separation << " deg\n"
              << "\n----------------------------------------\n\n";
  }
};

struct GaiaData {
  std::vector<GaiaStar> stars;

  static GaiaData from_json(const nlohmann::json& j) {
    GaiaData data;

    // If there's a "data" array in the JSON
    if (j.contains("data")) {
      // Convert each array element to a GaiaStar
      auto& data_array = j["data"];
      data.stars.reserve(data_array.size());

      for (const auto& row : data_array) {
        GaiaStar star;
        // Parse array values in order of metadata fields
        star.designation            = row[0].get<std::string>();
        star.source_id              = row[1].get<int64_t>();
        star.ra                     = row[2].get<double>();
        star.dec                    = row[3].get<double>();
        star.parallax               = row[4].is_null() ? 0.0 : row[4].get<double>();
        star.parallax_error         = row[5].is_null() ? 0.0f : row[5].get<float>();
        star.pmra                   = row[6].is_null() ? 0.0 : row[6].get<double>();
        star.pmdec                  = row[7].is_null() ? 0.0 : row[7].get<double>();
        star.ruwe                   = row[8].is_null() ? 0.0f : row[8].get<float>();
        star.phot_g_mean_mag        = row[9].is_null() ? 0.0f : row[9].get<float>();
        star.phot_bp_mean_mag       = row[10].is_null() ? 0.0f : row[10].get<float>();
        star.phot_rp_mean_mag       = row[11].is_null() ? 0.0f : row[11].get<float>();
        star.bp_rp                  = row[12].is_null() ? 0.0f : row[12].get<float>();
        star.bp_g                   = row[13].is_null() ? 0.0f : row[13].get<float>();
        star.g_rp                   = row[14].is_null() ? 0.0f : row[14].get<float>();
        star.radial_velocity        = row[15].is_null() ? 0.0f : row[15].get<float>();
        star.phot_variable_flag     = row[16].get<std::string>();
        star.non_single_star        = row[17].get<int16_t>();
        star.has_xp_continuous      = row[18].get<bool>();
        star.has_xp_sampled         = row[19].get<bool>();
        star.has_rvs                = row[20].get<bool>();
        star.has_epoch_photometry   = row[21].get<bool>();
        star.has_epoch_rv           = row[22].get<bool>();
        star.has_mcmc_gspphot       = row[23].get<bool>();
        star.has_mcmc_msc           = row[24].get<bool>();
        star.teff_gspphot           = row[25].is_null() ? 0.0f : row[25].get<float>();
        star.logg_gspphot           = row[26].is_null() ? 0.0f : row[26].get<float>();
        star.mh_gspphot             = row[27].is_null() ? 0.0f : row[27].get<float>();
        star.distance_gspphot       = row[28].is_null() ? 0.0f : row[28].get<float>();
        star.azero_gspphot          = row[29].is_null() ? 0.0f : row[29].get<float>();
        star.ag_gspphot             = row[30].is_null() ? 0.0f : row[30].get<float>();
        star.ebpminrp_gspphot       = row[31].is_null() ? 0.0f : row[31].get<float>();
        star.target_id              = row[32].get<std::string>();
        star.target_ra              = row[33].get<double>();
        star.target_dec             = row[34].get<double>();
        star.target_parallax        = row[35].get<double>();
        star.target_pm_ra           = row[36].get<double>();
        star.target_pm_dec          = row[37].get<double>();
        star.target_radial_velocity = row[38].get<double>();
        star.epoch                  = row[39].get<int>();
        star.target_separation      = row[40].get<double>();

        data.stars.push_back(std::move(star));
      }
    }

    return data;
  }
};
