#pragma once

#include <fstream>
#include <sstream>
#include "rtwtypes.hpp"
#include <cmath>
#include <cstring>
#include <type_traits>

struct input_struct {
  ap_fixed<14,2> x[4];
  ap_ufixed<14,0> w[4];
  ap_uint<1> b;
};

struct output_struct {
  ap_fixed<14,0> y;
};

class neuron_fixptClass_tb
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
 public:
  neuron_fixptClass_tb()
  {
    num_test_cases = 1;
    input_test_cases = 0;
    output_test_cases = 0;
    failed_test_cases = 0;
    sim_passes = true;
    stimuli_done = false;
    checker_done = false;
    test_point_failed = false;
  }

  ~neuron_fixptClass_tb()
  {
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
    void get_next_value(std::ifstream& fs, T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    ap_biguint<128> ref = ref_str.c_str();
    in = ref;
  }

  void get_next_value(std::ifstream& fs, boolean_T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    in = std::stoi(ref_str);
  }

  void get_next_value(std::ifstream& fs, real_T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    uint64_T ref_int = (uint64_T)std::stoull(ref_str, nullptr, 16);
    std::memcpy(&in, &ref_int, sizeof(real_T));
  }

  void get_next_value(std::ifstream& fs, real32_T (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    uint32_T ref_int = (uint32_T)std::stoull(ref_str, nullptr, 16);
    std::memcpy(&in, &ref_int, sizeof(real32_T));
  }

  template<int wl, int iwl>
    void get_next_value(std::ifstream& fs, ap_ufixed<wl,iwl> (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    in.range() = ref_str.c_str();
  }

  template<int wl, int iwl>
    void get_next_value(std::ifstream& fs, ap_fixed<wl,iwl> (&in))
  {
    std::string ref_str;
    fs >> ref_str;
    ref_str = "0x" + ref_str;
    in.range() = ref_str.c_str();
  }

  template<typename T>
    void read_scalar_input(std::ifstream& fs, T (&in))
  {
    get_next_value(fs,in);
  }

  template<typename T, size_t dim_1>
    void read_vector_input(std::ifstream& fs, T (&in)[dim_1])
  {
    for (int j_1 = 0; j_1 < dim_1; j_1++) {
      read_scalar_input(fs, in[j_1]);
    }
  }

  template<typename T, size_t dim_1, size_t dim_2>
    void read_2Dmatrix_input(std::ifstream& fs, T (&in)[dim_1][dim_2])
  {
    for (int j_2 = 0; j_2 < dim_2; j_2++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        read_scalar_input(fs, in[j_1][j_2]);
      }
    }
  }

  template<typename T, size_t dim_1, size_t dim_2, size_t dim_3>
    void read_3Dmatrix_input(std::ifstream& fs, T (&in)[dim_1][dim_2][dim_3])
  {
    for (int j_3 = 0; j_3 < dim_3; j_3++) {
      for (int j_1 = 0; j_1 < dim_1; j_1++) {
        for (int j_2 = 0; j_2 < dim_2; j_2++) {
          read_scalar_input(fs, in[j_1][j_2][j_3]);
        }
      }
    }
  }

  void generate_stimulus(input_struct& in)
  {
    ap_fixed<14,2> x_loc_0;
    x_loc_0.range() = "0x3941";
    in.x[0] = x_loc_0;
    ap_fixed<14,2> x_loc_1;
    x_loc_1.range() = "0x2c4f";
    in.x[1] = x_loc_1;
    ap_fixed<14,2> x_loc_2;
    x_loc_2.range() = "0x2a66";
    in.x[2] = x_loc_2;
    ap_fixed<14,2> x_loc_3;
    x_loc_3.range() = "0x308f";
    in.x[3] = x_loc_3;
    ap_ufixed<14,0> w_loc_0;
    w_loc_0.range() = "0x2000";
    in.w[0] = w_loc_0;
    ap_ufixed<14,0> w_loc_1;
    w_loc_1.range() = "0x1333";
    in.w[1] = w_loc_1;
    ap_ufixed<14,0> w_loc_2;
    w_loc_2.range() = "0x0666";
    in.w[2] = w_loc_2;
    ap_ufixed<14,0> w_loc_3;
    w_loc_3.range() = "0x0666";
    in.w[3] = w_loc_3;
    ap_uint<1> b_loc;
    b_loc = ap_biguint<128>("0x0");
    in.b = b_loc;
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
    void check_scalar_output(std::ifstream& fs, T (&out), const std::string
    outName)
  {
    T ref;
    get_next_value(fs, ref);
    check_scalar_output(ref,out,outName);
  }

  template<typename T, size_t dim_1>
    void check_vector_output(std::ifstream& fs, T (&out)[dim_1], const std::
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
    void check_2Dmatrix_output(std::ifstream& fs, T (&out)[dim_1][dim_2], const
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
    void check_3Dmatrix_output(std::ifstream& fs, T (&out)[dim_1][dim_2][dim_3],
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
    ap_fixed<14,0> y_ref;
    y_ref.range() = "0x0c10";
    check_scalar_output(y_ref, out.y, "y");
    if (test_point_failed) {
      failed_test_cases++;
    }

    output_test_cases++;
    if (output_test_cases == num_test_cases) {
      checker_done = true;
    }
  }
};
