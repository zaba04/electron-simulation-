#include <fstream>
#include <iostream>

#include "wave_function.h"


int main() {

    //               N,   K0, omega, tau, deltatau
    wave_function wf(100, 1, 14.804066, 0, 0.0001);

    std::ofstream out_file("after_init.out");
    if (!out_file.is_open()) {
        std::cerr << "Nie mogę utworzyć pliku after init" << std::endl;
        return 1;
    }

    std::ofstream out_file2("density.dat");
    if (!out_file2.is_open()) {
        std::cerr << "Nie mogę utworzyć pliku density" << std::endl;
        return 1;
    }

    for (int j = 0; j < 5000000; j++) {
        wf.calculate();
        if (j%1000 == 0) {
            std::vector<double> tmp = wf.calculate_params_for_file();
            out_file << j*0.0001 << "  " << tmp[0] << "  " << tmp[1] << "  " << tmp[2] << std::endl;
            tmp.clear();

            std::vector<double> tmpDen = wf.calculate_density_for_file();
            for (int i = 0; i < tmpDen.size(); i++) {
                out_file2 << tmpDen[i] << std::endl;
            }
            out_file2 << std::endl;
            out_file2 << std::endl;
        }
    }

    out_file.close();
    out_file.close();
    return 0;
}
