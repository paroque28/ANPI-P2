#include <complex>
#include "lib/optionparser.h"
#include "src/stringUtils.h"
#include "src/laguerre.h"
#include "src/muller.h"
#include <boost/math/tools/polynomial.hpp>
using namespace boost::math::tools;
using namespace std;
int main(int argc, char* argv[]) {
    try {
        cxxopts::Options options("anpi-pol", " anpi-pol - Laguerre - Muller solutions for polynomial equations");

        options.add_options()
                ("l,laguerre", "Use Laguerre method")
                ("m,muller", "Use Muller method")
                ("t,time", "Use time tests")
                ("f,float", "Use floats for precission")
                ("p,polish", "Use polish")
                ("d,division", "Division of polynomials")
                ("a,xl", "Muller lower x",cxxopts::value<double>())
                ("b,xm", "Muller medium x",cxxopts::value<double>())
                ("c,xu", "Muller upper x",cxxopts::value<double>())
                ("u,equ", "Equation 1 to solve, example \"3.0+2.0+1.0\" is equivalent to 3x^2+2x+1",cxxopts::value<std::string>())
                ("v,eqv", "Equation 2 used to divide",cxxopts::value<std::string>())
                ("h,help", "Print help");
        options.parse(argc, argv);



        if (options.count("help")) {
            std::cout << options.help({""}) << std::endl;
            exit(0);
        }

        if (options.count("equ")) {
            std::string ustring = options["equ"].as<std::string>();
            std::string del = "+";
            std::vector<std::complex<double>> u = splitDouble(ustring, del);
            if (options.count("laguerre")) {
                std::vector<std::complex<double>> res = allRoots(u);
                for (int j = 0; j < res.size(); ++j) {
                    std::cout  << res[j] << std::endl;
                }

            } else if (options.count("muller")) {
                double xl,xm,xu;
                if(options.count("xl"))xl = options["xl"].as<double>(); else{exit(1);}
                if(options.count("xm"))xm = options["xm"].as<double>(); else{exit(1);}
                if(options.count("xu"))xu = options["xu"].as<double>(); else{exit(1);}
                std::vector<std::complex<double>> res = anpi::muller::allRoots(u,xl,xm,xu);
                for (int j = 0; j < res.size(); ++j) {
                    std::cout  << res[j] << std::endl;
                }


            } else if (options.count("division")) {
                if (options.count("eqv")) {
                    std::string vstring = options["eqv"].as<std::string>();
                    std::vector<std::complex<double>> v = splitDouble(vstring, del);
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
