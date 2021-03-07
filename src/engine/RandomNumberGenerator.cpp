//
// Created by Ciaran on 05/02/2021.
//

#include "PokerX/engine/RandomNumberGenerator.h"
#include <random>

namespace pokerx {


    RandomNumberGenerator::RandomNumberGenerator(unsigned long long seed)
            : seed_(seed), generator_(std::default_random_engine(seed)) {}

    RandomNumberGenerator &RandomNumberGenerator::getInstance() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        static RandomNumberGenerator singleton(seed);
        return singleton;
    }

    unsigned long long int RandomNumberGenerator::getSeed() const {
        return seed_;
    }

    void RandomNumberGenerator::setSeed(unsigned long long int seed) {
        // it is pointless setting a seed and not restarting the
        // rng with that seed. So setting the seed also resets the rng
        // with that seed
        seed_ = seed;
        generator_ = std::default_random_engine(seed_);
    }

    std::default_random_engine RandomNumberGenerator::getGenerator() const {
        return generator_;
    }

    void RandomNumberGenerator::setGenerator(const std::default_random_engine &generator) {
        generator_ = generator;
    }

    double RandomNumberGenerator::uniformReal(double lb, double ub) {
        std::uniform_real_distribution<double> distibution(lb, ub);
        return distibution(generator_);
    }

    std::vector<double> RandomNumberGenerator::uniformReal(double lb, double ub, int size) {
        std::vector<double> r;
        for (int i=0; i<size; i++){
            r.push_back(uniformReal(lb, ub));
        }
        return r;
    }

    double RandomNumberGenerator::uniformInt(int lb, int ub) {
        std::uniform_int_distribution<int> distibution(lb, ub);
        return distibution(generator_);
    }

    std::vector<double> RandomNumberGenerator::uniformInt(int lb, int ub, int size) {
        std::vector<double> r;
        for (int i=0; i<size; i++){
            r.push_back(uniformInt(lb, ub));
        }
        return r;
    }


    double RandomNumberGenerator::normal(double mu, double sigma) {
        std::normal_distribution<double> distibution(mu, sigma);
        return distibution(generator_);
    }

    std::vector<double> RandomNumberGenerator::normal(double mu, double sigma, int size) {
        std::vector<double> r;
        for (int i=0; i<size; i++){
            r.push_back(normal(mu, sigma));
        }
        return r;
    }


}