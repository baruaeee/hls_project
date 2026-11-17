#pragma once

#include <fstream>
#include <sstream>
#include "rtwtypes.hpp"
#include <cmath>
#include <cstring>
#include <type_traits>

struct input_struct {
  ap_int<11> x_in;
  bool reset_rsvd;
};

struct output_struct {
  ap_int<10> residual;
  ap_int<12> predicted;
};

class neuron_predictor_fixptClass_tb
{
 private:
  int num_test_cases;
  int input_test_cases;
  int output_test_cases;
  int failed_test_cases;
  bool sim_passes;
  bool stimuli_done;
  bool checker_done;
  bool test_point_failed;
  std::ifstream fstream_x_in;
  std::ifstream fstream_reset_rsvd;
  std::ifstream fstream_residual_expected;
  std::ifstream fstream_predicted_expected;
 public:
  neuron_predictor_fixptClass_tb()
  {
    num_test_cases = 256;
    input_test_cases = 0;
    output_test_cases = 0;
    failed_test_cases = 0;
    sim_passes = true;
    stimuli_done = false;
    checker_done = false;
    test_point_failed = false;
    fstream_x_in.open("x_in.dat");
    fstream_reset_rsvd.open("reset_rsvd.dat");
    fstream_residual_expected.open("residual_expected.dat");
    fstream_predicted_expected.open("predicted_expected.dat");
  }

  ~neuron_predictor_fixptClass_tb()
  {
    fstream_x_in.close();
    fstream_reset_rsvd.close();
    fstream_residual_expected.close();
    fstream_predicted_expected.close();
  }

  int get_num_test_cases()
  {
    return num_test_cases;
  }

  int get_num_test_cases_passed()
  {
    return (num_test_cases - failed_test_cases);
  }

  int get_num_test_cases_failed()
  {
    return failed_test_cases;
  }

  bool is_sim_passing()
  {
    return sim_passes;
  }

  bool is_stimuli_done()
  {
    return stimuli_done;
  }

  bool is_checker_done()
  {
    return checker_done;
  }

  void print_pass_fail()
  {
    if (sim_passes) {
      std::cout << "### Total Testpoints   : "<< num_test_cases << std::endl;
      std::cout << "### Tests Passed       : "<< get_num_test_cases_passed() <<
        std::endl;
      std::cout << "**************TEST COMPLETED (PASSED)**************" << std::
        endl;
    } else {
      std::cout << "### Total Testpoints   : "<< num_test_cases << std::endl;
      std::cout << "### Tests Failed       : "<< get_num_test_cases_failed() <<
        std::endl;
      std::cout << "**************TEST COMPLETED (FAILED)**************" << std::
        endl;
    }
  }

  template<typename T>
    void get_next_value(std::istream& fs, T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    in = ref_str.c_str();
  }

  void get_next_value(std::istream& fs, boolean_T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    in = std::stoi(ref_str);
  }

  void get_next_value(std::istream& fs, real_T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    uint64_T ref_int = (uint64_T)std::stoull(ref_str, nullptr, 16);
    std::memcpy(&in, &ref_int, sizeof(real_T));
  }

  void get_next_value(std::istream& fs, real32_T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    uint32_T ref_int = (uint32_T)std::stoull(ref_str, nullptr, 16);
    std::memcpy(&in, &ref_int, sizeof(real32_T));
  }

  template<int wl, int iwl>
    void get_next_value(std::istream& fs, ap_ufixed<wl,iwl> (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    in.range() = ref_str.c_str();
  }

  template<int wl, int iwl>
    void get_next_value(std::istream& fs, ap_fixed<wl,iwl> (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    in.range() = ref_str.c_str();
  }

  template<typename T>
    void read_scalar_input(std::istream& fs, T (&in))
  {
    get_next_value(fs,in);
  }

  template<typename T, size_t dim_1>
    void read_vector_input(std::istream& fs, T (&in)[dim_1])
  {
    for (int j_1 = 0; j_1 < dim_1; j_1++) {
      read_scalar_input(fs, in[j_1]);
    }
  }

  template<typename T, size_t dim_1, size_t dim_2>
    void read_2Dmatrix_input(std::istream& fs, T (&in)[dim_1][dim_2])
  {
    for (int j_2 = 0; j_2 < dim_2; j_2++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        read_scalar_input(fs, in[j_1][j_2]);
      }
    }
  }

  template<typename T, size_t dim_1, size_t dim_2, size_t dim_3>
    void read_3Dmatrix_input(std::istream& fs, T (&in)[dim_1][dim_2][dim_3])
  {
    for (int j_3 = 0; j_3 < dim_3; j_3++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        for (int j_2 = 0; j_2 < dim_2; j_2++) {
          read_scalar_input(fs, in[j_1][j_2][j_3]);
        }
      }
    }
  }

  void read_struct_field_from_line(std::string& line, size_t& pos, real_T& field)
  {
    std::string hex_str = line.substr(pos, 16);
    pos += 16;
    hex_str = "0x" + hex_str;
    uint64_T ref_int = (uint64_T)std::stoull(hex_str, nullptr, 16);
    std::memcpy(&field, &ref_int, sizeof(real_T));
  }

  void read_struct_field_from_line(std::string& line, size_t& pos, real32_T
    & field)
  {
    std::string hex_str = line.substr(pos, 8);
    pos += 8;
    hex_str = "0x" + hex_str;
    uint32_T ref_int = (uint32_T)std::stoull(hex_str, nullptr, 16);
    std::memcpy(&field, &ref_int, sizeof(real32_T));
  }

  void read_struct_field_from_line(std::string& line, size_t& pos, boolean_T
    & field)
  {
    std::string hex_str = line.substr(pos, 1);
    pos += 1;
    field = std::stoi(hex_str, nullptr, 16);
  }

  template<int wl, int iwl>
    void read_struct_field_from_line(std::string& line, size_t& pos, ap_fixed<wl,
    iwl>& field)
  {
    int hex_chars = (wl + 3) / 4;
    std::string hex_str = line.substr(pos, hex_chars);
    pos += hex_chars;
    hex_str = "0x" + hex_str;
    field.range() = hex_str.c_str();
  }

  template<int wl, int iwl>
    void read_struct_field_from_line(std::string& line, size_t& pos, ap_ufixed<
    wl,iwl>& field)
  {
    int hex_chars = (wl + 3) / 4;
    std::string hex_str = line.substr(pos, hex_chars);
    pos += hex_chars;
    hex_str = "0x" + hex_str;
    field.range() = hex_str.c_str();
  }

  template<int wl>
    void read_struct_field_from_line(std::string& line, size_t& pos, ap_int<wl>&
    field)
  {
    int hex_chars = (wl + 3) / 4;
    std::string hex_str = line.substr(pos, hex_chars);
    pos += hex_chars;
    hex_str = "0x" + hex_str;
    field = hex_str.c_str();
  }

  template<int wl>
    void read_struct_field_from_line(std::string& line, size_t& pos, ap_uint<wl>
    & field)
  {
    int hex_chars = (wl + 3) / 4;
    std::string hex_str = line.substr(pos, hex_chars);
    pos += hex_chars;
    hex_str = "0x" + hex_str;
    field = hex_str.c_str();
  }

  template<typename T>
    void read_struct_field(std::string& line, size_t& pos, T& field)
  {
    read_struct_field_from_line(line, pos, field);
  }

  template<typename T, size_t dim_1>
    void read_struct_field(std::string& line, size_t& pos, T (&field)[dim_1])
  {
    for (int j_1 = 0; j_1 < dim_1; j_1++) {
      read_struct_field(line, pos, field[j_1]);
    }
  }

  template<typename T, size_t dim_1, size_t dim_2>
    void read_struct_field(std::string& line, size_t& pos, T (&field)[dim_1]
    [dim_2])
  {
    for (int j_2 = 0; j_2 < dim_2; j_2++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        read_struct_field(line, pos, field[j_1][j_2]);
      }
    }
  }

  template<typename T, size_t dim_1, size_t dim_2, size_t dim_3>
    void read_struct_field(std::string& line, size_t& pos, T (&field)[dim_1]
    [dim_2][dim_3])
  {
    for (int j_3 = 0; j_3 < dim_3; j_3++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        for (int j_2 = 0; j_2 < dim_2; j_2++) {
          read_struct_field(line, pos, field[j_1][j_2][j_3]);
        }
      }
    }
  }

  void generate_stimulus(input_struct& in)
  {
    read_scalar_input(fstream_x_in, in.x_in);
    read_scalar_input(fstream_reset_rsvd, in.reset_rsvd);
    input_test_cases++;
    if (input_test_cases == num_test_cases) {
      stimuli_done = true;
    }
  }

  template<typename T>
    void check_scalar_output(T (&ref), T (&act), const std::string outName)
  {
    if (act != ref) {
      std::cout << "TestPoint: ";
      sim_passes = false;
      test_point_failed = true;
      std::cout << std::to_string(output_test_cases + 1);
      std::cout << " Output mismatch: " << outName;
      std::cout << " Expected: " << ref;
      std::cout << " Actual: " << act;
      std::cout << std::endl;
    }
  }

  template<typename T>
    void check_scalar_output(std::istream& fs, T (&out), const std::string
    outName)
  {
    T ref;
    get_next_value(fs, ref);
    check_scalar_output(ref,out,outName);
  }

  template<typename T, size_t dim_1>
    void check_vector_output(std::istream& fs, T (&out)[dim_1], const std::
    string outName)
  {
    for (int j_1 = 0; j_1 < dim_1; j_1++) {
      check_scalar_output(fs, out[j_1], outName);
    }
  }

  template<typename T, size_t dim_1>
    void check_vector_output(T (&out_ref)[dim_1], T (&out)[dim_1], const std::
    string outName)
  {
    for (int j_1 = 0; j_1 < dim_1; j_1++) {
      check_scalar_output(out_ref[j_1], out[j_1], outName);
    }
  }

  template<typename T, size_t dim_1, size_t dim_2>
    void check_2Dmatrix_output(std::istream& fs, T (&out)[dim_1][dim_2], const
    std::string outName)
  {
    for (int j_2 = 0; j_2 < dim_2; j_2++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        check_scalar_output(fs, out[j_1][j_2], outName);
      }
    }
  }

  template<typename T, size_t dim_1, size_t dim_2>
    void check_2Dmatrix_output(T (&out_ref)[dim_1][dim_2], T (&out)[dim_1][dim_2],
    const std::string outName)
  {
    for (int j_2 = 0; j_2 < dim_2; j_2++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        check_scalar_output(out_ref[j_1][j_2], out[j_1][j_2], outName);
      }
    }
  }

  template<typename T, size_t dim_1, size_t dim_2, size_t dim_3>
    void check_3Dmatrix_output(std::istream& fs, T (&out)[dim_1][dim_2][dim_3],
    const std::string outName)
  {
    for (int j_3 = 0; j_3 < dim_3; j_3++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        for (int j_2 = 0; j_2 < dim_2; j_2++) {
          check_scalar_output(fs, out[j_1][j_2][j_3], outName);
        }
      }
    }
  }

  template<typename T, size_t dim_1, size_t dim_2, size_t dim_3>
    void check_3Dmatrix_output(T (&out_ref)[dim_1][dim_2][dim_3], T (&out)[dim_1]
    [dim_2][dim_3], const std::string outName)
  {
    for (int j_3 = 0; j_3 < dim_3; j_3++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        for (int j_2 = 0; j_2 < dim_2; j_2++) {
          check_scalar_output(out_ref[j_1][j_2][j_3], out[j_1][j_2][j_3],
                              outName);
        }
      }
    }
  }

  void check_output(output_struct& out)
  {
    test_point_failed = false;
    check_scalar_output(fstream_residual_expected, out.residual, "residual");
    check_scalar_output(fstream_predicted_expected, out.predicted, "predicted");
    if (test_point_failed) {
      failed_test_cases++;
    }

    output_test_cases++;
    if (output_test_cases == num_test_cases) {
      checker_done = true;
    }
  }
};
