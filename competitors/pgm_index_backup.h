#ifndef SOSDB_PGM_H
#define SOSDB_PGM_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "../util.h"
#include "base.h"
//#include "port_infer.h"
#include <torch/script.h>

int path_dimension = 1;
std::vector<double> inputs(1);

torch::jit::script::Module module_0;
torch::jit::script::Module module_1;
torch::jit::script::Module module_2;
torch::jit::script::Module module_3;
torch::jit::script::Module module_4;
torch::jit::script::Module module_5;
torch::jit::script::Module module_6;
torch::jit::script::Module module_7;
torch::jit::script::Module module_8;
torch::jit::script::Module module_9;
torch::jit::script::Module module_10;
torch::jit::script::Module module_11;
torch::jit::script::Module module_12;
torch::jit::script::Module module_13;
torch::jit::script::Module module_14;
torch::jit::script::Module module_15;
torch::jit::script::Module module_16;
torch::jit::script::Module module_17;
torch::jit::script::Module module_18;
torch::jit::script::Module module_19;
torch::jit::script::Module module_20;

std::vector<std::vector<double> *> prefix_vector;
void load_modules(){
  try {
    module_0 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_0.pt");
    module_1 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_1.pt");
    module_2 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_2.pt");
    module_3 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_3.pt");
    module_4 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_4.pt");
    module_5 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_5.pt");
    module_6 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_6.pt");
    module_7 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_7.pt");
    module_8 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_8.pt");
    module_9 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_9.pt");
    module_10 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_10.pt");
    module_11 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_11.pt");
    module_12 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_12.pt");
    module_13 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_13.pt");
    module_14 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_14.pt");
    module_15 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_15.pt");
    module_16 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_16.pt");
    module_17 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_17.pt");
    module_18 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_18.pt");
    module_19 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_19.pt");
    module_20 = torch::jit::load("/home/pgu/git/SOSD/competitors/learned_index/model_20.pt");
    }
    catch (const c10::Error& e) {
      std::cerr << "error loading the model\n";
    }
}

int cmp_path_prefix (double double_input, std::vector<double> *prefix) {
    long input_element, prefix_element;
    input_element = (long)(double_input * 100000000000000000);
    prefix_element = (long)(prefix->at(0) * 100000000000000000);
    //std::cout << "input " << input_element << " prefix " << prefix_element << std::endl;
    if (input_element > prefix_element){
        return 1;
    } else if (input_element < prefix_element){
        return -1;
    }
    return 0;
}

int int2index(uint64_t int_input){
    int path_dimension = 1;
    int nn_index = 0;
    double double_input = ((double)int_input - 979672113)/(1216240356 - 979672113);
    
    //std::cout << std::setprecision(19);
    //std::cout << "Normalized input" << double_input << std::endl;
    inputs.at(0) = double_input;
    
    int left = 0, right = prefix_vector.size() - 1, index = (int)((left + right) / 2);
    if (cmp_path_prefix(double_input, prefix_vector.at(left)) <= 0) {
        nn_index = (int)(prefix_vector.at(left))->at(path_dimension);
    } else if (cmp_path_prefix(double_input, prefix_vector.at(right)) >= 0) {
        nn_index = (int)(prefix_vector.at(right))->at(path_dimension);
    } else {
        while (left < right - 1) {
            int cmp_result = cmp_path_prefix(double_input, prefix_vector.at(index));
            if (cmp_result == 0) {
                nn_index = (int)(prefix_vector.at(index))->at(path_dimension);
                break;
            } else if (cmp_result > 0) {
                left = index;
                index = (int)((left + right) / 2);
            } else {
                right = index;
                index = (int)((left + right) / 2);
            }
        }
        if (right - left == 1) {
            nn_index = (int)(prefix_vector.at(left))->at(path_dimension);
        }
    }

    //printf("USE NN: %d\n", nn_index);
    std::vector<torch::jit::IValue> inputs_nn;
    at::Tensor input_tensor = torch::tensor({{inputs.at(0)}}, torch::TensorOptions().dtype(torch::kFloat64));
    inputs_nn.push_back(input_tensor);

    at::Tensor output;
    if (nn_index == 0) {
        output = module_0.forward(inputs_nn).toTensor();
    }
    if (nn_index == 1) {
        output = module_1.forward(inputs_nn).toTensor();
    }
    if (nn_index == 2) {
        output = module_2.forward(inputs_nn).toTensor();
    }
    if (nn_index == 3) {
        output = module_3.forward(inputs_nn).toTensor();
    }
    if (nn_index == 4) {
        output = module_4.forward(inputs_nn).toTensor();
    }
    if (nn_index == 5) {
        output = module_5.forward(inputs_nn).toTensor();
    }
    if (nn_index == 6) {
        output = module_6.forward(inputs_nn).toTensor();
    }
    if (nn_index == 7) {
        output = module_7.forward(inputs_nn).toTensor();
    }
    if (nn_index == 8) {
        output = module_8.forward(inputs_nn).toTensor();
    }
    if (nn_index == 9) {
        output = module_9.forward(inputs_nn).toTensor();
    }
    if (nn_index == 10) {
        output = module_10.forward(inputs_nn).toTensor();
    }
    if (nn_index == 11) {
        output = module_11.forward(inputs_nn).toTensor();
    }
    if (nn_index == 12) {
        output = module_12.forward(inputs_nn).toTensor();
    }
    if (nn_index == 13) {
        output = module_13.forward(inputs_nn).toTensor();
    }
    if (nn_index == 14) {
        output = module_14.forward(inputs_nn).toTensor();
    }
    if (nn_index == 15) {
        output = module_15.forward(inputs_nn).toTensor();
    }
    if (nn_index == 16) {
        output = module_16.forward(inputs_nn).toTensor();
    }
    if (nn_index == 17) {
        output = module_17.forward(inputs_nn).toTensor();
    }
    if (nn_index == 18) {
        output = module_18.forward(inputs_nn).toTensor();
    }
    if (nn_index == 19) {
        output = module_19.forward(inputs_nn).toTensor();
    }
    if (nn_index == 20) {
        output = module_20.forward(inputs_nn).toTensor();
    }
    //std::cout << "PREDICTION DOUBLE: " << output[0][0].item<double>() << '\n';
    return (int)(output[0][0].item<double>() * 999999);
}

void parse_prefix(){
  std::ifstream prefix_file("/home/pgu/git/SOSD/competitors/learned_index/prefix_processed");
  std::string tup;
  std::string double_str;
  double doub;
  while (std::getline(prefix_file, tup)) {
    size_t start_pos = 0;
    size_t found = tup.find(',');
    std::vector<double> *line_vec = new std::vector<double>();
    while (found != std::string::npos) {
      double_str = tup.substr(start_pos, found);
      doub = std::stod(double_str);
      //std::cout << doub << std::endl;
      line_vec->push_back(doub);
      start_pos = found+1;
      found = tup.find(',', found + 1);
    }
    double_str = tup.substr(start_pos);
    doub = std::stod(double_str);
    //std::cout << doub << "\n" << std::endl;
    line_vec->push_back(doub);
    prefix_vector.push_back(line_vec);
  }
}

std::size_t port_size(){
  return -1;
}

struct Pos {
    size_t pos; ///< The approximate position of the key.
    size_t lo;  ///< The lower bound of the range where the key can be found.
    size_t hi;  ///< The upper bound of the range where the key can be found.
};


struct Pos find_approx_pos(uint64_t lookup_key) {
  Pos pos;
  int pred = int2index(lookup_key);
  //std::cout << "INT2INDEX PREDICTION: " << pred << std::endl;
  pos.lo = std::max(pred - 256, 0);
  pos.hi = std::min(pred + 256, 999999);
  return pos;
}

template <class KeyType, int pgm_error>
class PGM : public Competitor {
 public:
  uint64_t Build(const std::vector<KeyValue<KeyType>>& data) {
    const auto extract_key = [](KeyValue<KeyType> kv) { return kv.key; };

    // This code uses a boost transform iterator to avoid a copy. It
    // seems to be much slower, however.
    /*
    auto it_begin = boost::make_transform_iterator(data.begin(), extract_key);
    auto it_end = boost::make_transform_iterator(data.end(), extract_key);
    pgm_ = PGMIndex<KeyType, pgm_error, 4>(it_begin, it_end);
    */

    // don't count the data copy time against the PGM build time
    std::vector<KeyType> keys;
    keys.reserve(data.size());
    std::transform(data.begin(), data.end(), std::back_inserter(keys),
                   extract_key);
    std::cout << "PORTFOLIO BUILD" << std::endl;
    /*for(KeyType key:keys) {
      std::cout << "key: " << key << std::endl;
    }*/

    uint64_t build_time =
        util::timing([&] {parse_prefix();  load_modules(); });
    //std::cout << "PORTFOLIO BUILD FINISHED" << std::endl;

    return build_time;
  }

  SearchBound EqualityLookup(const KeyType lookup_key) const {
    //std::cout << "PORTFOLIO LOOKUP: " << lookup_key << "!" << std::endl;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    auto approx_range = find_approx_pos((uint64_t)lookup_key);
    auto lo = approx_range.lo;
    auto hi = approx_range.hi;
    end = std::chrono::high_resolution_clock::now();
    std::cout <<  "port lookup ns: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
    //std::cout << "PORTFOLIO LOOKUP FINISHED" << lookup_key << std::endl;

    return (SearchBound){lo, hi + 1};
  }

  std::string name() const { return "PORT"; }

  std::size_t size() const { return port_size(); }

  bool applicable(bool unique, const std::string& data_filename) const {
    return true;
  }

  int variant() const { return pgm_error; }

};

#endif  // SOSDB_PGM_H
