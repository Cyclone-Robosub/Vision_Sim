#include <torch/script.h> // Essential for loading models
#include <iostream>
#include <memory>

int main() {
    torch::jit::script::Module module;
    try {
        // Load the model
        module = torch::jit::load("best_traced.pt");
    }
    catch (const c10::Error& e) {
        std::cerr << "Error loading the modelvis\n";
        return -1;
    }

    // Create a vector of inputs (models expect a list of inputs)
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(torch::ones({1, 3, 640, 640}));

    // Execute the model
    at::Tensor output = module.forward(inputs).toTensor();

    std::cout << "Output shape: " << output.sizes() << std::endl;
    return 0;
}