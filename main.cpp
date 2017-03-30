#include "lib/optionparser.h"
#include "src/stringUtils.h"
int main(int argc, char* argv[]) {
    try {
        cxxopts::Options options("anpi-pol", " anpi-pol - Laguerre - Muller solutions for polynomial equations");

        options.add_options()
                ("l,laguerre", "Use Laguerre method")
                ("m,muller", "Use Muller method")
                ("t,time", "Use time tests")
                ("d,division", "Division of polynomials")
                ("u,equ", "Equation 1 to solve, example \"3.0+2.0+1.0\" is equivalent to 3x^2+2x+1",cxxopts::value<std::string>())
                ("v,eqv", "Equation 2 used to divide",cxxopts::value<std::string>())
                ("h,help", "Print help");
        options.parse(argc, argv);


        if (options.count("help") || argc == 0) {
            std::cout << options.help({""}) << std::endl;
            exit(0);
        }

        if (options.count("equ")) {
            std::string ustring = options["equ"].as<std::string>();
            std::string del = "+";
            std::vector<double> u = splitDouble(ustring, del);
            if (options.count("laguerre")) {



            } else if (options.count("muller")) {



            } else if (options.count("division")) {
                if (options.count("eqv")) {
                    std::string vstring = options["eqv"].as<std::string>();
                    std::vector<double> v = splitDouble(vstring, del);


                }
            }
        }
    }
    catch (const cxxopts::OptionException& e)
    {
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }

}
